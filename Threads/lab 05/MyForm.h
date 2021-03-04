#pragma once
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <process.h>
using namespace std;

double milliseconds = 0;

typedef struct ST
{
	double start = 0;
	double end = 3;
	size_t countOfStep;
	size_t index;
}theStruct;

typedef struct ArrayParameter
{
	size_t* arr;
	size_t start;
	size_t end;
}ArrayParameters;

unsigned int __stdcall mythread(void* data)
{
	theStruct* args = (theStruct*)data;
	double start = args->start;
	double end = args->end;
	string nameOfFile = to_string(args->index) + ".txt";
	ofstream out("Thread_" + nameOfFile);
	int n = args->countOfStep;
	int index = args->index;
	double eps = 0.1;
	double x = start;
	double step = (double)(start + end) / n;
	while (x < end)
	{
		double formula = cos(x);
		double result = 0;
		double diff = 0;

		int n = 1;
		double tmp;
		do
		{
			int fact = 1, mult = 2 * n;
			while (mult != 1) {
				fact *= mult;
				mult--;
			}
			tmp = diff;
			diff = (pow(-1, n) * (pow(x, (2 * n)) / (fact)));
			result += diff;
			n++;
		} while (fabs(diff - tmp) > eps);
		result = 1 + result;
		x += step;
		Sleep(10);
		out << "X = " << x << ", formula = " << formula << ", result = " << result << "\n";
	}
	return 0;
}

string GetPriority(int priority)
{
	string strPriority;
	switch (priority)
	{
	case THREAD_PRIORITY_ABOVE_NORMAL: strPriority = "Above normal"; break;
	case BELOW_NORMAL_PRIORITY_CLASS: strPriority = "Below normal"; break;
	case NORMAL_PRIORITY_CLASS: strPriority = "Normal"; break;
	case IDLE_PRIORITY_CLASS: strPriority = "Idle"; break;
	case HIGH_PRIORITY_CLASS: strPriority = "High"; break;
	case REALTIME_PRIORITY_CLASS: strPriority = "Real Time"; break;
	default: strPriority = "";
	}
	return strPriority;
}

