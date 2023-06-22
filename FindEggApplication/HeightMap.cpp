#include "HeightMap.h"
#include <iostream>
#include <fstream> // подключаем библиотеку
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;


HeightMap::HeightMap()
{

}

HeightMap::HeightMap(int count, int iteration, int col, float update, float width)
{
	this->count = count;
	this->iteration = iteration;
	this->col = col;
	this->update = update;
	this->width = width;
}

void HeightMap::someMethod()
{

}

void HeightMap::readFile()
{
	String^ LastFileDirectory;
	String^ Filename;

	//If last directory is not valid then default to My Documents (if you don't include this the catch below won't occur for null strings so the start directory is undefined)
	if (!Directory::Exists(LastFileDirectory))
		LastFileDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);

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


		int count, iteration, col;
		float update, width, distanceToConv, noise;

		//string path = "C:\\Users\\NIKITA-PC\\Desktop\\data\\file.bin";
		string path = msclr::interop::marshal_as<std::string>(Filename);
		ifstream fin(path, ios_base::binary);


		fin.read((char*)&count, sizeof(int));
		fin.read((char*)&iteration, sizeof(int));
		fin.read((char*)&col, sizeof(int));
		fin.read((char*)&update, sizeof(float));
		fin.read((char*)&width, sizeof(float));
		fin.read((char*)&distanceToConv, sizeof(float));
		fin.read((char*)&noise, sizeof(float));

		this->count = count;
		this->iteration = iteration;
		this->col = col;
		this->update = update;
		this->width = width;
		this->distanceToConv = distanceToConv;
		this->noise = noise;



		this->array = new float* [count];


		for (int i = 0; i < count; i++) {
			array[i] = new float[iteration];
		}

		for (int j = 0; j < iteration; j++) {


			for (int i = 0; i < count; i++) {



				float data;
				fin.read((char*)&data, sizeof(float));
				cout << data << endl;
				array[i][j] = data;
			}

		}
		for (int j = 0; j < iteration; j++) {


			for (int i = 0; i < count; i++) {



				float datasss = array[i][j];
				cout << datasss << endl;


			}

		}
		//STORE LAST USED DIRECTORY
		if (Filename->LastIndexOf("\\") >= 0)
			LastFileDirectory = Filename->Substring(0, (Filename->LastIndexOf("\\") + 1));

	}
}

cv::Mat HeightMap::draw()
{


	cv::Mat image(iteration, count, CV_8UC3, cv::Scalar(0, 0, 0));
	//randu(image, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));

	// изменяем значения пикселей по координатам
	//image.at<cv::Vec3b>(100, 200) = cv::Vec3b(255, 255, 255);

	// сохраняем изображение
	//cv::imwrite("image.png", image);


	for (int j = 0; j < iteration; j++) {


		for (int i = 0; i < count; i++) {


			float value = array[i][j];
			//value = (((0.10f - value) * 1000) - 21) / 0.003f / 10000;

			if (value > distanceToConv - noise)
				value = 0;
			else
				value = (distanceToConv + noise - value) * 20 * 255;

			if (value > 255)
				value = 255;


			image.at<cv::Vec3b>(j, i) = cv::Vec3b((int)value, (int)value, (int)value);



		}

	}
	return image;
}








