#include "HeightMap.h"
#include <iostream>
#include <fstream> // подключаем библиотеку
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>



using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Collections::Generic;

struct InData
{
	int count;
	int iteration;
	int col;
	float update;
	float width;
	float distanceToConv;
	float noise;
};


void HeightMap::setEntryThreshold(float val)
{
	this->entryThreshold = val;
}

void HeightMap::setLoweringThreshold(float val)
{
	this->loweringThreshold = val;
}

HeightMap::HeightMap()
{
	this->vector = gcnew List<List<float>^>();
	this->sensors = gcnew List<Sensors^>();
	this->drawVector = gcnew List<List<float>^>();


}

HeightMap::HeightMap(int count, int iteration, int col, float update, float width)
{
	this->count = count;
	this->iteration = iteration;
	this->col = col;
	this->update = update;
	this->width = width;
	this->vector = gcnew List<List<float>^>();

}

void HeightMap::someMethod()
{

}
//Чтение файла и запись в массив
void HeightMap::readFile()
{
	String^ LastFileDirectory = "C:\\Users\\NIKITA-PC\\Desktop\\data";
	String^ Filename;

	/*if (!Directory::Exists(LastFileDirectory))
		LastFileDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);*/

		//----- FILE OPEN DIALOG BOX -----
	OpenFileDialog^ SelectFileDialog = gcnew OpenFileDialog();

	SelectFileDialog->Filter = "Binary files (*.bin)|*.bin";		//"txt files (*.txt)|*.txt|All files (*.*)|*.*"
	SelectFileDialog->FilterIndex = 1;				//(First entry is 1, not 0)
	try
	{
		SelectFileDialog->InitialDirectory = LastFileDirectory;
	}
	catch (Exception^)
	{
		SelectFileDialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);
	}
	//Display dialog box
	if (SelectFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//----- OPEN THE FILE -----
		Filename = SelectFileDialog->FileName;



		string path = msclr::interop::marshal_as<std::string>(Filename);
		ifstream fin(path, ios_base::binary);

		InData inData;

		fin.read(reinterpret_cast<char*>(&inData), sizeof(InData));


		this->count = inData.count;
		this->iteration = inData.iteration;
		this->initIter = inData.iteration;
		this->col = inData.col;
		this->update = inData.update;
		this->width = inData.width;
		this->distanceToConv = inData.distanceToConv;
		this->noise = inData.noise;
		/*fin.read((char*)&count, sizeof(int));
		fin.read((char*)&iteration, sizeof(int));
		fin.read((char*)&col, sizeof(int));
		fin.read((char*)&update, sizeof(float));
		fin.read((char*)&width, sizeof(float));
		fin.read((char*)&distanceToConv, sizeof(float));
		fin.read((char*)&noise, sizeof(float));

		this->count = count;
		this->iteration = iteration;
		this->initIter = iteration;
		this->col = col;
		this->update = update;
		this->width = width;
		this->distanceToConv = distanceToConv;
		this->noise = noise;*/
		//this->entryThreshold = 0.065;

		for (int i = 0; i < this->count; i++) {
			this->vector->Add(gcnew List<float>());
			this->drawVector->Add(gcnew List<float>());
			this->sensors->Add(gcnew Sensors(i, this->entryThreshold));
		}

		for (int j = 0; j < this->iteration - 1; j++) {
			for (int i = 0; i < count; i++) {
				float data;
				fin.read((char*)&data, sizeof(float));
				vector[i]->Add(data);
				drawVector[i]->Add(data);

			}
		}



		//-----------------------------------------
		//Биквадратный фильтр
		//for (int j = 0; j < iteration - 2; j++) {
		//	List<float>^ vector = gcnew List<float>();
		//	// Коэффициенты фильтра
		//	const double b0 = 1.0;
		//	const double b1 = -1.143;
		//	const double b2 = 0.4128;
		//	const double a1 = -1.142;
		//	const double a2 = 0.4123;
		//	
		//	
		//	// Инициализация предыдущих входных и выходных значений
		//	double x1 = 0.0, x2 = 0.0;
		//	double y1 = 0.0, y2 = 0.0;
		//	for (int i = 0; i < count - 1; i++) {
		//		float inputVal = this->vector[i][j];
		//		double outputVal = b0 * inputVal + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
		//		x2 = x1;
		//		x1 = inputVal;
		//		y2 = y1;
		//		y1 = outputVal;
		//		this->vector[i][j] = outputVal;
		//		//vector->Add(this->vector[i][j]);
		//	}
		//}
		//-----------------------------------------



		//скользь

		for (int j = 0; j < iteration - 2; j++) {
			for (int i = 0; i < count - 2; i++) {
				float val = this->vector[i][j];

				if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0 && val < entryThreshold)
				{

					float valLeft = this->vector[i - 1][j];
					float valRight = this->vector[i + 1][j];

					float valTop = this->vector[i][j + 1];
					float valBot = this->vector[i][j - 1];


					float valTopLeft = this->vector[i - 1][j + 1];
					float valTopRight = this->vector[i + 1][j + 1];


					float valBotLeft = this->vector[i - 1][j - 1];
					float valBotRight = this->vector[i + 1][j - 1];

					float power = (val * 4 + valLeft * 2 + valRight * 2 + valTop * 2 + valBot * 2 + valTopLeft + valTopRight + valBotLeft + valBotRight) / 16;

					this->vector[i][j] = power;
					this->drawVector[i][j] = power;

				}
			}
		}



		//for (int j = 2; j < iteration - 3; j++) {
		//	for (int i = 2; i < count - 2; i++) {
		//		float val = this->vector[i][j];

		//		if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0 && val < entryThreshold)
		//		{

		//			float valLeft = this->vector[i - 1][j];
		//			float valLeftLeft = this->vector[i - 2][j];

		//			float valRight = this->vector[i + 1][j];
		//			float valRightRight = this->vector[i + 2][j];

		//			float valTop = this->vector[i][j + 1];
		//			float valTopTop = this->vector[i][j + 2];

		//			float valBot = this->vector[i][j - 1];
		//			float valBotBot = this->vector[i][j - 2];


		//			float valTopLeft = this->vector[i - 1][j + 1];
		//			float valTopRight = this->vector[i + 1][j + 1];


		//			float valBotLeft = this->vector[i - 1][j - 1];
		//			float valBotRight = this->vector[i + 1][j - 1];

		//			//float power = (val * 4 + valLeft * 2 + valRight * 2 + valTop * 2 + valBot * 2 + valTopLeft + valTopRight + valBotLeft + valBotRight) / 16;
		//			float power = (val + valLeft + valLeftLeft + valRight + valRightRight + valTop + valTopTop + valBot + valBotBot + valTopLeft + valTopRight + valBotLeft + valBotRight) / 13;
		//			this->vector[i][j] = power;
		//			this->drawVector[i][j] = power;

		//		}
		//	}
		//}

		/*for (int j = 0; j < iteration - 2; j++) {
			for (int i = 0; i < count - 2; i++) {
				float val = this->vector[i][j];

				if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0 && val < entryThreshold)
				{

					float valLeft = this->vector[i - 1][j];
					float valRight = this->vector[i + 1][j];

					float valTop = this->vector[i][j + 1];
					float valBot = this->vector[i][j - 1];


					float valTopLeft = this->vector[i - 1][j + 1];
					float valTopRight = this->vector[i + 1][j + 1];


					float valBotLeft = this->vector[i - 1][j - 1];
					float valBotRight = this->vector[i + 1][j - 1];

					float power = (val * 4 + valLeft * 2 + valRight * 2 + valTop * 2 + valBot * 2 + valTopLeft + valTopRight + valBotLeft + valBotRight) / 16;

					this->vector[i][j] = power;
					this->drawVector[i][j] = power;

				}
			}
		}*/



		for (int j = 0; j < this->iteration - 1; j++) {
			for (int i = 0; i < this->count; i++) {

				this->checkSensor(i, j);

			}
		}
		fin.close();
		if (Filename->LastIndexOf("\\") >= 0)
			LastFileDirectory = Filename->Substring(0, (Filename->LastIndexOf("\\") + 1));

	}
}

