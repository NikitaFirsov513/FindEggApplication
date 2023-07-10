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
	float minValue, maxValue;
	bool listhen;
	bool interruptEnabled;
	bool groupInterruptEnabled;

	Sensors(int id, float minValue, float maxValue);
	void reset(float minValue);
	void startListhen(float value, int idGroup, float maxValue);
	void startListhen(float value, int idGroup, bool intEna);
	void startListhen(float value, bool intEna);
	void startListhen(float value, bool intEna, bool gIntEna);

	void stopListhen(float value);
	void setMinValue(float value);
	void toggleInterruptEnabled();


};

