#include "HeightMap.h"
#include <iostream>
#include <fstream> // подключаем библиотеку
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <random>


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

HeightMap::HeightMap(int count, int iteration, int col, float update, float width, float distanceToConv)
{

	this->vector = gcnew List<List<float>^>();
	this->sensors = gcnew List<Sensors^>();
	this->drawVector = gcnew List<List<float>^>();

	this->count = count;
	this->iteration = iteration;
	this->col = col;
	this->update = update;
	this->width = width;
	this->distanceToConv = distanceToConv;

	this->initSensors();

}

void HeightMap::someMethod()
{

}
//Чтение файла и запись в массив
void HeightMap::readFile(bool noise)
{
	String^ LastFileDirectory = "C:\\Users\\NIKITA-PC\\Desktop\\data";
	String^ Filename;

	random_device rd; // используется для инициализации генератора случайных чисел
	mt19937 gen(rd()); // генератор случайных чисел
	uniform_real_distribution<float> dis(-0.0000025f, 0.0000025f); // распределение

	//uniform_real_distribution<float> dis(-0.0025f, 0.0025f); // распределение

	// Генерация случайного числа
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

			this->sensors->Add(gcnew Sensors(false, false, this->entryThreshold, 0));
		}

		for (int j = 0; j < this->iteration - 1; j++) {
			for (int i = 0; i < count; i++) {
				float data;
				fin.read((char*)&data, sizeof(float));
				float randomNumber = 0;

				if (noise)
					randomNumber = dis(gen);


				vector[i]->Add(data + randomNumber);
				drawVector[i]->Add(data + randomNumber);


			}
		}


		this->movingAverage();
		//this->medialFilter();



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



		////5*5
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



		//5*5 20
		/*for (int j = 2; j < iteration - 3; j++) {
			for (int i = 2; i < count - 2; i++) {
				float val = this->vector[i][j];

				if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0 && val < entryThreshold)
				{

					float valLeft = this->vector[i - 1][j];
					float valLeftLeft = this->vector[i - 2][j];

					float valRight = this->vector[i + 1][j];
					float valRightRight = this->vector[i + 2][j];

					float valTop = this->vector[i][j + 1];
					float valTopTop = this->vector[i][j + 2];

					float valBot = this->vector[i][j - 1];
					float valBotBot = this->vector[i][j - 2];


					float valTopLeft = this->vector[i - 1][j + 1];
					float valTopRight = this->vector[i + 1][j + 1];


					float valBotLeft = this->vector[i - 1][j - 1];
					float valBotRight = this->vector[i + 1][j - 1];

					float power = (val*4 + valLeft*2 + valLeftLeft + valRight*2 + valRightRight + valTop*2 + valTopTop + valBot*2 + valBotBot + valTopLeft + valTopRight + valBotLeft + valBotRight) / 20;
					this->vector[i][j] = power;
					this->drawVector[i][j] = power;

				}
			}
		}*/



		//5*5 28

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
		//			float power = (val * 4 + valLeft * 3 + valLeftLeft + valRight * 3 + valRightRight + valTop * 3 + valTopTop + valBot * 3 + valBotBot + valTopLeft * 2 + valTopRight * 2 + valBotLeft * 2 + valBotRight * 2) / 28;
		//			this->vector[i][j] = power;
		//			this->drawVector[i][j] = power;

		//		}
		//	}
		//}


		//3*3
		//for (int j = 0; j < iteration - 2; j++) {
		//	for (int i = 0; i < count - 2; i++) {
		//		float val = this->vector[i][j];

		//		if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0/* && val < entryThreshold*/)
		//		{

		//			float valLeft = this->vector[i - 1][j];
		//			float valRight = this->vector[i + 1][j];

		//			float valTop = this->vector[i][j + 1];
		//			float valBot = this->vector[i][j - 1];


		//			float valTopLeft = this->vector[i - 1][j + 1];
		//			float valTopRight = this->vector[i + 1][j + 1];


		//			float valBotLeft = this->vector[i - 1][j - 1];
		//			float valBotRight = this->vector[i + 1][j - 1];

		//			float power = (val * 4 + valLeft * 2 + valRight * 2 + valTop * 2 + valBot * 2 + valTopLeft + valTopRight + valBotLeft + valBotRight) / 16;

		//			this->vector[i][j] = power;
		//			this->drawVector[i][j] = power;

		//		}
		//	}
		//}
		////3*3 9
		//for (int j = 0; j < iteration - 2; j++) {
		//	for (int i = 0; i < count - 2; i++) {
		//		float val = this->vector[i][j];

		//		if (j != iteration - 1 && j != 0 && i != count - 1 && i != 0 && val < entryThreshold)
		//		{

		//			float valLeft = this->vector[i - 1][j];
		//			float valRight = this->vector[i + 1][j];

		//			float valTop = this->vector[i][j + 1];
		//			float valBot = this->vector[i][j - 1];


		//			float valTopLeft = this->vector[i - 1][j + 1];
		//			float valTopRight = this->vector[i + 1][j + 1];


		//			float valBotLeft = this->vector[i - 1][j - 1];
		//			float valBotRight = this->vector[i + 1][j - 1];

		//			float power = (val  + valLeft  + valRight  + valTop  + valBot  + valTopLeft + valTopRight + valBotLeft + valBotRight) / 9;

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

			//проверка сенсоров
			// 
			// 
			// 
			//проверка сенсоров\







			//нужно дописать метод checkSensor под новый авлгоритм
			for (int i = 0; i < this->count; i++) {

				this->checkSensor(i, j);

			}
			this->correctSensorGroup(j);
			this->updateSensors(j);

		}

		fin.close();
		if (Filename->LastIndexOf("\\") >= 0)
			LastFileDirectory = Filename->Substring(0, (Filename->LastIndexOf("\\") + 1));

	}
}