cv::Mat HeightMap::draw()
{

	cv::Mat image(iteration, count, CV_8UC3, cv::Scalar(0, 0, 0));


	for (int j = iteration - 2; j >= 0; j--) {


		for (int i = count - 2; i >= 0; i--) {


			float value = this->drawVector[i][j];


			if (value == -1) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)0, (int)0, (int)255);
				continue;
			}
			if (value == -2) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)255, (int)0, (int)255);
				continue;
			}
			if (value == -3) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)255, (int)255, (int)0);
				continue;
			}
			if (value == -4) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)0, (int)255, (int)0);
				continue;
			}
			if (value == -5) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)0, (int)255, (int)255);
				continue;
			}
			if (value == -6) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)128, (int)0, (int)0);
				continue;
			}
			if (value == -7) {
				image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)218, (int)165, (int)32);
				continue;
			}
			//if (value > 0.095f)
			if (value > entryThreshold)
				value = 0;
			else
				value = (distanceToConv + noise - value) * 20 * 255;
			//value = 255;

			if (value > 255)
				value = 255;

			image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)value, (int)value, (int)value);

		}
	}

	return image;
}
cv::Mat HeightMap::drawOrig()
{

	cv::Mat image(iteration, count, CV_8UC3, cv::Scalar(0, 0, 0));


	for (int j = iteration - 2; j >= 0; j--) {


		for (int i = count - 2; i >= 0; i--) {


			float value = this->vector[i][j];



			//if (value > entryThreshold)
			if (value > 0.095f)
				value = 0;
			else
				value = (distanceToConv + noise - value) * 20 * 255;
			//value = 255;

			if (value > 255)
				value = 255;

			image.at<cv::Vec3b>(iteration - 1 - j, count - 1 - i) = cv::Vec3b((int)value, (int)value, (int)value);

		}
	}

	return image;
}

