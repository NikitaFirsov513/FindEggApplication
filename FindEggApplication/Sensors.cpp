#include "Sensors.h"

Sensors::Sensors(int id, float minValue, float maxValue)
{
	this->id = id;
	this->minValue = minValue;
	this->maxValue = maxValue;
	this->interruptEnabled = true;
	this->groupInterruptEnabled = true;
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

void Sensors::startListhen(float value, int  idGroup, float maxValue)
{
	this->minValue = value;
	this->idGroup = idGroup;
	this->maxValue = maxValue;
	this->listhen = true;


}

void Sensors::startListhen(float value, int idGroup, bool intEna)
{
	this->minValue = value;
	this->idGroup = idGroup;
	this->listhen = true;
	this->interruptEnabled = intEna;
}

void Sensors::startListhen(float value, bool intEna)
{
	this->minValue = value;
	this->maxValue = value;
	this->listhen = true;
	this->groupInterruptEnabled = true;
	this->interruptEnabled = intEna;
}

void Sensors::startListhen(float value, bool intEna, bool gIntEna)
{
	this->minValue = value;
	this->maxValue = value;
	this->listhen = true;
	this->groupInterruptEnabled = gIntEna;
	this->interruptEnabled = intEna;
}

void Sensors::stopListhen(float value)
{

	this->minValue = value;
	this->maxValue = value;
	this->idGroup = -1;
	this->listhen = false;
	this->interruptEnabled = true;
	this->groupInterruptEnabled = true;

}

void Sensors::setMinValue(float value)
{
	this->minValue = value;
}

void Sensors::toggleInterruptEnabled()
{
	this->interruptEnabled = !this->interruptEnabled;
}



