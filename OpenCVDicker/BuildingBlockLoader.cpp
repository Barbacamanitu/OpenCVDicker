#include "stdafx.h"
#include "BuildingBlockLoader.h"
#include <Windows.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
BuildingBlockLoader::BuildingBlockLoader()
{
}


BuildingBlockLoader::~BuildingBlockLoader()
{
}

std::vector<BuildingBlock> BuildingBlockLoader::loadBlocks(std::vector<std::string> filenames)
{
	std::vector<BuildingBlock> blocks;
	blocks.reserve(filenames.size());
	cv::Mat tempIcon(cv::Size(20, 20),CV_8UC4);

	for each (auto filename in filenames)
	{
		BuildingBlock bb;
		cv::Mat loaded = cv::imread(filename,-1);
		cv::resize(loaded, tempIcon, cv::Size(20, 20), 0, 0, cv::InterpolationFlags::INTER_LINEAR);
		tempIcon.copyTo(bb.mat);
		cv::Mat mask(loaded.size(), CV_8UC4);
		cv::Mat mask2(loaded.size(), CV_8UC4);
		cv::inRange(loaded, cv::Scalar(1, 1, 1), cv::Scalar(255, 255, 255), mask);
		cv::bitwise_not(mask, mask2);
		bb.average = cv::mean(loaded,mask2);
		blocks.push_back(bb);
	}
	return blocks;
}

std::vector<BuildingBlock> BuildingBlockLoader::loadIcons()
{
	std::vector<std::string> filenames;
	std::string root = "K:\\icons\\png\\";

	filenames.push_back(root + "android.png");
	filenames.push_back(root + "behance.png");
	filenames.push_back(root + "bing.png");
	filenames.push_back(root + "box.png");
	filenames.push_back(root + "creative-market.png");
	filenames.push_back(root + "deviantart.png");
	filenames.push_back(root + "dribbble.png");
	filenames.push_back(root + "dropbox.png");
	filenames.push_back(root + "envato.png");
	filenames.push_back(root + "etsy.png");
	filenames.push_back(root + "facebook.png");
	filenames.push_back(root + "flickr.png");
	filenames.push_back(root + "foursquare.png");
	filenames.push_back(root + "google-plus.png");
	filenames.push_back(root + "howcast.png");
	filenames.push_back(root + "html-5.png");
	filenames.push_back(root + "kickstarter.png");
	filenames.push_back(root + "linkedin.png");
	filenames.push_back(root + "medium.png");
	filenames.push_back(root + "path.png");
	filenames.push_back(root + "paypal.png");
	filenames.push_back(root + "periscope.png");
	filenames.push_back(root + "pinterest.png");
	filenames.push_back(root + "plaxo.png");
	filenames.push_back(root + "quora.png");
	filenames.push_back(root + "scribd.png");
	filenames.push_back(root + "shutterstock.png");
	filenames.push_back(root + "skype.png");
	filenames.push_back(root + "spotify.png");
	filenames.push_back(root + "stumbleupon.png");
	filenames.push_back(root + "trello.png");
	filenames.push_back(root + "tumblr.png");
	filenames.push_back(root + "twitter.png");
	filenames.push_back(root + "vimeo.png");
	filenames.push_back(root + "vine.png");
	filenames.push_back(root + "whatsapp.png");
	filenames.push_back(root + "wordpress.png");
	filenames.push_back(root + "yelp.png");
	filenames.push_back(root + "youtube.png");


	return loadBlocks(filenames);
}
