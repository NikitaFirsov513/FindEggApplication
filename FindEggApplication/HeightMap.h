#include <opencv2/opencv.hpp>

#pragma once
ref class HeightMap
{
public:
	int count, iteration, col;
	float update, width, distanceToConv, noise;
	float** array;
	HeightMap();
	HeightMap(int count, int iteration, int col, float update, float width);
	void someMethod();
	void readFile();
	cv::Mat draw();
private:

};
