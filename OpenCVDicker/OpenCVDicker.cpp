// OpenCVDicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#include <random>
#include <time.h>
#include "../../../Lib/opencv/build/include/opencv2/core/types.hpp"
#include "BuildingBlockLoader.h"
#include "BuildingBlock.hpp"
#include "Overlayer.hpp"





int main(int argc, char** argv)
{
	srand(time(0));

	BuildingBlockLoader bb;
	std::vector<BuildingBlock> icons = bb.loadIcons();


	cv::Mat image = cv::imread("trump.jpg", CV_8UC4);
	//cv::imshow("testsetest", image);
	//cv::waitKey(0);
	cv::Mat1b mask(image.size(), image.type());
	cv::Mat outImage(image.size(), CV_8UC4);
	int iterations = 4000;
	int radius = 10;

	outImage.setTo(cv::mean(image));
	cv::Mat blendImage(outImage.size(), CV_8UC4);

	float alpha = .75;
	for (int i = 0; i < iterations; i++)
	{
		mask.setTo(cv::Scalar(0));
		int x = rand() % (image.size().width - (radius * 2));
		int y = rand() % (image.size().height- (radius * 2));
		cv::Point position(x, y);
		cv::circle(mask, position, radius, cv::Scalar(255), -1);
		cv::Scalar average = cv::mean(image, mask);
		double distance = -1;
		BuildingBlock b;
		for each (auto bb in icons)
		{
			cv::Vec4d d = average - bb.average;
			double dis = cv::norm(d);
			if (dis < distance || distance == -1)
			{
				b = bb;
				distance = dis;
			}
		}

		Overlayer::overlayImage(&outImage, &b.mat, position);
		//cv::imshow("Temp", outImage);
		//cv::waitKey(0);
	}
	cv::imshow("done", outImage);
	cv::waitKey(0);






	return -1;
	                                 
	return 0;
}
