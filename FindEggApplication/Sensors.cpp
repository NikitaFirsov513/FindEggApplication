#include "Sensors.h"

Sensors::Sensors(int id, float minValue)
{
	this->id = id;
	this->minValue = minValue;
	this->interruptEnabled = true;
	this->idGroup = -1;
	this->listhen = false;
}

void Sensors::reset(float minValue)
{
	this->minValue = minValue;
	this->interruptEnabled = true;
	this->listhen = false;
	this->idGroup = -1;
}

void Sensors::startListhen(float value, int  idGroup)
{
	this->minValue = value;
	this->idGroup = idGroup;
	this->listhen = true;
	

}

void Sensors::startListhen(float value, int idGroup, bool intEna)
{
	this->minValue = value;
	this->idGroup = idGroup;
	this->listhen = true;
	this->interruptEnabled = intEna;
}

void Sensors::stopListhen(float value)
{

	this->minValue = value;
	this->idGroup = -1;
	this->listhen = false;
	this->interruptEnabled = true;

}

void Sensors::setMinValue(float value)
{
	this->minValue = value;
}

void Sensors::toggleInterruptEnabled()
{
	this->interruptEnabled = !this->interruptEnabled;
}



