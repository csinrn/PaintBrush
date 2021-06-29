#include "Paint.hpp"
#include <cstdlib>
Paint::Paint(/* args */)
{  
}

Paint::~Paint()
{
}

void Paint::painting(Mat& src, Mat& dst, Para para)
{
    // create a set of brush sizes
    std::vector<int> brushSet;
    float brushSize = para.minBrushSize;
    for (size_t i = 0; i < para.brushNum; i++)
    {
        brushSet.push_back(brushSize);
        brushSize *= para.brushSizeRatio;
    }
    
/*     // create a blurred src image as the reference image
    Mat referenceImage;
    int sigma = int(brushSet.back()* para.blurFactor);
    GaussianBlur(src, referenceImage, Size(para.gridSize, para.gridSize), sigma);
    
    // create gradient mat for painting
    Mat xGradient, yGradient;
	vector<Mat> channels;
    split(referenceImage, channels);
    Mat luminance = channels.at(0)*0.11 + channels.at(0)*0.59 + channels.at(0)*0.3;
    Sobel(luminance, xGradient, CV_8U, 1, 0);
    Sobel(luminance, yGradient, CV_8U, 0, 1); */

    // create a new constant color image as base canvas
    Mat canvas(src.size(), CV_8UC3, Scalar(0,0,0));
    Mat referenceImage;

    // paint layers for each brush size
    for(int i=brushSet.size()-1; i>=0; i--)
    {
        // create a blurred src image as the reference image
        int sigma = int(brushSet.back()* para.blurFactor);
        GaussianBlur(src, referenceImage, Size(brushSet.at(i)+1, brushSet.at(i)+1), sigma);

        // luminance gradient mat for each reference image
        Mat xGradient, yGradient;
        vector<Mat> channels;
        split(referenceImage, channels);
        Mat luminance = channels.at(0)*0.11 + channels.at(0)*0.59 + channels.at(0)*0.3;
        Sobel(luminance, xGradient, CV_8U, 1, 0, 5);
        Sobel(luminance, yGradient, CV_8U, 0, 1, 5);

        paintLayer(canvas, referenceImage, brushSet.at(i), para, xGradient, yGradient);
    }
    Mat mask;
    cvtColor(canvas, mask, COLOR_BGR2GRAY);
    threshold(mask, mask, 0, 255, THRESH_BINARY_INV);
    referenceImage.copyTo(canvas, mask);
    dst = canvas.clone();
}

void Paint::paintLayer(Mat& canvas, Mat& referenceImage, int brushSize, Para para, Mat& xGradient, Mat& yGradient)
{
    // set of strokes to paint
    std::vector<std::vector<Point2d>> S;

    // decide grid size for brush scanning
    float fg = 1.5;
    int grid = int(fg*brushSize);
    if (grid <= 1) grid = 2;

    // create a mat D = difference(referenced image, canvas)
    Mat ci, ri;
    canvas.convertTo(ci, CV_32FC3);
    referenceImage.convertTo(ri, CV_32FC3);
    Mat D = abs(ri-ci);
    D.convertTo(D, CV_8UC1);
    cvtColor(D, D, COLOR_BGR2GRAY);
    
    double err;
    double minVal; 
    double maxVal; 
    Point minLoc; 
    Point maxLoc;
    std::vector<Point2d> s;

    // through all image, calculate the average difference in a kernel, if the err > threshold, paint a stroke and store it
    for (size_t x = int(grid/2); x < canvas.cols - int(grid/2); x+=grid)
    {
        for (size_t y = int(grid/2); y < canvas.rows - int(grid/2); y+=grid)
        {
            // sum the error near (x,y)
            Rect roi(Point2d(x-grid/2, y-grid/2), Point2d(x+grid/2, y+grid/2));
            err = sum(D(roi))[0] / double(grid*grid);

            // place a stroke starting from the maximum error pixel in this grid
            if(err > para.thresh)
            {
                minMaxLoc( D(roi), &minVal, &maxVal, &minLoc, &maxLoc );
                s = makeSplineStroke( (x-grid/2)+maxLoc.x, (y-grid/2)+maxLoc.y, brushSize, referenceImage, canvas, para, xGradient, yGradient);
                S.push_back(s);
            }
        }
        
    }

    // paint all strokes in S on the canvas
    Vec3b color;
    Point2d startPoint;
    int jitter = para.colorJitter;
    for (auto stroke : S)
    {
        startPoint = stroke.at(0);
        color  =referenceImage.at<Vec3b>(startPoint) + Vec3b(rand()%jitter + rand()%jitter + rand()% jitter);
        for(int i=1; i<stroke.size(); i++)
        {
            line(canvas, stroke.at(i-1), stroke.at(i), color, brushSize);
        }
    }

}

std::vector<Point2d> Paint::makeSplineStroke(int x0, int y0, int R, Mat& referenceImage, Mat& canvas,Para para, Mat& xGradient, Mat& yGradient)
{
    Vec3b strokeColor  =referenceImage.at<Vec3b>(Point(x0, y0));
    Vec3b refColor, canvasColor;
    auto diff = [](Vec3b c1, Vec3b c2)
    {
        return sqrt(pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2) + pow(c1[2] - c2[2], 2));
    };

    // K is the points set of one continuous stroke
    std::vector<Point2d> K;
    Point2d nowPoint = Point2d(x0, y0);
    Point2f lastdxy = Point2f(0,0);
    K.push_back(nowPoint);  // start point

    // store points into K according to the gradient map
    for(int i=0; i< para.maxStrokeLength; i++)
    {
        refColor = referenceImage.at<Vec3b>(nowPoint);
        canvasColor = canvas.at<Vec3b>(nowPoint);

        if(i>para.minStrokeLength  &&  diff(refColor, canvasColor) < diff(refColor, strokeColor))
        {
            return K;
        }

        // make the painting looks alike with src image
        /*if (diff(refColor, strokeColor) > 5)
        {
            return K;
        } */

        float gx = xGradient.at<uchar>(nowPoint);
        float gy = yGradient.at<uchar>(nowPoint);
        if(gx==0 && gy==0)
        {
            return K;
        }
        
        // if necessary, reverse direction
        Point2f normal = Point2f(-gy, gx);
        if(lastdxy.x * normal.x + lastdxy.y*normal.y < 0)
        {
            normal *= -1;
        } 

        // filter the stroke direction
        normal = para.curvatureFilter*normal + (1-para.curvatureFilter) * lastdxy;
        normal = normal / sqrt(normal.x*normal.x + normal.y*normal.y);
        Point2f t = Point2f(nowPoint) + R*normal;
        nowPoint.x = round(t.x);
        nowPoint.y = round(t.y);
        if(nowPoint.x<0 || nowPoint.y<0 || nowPoint.x>=canvas.cols || nowPoint.y>=canvas.rows)
			break;

        K.push_back(nowPoint);
        lastdxy = normal;
    }
    return K;
}