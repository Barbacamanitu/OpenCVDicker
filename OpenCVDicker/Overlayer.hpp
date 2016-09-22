#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
class Overlayer
{
public:
	static void overlayImage(Mat* src, Mat* overlay, const Point& location)
	{
		for (int y = max(location.y, 0); y < src->rows; ++y)
		{
			int fY = y - location.y;

			if (fY >= overlay->rows)
				break;

			for (int x = max(location.x, 0); x < src->cols; ++x)
			{
				int fX = x - location.x;

				if (fX >= overlay->cols)
					break;

				double opacity = ((double)overlay->data[fY * overlay->step + fX * overlay->channels() + 3]) / 255;
				opacity *= .7;

				for (int c = 0; opacity > 0 && c < src->channels(); ++c)
				{
					unsigned char overlayPx = overlay->data[fY * overlay->step + fX * overlay->channels() + c];
					unsigned char srcPx = src->data[y * src->step + x * src->channels() + c];
					src->data[y * src->step + src->channels() * x + c] = srcPx * (1. - opacity) + overlayPx * opacity;
				}
			}
		}
	}
};