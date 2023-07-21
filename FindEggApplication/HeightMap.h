#include <opencv2/opencv.hpp>
#include "Sensors.h"
using namespace System::Collections::Generic;

#pragma once
ref class HeightMap
{
public:
	int count = 1, iteration, initIter, col, findCol = 0, idSensors = 0, N = 3, downPerc = 1;
	float update, width, distanceToConv, noise, entryThreshold = 0.07225, loweringThreshold = 0.06855;
	void setEntryThreshold(float val);
	void setLoweringThreshold(float val);
	List<List<float>^>^ vector;
	List<List<float>^>^ drawVector;
	List<Sensors^>^ sensors;
	HeightMap();
	HeightMap(int count, int iteration, int col, float update, float width, float distanceToConv);
	void someMethod();
	void readFile(bool noise);
	cv::Mat draw();
	cv::Mat drawOrig();
	void addToVector();
	void addToVector(List<float>^ newData);
	void updateSensors(int iter);
	void correctSensorGroup(int iter);
	void checkSensors();

	void checkSensor(int sensorId, int iter);
	void findGroup(int sensorId, int iter);
	void movingAverage();
	void medialFilter();
private:
	void initSensors();
	bool isSkip = false;
	int sensorSkip;
};
