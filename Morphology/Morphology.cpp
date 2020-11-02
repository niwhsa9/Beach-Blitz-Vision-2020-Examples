#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

#define USE
#ifdef USE

int main()
{
    // Load a BGR image
    Mat raw_target;
    raw_target = imread("Images/noisy-target.png");
    imshow("Pre-filter", raw_target);
    waitKey(0);

    // Filter on the green
    Mat hsv_target;
    cvtColor(raw_target, hsv_target, COLOR_BGR2HSV);
    Mat binarytarget(raw_target.size(), CV_8U);
    inRange(hsv_target, Scalar(50, 150, 80), Scalar(70, 255, 255), binarytarget);
    imshow("Post HSV Filter", binarytarget);
    waitKey(0);

    // Noise removal with morphology
    Mat kernel;
    //Larger kernel means bigger "noise" gets removed
    kernel = cv::getStructuringElement(MORPH_RECT, Size(3, 3));
    cv::morphologyEx(binarytarget, binarytarget, MORPH_OPEN, kernel);
    imshow("Post Morphology", binarytarget);
    waitKey(0);

	return 0;
}

#endif
