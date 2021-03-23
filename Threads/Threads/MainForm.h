#pragma once
#include <Windows.h>
#include <chrono>
#include <iostream>

using namespace std;
HANDLE* hMutex = nullptr; //Вказівник на змінну, в якій буде дескриптор на м'ютекс для синхронізації потоків
HANDLE* handles = nullptr; //Вказівник на змінну, в якій буде дескриптори на потоки
chrono::duration<double> totalTime; //Змінна, в якій буде час, за який виконалось завдання
static int* arr = nullptr; //Масив, з яким ми працюватимемо
int totalMinElem;
bool isFirst = false; //Перевірка, чи це перше проходження по масиві
size_t step; //Кількість кроків для потоку
int** params; //Параметри для функції
void(_stdcall* FuncPtr)(int* currentThread); //Вказівник на функцію, яка буде працювати в потоці

void WINAPI AsyncFunction(int* currentThread) //Функція з синхронізацією
{
	int start = step * (*currentThread);
	int end = step * ((*currentThread) + 1);
	auto startTimer = chrono::high_resolution_clock::now();
	int minElem = arr[start];
	for (size_t i = start; i < end; i++)
	{
		if (minElem > arr[i])
			minElem = arr[i];
	}
	auto endTimer = chrono::high_resolution_clock::now();
	totalTime += endTimer - startTimer;
	cout << "Thread " << *currentThread + 1 << ": min element: " << minElem << endl;
	if (!isFirst)
	{
		isFirst = true;
		totalMinElem = minElem;
	}
	else
		if (totalMinElem > minElem)
			totalMinElem = minElem;
}

void WINAPI SyncFunction(int* currentThread) //Функція без синхронізації
{
	WaitForSingleObject(*hMutex, INFINITE);
	int start = step * (*currentThread);
	int end = step * ((*currentThread) + 1);
	auto startTimer = chrono::high_resolution_clock::now();
	int minElem = arr[start];
	for (size_t i = start; i < end; i++)
	{
		if (minElem > arr[i])
			minElem = arr[i];
	}
	auto endTimer = chrono::high_resolution_clock::now();
	totalTime += endTimer - startTimer;
	cout << "Thread " << *currentThread + 1 << ": min element: " << minElem << endl;
	if (!isFirst)
	{
		isFirst = true;
		totalMinElem = minElem;
	}
	else
		if (totalMinElem > minElem)
			totalMinElem = minElem;
	ReleaseMutex(*hMutex);
}