cv::Mat HeightMap::draw()
{

	cv::Mat image(iteration, count, CV_8UC3, cv::Scalar(0, 0, 0));


	for (int j = 0; j < iteration - 1; j++) {


		for (int i = 0; i < drawVector->Count - 1; i++) {


			/*for (int j = iteration - 2; j >= 0; j--) {


				for (int i = count - 2; i >= 0; i--) {*/


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


	for (int j = 0; j < iteration - 1; j++) {


		for (int i = 0; i < drawVector->Count - 1; i++) {


			float value = this->vector[i][j];



			if (value > entryThreshold)
				value = 0;
			else
				value = (distanceToConv + 0.005 - value) * 20 * 255;
			//value = 255;

			//if (value > 0.095f)

			if (value > 255)
				value = 255;
			if (value < 0)
				value = 0;

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

void HeightMap::addToVector(List<float>^ newData)
{
	for (int i = 0; i < count; i++) {
		this->vector[i]->Add(newData[i]);
		this->drawVector[i]->Add(newData[i]);

	}
	this->iteration++;

}

void HeightMap::updateSensors(int iter)
{
	//проверка сенсоров (смежение+окраска/выключение)




	for (int i = 1; i <= sensors->Count - 2; i++) {

		//поиск группы
		//-если слишким длинная, то принимаем решение о разделении(экстремумы)
		//-если нет центра, то принемаем решение о установке этого центра.
		//-если размер подходит и центр есть, то принимаем решение о его смещении

		Sensors^ nowSensor = sensors[i];

		int startSensor = i;
		int endSensor = i;

		bool isCenterFind = false;
		int idCenter;
		int findGroup = nowSensor->idGroup;

		//поиск группы
		if (nowSensor->idGroup != -1) {

			while (this->sensors[endSensor]->idGroup == findGroup) {
				if (this->sensors[endSensor]->center) {
					isCenterFind = true;
					idCenter = endSensor;
				}
				endSensor++;
			}

		}
		//если длинна = 0 
		if (endSensor - startSensor == 0) continue;


		//-если слишким длинная, то принимаем решение о разделении(экстремумы)

		if (endSensor - startSensor >= 3 * N && isCenterFind) {
			//далее нужно разделить большую группу на несколько поменьше и установить у них центры
			//отложено на потом



			//проходимся по всему списку и ищем ++--
			//если нашли именно в такой последовательности, то создаем новую группу 




			for (int i = startSensor; i < endSensor - 4; i++) {

				//перебор массива 	
				float deltaValueOne = sensors[i + 1]->deltaY;
				float deltaValueTwo = sensors[i + 2]->deltaY;
				float deltaValueThree = sensors[i + 3]->deltaY;
				float deltaValueFour = sensors[i + 4]->deltaY;


				//если нашел перепад в ++--, то отделяем в нвовую группу.
				//деление происходит по принципу где находится центер, там группа сохраняется
				if (deltaValueOne > 0 && deltaValueTwo > 0 && deltaValueThree < 0 && deltaValueFour < 0) {

					int borderOne = i + 1;
					int startTwo = borderOne + 1;
					int borderTwo = endSensor;

					//сохраняем слева и добавляем в группу справа
					if (idCenter < borderOne) {


						float val = this->vector[startTwo][iter];
						float deltaStart = sensors[startTwo]->deltaY;

						idSensors++;

						sensors[startTwo]->startListhen(false, true, val, deltaStart, idSensors, false);

						this->drawVector[startTwo][iter] = -2;

						for (int j = startTwo + 1; j < borderTwo; j++) {

							float value = this->vector[j][iter];
							float delta = sensors[j]->deltaY;


							sensors[j]->startListhen(false, true, value, delta, idSensors, false);
							this->drawVector[j][iter] = -1;

						}

						i += borderOne - startSensor;
						continue;



					}
					//сохраняем справа и добавляем в группу слева
					else {

						float val = this->vector[startSensor][iter];
						float deltaStart = sensors[startSensor]->deltaY;

						idSensors++;

						sensors[startSensor]->startListhen(false, true, val, deltaStart, idSensors, false);
						this->drawVector[startSensor][iter] = -2;

						for (int j = startSensor; j <= borderOne; j++) {

							float value = this->vector[j][iter];
							float delta = sensors[j]->deltaY;


							sensors[j]->startListhen(false, true, value, delta, idSensors, false);
							this->drawVector[j][iter] = -1;

						}

						//i -= 1;

						i += borderOne - startSensor;

						continue;

					}



				}


				//this->drawVector[idCenter][iter] = -6;

			}

			//-если нет центра, то принемаем решение о установке этого центра.
			if (!isCenterFind && !nowSensor->isFindTop) {
				//устанавливаем центр
				//точка 1на
				if (endSensor - startSensor == 1) {
					nowSensor->setCenter(true);

					//this->drawVector[i][iter] = -6;
				}
				//точек > 1
				else {


					////ВРЕМЕННО
					//nowSensor->setCenter(true);

					//this->drawVector[i][iter] = -6;
					//*ВРЕМЕННО

					float minVal = this->vector[startSensor - 1][iter] + this->vector[startSensor + 1][iter] + this->vector[startSensor][iter];
					int minIndex = startSensor;

					for (int a = startSensor; a <= endSensor; a++) {

						float val = this->vector[a - 1][iter] + this->vector[a + 1][iter] + this->vector[a][iter];
						if (minVal > val) {



							minVal = val;
							minIndex = a;
						}


					}
					this->sensors[minIndex]->setCenter(true);

					//this->drawVector[minIndex][iter] = -3;
					//this->drawVector[minIndex - 1][iter] = -3;
					//this->drawVector[minIndex + 1][iter] = -3;


					//реализовать проверкулучшего варианта
					/*for (;;) {

					}*/

				}

				i += endSensor - startSensor;
				continue;
			}

			//-если размер подходит и центр есть, то принимаем решение о его смещении
			if (isCenterFind) {


				if (nowSensor->isFindTop) {
					//this->drawVector[idCenter][iter] = -5;

					i += endSensor - startSensor;
					continue;
				}

				float prevData = sensors[idCenter - 1]->value + sensors[idCenter]->value + sensors[idCenter + 1]->value;


				float minVal = this->vector[startSensor - 1][iter] + this->vector[startSensor + 1][iter] + this->vector[startSensor][iter];
				int minIndex = startSensor;

				for (int a = startSensor; a <= endSensor; a++) {

					float val = this->vector[a - 1][iter] + this->vector[a + 1][iter] + this->vector[a][iter];
					if (minVal > val) {



						minVal = val;
						minIndex = a;
					}


				}

				if (minVal < prevData) {


					//нужно добавить условие на проверку  процентов


					/*if (prevData - minVal > (minVal / 100) * 10)*/ {


						//отрубить центр для прошлых
						this->sensors[idCenter]->setCenter(false);


						this->sensors[minIndex - 1]->setValue(this->vector[minIndex - 1][iter]);

						this->sensors[minIndex]->setValue(this->vector[minIndex][iter]);
						this->sensors[minIndex]->setCenter(true);

						this->sensors[minIndex + 1]->setValue(this->vector[minIndex + 1][iter]);

						this->drawVector[minIndex][iter] = -3;
						this->drawVector[minIndex - 1][iter] = -3;

						this->drawVector[minIndex + 1][iter] = -3;

					}
				}
				else {
					//изменить. нужно так делать для всей группы
					/*sensors[idCenter - 1]->setIsFindTop(true);
					sensors[idCenter]->setIsFindTop(true);
					sensors[idCenter + 1]->setIsFindTop(true);*/



					if (minVal - prevData > (minVal / 100) * downPerc) {
						this->findCol++;

						int a = idCenter;
						while (this->sensors[a]->idGroup == nowSensor->idGroup) {

							this->sensors[a]->setIsFindTop(true);
							a--;

						}
						a = idCenter + 1;
						while (this->sensors[a]->idGroup == nowSensor->idGroup) {
							this->sensors[a]->setIsFindTop(true);
							a++;
						}
						this->drawVector[idCenter][iter] = -4;
					}


				}


				i += endSensor - startSensor;
				continue;


			}





		}



		//-если нет центра, то принемаем решение о установке этого центра.
		if (!isCenterFind && !nowSensor->isFindTop) {
			//устанавливаем центр
			//точка 1на
			if (endSensor - startSensor == 1) {
				nowSensor->setCenter(true);

				//this->drawVector[i][iter] = -6;
			}
			//точек > 1
			else {


				////ВРЕМЕННО
				//nowSensor->setCenter(true);

				//this->drawVector[i][iter] = -6;
				//*ВРЕМЕННО

				float minVal = this->vector[startSensor - 1][iter] + this->vector[startSensor + 1][iter] + this->vector[startSensor][iter];
				int minIndex = startSensor;

				for (int a = startSensor; a <= endSensor; a++) {

					float val = this->vector[a - 1][iter] + this->vector[a + 1][iter] + this->vector[a][iter];
					if (minVal > val) {



						minVal = val;
						minIndex = a;
					}


				}
				this->sensors[minIndex]->setCenter(true);

				/*this->drawVector[minIndex][iter] = -3;
				this->drawVector[minIndex - 1][iter] = -3;
				this->drawVector[minIndex + 1][iter] = -3;*/


				//реализовать проверкулучшего варианта
				/*for (;;) {

				}*/

			}

			i += endSensor - startSensor;
			continue;
		}

		//-если размер подходит и центр есть, то принимаем решение о его смещении
		if (isCenterFind) {


			if (nowSensor->isFindTop) {
				//this->drawVector[idCenter][iter] = -5;

				i += endSensor - startSensor;
				continue;
			}

			float prevData = sensors[idCenter - 1]->value + sensors[idCenter]->value + sensors[idCenter + 1]->value;


			float minVal = this->vector[startSensor - 1][iter] + this->vector[startSensor + 1][iter] + this->vector[startSensor][iter];
			int minIndex = startSensor;

			for (int a = startSensor; a <= endSensor; a++) {

				float val = this->vector[a - 1][iter] + this->vector[a + 1][iter] + this->vector[a][iter];
				if (minVal > val) {



					minVal = val;
					minIndex = a;
				}


			}

			if (minVal < prevData) {


				//нужно добавить условие на проверку  процентов


				/*if (prevData - minVal > (minVal / 100) * 10)*/ {


					this->sensors[idCenter]->setCenter(false);

					//отрубить центр для прошлых
					this->sensors[minIndex - 1]->setValue(this->vector[minIndex - 1][iter]);

					this->sensors[minIndex]->setValue(this->vector[minIndex][iter]);
					this->sensors[minIndex]->setCenter(true);

					this->sensors[minIndex + 1]->setValue(this->vector[minIndex + 1][iter]);

					/*this->drawVector[minIndex][iter] = -3;
					this->drawVector[minIndex - 1][iter] = -3;

					this->drawVector[minIndex + 1][iter] = -3;
				*/}
			}


			else {
				//изменить. нужно так делать для всей группы
				/*sensors[idCenter - 1]->setIsFindTop(true);
				sensors[idCenter]->setIsFindTop(true);
				sensors[idCenter + 1]->setIsFindTop(true);*/



				if (minVal - prevData > (minVal / 100) * downPerc) {
					this->findCol++;

					int a = idCenter;
					while (this->sensors[a]->idGroup == nowSensor->idGroup) {

						this->sensors[a]->setIsFindTop(true);
						a--;

					}
					a = idCenter + 1;
					while (this->sensors[a]->idGroup == nowSensor->idGroup) {
						this->sensors[a]->setIsFindTop(true);
						a++;
					}
					this->drawVector[idCenter][iter] = -4;
				}


			}


			i += endSensor - startSensor;
			continue;


		}





	}








}

void HeightMap::correctSensorGroup(int iter)
{

	//проверяем все сенсоры
	//	если нашли группу, то смотрим всю линию и считаем уникальные группы, а также перепады ++--
	//		если (количество сенсоров - 1)!=количеству перепадов
	//		+	если групп-1 > количества перепадов
	//			+	групп слишком много и нужно уменьшать.
	//				такжу нужно выставить новые центры и дать новые id
	//			-	групп слишком мало и нужно увеличивать.
	//				также нужно выставить новые центры и дать новые id
	//			
	// 
	// 
	// 
	// 
	//		-	пропуск линии
	// 
	// 
	// 
	// 
	// 
	// 
	//	!!!!!!!!!!!!!!!!!!!!!!!нужно продумать как сохранять isFindCenter



	for (int i = 1; i <= sensors->Count - 2; i++) {

		if (sensors[i]->idGroup != -1) {

			int startSensor = i;
			int uniqueGroup = 1;
			int findDrop = 0;
			while (sensors[i]->idGroup != -1) {

				//если рядом разные группы, то добавляем uniqueGroup
				if (sensors[i - 1]->idGroup != -1 && sensors[i - 1]->idGroup != sensors[i]->idGroup) {
					uniqueGroup++;
				}




				int indexSensorOne = i;
				int indexSensorTwo = i + 1;
				int indexSensorThree = i + 2;
				int indexSensorFour = i + 3;

				float deltaValueOne = sensors[indexSensorOne]->deltaY;
				float deltaValueTwo = sensors[indexSensorTwo]->deltaY;
				float deltaValueThree = sensors[indexSensorThree]->deltaY;
				float deltaValueFour = sensors[indexSensorFour]->deltaY;

				bool isAllSensorsValid = sensors[indexSensorOne]->idGroup != -1 &&
					sensors[indexSensorTwo]->idGroup != -1 &&
					sensors[indexSensorThree]->idGroup != -1 &&
					sensors[indexSensorFour]->idGroup != -1;

				bool isFindDrop = deltaValueOne > 0 &&
					deltaValueTwo > 0 &&
					deltaValueThree < 0 &&
					deltaValueFour < 0;

				//увиличиваем количество перепадов
				if (isAllSensorsValid && isFindDrop) {
					findDrop++;
				}



				/*
				float deltaValueOne = sensors[i + 1]->deltaY;
				float deltaValueTwo = sensors[i + 2]->deltaY;
				float deltaValueThree = sensors[i + 3]->deltaY;
				float deltaValueFour = sensors[i + 4]->deltaY;*/

				//нужна проверка на перепады. 



				i++;

			}

			int endSensor = i - 1;
			//если перепадов больше чем групп, значит нужно делить и красим в желтый
			if (findDrop > uniqueGroup - 1) {
				for (int n = startSensor; n <= endSensor; n++) {

					this->drawVector[n][iter] = -5;


				}
			}


			//если перепадов меньше чем групп, значит нужно объединять и красим в синий
			if (findDrop < uniqueGroup - 1) {



				//все нужно объеденить в одну группу
				//принимать решение на основе формы
				//  
				//если идет вверх, то isFindTop false
				//если идет вниз, то isFindTop true
				if (findDrop == 0) {



					int sensorsGoTop = 0;
					int sensorsGoBot = 0;



					for (int n = startSensor; n <= endSensor; n++) {


						/*if ((this->vector[n][iter] - this->vector[n][iter - 1] < 0 &&
							this->vector[n][iter - 1] - this->vector[n][iter - 2] < 0 &&
							this->vector[n][iter - 2] - this->vector[n][iter - 3] < 0)
							|| this->vector[n][iter - 1] > entryThreshold
							|| this->vector[n][iter - 2] > entryThreshold
							|| this->vector[n][iter - 3] > entryThreshold)
							sensorsGoTop++;
						else
							sensorsGoBot++;*/

						if (!sensors[n]->isFindTop) {
							sensorsGoTop++;
						}
						else {
							sensorsGoBot++;
						}

						this->drawVector[n][iter] = -7;





					}

					//идет вверх isFindTop false
					if (sensorsGoTop > sensorsGoBot) {
						this->drawVector[startSensor][iter] = -5;
						this->drawVector[endSensor][iter] = -5;

						this->idSensors++;

						for (int n = startSensor; n <= endSensor; n++) {

							sensors[n]->idGroup = idSensors;
							sensors[n]->isFindTop = false;



						}

					}
					else
					{
						//идет вниз isFindTop true
						this->drawVector[startSensor][iter] = -3;
						this->drawVector[endSensor][iter] = -3;
						this->idSensors++;


						for (int n = startSensor; n <= endSensor; n++) {

							sensors[n]->idGroup = idSensors;
							sensors[n]->isFindTop = true;



						}

					}


				}

			}




		}


	}



}

void HeightMap::checkSensors()
{
	if (vector->Count < 3 && iteration < 5)
		return;


	int prevIndex = iteration - 1;

	for (int i = 1; i < vector->Count - 2; i++) {

		this->checkSensor(i, prevIndex);

	}
}

void HeightMap::checkSensor(int sensorId, int iter)
{

	if (sensorId == 0 || sensorId == vector->Count - 1 || iter < 3 || iter == iteration)
		return;

	//1 порог присутствия  = this->entryThreshold;
	//2 порог обнаружения пиков(в патенте равен 10);
	//3 порог объекта(в патенте равен 4);
	/*float peakDetectionThreshold = 0.007;
	float objectThreshold = 0.0035;*/

	//сенсоры
	Sensors^ nowSensor = sensors[sensorId];
	Sensors^ prevSensor = sensors[sensorId - 1];
	Sensors^ nextSensor = sensors[sensorId + 1];

	//соседние значения
	float nowValue = this->vector[sensorId][iter];
	float prevValue = this->vector[sensorId - 1][iter];
	float nextValue = this->vector[sensorId + 1][iter];










	//если значение не добаленно в группу, то делаем операции по добавлению
	if (!nowSensor->listhen && nowValue < entryThreshold && this->vector[sensorId][iter - 1] > entryThreshold) {

		//есть ли рядом включенные датчики датчики?
		//
		//+		датчик 1н?
		//		+ добавляем
		//		- решаем к какому добавить
		// 
		//-		проверяем все датчики дальше в поисках группы/конца яйца
		//		нашло группу?
		//		+ добавляем к группе
		//		- создаем группу

		if (prevSensor->listhen || nextSensor->listhen) {
			//прослушиваются оба
			if (prevSensor->listhen && nextSensor->listhen) {

				if (prevValue < nextValue) {
					nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, prevSensor->idGroup, prevSensor->isFindTop);
				}
				else {
					nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, nextSensor->idGroup, nextSensor->isFindTop);
				}

			}
			//прослушивается прошлый сенсор
			if (prevSensor->listhen && !nextSensor->listhen) {
				nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, prevSensor->idGroup, prevSensor->isFindTop);
			}

			//прослушивается след сенсор
			if (!prevSensor->listhen && nextSensor->listhen) {
				nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, nextSensor->idGroup, nextSensor->isFindTop);
			}

		}
		else {

			//проверяем все датчики дальше в поисках группы / конца яйца
			//if (this->vector[sensorId + 1][iter] < entryThreshold) 
			{

				int findGroup = sensorId + 1;


				while (!sensors[findGroup]->listhen && this->vector[findGroup][iter] < entryThreshold) {
					findGroup++;
				}

				//нашел группу=> добавляем к ней
				if (sensors[findGroup]->idGroup != -1) {

					nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, sensors[findGroup]->idGroup, sensors[findGroup]->isFindTop);

				}
				//не нашел группу => создаем новую
				else {

					idSensors++;
					nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, idSensors, false);


					this->drawVector[sensorId][iter] = -2;
					return;
					//потом нужно будет принять решение по поводу расположения центра
				}
			}

		}

		this->drawVector[sensorId][iter] = -1;
		return;
	}


	//обновление deltaY для каждого датчика
	if (nowSensor->listhen && nowValue < entryThreshold) {

		nowSensor->setDeltaY(nowValue - prevValue);

	}

	//Временно для примера
	if (nowSensor->listhen && nowValue > entryThreshold) {

		nowSensor->resetSensor(this->entryThreshold);
		this->drawVector[sensorId][iter] = -6;


	}



	float deltaPrevIterOne = this->vector[sensorId][iter] - this->vector[sensorId][iter - 1];
	float deltaPrevIterTwo = this->vector[sensorId][iter - 1] - this->vector[sensorId][iter - 2];
	float deltaPrevIterThree = this->vector[sensorId][iter - 2] - this->vector[sensorId][iter - 3];

	if (nowSensor->isFindTop && deltaPrevIterOne < 0 && deltaPrevIterTwo < 0) {

		//int skipGroup = nowSensor->idGroup;

		int prevGroup = nowSensor->idGroup;
		bool isAllSenrorGoTop = true;
		int i = sensorId - 1;
		int colGr = 0;
		while (prevGroup == sensors[i]->idGroup) {

			if (!(this->vector[i][iter] - this->vector[i][iter - 1] < 0 && this->vector[i][iter - 1] - this->vector[i][iter - 2] < 0) || this->vector[i][iter - 1] > entryThreshold || this->vector[i][iter - 2] > entryThreshold) {
				isAllSenrorGoTop = false;
			}
			colGr++;
			i++;
		}
		int j = sensorId + 1;

		while (prevGroup == sensors[j]->idGroup) {


			if (!(this->vector[j][iter] - this->vector[j][iter - 1] < 0 &&
				this->vector[j][iter - 1] - this->vector[j][iter - 2] < 0) || this->vector[j][iter - 1] > entryThreshold || this->vector[j][iter - 2] > entryThreshold) {
				isAllSenrorGoTop = false;
			}
			colGr++;
			j++;
		}


		if (isAllSenrorGoTop || colGr == 0) {

			idSensors++;
			nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, idSensors, false);

			this->drawVector[sensorId][iter] = -6;

		}

		//смотрим все сенсоры в группе
		//если они все вверх, то новая группа 








		//int prevGroup = nowSensor->idGroup;
		//bool isFindGroup = false;
		//int findGroupId;
		//int i = sensorId - 1;
		//while (this->vector[i][iter] < entryThreshold) {

		//	if (this->sensors[i]->isFindTop == false) {
		//		isFindGroup = true;
		//		findGroupId = this->sensors[i]->idGroup;
		//	}
		//	i--;
		//}


		//int j = sensorId + 1;
		//while (this->vector[j][iter] < entryThreshold) {

		//	if (this->sensors[j]->isFindTop == false) {
		//		isFindGroup = true;
		//		findGroupId = this->sensors[j]->idGroup;
		//	}
		//	j++;
		//}

		//if (isFindGroup) {
		//	//копируем группу

		//	nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, findGroupId, false);

		//}
		//else {
		//	//создаем группу
		//	idSensors++;

		//	nowSensor->startListhen(false, true, nowValue, nowValue - prevValue, idSensors, false);

		//}



		//проверка всех сенсеров в линиии и запоминием текущую группу

		//если не нашел грушшу с не пройденым пиком, то создаем новую гуппу.

		//если в линии нашлась еще группа, то присоединяем к ней




		//nowSensor->resetSensor(this->entryThreshold);
		//поиск сетнсоров рядом кроме прошлой группы










	}
}