void HeightMap::addToVector()
{

	if (this->initIter >= this->iteration)
		this->initIter = 0;

	for (int i = 0; i < count; i++) {
		vector[i]->Add(this->vector[i][initIter]);
	}
	this->iteration++;
	this->initIter++;
}

void HeightMap::checkSensor(int sensorId, int iter)
{
	//работа с датчиком
	if (iter < 3 || iter == vector[sensorId]->Count - 2 || sensorId == 0 || sensorId == this->count - 1)
		return;



	float value = this->vector[sensorId][iter];
	float prevValue = this->vector[sensorId - 1][iter];
	float nextValue = this->vector[sensorId + 1][iter];

	int coc = this->findCol;
	Sensors^ prevSensor = sensors[sensorId - 1];
	Sensors^ nowSensor = sensors[sensorId];
	Sensors^ nextSensor = sensors[sensorId + 1];

	//датчик отслеживается
	if (this->sensors[sensorId]->listhen) {

		if (nowSensor->interruptEnabled) {
			//прерывания разрешены (пик не найден)
			if (nowSensor->minValue > value) {

				this->drawVector[sensorId][iter] = -4;

				nowSensor->minValue = value;
			}
			else {
				if (value - nowSensor->minValue > 0.005) {



					this->drawVector[sensorId][iter] = -1;

					this->findCol++;

					int groupId = sensors[sensorId]->idGroup;
					/*if (groupId == -1)
						return;*/
					int i = sensorId;
					while (sensors[i]->idGroup == groupId && sensors[i]->interruptEnabled && sensors[i]->listhen) {
						sensors[i]->toggleInterruptEnabled();
						i--;
					}

					int j = sensorId + 1;
					while (sensors[j]->idGroup == groupId && sensors[j]->interruptEnabled && sensors[j]->listhen) {
						sensors[j]->toggleInterruptEnabled();
						j++;
					}
					return;
				}
				this->drawVector[sensorId][iter] = -7;

			}

		}
		else {
			//прерывания не разрешены (пик найден)
			if (value > this->entryThreshold) {
				nowSensor->stopListhen(this->entryThreshold);
				//checkSensor(sensorId, iter);
				this->drawVector[sensorId][iter] = -6;
				return;

			}
			if (value < this->entryThreshold && this->vector[sensorId][iter - 1] > value &&
				this->vector[sensorId][iter - 1] > this->vector[sensorId][iter - 2] &&
				((prevSensor->idGroup == nowSensor->idGroup && this->vector[sensorId - 1][iter - 1] > prevValue && this->vector[sensorId - 1][iter - 1] > this->vector[sensorId - 1][iter - 2]) ||
					(nextSensor->idGroup == nowSensor->idGroup && this->vector[sensorId + 1][iter - 1] > nextValue && this->vector[sensorId + 1][iter - 1] > this->vector[sensorId + 1][iter - 2]) ||
					(prevSensor->idGroup != nowSensor->idGroup && nextSensor->idGroup != nowSensor->idGroup) ||
					(prevValue > this->entryThreshold || nextValue > this->entryThreshold) ||
					(this->vector[sensorId - 1][iter - 1] > this->entryThreshold || this->vector[sensorId + 1][iter - 1] > this->entryThreshold))) {
				//nowSensor->stopListhen(this->entryThreshold);
				/*&&
				((prevSensor->idGroup == nowSensor->idGroup &&
					prevValue < this->entryThreshold &&
					this->vector[sensorId - 1][iter - 1] >prevValue &&
					this->vector[sensorId - 1][iter - 1] > this->vector[sensorId - 1][iter - 2]) ||
					(nextSensor->idGroup == nowSensor->idGroup &&
						nextValue < this->entryThreshold &&
						this->vector[sensorId + 1][iter - 1] >nextValue &&
						this->vector[sensorId + 1][iter - 1] > this->vector[sensorId + 1][iter - 2]) ||
					(prevValue > this->entryThreshold && nextValue > this->entryThreshold))
					*/
				this->drawVector[sensorId][iter] = -3;


				int groupId = sensors[sensorId]->idGroup;
				/*if (groupId == -1)
					return;*/
				int i = sensorId;
				while (sensors[i]->idGroup == groupId && sensors[i]->listhen) {
					sensors[i]->stopListhen(this->entryThreshold);
					i--;
				}

				int j = sensorId + 1;
				while (sensors[j]->idGroup == groupId && sensors[j]->listhen) {
					sensors[j]->stopListhen(this->entryThreshold);
					j++;
				}

				//checkSensor(sensorId, iter);

				//checkSensor(sensorId, iter);
				return;

			}
			this->drawVector[sensorId][iter] = -5;


		}

	}
	else
	{//датчик не отслеживается

		 //датчик не отслеживатся и выше порога

			//нужно смотреть соседние датчики
		if (value > this->entryThreshold)
			return;


		bool isPrevSensorListhen = (prevSensor->listhen);
		bool isNextSensorListhen = (nextSensor->listhen);
		//если рядом датчиков нет
		if (!isPrevSensorListhen && !isNextSensorListhen && (prevValue < this->entryThreshold || nextValue < this->entryThreshold)) {
			//
			nowSensor->startListhen(value, -1);

			findGroup(sensorId, iter);
			return;
		}
		//рядом 2 датчика прослушиваются
		if (isPrevSensorListhen && isNextSensorListhen) {

			if (prevValue > nextValue)
			{
				if (nextSensor->interruptEnabled) {
					nowSensor->startListhen(value, nextSensor->idGroup);
				}
				else {
					nowSensor->startListhen(value, prevSensor->idGroup);
				}

			}
			if (prevValue < nextValue)
			{
				if (prevSensor->interruptEnabled) {
					nowSensor->startListhen(value, prevSensor->idGroup);
				}
				else {
					nowSensor->startListhen(value, nextSensor->idGroup);
				}


			}
			return;


		}

		/*if (isPrevSensorListhen && value < prevValue && value < nextValue) {
			this->drawVector[sensorId][iter] = -2;

			this->idSensors++;
			nowSensor->startListhen(value, this->idSensors);
			return;
		}

		if (isNextSensorListhen && value < prevValue && value < nextValue) {
			this->drawVector[sensorId][iter] = -2;

			this->idSensors++;
			nowSensor->startListhen(value, this->idSensors);
			return;
		}*/

		if (isPrevSensorListhen && prevSensor->interruptEnabled)
			nowSensor->startListhen(value, prevSensor->idGroup);

		if (isPrevSensorListhen && !prevSensor->interruptEnabled)
			nowSensor->startListhen(value, prevSensor->idGroup, false);


		if (isNextSensorListhen && nextSensor->interruptEnabled)
			nowSensor->startListhen(value, nextSensor->idGroup);

		if (isNextSensorListhen && !nextSensor->interruptEnabled)
			nowSensor->startListhen(value, nextSensor->idGroup, false);



	}
}