namespace Threads
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			arraySize_textBox->ForeColor = Color::Gray;
			threadCount_textBox->ForeColor = Color::Gray;
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::RadioButton^ async_radioBttn;
		System::Windows::Forms::RadioButton^ sync_radioBttn;
		System::Windows::Forms::Label^ arraySize_label;
		System::Windows::Forms::GroupBox^ infoPanel_groupBox;
		System::Windows::Forms::TextBox^ time_textBox;
		System::Windows::Forms::Label^ sec_label;
		System::Windows::Forms::Label^ time_label;
		System::Windows::Forms::Button^ runAll_bttn;
		System::Windows::Forms::Label^ threadCount_label;
		System::Windows::Forms::DataGridView^ threadsInfo_dataGridView;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
		System::Windows::Forms::TextBox^ arraySize_textBox;
		System::Windows::Forms::GroupBox^ controlPanel_groupBox;
		System::Windows::Forms::NumericUpDown^ numberOfThread_numUpDwn;
		System::Windows::Forms::Button^ pause_bttn;
		System::Windows::Forms::Button^ run_bttn;
		System::Windows::Forms::ComboBox^ priority_comboBox;
		System::Windows::Forms::Label^ priority_label;
		System::Windows::Forms::Label^ threadNumber_label;
		System::Windows::Forms::Button^ createThreads_bttn;
		System::Windows::Forms::TextBox^ threadCount_textBox;
		System::ComponentModel::Container^ components;
		size_t threadCount;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->async_radioBttn = (gcnew System::Windows::Forms::RadioButton());
			this->sync_radioBttn = (gcnew System::Windows::Forms::RadioButton());
			this->arraySize_label = (gcnew System::Windows::Forms::Label());
			this->infoPanel_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->time_textBox = (gcnew System::Windows::Forms::TextBox());
			this->sec_label = (gcnew System::Windows::Forms::Label());
			this->time_label = (gcnew System::Windows::Forms::Label());
			this->runAll_bttn = (gcnew System::Windows::Forms::Button());
			this->threadCount_label = (gcnew System::Windows::Forms::Label());
			this->threadsInfo_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arraySize_textBox = (gcnew System::Windows::Forms::TextBox());
			this->controlPanel_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->numberOfThread_numUpDwn = (gcnew System::Windows::Forms::NumericUpDown());
			this->pause_bttn = (gcnew System::Windows::Forms::Button());
			this->run_bttn = (gcnew System::Windows::Forms::Button());
			this->priority_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->priority_label = (gcnew System::Windows::Forms::Label());
			this->threadNumber_label = (gcnew System::Windows::Forms::Label());
			this->createThreads_bttn = (gcnew System::Windows::Forms::Button());
			this->threadCount_textBox = (gcnew System::Windows::Forms::TextBox());
			this->infoPanel_groupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsInfo_dataGridView))->BeginInit();
			this->controlPanel_groupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberOfThread_numUpDwn))->BeginInit();
			this->SuspendLayout();
			// 
			// async_radioBttn
			// 
			this->async_radioBttn->AutoSize = true;
			this->async_radioBttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->async_radioBttn->Location = System::Drawing::Point(12, 39);
			this->async_radioBttn->Name = L"async_radioBttn";
			this->async_radioBttn->Size = System::Drawing::Size(63, 20);
			this->async_radioBttn->TabIndex = 44;
			this->async_radioBttn->Text = L"Async";
			this->async_radioBttn->UseVisualStyleBackColor = true;
			// 
			// sync_radioBttn
			// 
			this->sync_radioBttn->AutoSize = true;
			this->sync_radioBttn->Checked = true;
			this->sync_radioBttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sync_radioBttn->Location = System::Drawing::Point(12, 12);
			this->sync_radioBttn->Name = L"sync_radioBttn";
			this->sync_radioBttn->Size = System::Drawing::Size(56, 20);
			this->sync_radioBttn->TabIndex = 43;
			this->sync_radioBttn->TabStop = true;
			this->sync_radioBttn->Text = L"Sync";
			this->sync_radioBttn->UseVisualStyleBackColor = true;
			// 
			// arraySize_label
			// 
			this->arraySize_label->AutoSize = true;
			this->arraySize_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arraySize_label->Location = System::Drawing::Point(108, 11);
			this->arraySize_label->Name = L"arraySize_label";
			this->arraySize_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->arraySize_label->Size = System::Drawing::Size(83, 18);
			this->arraySize_label->TabIndex = 41;
			this->arraySize_label->Text = L"Array size";
			// 
			// infoPanel_groupBox
			// 
			this->infoPanel_groupBox->Controls->Add(this->time_textBox);
			this->infoPanel_groupBox->Controls->Add(this->sec_label);
			this->infoPanel_groupBox->Controls->Add(this->time_label);
			this->infoPanel_groupBox->Enabled = false;
			this->infoPanel_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoPanel_groupBox->Location = System::Drawing::Point(433, 12);
			this->infoPanel_groupBox->Name = L"infoPanel_groupBox";
			this->infoPanel_groupBox->Size = System::Drawing::Size(163, 73);
			this->infoPanel_groupBox->TabIndex = 40;
			this->infoPanel_groupBox->TabStop = false;
			this->infoPanel_groupBox->Text = L"Info panel";
			// 
			// time_textBox
			// 
			this->time_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_textBox->Location = System::Drawing::Point(10, 42);
			this->time_textBox->Name = L"time_textBox";
			this->time_textBox->ReadOnly = true;
			this->time_textBox->Size = System::Drawing::Size(101, 23);
			this->time_textBox->TabIndex = 10;
			// 
			// sec_label
			// 
			this->sec_label->AutoSize = true;
			this->sec_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sec_label->Location = System::Drawing::Point(117, 44);
			this->sec_label->Name = L"sec_label";
			this->sec_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->sec_label->Size = System::Drawing::Size(35, 18);
			this->sec_label->TabIndex = 12;
			this->sec_label->Text = L"sec";
			// 
			// time_label
			// 
			this->time_label->AutoSize = true;
			this->time_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_label->Location = System::Drawing::Point(6, 19);
			this->time_label->Name = L"time_label";
			this->time_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->time_label->Size = System::Drawing::Size(43, 17);
			this->time_label->TabIndex = 11;
			this->time_label->Text = L"Time:";
			// 
			// runAll_bttn
			// 
			this->runAll_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->runAll_bttn->Location = System::Drawing::Point(10, 271);
			this->runAll_bttn->Name = L"runAll_bttn";
			this->runAll_bttn->Size = System::Drawing::Size(73, 30);
			this->runAll_bttn->TabIndex = 39;
			this->runAll_bttn->Text = L"Run all";
			this->runAll_bttn->UseVisualStyleBackColor = true;
			this->runAll_bttn->Click += gcnew System::EventHandler(this, &MainForm::runAll_bttn_Click);
			// 
			// threadCount_label
			// 
			this->threadCount_label->AutoSize = true;
			this->threadCount_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->threadCount_label->Location = System::Drawing::Point(272, 9);
			this->threadCount_label->Name = L"threadCount_label";
			this->threadCount_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->threadCount_label->Size = System::Drawing::Size(112, 18);
			this->threadCount_label->TabIndex = 37;
			this->threadCount_label->Text = L"Thread count:";
			// 
			// threadsInfo_dataGridView
			// 
			this->threadsInfo_dataGridView->AllowUserToAddRows = false;
			this->threadsInfo_dataGridView->AllowUserToDeleteRows = false;
			this->threadsInfo_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->threadsInfo_dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->threadsInfo_dataGridView->Location = System::Drawing::Point(12, 129);
			this->threadsInfo_dataGridView->Name = L"threadsInfo_dataGridView";
			this->threadsInfo_dataGridView->ReadOnly = true;
			this->threadsInfo_dataGridView->RowHeadersVisible = false;
			this->threadsInfo_dataGridView->RowHeadersWidth = 51;
			this->threadsInfo_dataGridView->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->threadsInfo_dataGridView->RowTemplate->Height = 24;
			this->threadsInfo_dataGridView->RowTemplate->ReadOnly = true;
			this->threadsInfo_dataGridView->Size = System::Drawing::Size(408, 265);
			this->threadsInfo_dataGridView->TabIndex = 36;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Thread ID";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 115;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Prioriry";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Status";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 125;
			// 
			// arraySize_textBox
			// 
			this->arraySize_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->arraySize_textBox->Location = System::Drawing::Point(111, 38);
			this->arraySize_textBox->Name = L"arraySize_textBox";
			this->arraySize_textBox->Size = System::Drawing::Size(119, 23);
			this->arraySize_textBox->TabIndex = 35;
			this->arraySize_textBox->Text = L"2";
			this->arraySize_textBox->Enter += gcnew System::EventHandler(this, &MainForm::arraySize_textBox_Enter);
			this->arraySize_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::arraySize_textBox_KeyPress);
			this->arraySize_textBox->Leave += gcnew System::EventHandler(this, &MainForm::arraySize_textBox_Leave);
			// 
			// controlPanel_groupBox
			// 
			this->controlPanel_groupBox->Controls->Add(this->numberOfThread_numUpDwn);
			this->controlPanel_groupBox->Controls->Add(this->pause_bttn);
			this->controlPanel_groupBox->Controls->Add(this->run_bttn);
			this->controlPanel_groupBox->Controls->Add(this->priority_comboBox);
			this->controlPanel_groupBox->Controls->Add(this->priority_label);
			this->controlPanel_groupBox->Controls->Add(this->runAll_bttn);
			this->controlPanel_groupBox->Controls->Add(this->threadNumber_label);
			this->controlPanel_groupBox->Enabled = false;
			this->controlPanel_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->controlPanel_groupBox->Location = System::Drawing::Point(433, 91);
			this->controlPanel_groupBox->Name = L"controlPanel_groupBox";
			this->controlPanel_groupBox->Size = System::Drawing::Size(163, 303);
			this->controlPanel_groupBox->TabIndex = 34;
			this->controlPanel_groupBox->TabStop = false;
			this->controlPanel_groupBox->Text = L"Control panel";
			// 
			// numberOfThread_numUpDwn
			// 
			this->numberOfThread_numUpDwn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numberOfThread_numUpDwn->Location = System::Drawing::Point(10, 58);
			this->numberOfThread_numUpDwn->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numberOfThread_numUpDwn->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numberOfThread_numUpDwn->Name = L"numberOfThread_numUpDwn";
			this->numberOfThread_numUpDwn->Size = System::Drawing::Size(73, 24);
			this->numberOfThread_numUpDwn->TabIndex = 15;
			this->numberOfThread_numUpDwn->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numberOfThread_numUpDwn->ValueChanged += gcnew System::EventHandler(this, &MainForm::numberOfThread_numUpDwn_ValueChanged);
			// 
			// pause_bttn
			// 
			this->pause_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pause_bttn->Location = System::Drawing::Point(10, 222);
			this->pause_bttn->Name = L"pause_bttn";
			this->pause_bttn->Size = System::Drawing::Size(74, 29);
			this->pause_bttn->TabIndex = 14;
			this->pause_bttn->Text = L"Pause";
			this->pause_bttn->UseVisualStyleBackColor = true;
			this->pause_bttn->Click += gcnew System::EventHandler(this, &MainForm::pause_bttn_Click);
			// 
			// run_bttn
			// 
			this->run_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->run_bttn->Location = System::Drawing::Point(9, 173);
			this->run_bttn->Name = L"run_bttn";
			this->run_bttn->Size = System::Drawing::Size(74, 29);
			this->run_bttn->TabIndex = 13;
			this->run_bttn->Text = L"Run";
			this->run_bttn->UseVisualStyleBackColor = true;
			this->run_bttn->Click += gcnew System::EventHandler(this, &MainForm::run_bttn_Click);
			// 
			// priority_comboBox
			// 
			this->priority_comboBox->DisplayMember = L"1";
			this->priority_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->priority_comboBox->FormattingEnabled = true;
			this->priority_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Idle", L"Below normal", L"Normal", L"Above normal",
					L"High"
			});
			this->priority_comboBox->Location = System::Drawing::Point(10, 122);
			this->priority_comboBox->Name = L"priority_comboBox";
			this->priority_comboBox->Size = System::Drawing::Size(123, 28);
			this->priority_comboBox->TabIndex = 12;
			this->priority_comboBox->Text = L"Normal";
			this->priority_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::priority_comboBox_SelectedIndexChanged);
			// 
			// priority_label
			// 
			this->priority_label->AutoSize = true;
			this->priority_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->priority_label->Location = System::Drawing::Point(6, 99);
			this->priority_label->Name = L"priority_label";
			this->priority_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->priority_label->Size = System::Drawing::Size(56, 17);
			this->priority_label->TabIndex = 11;
			this->priority_label->Text = L"Priority:";
			// 
			// threadNumber_label
			// 
			this->threadNumber_label->AutoSize = true;
			this->threadNumber_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->threadNumber_label->Location = System::Drawing::Point(6, 27);
			this->threadNumber_label->Name = L"threadNumber_label";
			this->threadNumber_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->threadNumber_label->Size = System::Drawing::Size(110, 17);
			this->threadNumber_label->TabIndex = 9;
			this->threadNumber_label->Text = L"Thread number:";
			// 
			// createThreads_bttn
			// 
			this->createThreads_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->createThreads_bttn->Location = System::Drawing::Point(111, 75);
			this->createThreads_bttn->Name = L"createThreads_bttn";
			this->createThreads_bttn->Size = System::Drawing::Size(119, 28);
			this->createThreads_bttn->TabIndex = 33;
			this->createThreads_bttn->Text = L"Create threads";
			this->createThreads_bttn->UseVisualStyleBackColor = true;
			this->createThreads_bttn->Click += gcnew System::EventHandler(this, &MainForm::createThreads_bttn_Click);
			// 
			// threadCount_textBox
			// 
			this->threadCount_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->threadCount_textBox->Location = System::Drawing::Point(265, 38);
			this->threadCount_textBox->Name = L"threadCount_textBox";
			this->threadCount_textBox->Size = System::Drawing::Size(119, 23);
			this->threadCount_textBox->TabIndex = 45;
			this->threadCount_textBox->Text = L"1";
			this->threadCount_textBox->Enter += gcnew System::EventHandler(this, &MainForm::threadCount_textBox_Enter);
			this->threadCount_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::arraySize_textBox_KeyPress);
			this->threadCount_textBox->Leave += gcnew System::EventHandler(this, &MainForm::threadCount_textBox_Leave);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(606, 404);
			this->Controls->Add(this->threadCount_textBox);
			this->Controls->Add(this->async_radioBttn);
			this->Controls->Add(this->sync_radioBttn);
			this->Controls->Add(this->arraySize_label);
			this->Controls->Add(this->infoPanel_groupBox);
			this->Controls->Add(this->threadCount_label);
			this->Controls->Add(this->threadsInfo_dataGridView);
			this->Controls->Add(this->arraySize_textBox);
			this->Controls->Add(this->controlPanel_groupBox);
			this->Controls->Add(this->createThreads_bttn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"Lab01";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->infoPanel_groupBox->ResumeLayout(false);
			this->infoPanel_groupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsInfo_dataGridView))->EndInit();
			this->controlPanel_groupBox->ResumeLayout(false);
			this->controlPanel_groupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberOfThread_numUpDwn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region RightInputSettings
	private: System::Void arraySize_textBox_Enter(System::Object^ sender, System::EventArgs^ e) //Цей метод очищає поле вводу розміру масиву, якщо там не було нічого до цього написано
	{
		if (arraySize_textBox->ForeColor == Color::Gray)
		{
			arraySize_textBox->Text = "";
			arraySize_textBox->ForeColor = Color::Black;
		}
	}
	private: System::Void arraySize_textBox_Leave(System::Object^ sender, System::EventArgs^ e) //Цей метод ставить мінімальний розмір масиву, якшо там не було нічого не написано, або якщо там було записано менше мінімального
	{
		if (arraySize_textBox->Text == "")
		{
			arraySize_textBox->ForeColor = Color::Gray;
			arraySize_textBox->Text = "2";
		}
		if (arraySize_textBox->Text == "1" || arraySize_textBox->Text == "0")
		{
			MessageBox::Show("Wrong input. Minimal value: 2");
			arraySize_textBox->Text = "2";
			arraySize_textBox->ForeColor = Color::Gray;
		}
	}
	private: System::Void arraySize_textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) //Цей метод не дозволяє записувати будь-що в поле вводу крім чисел та backspace
	{
		if (!Char::IsDigit(e->KeyChar) && !e->KeyChar.Equals(Convert::ToChar(Keys::Back)))
			e->Handled = true;
		else
			e->Handled = false;
	}
	private: System::Void threadCount_textBox_Enter(System::Object^ sender, System::EventArgs^ e) //Цей метод очищає поле вводу кількості потоків, якщо там не було нічого до цього написано
	{
		if (threadCount_textBox->ForeColor == Color::Gray)
		{
			threadCount_textBox->Text = "";
			threadCount_textBox->ForeColor = Color::Black;
		}
	}
	private: System::Void threadCount_textBox_Leave(System::Object^ sender, System::EventArgs^ e)  //Цей метод ставить мінімальну кількість потоків(якшо 1, то буде лише головний), якшо там не було нічого не написано, або якщо там було записано менше мінімального
	{
		if (threadCount_textBox->Text == "")
		{
			threadCount_textBox->ForeColor = Color::Gray;
			threadCount_textBox->Text = "1";
		}
		if (threadCount_textBox->Text == "0")
		{
			MessageBox::Show("Wrong input. Minimal value: 1");
			threadCount_textBox->Text = "1";
			threadCount_textBox->ForeColor = Color::Gray;
		}
		numberOfThread_numUpDwn->Maximum = Convert::ToInt32(threadCount_textBox->Text);
	}