void HeightMap::findGroup(int sensorId, int iter)
{



}

void HeightMap::movingAverage()
{

	//скользящее среднее для предпоследнего элемента


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
}


void HeightMap::medialFilter() {



	int radius = 1;



	for (int j = 1; j < iteration - 2; j++) {
		for (int i = 1; i < count - 2; i++) {

			List<float> window = gcnew List<float>();

			for (int k = -radius; k <= radius; k++) {
				for (int m = -radius; m <= radius; m++) {

					window.Add(this->vector[i + k][j + m]);

				}
			}
			window.Sort();

			this->drawVector[i][j] = window[window.Count - window.Count / 2];

		}
	}



	/*for (int j = 1; j < iteration - 2; j++) {
		for (int i = 1; i < count - 2; i++) {

			float valLeft = this->vector[i - 1][j];
			float valRight = this->vector[i + 1][j];

			float valTop = this->vector[i][j + 1];
			float valBot = this->vector[i][j - 1];


			float valTopLeft = this->vector[i - 1][j + 1];
			float valTopRight = this->vector[i + 1][j + 1];


			float valBotLeft = this->vector[i - 1][j - 1];
			float valBotRight = this->vector[i + 1][j - 1];

			List<float> window = gcnew List<float>();
			window.Add(valLeft);
			window.Add(valRight);
			window.Add(valTop);
			window.Add(valBot);
			window.Add(valTopLeft);
			window.Add(valTopRight);
			window.Add(valBotLeft);
			window.Add(valBotRight);
			window.Sort();
			this->drawVector[i][j] = window[4];
		}
	}*/

	for (int j = 0; j < iteration - 1; j++) {
		for (int i = 0; i < count - 1; i++) {


			this->vector[i][j] = this->drawVector[i][j];

		}
	}
}

void HeightMap::initSensors()
{
	for (int i = 0; i < this->count; i++) {
		this->vector->Add(gcnew List<float>());
		this->drawVector->Add(gcnew List<float>());
		this->sensors->Add(gcnew Sensors(false, false, this->entryThreshold, 0));
	}
}







