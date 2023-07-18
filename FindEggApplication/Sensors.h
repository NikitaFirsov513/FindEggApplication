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

	float value;
	float deltaY;

	bool center;
	bool listhen;
	bool isFindTop;

	int idGroup;

	Sensors();
	Sensors(bool center, bool listhen, float value, float deltaY);

	void startListhen(bool center, bool listhen, float value, float deltaY, int idGroup,bool isFindTop);

	void resetSensor(float value);

	void setValue(float value);
	void setDeltaY(float deltaY);

	void setCenter(bool center);
	void setIsFindTop(bool isFindTop);

	void setIdGroup(int idGroup);
};