void HeightMap::findGroup(int sensorId, int iter)
{


	float prevValue = this->vector[sensorId - 1][iter];
	float nextValue = this->vector[sensorId + 1][iter];
	float value = this->vector[sensorId][iter];

	Sensors^ prevSensor = sensors[sensorId - 1];
	Sensors^ nowSensor = sensors[sensorId];
	Sensors^ nextSensor = sensors[sensorId + 1];


	if (prevValue > this->entryThreshold && nextValue > this->entryThreshold) {

		//датчик 1н 
		this->drawVector[sensorId][iter] = -2;

		this->idSensors++;
		nowSensor->startListhen(value, this->idSensors);
		return;
	}
	if (prevValue < this->entryThreshold && nextValue < this->entryThreshold) {

		//датчик по центру 
		this->drawVector[sensorId][iter] = -2;

		this->idSensors++;
		nowSensor->startListhen(value, this->idSensors);
		return;
	}
	//слева входит
	if (prevValue < this->entryThreshold && nextValue > this->entryThreshold) {
		int i = sensorId - 1;

		while (sensors[i]->idGroup == -1 && this->vector[i][iter] < this->entryThreshold) {
			i--;
		}
		if (sensors[i]->idGroup != -1 && sensorId - i <= 5 && this->vector[i][iter] < this->entryThreshold)
			nowSensor->startListhen(value, sensors[i]->idGroup, sensors[i]->interruptEnabled);
		else
		{
			this->drawVector[sensorId][iter] = -2;
			this->idSensors++;
			nowSensor->startListhen(value, this->idSensors);
		}
		return;

		//идем до ближайшего активного сенсора
		//если такого нет то новый

	}
	//справа входит
	if (prevValue > this->entryThreshold && nextValue < this->entryThreshold) {

		//идем до ближайшего активного сенсора
		//если такого нет то новый
		int i = sensorId + 1;

		while (sensors[i]->idGroup == -1 && this->vector[i][iter] < this->entryThreshold) {
			i++;
		}
		if (sensors[i]->idGroup != -1 && i - sensorId <= 5 && this->vector[i][iter] < this->entryThreshold)
			nowSensor->startListhen(value, sensors[i]->idGroup, sensors[i]->interruptEnabled);
		else
		{
			this->drawVector[sensorId][iter] = -2;
			this->idSensors++;
			nowSensor->startListhen(value, this->idSensors);
		}
		return;


	}
}