namespace lab05 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public: size_t choosedIndex;
	public: size_t numberOfThreads;
	public: HANDLE* myHandle;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	public:
	private: System::Windows::Forms::TextBox^ textBox1;
	public: MyForm(void)
	{
		InitializeComponent();
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
			for (size_t i = 0; i < numberOfThreads; i++)
			{
				CloseHandle(myHandle[i]);
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ threadCount_comboBox;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ createThreads_button;
	private: System::Windows::Forms::DataGridView^ Grid1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->threadCount_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->createThreads_button = (gcnew System::Windows::Forms::Button());
			this->Grid1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// threadCount_comboBox
			// 
			this->threadCount_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->threadCount_comboBox->FormattingEnabled = true;
			this->threadCount_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"2", L"4", L"8", L"16" });
			this->threadCount_comboBox->Location = System::Drawing::Point(135, 12);
			this->threadCount_comboBox->Name = L"threadCount_comboBox";
			this->threadCount_comboBox->Size = System::Drawing::Size(121, 24);
			this->threadCount_comboBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Count of threads:";
			// 
			// createThreads_button
			// 
			this->createThreads_button->Location = System::Drawing::Point(262, 12);
			this->createThreads_button->Name = L"createThreads_button";
			this->createThreads_button->Size = System::Drawing::Size(81, 66);
			this->createThreads_button->TabIndex = 2;
			this->createThreads_button->Text = L"Create threads";
			this->createThreads_button->UseVisualStyleBackColor = true;
			this->createThreads_button->Click += gcnew System::EventHandler(this, &MyForm::createThreads_button_Click);
			// 
			// Grid1
			// 
			this->Grid1->AllowUserToAddRows = false;
			this->Grid1->AllowUserToDeleteRows = false;
			this->Grid1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1, this->Column2,
					this->Column3, this->Column4
			});
			this->Grid1->Location = System::Drawing::Point(12, 89);
			this->Grid1->Name = L"Grid1";
			this->Grid1->ReadOnly = true;
			this->Grid1->RowHeadersVisible = false;
			this->Grid1->RowHeadersWidth = 51;
			this->Grid1->RowTemplate->Height = 24;
			this->Grid1->Size = System::Drawing::Size(531, 350);
			this->Grid1->TabIndex = 3;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"є";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 115;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Priority";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Status";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(549, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(174, 90);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Information";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 46);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 17);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Time: ";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(549, 111);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(174, 328);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Actions";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 274);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(81, 48);
			this->button3->TabIndex = 10;
			this->button3->Text = L"PAUSE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 220);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(81, 48);
			this->button2->TabIndex = 9;
			this->button2->Text = L"RUN";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 166);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 48);
			this->button1->TabIndex = 6;
			this->button1->Text = L"KILL";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Idle", L"Below normal", L"Normal", L"Above normal",
					L"High", L"Real time"
			});
			this->comboBox2->Location = System::Drawing::Point(9, 114);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 8;
			this->comboBox2->Visible = false;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Priority";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16"
			});
			this->comboBox1->Location = System::Drawing::Point(9, 51);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Number of thread";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Count of steps:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(135, 61);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 7;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(349, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(81, 66);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Run all";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 451);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Grid1);
			this->Controls->Add(this->createThreads_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->threadCount_comboBox);
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Thread Creator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createThreads_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		numberOfThreads = Convert::ToUInt16(threadCount_comboBox->SelectedItem);
		myHandle = new HANDLE[numberOfThreads];
		double start = 0;
		double end = 3;
		double divided = (end - start) / numberOfThreads;
		for (size_t i = 0; i < numberOfThreads; i++)
		{
			theStruct* st = new theStruct;
			end = start + divided;
			size_t countOfStep = Convert::ToUInt32(textBox1->Text);
			st->start = start;
			st->end = end;
			st->countOfStep = countOfStep;
			st->index = i + 1;
			myHandle[i] = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)st, 0, 0);
			SuspendThread(myHandle[i]);
			start = end;
			Grid1->RowCount = numberOfThreads;
			Grid1->Rows[i]->Cells[0]->Value = i + 1;
			Grid1->Rows[i]->Cells[1]->Value = GetThreadId(myHandle[i]);
			Grid1->Rows[i]->Cells[2]->Value = "Normal";
			Grid1->Rows[i]->Cells[3]->Value = "Suspended";
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		choosedIndex = Convert::ToUInt16(comboBox1->SelectedItem) - 1;
		if (choosedIndex <= numberOfThreads)
		{
			comboBox2->Visible = true;
			button1->Visible = true;
			button2->Visible = true;
			button3->Visible = true;
		}
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox2->SelectedIndex)
		{
		case 0:
			SetThreadPriority(myHandle[choosedIndex], -15);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "Idle";
			break;
		case 1:
			SetThreadPriority(myHandle[choosedIndex], -1);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "Below normal";
			break;
		case 2:
			SetThreadPriority(myHandle[choosedIndex], 0);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "Normal";
			break;
		case 3:
			SetThreadPriority(myHandle[choosedIndex], 1);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "Above normal";
			break;
		case 4:
			SetThreadPriority(myHandle[choosedIndex], 2);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "High";
			break;
		case 5:
			SetThreadPriority(myHandle[choosedIndex], 15);
			Grid1->Rows[choosedIndex]->Cells[2]->Value = "Real time";
			break;
		default:
			break;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		TerminateThread(myHandle[choosedIndex], 0);
		Grid1->Rows[choosedIndex]->Cells[3]->Value = "Terminated";
		comboBox2->Visible = false;
		button1->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ResumeThread(myHandle[choosedIndex]);
		Grid1->Rows[choosedIndex]->Cells[3]->Value = "Running";
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SuspendThread(myHandle[choosedIndex]);
		Grid1->Rows[choosedIndex]->Cells[3]->Value = "Suspended";
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//timer1->Enabled = true;
		timer1->Start();
		for (size_t i = 0; i < numberOfThreads; i++)
		{
			ResumeThread(myHandle[i]);
		}
		WaitForMultipleObjects(numberOfThreads, myHandle, TRUE, INFINITE);
		for (size_t i = 0; i < numberOfThreads; i++)
		{
			Grid1->Rows[i]->Cells[3]->Value = "Finished";
		}
		timer1->Stop();
		//timer1->Enabled = false;
		label5->Text = "Time: " + Convert::ToString(milliseconds);
		milliseconds = 0;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		milliseconds += 1;
	}
	};
}
