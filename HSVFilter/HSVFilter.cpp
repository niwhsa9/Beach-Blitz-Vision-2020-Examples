#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

#define USE
#ifdef USE

int main()
{
    // Load a BGR image with many colored dice  
    Mat rgbdice;
    rgbdice = imread("Images/multicolor-dice.jpg");
    imshow("Pre-filter", rgbdice);

    //Convert to HSV colorspace 
    Mat hsvdice;
    cvtColor(rgbdice, hsvdice, COLOR_BGR2HSV);

    //Filter out all other colors except greens, leave the result in a grayscale image
    Mat binarydice(hsvdice.size(), CV_8U); 
    inRange(hsvdice, Scalar(50, 150, 80), Scalar(70, 255, 255), binarydice);
    imshow("Post-filter", binarydice);
    waitKey(0);

    return 0;
}

#endif