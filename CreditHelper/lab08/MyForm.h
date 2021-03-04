#pragma once
#include "Parts.h"
#include "Percent.h"
#include "Privilege.h"
#include "Credit.h"

namespace lab08 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	string sentence = "This program is using:\n";

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button4;


	private:
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(39, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Оберіть тип кредиту:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(42, 83);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Кредит \"Рівні частини\"";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(42, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(259, 34);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Кредит \"З відсотками\"";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(42, 163);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(259, 34);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Кредит \"Пільговий\"";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(467, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(281, 189);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"This program is using:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(386, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 189);
			this->button4->TabIndex = 5;
			this->button4->Text = L"print->";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 218);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Parts^ F2;
		F2 = gcnew Parts();
		F2->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Percent^ F2;
		F2 = gcnew Percent();
		F2->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Privilege^ F2;
		F2 = gcnew Privilege();
		F2->ShowDialog();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text += "\n Credit EqualParts PercentPayment PrivilegePayment";
		button4->Enabled = false;
	}
	};
}
