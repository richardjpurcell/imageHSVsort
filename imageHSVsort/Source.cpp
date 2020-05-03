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
Mat image, imageHSV, hue, sat, val, outHue, outVal, outSat, visualizeHue;
vector<int> hueCount(256, 0);

int insertionSort();
void fakeHistorgram();


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

	width = image.cols;
	height = image.rows;
	cvtColor(image, imageHSV, COLOR_BGR2HSV);
	vector<Mat> hsvChannels;
	split(imageHSV, hsvChannels);
	//create 1d Mat's of hue, sat and val.
	hue = hsvChannels[0].reshape(1, 1);
	sat = hsvChannels[1].reshape(1, 1);
	val = hsvChannels[2].reshape(1, 1);

	insertionSort();

	for (int x : hueCount)
		cout << x << " ";

	cout << endl;

	Mat out(image.rows, image.cols, CV_8UC3);


	outHue = hue.reshape(0, image.rows);
	outSat = sat.reshape(0, image.rows);
	outVal = val.reshape(0, image.rows);

	Mat in[] = { outHue, outSat, outVal };
	int from_to[] = { 0,0,1,1,2,2, };
	mixChannels(in, 3, &out, 1, from_to, 3);

	cvtColor(out, out, COLOR_HSV2BGR);

	fakeHistorgram();

	imshow("out", out);
	imshow("Image", image);

	int k = waitKey(0);

	destroyAllWindows();

	return 0;

}


int insertionSort() {
	uchar keyHue, keySat, keyVal;
	int  i, j;
	int total = image.rows * image.cols;
	int divider = total / 30;

	cout << "|*";

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

		hueCount[keyHue] += 1;

		if (i % divider == 0) {
			cout << "*";
		}

	}
	cout << "|" << endl;

	return 0;
}

void fakeHistorgram() {
	//make 2 vectors for each hue value (0-255) and 
	//populate them with the sat or val value for that color
	//then take the mean for that hue.
	//step through a version of the image filling each pixel in color order
	// with using the mean sat and val for that hue

	visualizeHue = Mat::zeros(Size(180 * 4, 255 * 2), CV_8UC3);
	cvtColor(visualizeHue, visualizeHue, COLOR_BGR2HSV);

	for (int i = 0; i < 180; i++) {
		int temp = (hueCount[i]/(float)(width*height)) * 255*20;

		rectangle(visualizeHue, Point(i * 4, 255*2), Point(i * 4 + 4, 255*2 - temp), Scalar(i, 150, 150), -1);
	}
	cvtColor(visualizeHue, visualizeHue, COLOR_HSV2BGR);
	imshow("visualize hue", visualizeHue);
}
