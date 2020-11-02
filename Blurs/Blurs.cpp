
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

#define USE
#ifdef USE

int main()
{
    // Load a BGR image with a lot of noise
    Mat original;
    original = imread("Images/jet.png");
    imshow("Pre-filter", original);
    waitKey(0);

    // Blur it to remove that noise, but note how edges soften
    Mat output(original.size(), CV_8UC3);
    GaussianBlur(original, output, Size(9, 9), 0);
    imshow("Post-blur", output);
    waitKey(0);
}
#endif