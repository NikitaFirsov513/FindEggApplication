#include "Sensors.h"

Sensors::Sensors()
{


}

Sensors::Sensors(bool center, bool listhen, float value, float deltaY)
{
	this->center = center;
	this->listhen = listhen;
	this->value = value;
	this->isFindTop = false;
	this->deltaY = deltaY;
	this->idGroup = -1;
}

void Sensors::startListhen(bool center, bool listhen, float value, float deltaY, int idGroup, bool isFindTop)
{
	this->center = center;
	this->listhen = listhen;
	this->value = value;
	this->isFindTop = isFindTop;
	this->deltaY = deltaY;

	this->idGroup = idGroup;
}

void Sensors::resetSensor(float value)
{
	this->center = false;
	this->listhen = false;
	this->isFindTop = false;
	this->value = value;
	this->deltaY = 0;
	this->idGroup = -1;
}

void Sensors::setValue(float value)
{
	this->value = value;
}

void Sensors::setDeltaY(float deltaY)
{
	this->deltaY = deltaY;
}

void Sensors::setCenter(bool center)
{

	this->center = center;

}

void Sensors::setIsFindTop(bool isFindTop)
{
	this->isFindTop = isFindTop;
}

void Sensors::setIdGroup(int idGroup)
{
	this->idGroup = idGroup;
}
