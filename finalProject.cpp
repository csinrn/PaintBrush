#include"Paint.hpp"
#include"Para.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    Para p;
    Paint paint;

    // read the video
    VideoCapture capture;
    Mat frame;
    string filename = argc ==1 ? "twice6.mp4" : argv[1];
    cout << "file: " << filename << endl;
    frame= capture.open(filename);
    if(!capture.isOpened())
    {
        printf("file can not open ...\n");
        return -1;
    }

    // encoded format
    int encodedformat;
    if(argc==3 && strcmp(argv[2]," MJPEG") )
        encodedformat = VideoWriter::fourcc('M','P','E','G');
    else
        encodedformat = VideoWriter::fourcc('D','I','V','X');
    
    // open video writer
    Size size = Size(capture.get(CAP_PROP_FRAME_WIDTH), capture.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter writer("f.avi",  encodedformat, 15, size, true);
    if(!writer.isOpened())
    {
        cout << "open failed";
        return 0;
    }

    // process the video
    Mat dst;
    int c = 100;
    while (capture.read(frame))
    {
        waitKey(2);

        capture.read(frame);
        paint.painting(frame, dst, p);
        // GaussianBlur(dst, dst, Size(3, 3), 1);
        writer <<dst;

        imshow("output", dst);
        waitKey(2);
        c--;
        if(c==0) break;
    }

    writer.release();
    capture.release();
    return 0;
}