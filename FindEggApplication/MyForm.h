#pragma once
#include <opencv2/opencv.hpp>
#include "HeightMap.h"
#include <thread>
#include <Windows.h> 
#include <ctime>
#include <conio.h>
#include <vcclr.h>


namespace FindEggApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Threading;
	using namespace System::IO::Ports;

	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			heightMap = gcnew HeightMap();
			isRun = false;
			textBoxEntryThreshold->Text = heightMap->entryThreshold.ToString();
			textBoxLower->Text = heightMap->loweringThreshold.ToString();

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private:
		HANDLE hSerial;
		SerialPort^ mySerialPort;
		HeightMap^ heightMap;
		Thread^ myThread;
		float eggSizeData = 0.037;
		float distanceToConv = 0.1;
		int count = 10;
		bool isRun;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;

	private: System::Windows::Forms::SplitContainer^ splitContainer2;

	private: System::Windows::Forms::Button^ buttonOpenFile;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;










	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBoxWidth;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBoxUpdate;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBoxCol;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ textBoxIter;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBoxCount;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;








	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ textBoxDistance;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBoxNoise;
	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
	private: System::Windows::Forms::Label^ label10;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::TextBox^ textBoxEntryThreshold;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBoxLower;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ save;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ eggSize;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::TextBox^ textBoxPercent;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::TextBox^ textBoxPercLow;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel6;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel7;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel8;
	private: System::Windows::Forms::Label^ labelRes;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel9;
	private: System::Windows::Forms::Label^ labelTest;




















		   /// <summary>
		   /// Обязательная переменная конструктора.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			   this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->panel6 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxIter = (gcnew System::Windows::Forms::TextBox());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxWidth = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->panel4 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxUpdate = (gcnew System::Windows::Forms::TextBox());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->panel5 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxCol = (gcnew System::Windows::Forms::TextBox());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxCount = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->panel7 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxDistance = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->panel9 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxNoise = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->panel10 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxEntryThreshold = (gcnew System::Windows::Forms::TextBox());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxLower = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->panel8 = (gcnew System::Windows::Forms::Panel());
			   this->eggSize = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel7 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->panel11 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxPercent = (gcnew System::Windows::Forms::TextBox());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->panel12 = (gcnew System::Windows::Forms::Panel());
			   this->textBoxPercLow = (gcnew System::Windows::Forms::TextBox());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel8 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->labelRes = (gcnew System::Windows::Forms::Label());
			   this->flowLayoutPanel9 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->labelTest = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->save = (gcnew System::Windows::Forms::Button());
			   this->buttonStop = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->buttonOpenFile = (gcnew System::Windows::Forms::Button());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			   this->splitContainer1->Panel1->SuspendLayout();
			   this->splitContainer1->Panel2->SuspendLayout();
			   this->splitContainer1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			   this->splitContainer2->Panel1->SuspendLayout();
			   this->splitContainer2->Panel2->SuspendLayout();
			   this->splitContainer2->SuspendLayout();
			   this->flowLayoutPanel1->SuspendLayout();
			   this->flowLayoutPanel4->SuspendLayout();
			   this->flowLayoutPanel2->SuspendLayout();
			   this->panel6->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->panel4->SuspendLayout();
			   this->panel5->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->panel7->SuspendLayout();
			   this->panel9->SuspendLayout();
			   this->flowLayoutPanel5->SuspendLayout();
			   this->flowLayoutPanel3->SuspendLayout();
			   this->panel10->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->flowLayoutPanel6->SuspendLayout();
			   this->panel8->SuspendLayout();
			   this->flowLayoutPanel7->SuspendLayout();
			   this->panel11->SuspendLayout();
			   this->panel12->SuspendLayout();
			   this->flowLayoutPanel8->SuspendLayout();
			   this->flowLayoutPanel9->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // splitContainer1
			   // 
			   this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			   this->splitContainer1->IsSplitterFixed = true;
			   this->splitContainer1->Location = System::Drawing::Point(0, 0);
			   this->splitContainer1->Name = L"splitContainer1";
			   // 
			   // splitContainer1.Panel1
			   // 
			   this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			   this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::splitContainer1_Panel1_Paint);
			   // 
			   // splitContainer1.Panel2
			   // 
			   this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			   this->splitContainer1->Size = System::Drawing::Size(505, 721);
			   this->splitContainer1->SplitterDistance = 249;
			   this->splitContainer1->TabIndex = 0;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Location = System::Drawing::Point(50, 9);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(150, 700);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   // 
			   // splitContainer2
			   // 
			   this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer2->Location = System::Drawing::Point(0, 0);
			   this->splitContainer2->Name = L"splitContainer2";
			   this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			   // 
			   // splitContainer2.Panel1
			   // 
			   this->splitContainer2->Panel1->Controls->Add(this->flowLayoutPanel1);
			   // 
			   // splitContainer2.Panel2
			   // 
			   this->splitContainer2->Panel2->Controls->Add(this->button2);
			   this->splitContainer2->Panel2->Controls->Add(this->save);
			   this->splitContainer2->Panel2->Controls->Add(this->buttonStop);
			   this->splitContainer2->Panel2->Controls->Add(this->button1);
			   this->splitContainer2->Panel2->Controls->Add(this->buttonOpenFile);
			   this->splitContainer2->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::splitContainer2_Panel2_Paint);
			   this->splitContainer2->Size = System::Drawing::Size(252, 721);
			   this->splitContainer2->SplitterDistance = 525;
			   this->splitContainer2->TabIndex = 0;
			   // 
			   // flowLayoutPanel1
			   // 
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel4);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel2);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel5);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel3);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel6);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel7);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel8);
			   this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel9);
			   this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			   this->flowLayoutPanel1->Location = System::Drawing::Point(-3, -2);
			   this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			   this->flowLayoutPanel1->Size = System::Drawing::Size(251, 525);
			   this->flowLayoutPanel1->TabIndex = 0;
			   this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel1_Paint);
			   // 
			   // flowLayoutPanel4
			   // 
			   this->flowLayoutPanel4->Controls->Add(this->label9);
			   this->flowLayoutPanel4->Location = System::Drawing::Point(3, 3);
			   this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			   this->flowLayoutPanel4->Size = System::Drawing::Size(245, 37);
			   this->flowLayoutPanel4->TabIndex = 13;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label9->Location = System::Drawing::Point(3, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(189, 30);
			   this->label9->TabIndex = 0;
			   this->label9->Text = L"Параметры файла";
			   // 
			   // flowLayoutPanel2
			   // 
			   this->flowLayoutPanel2->Controls->Add(this->panel6);
			   this->flowLayoutPanel2->Controls->Add(this->panel3);
			   this->flowLayoutPanel2->Controls->Add(this->panel4);
			   this->flowLayoutPanel2->Controls->Add(this->panel5);
			   this->flowLayoutPanel2->Controls->Add(this->panel1);
			   this->flowLayoutPanel2->Controls->Add(this->panel7);
			   this->flowLayoutPanel2->Controls->Add(this->panel9);
			   this->flowLayoutPanel2->Location = System::Drawing::Point(3, 46);
			   this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			   this->flowLayoutPanel2->Size = System::Drawing::Size(245, 120);
			   this->flowLayoutPanel2->TabIndex = 11;
			   // 
			   // panel6
			   // 
			   this->panel6->Controls->Add(this->textBoxIter);
			   this->panel6->Controls->Add(this->label11);
			   this->panel6->Location = System::Drawing::Point(3, 3);
			   this->panel6->Name = L"panel6";
			   this->panel6->Size = System::Drawing::Size(115, 20);
			   this->panel6->TabIndex = 5;
			   // 
			   // textBoxIter
			   // 
			   this->textBoxIter->Location = System::Drawing::Point(55, 0);
			   this->textBoxIter->Name = L"textBoxIter";
			   this->textBoxIter->ReadOnly = true;
			   this->textBoxIter->Size = System::Drawing::Size(57, 20);
			   this->textBoxIter->TabIndex = 3;
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(3, 3);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(21, 13);
			   this->label11->TabIndex = 2;
			   this->label11->Text = L"iter";
			   // 
			   // panel3
			   // 
			   this->panel3->Controls->Add(this->textBoxWidth);
			   this->panel3->Controls->Add(this->label6);
			   this->panel3->Location = System::Drawing::Point(124, 3);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(115, 20);
			   this->panel3->TabIndex = 0;
			   // 
			   // textBoxWidth
			   // 
			   this->textBoxWidth->Location = System::Drawing::Point(55, 0);
			   this->textBoxWidth->Name = L"textBoxWidth";
			   this->textBoxWidth->ReadOnly = true;
			   this->textBoxWidth->Size = System::Drawing::Size(57, 20);
			   this->textBoxWidth->TabIndex = 3;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(3, 3);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(32, 13);
			   this->label6->TabIndex = 2;
			   this->label6->Text = L"width";
			   this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			   // 
			   // panel4
			   // 
			   this->panel4->Controls->Add(this->textBoxUpdate);
			   this->panel4->Controls->Add(this->label7);
			   this->panel4->Location = System::Drawing::Point(3, 29);
			   this->panel4->Name = L"panel4";
			   this->panel4->Size = System::Drawing::Size(115, 20);
			   this->panel4->TabIndex = 4;
			   // 
			   // textBoxUpdate
			   // 
			   this->textBoxUpdate->Location = System::Drawing::Point(55, 0);
			   this->textBoxUpdate->Name = L"textBoxUpdate";
			   this->textBoxUpdate->ReadOnly = true;
			   this->textBoxUpdate->Size = System::Drawing::Size(57, 20);
			   this->textBoxUpdate->TabIndex = 3;
			   this->textBoxUpdate->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxUpdate_TextChanged);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(3, 3);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(40, 13);
			   this->label7->TabIndex = 2;
			   this->label7->Text = L"update";
			   // 
			   // panel5
			   // 
			   this->panel5->Controls->Add(this->textBoxCol);
			   this->panel5->Controls->Add(this->label8);
			   this->panel5->Location = System::Drawing::Point(124, 29);
			   this->panel5->Name = L"panel5";
			   this->panel5->Size = System::Drawing::Size(115, 20);
			   this->panel5->TabIndex = 4;
			   // 
			   // textBoxCol
			   // 
			   this->textBoxCol->Location = System::Drawing::Point(55, 0);
			   this->textBoxCol->Name = L"textBoxCol";
			   this->textBoxCol->ReadOnly = true;
			   this->textBoxCol->Size = System::Drawing::Size(57, 20);
			   this->textBoxCol->TabIndex = 3;
			   this->textBoxCol->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxCol_TextChanged);
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(3, 3);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(21, 13);
			   this->label8->TabIndex = 2;
			   this->label8->Text = L"col";
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->textBoxCount);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Location = System::Drawing::Point(3, 55);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(115, 20);
			   this->panel1->TabIndex = 6;
			   // 
			   // textBoxCount
			   // 
			   this->textBoxCount->Location = System::Drawing::Point(55, 0);
			   this->textBoxCount->Name = L"textBoxCount";
			   this->textBoxCount->ReadOnly = true;
			   this->textBoxCount->Size = System::Drawing::Size(57, 20);
			   this->textBoxCount->TabIndex = 3;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(3, 3);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(34, 13);
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"count";
			   // 
			   // panel7
			   // 
			   this->panel7->Controls->Add(this->textBoxDistance);
			   this->panel7->Controls->Add(this->label3);
			   this->panel7->Location = System::Drawing::Point(124, 55);
			   this->panel7->Name = L"panel7";
			   this->panel7->Size = System::Drawing::Size(115, 20);
			   this->panel7->TabIndex = 5;
			   // 
			   // textBoxDistance
			   // 
			   this->textBoxDistance->Location = System::Drawing::Point(55, 0);
			   this->textBoxDistance->Name = L"textBoxDistance";
			   this->textBoxDistance->ReadOnly = true;
			   this->textBoxDistance->Size = System::Drawing::Size(57, 20);
			   this->textBoxDistance->TabIndex = 3;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(3, 3);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(23, 13);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"dist";
			   // 
			   // panel9
			   // 
			   this->panel9->Controls->Add(this->textBoxNoise);
			   this->panel9->Controls->Add(this->label5);
			   this->panel9->Location = System::Drawing::Point(3, 81);
			   this->panel9->Name = L"panel9";
			   this->panel9->Size = System::Drawing::Size(115, 20);
			   this->panel9->TabIndex = 5;
			   // 
			   // textBoxNoise
			   // 
			   this->textBoxNoise->Location = System::Drawing::Point(55, 0);
			   this->textBoxNoise->Name = L"textBoxNoise";
			   this->textBoxNoise->ReadOnly = true;
			   this->textBoxNoise->Size = System::Drawing::Size(57, 20);
			   this->textBoxNoise->TabIndex = 3;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(3, 3);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(32, 13);
			   this->label5->TabIndex = 2;
			   this->label5->Text = L"noise";
			   // 
			   // flowLayoutPanel5
			   // 
			   this->flowLayoutPanel5->Controls->Add(this->label10);
			   this->flowLayoutPanel5->Location = System::Drawing::Point(3, 172);
			   this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
			   this->flowLayoutPanel5->Size = System::Drawing::Size(245, 37);
			   this->flowLayoutPanel5->TabIndex = 14;
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label10->Location = System::Drawing::Point(3, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(138, 30);
			   this->label10->TabIndex = 0;
			   this->label10->Text = L"Переменные";
			   // 
			   // flowLayoutPanel3
			   // 
			   this->flowLayoutPanel3->Controls->Add(this->panel10);
			   this->flowLayoutPanel3->Controls->Add(this->panel2);
			   this->flowLayoutPanel3->Location = System::Drawing::Point(3, 215);
			   this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			   this->flowLayoutPanel3->Size = System::Drawing::Size(245, 32);
			   this->flowLayoutPanel3->TabIndex = 12;
			   // 
			   // panel10
			   // 
			   this->panel10->Controls->Add(this->textBoxEntryThreshold);
			   this->panel10->Controls->Add(this->label12);
			   this->panel10->Location = System::Drawing::Point(3, 3);
			   this->panel10->Name = L"panel10";
			   this->panel10->Size = System::Drawing::Size(115, 20);
			   this->panel10->TabIndex = 6;
			   // 
			   // textBoxEntryThreshold
			   // 
			   this->textBoxEntryThreshold->Location = System::Drawing::Point(55, 0);
			   this->textBoxEntryThreshold->Name = L"textBoxEntryThreshold";
			   this->textBoxEntryThreshold->Size = System::Drawing::Size(57, 20);
			   this->textBoxEntryThreshold->TabIndex = 3;
			   this->textBoxEntryThreshold->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxEntryThreshold_TextChanged);
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Location = System::Drawing::Point(3, 3);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(30, 13);
			   this->label12->TabIndex = 2;
			   this->label12->Text = L"entry";
			   // 
			   // panel2
			   // 
			   this->panel2->Controls->Add(this->textBoxLower);
			   this->panel2->Controls->Add(this->label2);
			   this->panel2->Location = System::Drawing::Point(124, 3);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(115, 20);
			   this->panel2->TabIndex = 7;
			   // 
			   // textBoxLower
			   // 
			   this->textBoxLower->Location = System::Drawing::Point(55, 0);
			   this->textBoxLower->Name = L"textBoxLower";
			   this->textBoxLower->Size = System::Drawing::Size(57, 20);
			   this->textBoxLower->TabIndex = 3;
			   this->textBoxLower->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxLower_TextChanged);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(3, 3);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(32, 13);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"lower";
			   // 
			   // flowLayoutPanel6
			   // 
			   this->flowLayoutPanel6->Controls->Add(this->panel8);
			   this->flowLayoutPanel6->Location = System::Drawing::Point(3, 253);
			   this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
			   this->flowLayoutPanel6->Size = System::Drawing::Size(245, 30);
			   this->flowLayoutPanel6->TabIndex = 13;
			   // 
			   // panel8
			   // 
			   this->panel8->Controls->Add(this->eggSize);
			   this->panel8->Controls->Add(this->label4);
			   this->panel8->Location = System::Drawing::Point(3, 3);
			   this->panel8->Name = L"panel8";
			   this->panel8->Size = System::Drawing::Size(115, 20);
			   this->panel8->TabIndex = 7;
			   // 
			   // eggSize
			   // 
			   this->eggSize->Location = System::Drawing::Point(55, 0);
			   this->eggSize->Name = L"eggSize";
			   this->eggSize->Size = System::Drawing::Size(57, 20);
			   this->eggSize->TabIndex = 3;
			   this->eggSize->TextChanged += gcnew System::EventHandler(this, &MyForm::eggSize_TextChanged);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(3, 3);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(25, 13);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"egg";
			   this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			   // 
			   // flowLayoutPanel7
			   // 
			   this->flowLayoutPanel7->Controls->Add(this->panel11);
			   this->flowLayoutPanel7->Controls->Add(this->panel12);
			   this->flowLayoutPanel7->Location = System::Drawing::Point(3, 289);
			   this->flowLayoutPanel7->Name = L"flowLayoutPanel7";
			   this->flowLayoutPanel7->Size = System::Drawing::Size(245, 32);
			   this->flowLayoutPanel7->TabIndex = 14;
			   // 
			   // panel11
			   // 
			   this->panel11->Controls->Add(this->textBoxPercent);
			   this->panel11->Controls->Add(this->label13);
			   this->panel11->Location = System::Drawing::Point(3, 3);
			   this->panel11->Name = L"panel11";
			   this->panel11->Size = System::Drawing::Size(115, 20);
			   this->panel11->TabIndex = 8;
			   // 
			   // textBoxPercent
			   // 
			   this->textBoxPercent->Location = System::Drawing::Point(55, 0);
			   this->textBoxPercent->Name = L"textBoxPercent";
			   this->textBoxPercent->Size = System::Drawing::Size(57, 20);
			   this->textBoxPercent->TabIndex = 3;
			   this->textBoxPercent->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxPercent_TextChanged);
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Location = System::Drawing::Point(3, 3);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(47, 13);
			   this->label13->TabIndex = 2;
			   this->label13->Text = L"percEntr";
			   // 
			   // panel12
			   // 
			   this->panel12->Controls->Add(this->textBoxPercLow);
			   this->panel12->Controls->Add(this->label14);
			   this->panel12->Location = System::Drawing::Point(124, 3);
			   this->panel12->Name = L"panel12";
			   this->panel12->Size = System::Drawing::Size(115, 20);
			   this->panel12->TabIndex = 8;
			   // 
			   // textBoxPercLow
			   // 
			   this->textBoxPercLow->Location = System::Drawing::Point(55, 0);
			   this->textBoxPercLow->Name = L"textBoxPercLow";
			   this->textBoxPercLow->Size = System::Drawing::Size(57, 20);
			   this->textBoxPercLow->TabIndex = 3;
			   this->textBoxPercLow->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxPercLow_TextChanged);
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Location = System::Drawing::Point(3, 3);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(48, 13);
			   this->label14->TabIndex = 2;
			   this->label14->Text = L"percLow";
			   // 
			   // flowLayoutPanel8
			   // 
			   this->flowLayoutPanel8->Controls->Add(this->labelRes);
			   this->flowLayoutPanel8->Location = System::Drawing::Point(3, 327);
			   this->flowLayoutPanel8->Name = L"flowLayoutPanel8";
			   this->flowLayoutPanel8->Size = System::Drawing::Size(245, 61);
			   this->flowLayoutPanel8->TabIndex = 15;
			   // 
			   // labelRes
			   // 
			   this->labelRes->AutoSize = true;
			   this->labelRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelRes->Location = System::Drawing::Point(3, 0);
			   this->labelRes->Name = L"labelRes";
			   this->labelRes->Size = System::Drawing::Size(42, 46);
			   this->labelRes->TabIndex = 0;
			   this->labelRes->Text = L"0";
			   // 
			   // flowLayoutPanel9
			   // 
			   this->flowLayoutPanel9->Controls->Add(this->labelTest);
			   this->flowLayoutPanel9->Location = System::Drawing::Point(3, 394);
			   this->flowLayoutPanel9->Name = L"flowLayoutPanel9";
			   this->flowLayoutPanel9->Size = System::Drawing::Size(245, 61);
			   this->flowLayoutPanel9->TabIndex = 16;
			   // 
			   // labelTest
			   // 
			   this->labelTest->AutoSize = true;
			   this->labelTest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelTest->Location = System::Drawing::Point(3, 0);
			   this->labelTest->Name = L"labelTest";
			   this->labelTest->Size = System::Drawing::Size(14, 16);
			   this->labelTest->TabIndex = 0;
			   this->labelTest->Text = L"0";
			   // 
			   // button2
			   // 
			   this->button2->Enabled = false;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->Location = System::Drawing::Point(3, 140);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(245, 40);
			   this->button2->TabIndex = 5;
			   this->button2->Text = L"RESET";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // save
			   // 
			   this->save->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->save->Location = System::Drawing::Point(3, 95);
			   this->save->Name = L"save";
			   this->save->Size = System::Drawing::Size(245, 40);
			   this->save->TabIndex = 4;
			   this->save->Text = L"SAVE";
			   this->save->UseVisualStyleBackColor = true;
			   this->save->Click += gcnew System::EventHandler(this, &MyForm::save_Click);
			   // 
			   // buttonStop
			   // 
			   this->buttonStop->Enabled = false;
			   this->buttonStop->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonStop->Location = System::Drawing::Point(131, 49);
			   this->buttonStop->Name = L"buttonStop";
			   this->buttonStop->Size = System::Drawing::Size(117, 40);
			   this->buttonStop->TabIndex = 3;
			   this->buttonStop->Text = L"STOP";
			   this->buttonStop->UseVisualStyleBackColor = true;
			   this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button1->Location = System::Drawing::Point(3, 49);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(117, 40);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"START";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // buttonOpenFile
			   // 
			   this->buttonOpenFile->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buttonOpenFile->Location = System::Drawing::Point(3, 3);
			   this->buttonOpenFile->Name = L"buttonOpenFile";
			   this->buttonOpenFile->Size = System::Drawing::Size(245, 40);
			   this->buttonOpenFile->TabIndex = 0;
			   this->buttonOpenFile->Text = L"OPEN FILE";
			   this->buttonOpenFile->UseVisualStyleBackColor = true;
			   this->buttonOpenFile->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenFile_Click);
			   // 
			   // backgroundWorker1
			   // 
			   this->backgroundWorker1->WorkerSupportsCancellation = true;
			   this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(505, 721);
			   this->Controls->Add(this->splitContainer1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"MyForm";
			   this->Text = L"FindEggApplication";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->splitContainer1->Panel1->ResumeLayout(false);
			   this->splitContainer1->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			   this->splitContainer1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->splitContainer2->Panel1->ResumeLayout(false);
			   this->splitContainer2->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			   this->splitContainer2->ResumeLayout(false);
			   this->flowLayoutPanel1->ResumeLayout(false);
			   this->flowLayoutPanel4->ResumeLayout(false);
			   this->flowLayoutPanel4->PerformLayout();
			   this->flowLayoutPanel2->ResumeLayout(false);
			   this->panel6->ResumeLayout(false);
			   this->panel6->PerformLayout();
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->panel4->ResumeLayout(false);
			   this->panel4->PerformLayout();
			   this->panel5->ResumeLayout(false);
			   this->panel5->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panel7->ResumeLayout(false);
			   this->panel7->PerformLayout();
			   this->panel9->ResumeLayout(false);
			   this->panel9->PerformLayout();
			   this->flowLayoutPanel5->ResumeLayout(false);
			   this->flowLayoutPanel5->PerformLayout();
			   this->flowLayoutPanel3->ResumeLayout(false);
			   this->panel10->ResumeLayout(false);
			   this->panel10->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->flowLayoutPanel6->ResumeLayout(false);
			   this->panel8->ResumeLayout(false);
			   this->panel8->PerformLayout();
			   this->flowLayoutPanel7->ResumeLayout(false);
			   this->panel11->ResumeLayout(false);
			   this->panel11->PerformLayout();
			   this->panel12->ResumeLayout(false);
			   this->panel12->PerformLayout();
			   this->flowLayoutPanel8->ResumeLayout(false);
			   this->flowLayoutPanel8->PerformLayout();
			   this->flowLayoutPanel9->ResumeLayout(false);
			   this->flowLayoutPanel9->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		eggSize->Text = eggSizeData.ToString();

		float valEnt = 92;
		textBoxPercent->Text = valEnt.ToString();


		float valLow = 85;
		textBoxPercLow->Text = valLow.ToString();

		//изменить порог
		heightMap->setLoweringThreshold(distanceToConv - (eggSizeData / 100) * valLow);
		heightMap->setEntryThreshold(distanceToConv - (eggSizeData / 100) * valEnt);

		textBoxEntryThreshold->Text = heightMap->entryThreshold.ToString();

		textBoxLower->Text = heightMap->loweringThreshold.ToString();

	}

	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {

		heightMap->readFile();
		textBoxCount->Text = heightMap->count.ToString();
		textBoxIter->Text = heightMap->iteration.ToString();
		textBoxCol->Text = heightMap->col.ToString();
		textBoxUpdate->Text = heightMap->update.ToString();
		textBoxWidth->Text = heightMap->width.ToString();
		textBoxDistance->Text = heightMap->distanceToConv.ToString();
		textBoxNoise->Text = heightMap->noise.ToString();

		button2->Enabled = true;
		button1->Enabled = true;
		buttonOpenFile->Enabled = false;
		//textBoxEntryThreshold->Enabled = false;
		textBoxEntryThreshold->ReadOnly = true;
		textBoxLower->ReadOnly = true;
		save->Enabled = true;
		pictureBox1->Width = heightMap->count;
		//**************************************
		cv::Mat imageOne = heightMap->draw();
		cv::Mat image;
		//cv::imwrite("backgroundWorker1_DoWork.png", image);
		//cv::cvtColor(image, image, cv::);
		resize(imageOne, image, cv::Size(imageOne.cols, imageOne.cols));

		cv::cvtColor(imageOne, image, cv::COLOR_BGR2RGB);


		BITMAP bitmap = { 0 };
		if (image.channels() == 3)
		{
			bitmap.bmWidth = image.cols;
			bitmap.bmHeight = image.rows;
			bitmap.bmPlanes = 1;
			bitmap.bmBitsPixel = 24;
			bitmap.bmWidthBytes = ((image.cols * 3) + 3) & ~3;
			bitmap.bmBits = malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
			memset(bitmap.bmBits, 0, static_cast<size_t>(bitmap.bmWidthBytes) * bitmap.bmHeight);
		}

		MatToBitmap(image, bitmap);
		Bitmap^ bmp = gcnew Bitmap(bitmap.bmWidth, bitmap.bmHeight, bitmap.bmWidthBytes, PixelFormat::Format24bppRgb, IntPtr(bitmap.bmBits));
		bmp->SetResolution(image.cols, image.rows);

		pictureBox1->Image = bmp;

	}
	private: System::Void textBoxUpdate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxCol_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	public: void MatToBitmap(cv::Mat& matImage, BITMAP& bitmap)
	{
		int nChannels = matImage.channels();
		int width = matImage.cols;
		int height = matImage.rows;

		int bitmapWidth = bitmap.bmWidth;
		int bitmapHeight = bitmap.bmHeight;

		if (nChannels == 3 && width == bitmapWidth && height == bitmapHeight)
		{
			unsigned char* pSrc = (unsigned char*)matImage.data;
			unsigned char* pDst = (unsigned char*)bitmap.bmBits;

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					int nPixelIndex = y * width + x;

					int nBlue = *pSrc++;
					int nGreen = *pSrc++;
					int nRed = *pSrc++;

					*pDst++ = nBlue;
					*pDst++ = nGreen;
					*pDst++ = nRed;

					if (nChannels == 4)
					{
						int nAlpha = *pSrc++;
						*pDst++ = nAlpha;
					}
				}
			}
		}
	}
	public: void chamgePictureBox1(Bitmap^ bm) {

		pictureBox1->Image = bm;
	}
	public: void changeLableTest(String^ str) {

		labelTest->Text = str;
	}
	public: void chamgePictureBox1Mat(cv::Mat& mat) {

		ShowMatInForm(mat, pictureBox1);
	}


	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

		DWORD bytesRead;

		while (isRun)
		{

			char buffer[4];
			int i = 0;
			List<float>^ vector = gcnew List<float>();
			String^ strTest = "";
			while (1) {
				ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL); // прочитайте байты из порта


				if (bytesRead != 4)
					continue;
				string str(buffer, sizeof(buffer));
				if (str == "Data")	std::cout << "Data: " << str << std::endl;
				else {
					float* check = (float*)buffer;
					std::cout << "Data: " << *check << endl;
					vector->Add(*check);
					i++;
					strTest += *check + "\n";
				}

				if (i == count) {
					heightMap->addToVector(vector);
					heightMap->movingAverage();
					heightMap->checkSensors();


					labelTest->Invoke(gcnew Action<String^>(this, &MyForm::changeLableTest), strTest);
					vector = gcnew List<float>();
					i = 0;
					strTest = "";
				}

			}
		}

		CloseHandle(hSerial);




	}
	private:Bitmap^ MatToBitmap(const cv::Mat& mat)
	{
		auto ptr = (uchar*)mat.data; // указатель на данные Mat
		int width = mat.cols; // ширина Mat
		int height = mat.rows; // высота Mat
		int stride = mat.step; // ширина строки Mat

		auto bitmap = gcnew Bitmap(width, height, stride, PixelFormat::Format24bppRgb, IntPtr(ptr));

		return bitmap;
	}
	private:void ShowMatInForm(const cv::Mat& mat, PictureBox^ pictureBox)
	{
		auto bitmap = MatToBitmap(mat);
		pictureBox->Image = bitmap;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		int iteration = 0, col = 0;
		float update = 0, width = 0;

		heightMap = gcnew HeightMap(count, iteration, col, update, width, distanceToConv);


		hSerial = CreateFile(L"COM4", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (hSerial == INVALID_HANDLE_VALUE) {
			DWORD error = GetLastError();
			// Обработка ошибки
		}
		else {
			DCB dcbSerialParams = { 0 };
			dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
			if (!GetCommState(hSerial, &dcbSerialParams)) {
				// Обработка ошибки
			}
			else {
				dcbSerialParams.BaudRate = CBR_115200;
				dcbSerialParams.ByteSize = 8;
				dcbSerialParams.StopBits = ONESTOPBIT;
				dcbSerialParams.Parity = NOPARITY;
				if (!SetCommState(hSerial, &dcbSerialParams)) {
					// Обработка ошибки
				}
				else {
					buttonStop->Enabled = true;
					isRun = true;
					backgroundWorker1->RunWorkerAsync();
				}
			}
		}





	}
	private: void ReadComPortInBackground()
	{

	}
	private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
		//button1->Enabled = true;
		//buttonStop->Enabled = false;
		isRun = !isRun;

		backgroundWorker1->CancelAsync();

	}
	private: System::Void splitContainer2_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxEntryThreshold_TextChanged(System::Object^ sender, System::EventArgs^ e) {



		float num;
		if (System::Single::TryParse(textBoxEntryThreshold->Text, num))
		{

			heightMap->setEntryThreshold(num);




			// преобразование выполнено успешно
			// переменная num содержит число типа float
		}
		else
		{
			// произошла ошибка преобразования
		}
		//heightMap->setEntryThreshold((float)textBoxEntryThreshold->Text);

	}
	private: System::Void textBoxLower_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		float num;
		if (System::Single::TryParse(textBoxLower->Text, num))
		{

			heightMap->setLoweringThreshold(num);
		}
		else
		{
			// произошла ошибка преобразования
		}

	}
	private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) {
		cv::Mat image = heightMap->draw();

		cv::namedWindow("test", cv::WINDOW_NORMAL);
		cv::resizeWindow("test", image.cols * 3, image.rows * 3);

		cv::imshow("test", image);

		cv::imwrite("save.png", image);


		cv::Mat imageOne = heightMap->drawOrig();

		cv::namedWindow("test", cv::WINDOW_NORMAL);
		cv::resizeWindow("test", imageOne.cols * 3, imageOne.rows * 3);

		cv::imshow("testOrig", imageOne);

		cv::imwrite("saveOrig.png", imageOne);

		labelRes->Text = heightMap->findCol.ToString();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		heightMap = gcnew HeightMap();


		textBoxCount->Clear();
		textBoxIter->Clear();
		textBoxCol->Clear();
		textBoxUpdate->Clear();
		textBoxWidth->Clear();
		textBoxDistance->Clear();
		textBoxNoise->Clear();

		labelRes->Text = "0";

		pictureBox1->Image = nullptr;

		textBoxEntryThreshold->ReadOnly = false;
		textBoxLower->ReadOnly = false;
		button1->Enabled = true;
		button2->Enabled = false;
		buttonOpenFile->Enabled = true;
		save->Enabled = false;
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:void DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e)
	{
		SerialPort^ sp = (SerialPort^)sender;
		String^ indata = sp->ReadExisting();
		Console::WriteLine(L"Получены данные: {0}", indata);
	}
	private: System::Void textBoxPercent_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		float eggSize, percent;
		if (System::Single::TryParse(textBoxPercent->Text, percent))
		{

			//heightMap->setEntryThreshold(num);


			float val = (eggSizeData / 100) * percent;
			heightMap->setEntryThreshold(distanceToConv - val);

			textBoxEntryThreshold->Text = heightMap->entryThreshold.ToString();
			// преобразование выполнено успешно
			// переменная num содержит число типа float
		}
		else
		{
			// произошла ошибка преобразования
		}
	}
	private: System::Void eggSize_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		float val;
		if (System::Single::TryParse(eggSize->Text, val))
		{

			eggSizeData = val;
			//heightMap->setEntryThreshold(num);



			// преобразование выполнено успешно
			// переменная num содержит число типа float
		}
		else
		{
			// произошла ошибка преобразования
		}
	}
	private: System::Void textBoxPercLow_TextChanged(System::Object^ sender, System::EventArgs^ e) {


		float  percent;
		if (System::Single::TryParse(textBoxPercLow->Text, percent))
		{

			//heightMap->setEntryThreshold(num);


			float val = (eggSizeData / 100) * percent;
			heightMap->setLoweringThreshold(distanceToConv - val);

			textBoxLower->Text = heightMap->loweringThreshold.ToString();




			// преобразование выполнено успешно
			// переменная num содержит число типа float
		}
		else
		{
			// произошла ошибка преобразования
		}
	}
	};

}
