#pragma once

#include <opencv2/opencv.hpp>
#include "Para.hpp"
using namespace std;
using namespace cv;

class Paint
{
private:
    std::vector<Point2d> makeSplineStroke(int x0, int y0, int R, Mat& refImage, Mat& canvas, Para para, Mat& xGradient, Mat& yGradient);
    void paintLayer(Mat& canvas, Mat& referenceImage, int brushSize, Para para, Mat& xGradient, Mat& yGradient);

public:
    void painting(Mat& src, Mat& dst, Para para);

    Paint(/* args */);
    ~Paint();
};