
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
using namespace cv;
using namespace std;

#define USE
#ifdef USE

// Hit spacebar to advance frames
int main()
{
    // Load a BGR image and convert to grayscale 
    Mat original;
    original = imread("Images/shapes.png");
    original = ~original; //invert the colors

    //Grayscale
    Mat grayscale(original.size(), CV_8UC1);
    cvtColor(original, grayscale, COLOR_BGR2GRAY);
    imshow("Grayscale Image", grayscale);

    //Compute contours
    // each object's contour is a list of points. We need a list of contours
    vector<vector<Point> > contours; 
    // The hiearchy contains informations about how objects are nested, we don't need it
    vector<Vec4i> hierarchy; 
    // Find the contours and draw all of them (-1)
    findContours(grayscale, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));
    drawContours(original, contours, -1, Scalar(0, 0, 255), 3);
    imshow("Pipeline", original);
    waitKey(0); //waits for key press

    //Compute convex hull
    // Each object's hull is a vector of points. We need a list of hulls
    vector<vector<Point> > hulls(contours.size());
    for (int i = 0; i < contours.size(); i++) {
        convexHull(contours[i], hulls[i]);
    }
    drawContours(original, hulls, -1, Scalar(255, 0, 0), 3);
    imshow("Pipeline", original);
    waitKey(0);

    //Compute object angles using moments 
    for (int i = 0; i < hulls.size(); i++) {
        Moments m = moments(hulls[i], true);
        double area = m.m00;
        double centerX = m.m10 / area;
        double centerY = m.m01 / area;
        double mup20 = m.mu20 / area;
        double mup02 = m.mu02 / area;
        double mup11 = m.mu11 / area;

        double y = 2 * mup11;
        double x = mup20 - mup02;
        double theta = 0.5 * atan2(y, x);
        theta *= 180 / 3.141592; //convert 

        // Draw the centroid and write the angle of the object
        putText(original, to_string(theta), Point(centerX + 5, centerY), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 255), 2, LINE_AA);
        circle(original, Point(centerX, centerY), 4, Scalar(255, 255, 0), -1);
    }
    imshow("Pipeline", original);
    waitKey(0);

}

#endif