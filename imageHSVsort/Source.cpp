/*
* This program is used to test sorting functions on images
* Author: Richard Purcell May 01 2020.
*/

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int width, height;
Mat image, imageHSV, hue, sat, val, outHue, outVal, outSat;

int insertionSort();
int convertTo1D();

int main( int argc, char** argv) {

	if (argc != 2)
	{
		cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	image = imread(argv[1], IMREAD_COLOR);
	
	if (image.empty())
	{
		cout << "Could not open or find the image." << endl;
		return -1;
	}

	int width = image.cols;
	int height = image.rows;
	cvtColor(image, imageHSV, COLOR_BGR2HSV);
	vector<Mat> hsvChannels;
	split(imageHSV, hsvChannels);
	//create 1d Mat's of hue, sat and val.
	hue = hsvChannels[0].reshape(1, 1);
	sat = hsvChannels[1].reshape(1, 1);
	val = hsvChannels[2].reshape(1, 1);

	insertionSort();

	Mat out(image.rows, image.cols, CV_8UC3);


	outHue = hue.reshape(0, image.rows);
	outSat = sat.reshape(0, image.rows);
	outVal = val.reshape(0, image.rows);

	Mat in[] = { outHue, outSat, outVal };
	int from_to[] = { 0,0,1,1,2,2, };
	mixChannels(in, 3, &out, 1, from_to, 3);

	cvtColor(out, out, COLOR_HSV2BGR);

	imshow("out", out);
	imshow("Image", image);
	int k = waitKey(0);

	return 0;
}


int insertionSort() {
	uchar keyHue, keySat, keyVal;

	int  i, j;
	for (i = 1; i < hue.cols; i++) {
		keyHue = hue.at<uchar>(i);
		keySat = sat.at<uchar>(i);
		keyVal = val.at<uchar>(i);
		j = i - 1;
		while (j > 0 && hue.at<uchar>(j) > keyHue) {
			hue.at<uchar>(j + 1) = hue.at<uchar>(j);
			sat.at<uchar>(j + 1) = sat.at<uchar>(j);
			val.at<uchar>(j + 1) = val.at<uchar>(j);
			j = j - 1;
		}
		hue.at<uchar>(j + 1) = keyHue;
		sat.at<uchar>(j + 1) = keySat;
		val.at<uchar>(j + 1) = keyVal;
	}
	return 0;
}