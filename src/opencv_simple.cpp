#include "ros/ros.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main (int argc, char** argv)
{
//  ros::init (argc, argv, "opencv_simple");
//  ros::NodeHandle nh;

	cvNamedWindow("camera", CV_WINDOW_AUTOSIZE);
  CvCapture* capture = cvCaptureFromCAM(0);

	int key = 0;

//  while (nh.ok() && key != 27 && cvGrabFrame(capture)) {
  while (key != 27 && cvGrabFrame(capture)) {
		IplImage* img = cvRetrieveFrame(capture);

		cv::Mat mat = cv::cvarrToMat(img);
		cvCircle(img, cvPoint(320, 240), 80, CV_RGB(255,0,0), 5);
		for(int i = 300; i < 340; i++)
				for(int j = 200; j < 220; j++)
					mat.at<cv::Vec3b>(j,i) = cv::Vec3b(0, 255, 0);

		cvShowImage("camera", img);

		key = cvWaitKey(1) & 255;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("camera");

	return 0;
}
