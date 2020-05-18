/*
* Purpose: This program is used to test sorting functions on images
* Author:  Richard Purcell May 01 2020.
* Version: May 18, 2020.
* Notes:   This follows the template inclusion model shown in
*          https://docs.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates?view=vs-2019
*/
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv) {

    string filename;
    Mat img, imgGray;
    vector<uchar>imgVec; //vector to hold 1d array

    if (argc != 2) {
        cout << "usage:imageHSVsort.exe path_to_image" << endl;
        cout << "ie:imageHSVsort.exe kodim04_patch.png" << endl << endl;
        
        filename = "./kodim01.png";
    }
    else {
        filename = argv[1];
    }

    img = imread(filename);

    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    //copy image to vector
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            imgVec.push_back(imgGray.at<uchar>(i, j));
        }
    }

    //sort by value
    merge_sort(imgVec, 0, img.rows*img.cols);

    //new image from vector with original dimensions
    Mat imgSorted = Mat(imgVec).reshape(0,img.rows);

    imshow("original image", img);
    imshow("sorted image", imgSorted);
    waitKey(0);

    return 0;

}

