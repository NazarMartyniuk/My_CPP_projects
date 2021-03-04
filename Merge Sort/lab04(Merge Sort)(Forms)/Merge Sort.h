#pragma once
#include "MergeSort.h"

namespace lab04MergeSortForms {

	size_t milliseconds = 0;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MergeSort
	/// </summary>
	public ref class MergeSort : public System::Windows::Forms::Form
	{
	public:
		MergeSort(void)
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
		~MergeSort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Timer^ timer1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose count of rows:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Choose count of cols:";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10"
			});
			this->comboBox1->Location = System::Drawing::Point(166, 6);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 2;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10"
			});
			this->comboBox2->Location = System::Drawing::Point(162, 38);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(313, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 67);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Create matrix";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MergeSort::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 127);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(363, 275);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(381, 127);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(372, 275);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(191, 408);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(372, 275);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(111, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Your matrix";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(514, 107);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(138, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Individual task matrix";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(94, 547);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Sorted matrix";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(441, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(111, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Time for sorting:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(558, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 12;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MergeSort::timer1_Tick);
			// 
			// MergeSort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(765, 695);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MergeSort";
			this->ShowIcon = false;
			this->Text = L"MergeSort";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		size_t rows = Convert::ToUInt32(comboBox1->SelectedItem);
		size_t cols = Convert::ToUInt32(comboBox2->SelectedItem);
		MergeSorting sorting(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				textBox1->Text += Convert::ToString(sorting.GetMatr()[i][j]) + " ";
			}
			textBox1->Text += Environment::NewLine;
		}
		sorting.IndividualTask();
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				textBox2->Text += Convert::ToString(sorting.GetMatr()[i][j]) + " ";
			}
			textBox2->Text += Environment::NewLine;
		}
		timer1->Start();
		sorting.MergeSort(0, rows - 1);
		timer1->Stop();
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				textBox3->Text += Convert::ToString(sorting.GetMatr()[i][j]) + " ";
			}
			textBox3->Text += Environment::NewLine;
		}
		label7->Text = Convert::ToString(milliseconds);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		milliseconds++;
	}
};
}
