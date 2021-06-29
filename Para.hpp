#pragma once

#include <cstdlib>

class Para
{
private:
    /* data */
public:
    Para();
    ~Para();

    int thresh=20;  // 30  // the smaller it is, the more detailed is the painting
    int minBrushSize=2;   // 2 is the smallest
    int brushNum=5; 
    float brushSizeRatio=2; 
    float curvatureFilter=0.7;
    int blurFactor=1;   // sigma of Gaussian blur
    int minStrokeLength=2;
    int maxStrokeLength=2;
    int opacity;
    int gridSize=7;
    int colorJitter=1;
};
