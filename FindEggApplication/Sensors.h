#include <string>
using namespace System::Collections::Generic;

//struct SensorsList
//{
//	int id;
//	float mixValue;
//	bool interruptEnabled;
//};

#pragma once


ref class Sensors
{
public:
	int id;
	int idGroup;
	float minValue;
	bool listhen;
	bool interruptEnabled;
	Sensors(int id, float minValue);
	void reset(float minValue);
	void startListhen(float value, int idGroup);
	void stopListhen(float value);
	void setMinValue(float value);
	void toggleInterruptEnabled();


};

