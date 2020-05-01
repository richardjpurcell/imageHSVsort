/*
* This program is used to test sorting functions on images
* Author: Richard Purcell May 01 2020.
*/

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv) {

	if (argc != 2)
	{
		cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	Mat image;
	image = imread(argv[1], IMREAD_COLOR);

	if (image.empty())
	{
		cout << "Could not open or find the image." << endl;
		return -1;
	}

	imshow("Image", image);
	int k = waitKey(0);

	return 0;
}