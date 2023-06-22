#pragma once
#include <opencv2/opencv.hpp>
#include "HeightMap.h"
#include <thread>
#include <Windows.h> 
namespace FindEggApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Threading;

	using namespace std;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			heightMap = gcnew HeightMap();

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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
		HeightMap^ heightMap;
		Thread^ myThread;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;

	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Button^ buttonCalculate;
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
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;



	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ textBoxDistance;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBoxNoise;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
	private: System::Windows::Forms::Label^ label10;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button1;


















		   /// <summary>
		   /// ќб€зательна€ переменна€ конструктора.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			   this->panel8 = (gcnew System::Windows::Forms::Panel());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->buttonCalculate = (gcnew System::Windows::Forms::Button());
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
			   this->panel8->SuspendLayout();
			   this->panel2->SuspendLayout();
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
			   this->pictureBox1->Location = System::Drawing::Point(3, 9);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(243, 700);
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
			   this->splitContainer2->Panel2->Controls->Add(this->button1);
			   this->splitContainer2->Panel2->Controls->Add(this->buttonCalculate);
			   this->splitContainer2->Panel2->Controls->Add(this->buttonOpenFile);
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
			   this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			   this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
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
			   this->label9->Text = L"ѕараметры файла";
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
			   this->label10->Text = L"ѕеременные";
			   // 
			   // flowLayoutPanel3
			   // 
			   this->flowLayoutPanel3->Controls->Add(this->panel8);
			   this->flowLayoutPanel3->Controls->Add(this->panel2);
			   this->flowLayoutPanel3->Location = System::Drawing::Point(3, 215);
			   this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			   this->flowLayoutPanel3->Size = System::Drawing::Size(245, 100);
			   this->flowLayoutPanel3->TabIndex = 12;
			   // 
			   // panel8
			   // 
			   this->panel8->Controls->Add(this->textBox1);
			   this->panel8->Controls->Add(this->label4);
			   this->panel8->Location = System::Drawing::Point(3, 3);
			   this->panel8->Name = L"panel8";
			   this->panel8->Size = System::Drawing::Size(98, 20);
			   this->panel8->TabIndex = 5;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(41, 0);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(57, 20);
			   this->textBox1->TabIndex = 3;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(3, 3);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(21, 13);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"col";
			   // 
			   // panel2
			   // 
			   this->panel2->Controls->Add(this->textBox2);
			   this->panel2->Controls->Add(this->label2);
			   this->panel2->Location = System::Drawing::Point(107, 3);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(98, 20);
			   this->panel2->TabIndex = 6;
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(41, 0);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(57, 20);
			   this->textBox2->TabIndex = 3;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(3, 3);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(21, 13);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"col";
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button1->Location = System::Drawing::Point(4, 95);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(245, 40);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"DOWORK";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // buttonCalculate
			   // 
			   this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonCalculate->Location = System::Drawing::Point(3, 49);
			   this->buttonCalculate->Name = L"buttonCalculate";
			   this->buttonCalculate->Size = System::Drawing::Size(245, 40);
			   this->buttonCalculate->TabIndex = 1;
			   this->buttonCalculate->Text = L"CALCULATE";
			   this->buttonCalculate->UseVisualStyleBackColor = true;
			   this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
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
			   this->panel8->ResumeLayout(false);
			   this->panel8->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {


		cv::Mat img = heightMap->draw();

		// сохран€ем изображение
		cv::imwrite("image.png", img);



		Image^ image = Image::FromFile("image.png");
		pictureBox1->Image = image;

		/*ThreadStart^ threadStart = gcnew ThreadStart(this, &MyForm::Go);
		myThread = gcnew Thread(threadStart);
		myThread->Start();*/



		/*myThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::Go));
		myThread->Start();*/
		/*System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
		System::IntPtr ptr(img.ptr());Sy
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(img.cols, img.rows, img.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		//System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(img.cols, img.rows, img.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)img.data);
		System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
		graphics->DrawImage(b, rect);
		*/


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
	public: void DoSome(Bitmap^ bm) {

		pictureBox1->Image = bm;
	}
	public:Bitmap^ MatToBitmapTwo(cv::Mat& mat) {
		int width = mat.cols;
		int height = mat.rows;
		int stride = mat.step;
		IntPtr ptr(mat.ptr());

		Bitmap^ bitmap = gcnew Bitmap(width, height, stride, PixelFormat::Format24bppRgb, ptr);
		return bitmap;
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {










		//while (true)
		{
			Thread::Sleep(33);


			cv::Mat image(heightMap->iteration, heightMap->count, CV_8UC3, cv::Scalar(0, 0, 0));

			cv::imwrite("backgroundWorker1_DoWork.png", image);
			cv::line(image, cv::Point(0, 0), cv::Point(0, heightMap->iteration - 1), cv::Scalar(0, 0, 255), 3);

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

			//bitmap->Save();


			MatToBitmap(image, bitmap);
			Bitmap^ bmp = gcnew Bitmap(bitmap.bmWidth, bitmap.bmHeight, bitmap.bmWidthBytes, PixelFormat::Format24bppRgb, IntPtr(bitmap.bmBits));
			//Bitmap^ bmp = MatToBitmapTwo(image);

			bmp->Save("bmp.jpg", System::Drawing::Imaging::ImageFormat::Jpeg);


			//cv::imwrite("image.png", image);
			//BITMAP bm;
			//Bitmap^ bitmap = MatToBitmap(image, bm);

			//Bitmap^ bitmap = MatToBitmap(image, bm);
			pictureBox1->Invoke(gcnew Action<Bitmap^>(this, &MyForm::DoSome), bmp);
			//Thread::Sleep(500);

		}




	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		backgroundWorker1->RunWorkerAsync();
	}
	};
}