//есть рядом объекты
			//if (((prevSensor->listhen && !prevSensor->interruptEnabled) && (nextSensor->listhen && !nextSensor->interruptEnabled)) ||
			//	((prevSensor->listhen && !prevSensor->interruptEnabled) && !nextSensor->listhen) ||
			//	((nextSensor->listhen && !nextSensor->interruptEnabled) && !prevSensor->listhen)) {
			//	//объектов нет => создаем новую группу и обновляем минимум


			//	if ((!prevSensor->interruptEnabled && nextValue > entryThreshold) ||
			//		(!nextSensor->interruptEnabled && prevValue > entryThreshold)) {
			//		return;
			//	}

			//	this->vector[sensorId][iter] = -2;

			//	this->findCol++;
			//	nowSensor->startListhen(value, this->findCol);
			//	return;
			//}
			//if (!prevSensor->listhen && !nextSensor->listhen) {
			//	//объектов нет => создаем новую группу и обновляем минимум
			//	this->vector[sensorId][iter] = -2;

			//	this->findCol++;
			//	nowSensor->startListhen(value, this->findCol);

			//}//объект есть	
			//else
			//{
			//	if (prevSensor->listhen && nextSensor->listhen) {
			//		//	объект не 1н =>добавляем данный датчик в группу по правилу меньшего значенияи обновляем мин
			//		if (prevValue > nextValue) {
			//			if (nextSensor->interruptEnabled) {
			//				nowSensor->startListhen(value, nextSensor->idGroup);
			//			}
			//			else {
			//				nowSensor->startListhen(value, prevSensor->idGroup);
			//			}
			//		}
			//		if (prevValue < nextValue)
			//		{
			//			if (prevSensor->interruptEnabled) {
			//				nowSensor->startListhen(value, prevSensor->idGroup);
			//			}
			//			else {
			//				nowSensor->startListhen(value, nextSensor->idGroup);
			//			}
			//		}

			//	}
			//	else
			//	{
			//		//	объект 1н => добавляем в группу
			//		if (prevSensor->listhen && prevSensor->interruptEnabled)
			//			nowSensor->startListhen(value, prevSensor->idGroup);
			//		if (nextSensor->listhen && prevSensor->interruptEnabled)
			//			nowSensor->startListhen(value, nextSensor->idGroup);
			//	}
			//}