#pragma endregion
	private: void FreeMemory() //Звільняє пам'ять в дескрипторах і всьому іншому
	{
		if (hMutex)
		{
			CloseHandle(hMutex);
			delete hMutex;
			hMutex = nullptr;
		}
		if (handles)
		{
			for (size_t i = 0; i < threadCount; i++)
				CloseHandle(handles[i]);
			delete[]handles;
			handles = nullptr;
		}
		if (arr)
		{
			delete[]arr;
			arr = nullptr;
		}
		if (params)
		{
			for (size_t i = 0; i < threadCount; i++)
			{
				delete[]params[i];
			}
			delete[]params;
			params = nullptr;
		}
	}
	private: String^ GetPriority(DWORD code) //Цей метод повертає пріоритет потоку по числу, яке ми передали як параметр
	{
		switch (code)
		{
		case 1: return "Above normal";
		case -1: return "Below normal";
		case 0: return "Normal";
		case -15: return "Idle";
		case 2: return "High";
		default: return "";
		}
	}
	private: System::Void createThreads_bttn_Click(System::Object^ sender, System::EventArgs^ e) //Цей метод опрацьовує введені дані та створює потоки
	{
		FreeMemory();
		totalTime = chrono::milliseconds::zero();
		threadCount = Convert::ToInt32(threadCount_textBox->Text);
		threadsInfo_dataGridView->RowCount = threadCount;
		size_t size = Convert::ToInt32(arraySize_textBox->Text);
		handles = new HANDLE[threadCount];
		controlPanel_groupBox->Enabled = true;
		infoPanel_groupBox->Enabled = true;
		numberOfThread_numUpDwn->Maximum = threadCount;
		step = size / threadCount;
		DWORD threadID;
		AllocConsole(); //Створюємо консоль
		AttachConsole(GetCurrentProcessId());
		freopen("CON", "w", stdout);
		params = new int* [threadCount];
		for (size_t i = 0; i < threadCount; i++)
		{
			params[i] = new int;
			params[i][0] = i;
		}
		if (sync_radioBttn->Checked)
		{
			FuncPtr = SyncFunction;
			cout << "=================================================  SYNC ARRAY SEARCHING  ===============================================\n";
			hMutex = new HANDLE;
			*hMutex = CreateMutexA(nullptr, FALSE, nullptr);

		}
		else
		{
			FuncPtr = AsyncFunction;
			cout << "=================================================  ASYNC ARRAY SEARCHING  ===============================================\n";
		}
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 501 - 250;
			cout << arr[i] << " ";
		}
		cout << endl;
		for (size_t i = 0; i < threadCount; i++)
		{
			if (!(handles[i] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FuncPtr, params[i], CREATE_SUSPENDED, &threadID)))
				MessageBox::Show("Error, thread wasn't created");
			threadsInfo_dataGridView->Rows[i]->Cells[0]->Value = i + 1;
			threadsInfo_dataGridView->Rows[i]->Cells[1]->Value = threadID;
			threadsInfo_dataGridView->Rows[i]->Cells[2]->Value = GetPriority(GetThreadPriority(handles[i]));
			threadsInfo_dataGridView->Rows[i]->Cells[3]->Value = "Suspended";
		}
	}
	private: System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) //Цей метод спрацьовує при закритті програми і звільняє всю динамічно виділену пам'ять
	{
		FreeMemory();
	}
	private: System::Void numberOfThread_numUpDwn_ValueChanged(System::Object^ sender, System::EventArgs^ e) //Цей метод ніби ставить вказівник на той потік, з яким ми хочемо працювати
	{
		if (threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[3]->Value == "Finished")
		{
			run_bttn->Enabled = false;
			pause_bttn->Enabled = false;
			priority_comboBox->Enabled = false;
			return;
		}
		else
		{
			run_bttn->Enabled = true;
			pause_bttn->Enabled = true;
			priority_comboBox->Enabled = true;
		}
		switch (GetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]))
		{
		case 1: priority_comboBox->SelectedIndex = 3; break;
		case -1: priority_comboBox->SelectedIndex = 1; break;
		case 0: priority_comboBox->SelectedIndex = 2; break;
		case -15: priority_comboBox->SelectedIndex = 0; break;
		case 2: priority_comboBox->SelectedIndex = 4; break;
		}
	}
	private: System::Void priority_comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) //Зміна пріоритету потока
	{
		switch (priority_comboBox->SelectedIndex)
		{
		case 0:
		{
			SetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1], -15);
			threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[2]->Value = "Idle";
			break;
		}
		case 1:
		{
			SetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1], -1);
			threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[2]->Value = "Below normal";
			break;
		}
		case 2:
		{
			SetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1], -0);
			threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[2]->Value = "Normal";
			break;
		}
		case 3:
		{
			SetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1], 1);
			threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[2]->Value = "Above normal";
			break;
		}
		case 4:
		{
			SetThreadPriority(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1], 2);
			threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[2]->Value = "High";
			break;
		}
		}
	}
	private: System::Void run_bttn_Click(System::Object^ sender, System::EventArgs^ e) //Цей метод запускає в дію один виділений поток
	{
		threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[3]->Value = "Running";
		ResumeThread(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]);
	}
	private: System::Void pause_bttn_Click(System::Object^ sender, System::EventArgs^ e) //Цей метод зупиняє виконання виідленого потоку
	{
		threadsInfo_dataGridView->Rows[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]->Cells[3]->Value = "Suspended";
		SuspendThread(handles[Convert::ToInt32(numberOfThread_numUpDwn->Value) - 1]);
	}
	private: System::Void runAll_bttn_Click(System::Object^ sender, System::EventArgs^ e) //Цей метод запускає одночасно всі потоки
	{
		totalMinElem = 0;
		int handleCounter = 0;
		HANDLE threadHandles[16];
		for (size_t i = 0; i < threadCount; i++)
		{
			if (threadsInfo_dataGridView->Rows[i]->Cells[3]->Value == "Finished")
				continue;
			threadHandles[handleCounter++] = handles[i];
		}
		for (size_t i = 0; i < threadCount; i++)
		{
			if (threadsInfo_dataGridView->Rows[i]->Cells[3]->Value == "Finished")
				continue;
			threadsInfo_dataGridView->Rows[i]->Cells[3]->Value = "Running";
			ResumeThread(handles[i]);
		}
		WaitForMultipleObjects(handleCounter, threadHandles, TRUE, INFINITE);
		cout << "Total minimal element = " << totalMinElem << endl;
		time_textBox->Text = Convert::ToString(totalTime.count());
		for (size_t i = 0; i < threadCount; i++)
		{
			threadsInfo_dataGridView->Rows[i]->Cells[3]->Value = "Finished";
		}
	}
	};
}
