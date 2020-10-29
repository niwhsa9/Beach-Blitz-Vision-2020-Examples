#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

int main()
{
    // Set up your camera object, the number will be N in /dev/videoN
    cv::VideoCapture stream(0);
    //Mat is a matrix object that stores the frame
    cv::Mat frame;
    //Stream frames with 10 ms period until spacebar is pressed
    while (cv::waitKey(10) != ' ') {
        stream >> frame;
        imshow("Display", frame);
    }
}
