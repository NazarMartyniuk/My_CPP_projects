#pragma once
#include <iostream>
#include "Complex.h"

namespace lab05 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;





	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;



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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->textBox1->Location = System::Drawing::Point(19, 46);
			this->textBox1->MaxLength = 3;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(95, 52);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(120, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"+";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->textBox2->Location = System::Drawing::Point(156, 46);
			this->textBox2->MaxLength = 3;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(95, 52);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label2->Location = System::Drawing::Point(257, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 31);
			this->label2->TabIndex = 3;
			this->label2->Text = L"i";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label3->Location = System::Drawing::Point(26, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 31);
			this->label3->TabIndex = 4;
			this->label3->Text = L"   a       +       b      i";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label7->Location = System::Drawing::Point(47, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(181, 31);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Перше число";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label4->Location = System::Drawing::Point(380, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(169, 31);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Друге число";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label5->Location = System::Drawing::Point(359, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(227, 31);
			this->label5->TabIndex = 15;
			this->label5->Text = L"   a       +       b      i";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label6->Location = System::Drawing::Point(590, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 31);
			this->label6->TabIndex = 14;
			this->label6->Text = L"i";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->textBox3->Location = System::Drawing::Point(489, 46);
			this->textBox3->MaxLength = 3;
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(95, 52);
			this->textBox3->TabIndex = 13;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label8->Location = System::Drawing::Point(453, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 31);
			this->label8->TabIndex = 12;
			this->label8->Text = L"+";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->textBox4->Location = System::Drawing::Point(352, 46);
			this->textBox4->MaxLength = 3;
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(95, 52);
			this->textBox4->TabIndex = 11;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label9->Location = System::Drawing::Point(12, 198);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 31);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Сума: ";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->button1->Location = System::Drawing::Point(217, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 39);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Порахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label10->Location = System::Drawing::Point(98, 198);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 31);
			this->label10->TabIndex = 19;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label11->Location = System::Drawing::Point(12, 238);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(128, 31);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Різниця: ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label12->Location = System::Drawing::Point(136, 238);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 31);
			this->label12->TabIndex = 21;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label13->Location = System::Drawing::Point(13, 279);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(135, 31);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Добуток: ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label14->Location = System::Drawing::Point(142, 279);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 31);
			this->label14->TabIndex = 23;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label15->Location = System::Drawing::Point(15, 321);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(408, 31);
			this->label15->TabIndex = 24;
			this->label15->Text = L"Піднесення до n-го степеня: n=";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->textBox5->Location = System::Drawing::Point(443, 305);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(55, 55);
			this->textBox5->TabIndex = 25;
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label16->Location = System::Drawing::Point(359, 366);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(184, 31);
			this->label16->TabIndex = 26;
			this->label16->Text = L"Друге число: ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label17->Location = System::Drawing::Point(15, 366);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(196, 31);
			this->label17->TabIndex = 27;
			this->label17->Text = L"Перше число: ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label18->Location = System::Drawing::Point(538, 366);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 31);
			this->label18->TabIndex = 28;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label19->Location = System::Drawing::Point(201, 366);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 31);
			this->label19->TabIndex = 29;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label20->Location = System::Drawing::Point(15, 408);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(125, 31);
			this->label20->TabIndex = 30;
			this->label20->Text = L"Модуль: ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label21->Location = System::Drawing::Point(15, 452);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(196, 31);
			this->label21->TabIndex = 31;
			this->label21->Text = L"Перше число: ";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label22->Location = System::Drawing::Point(17, 495);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(184, 31);
			this->label22->TabIndex = 32;
			this->label22->Text = L"Друге число: ";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label23->Location = System::Drawing::Point(201, 452);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(0, 31);
			this->label23->TabIndex = 33;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label24->Location = System::Drawing::Point(188, 495);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(0, 31);
			this->label24->TabIndex = 34;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label25->Location = System::Drawing::Point(15, 540);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(560, 31);
			this->label25->TabIndex = 35;
			this->label25->Text = L"Представлення в тригонометричній формі: ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label26->Location = System::Drawing::Point(17, 580);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(196, 31);
			this->label26->TabIndex = 36;
			this->label26->Text = L"Перше число: ";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label27->Location = System::Drawing::Point(17, 621);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(184, 31);
			this->label27->TabIndex = 37;
			this->label27->Text = L"Друге число: ";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label28->Location = System::Drawing::Point(211, 580);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(0, 31);
			this->label28->TabIndex = 38;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label29->Location = System::Drawing::Point(201, 621);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(0, 31);
			this->label29->TabIndex = 39;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(696, 899);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ComplexHelper";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			if (textBox1->Text != "" || textBox2->Text != "" || textBox3->Text != "" || textBox4->Text != "")
			{
				double validNumb1, validNumb2, imaginaryNumb1, imaginaryNumb2;
				int power;
				validNumb1 = Convert::ToDouble(textBox1->Text);
				validNumb2 = Convert::ToDouble(textBox4->Text);
				imaginaryNumb1 = Convert::ToDouble(textBox2->Text);
				imaginaryNumb2 = Convert::ToDouble(textBox3->Text);
				power = Convert::ToInt16(textBox5->Text);
				Complex a(validNumb1, validNumb2, imaginaryNumb1, imaginaryNumb2);
				Complex b(validNumb1, imaginaryNumb1, power);
				Complex c(validNumb2, imaginaryNumb2, power);
				label10->Text = Convert::ToString(a.ValidSum()) + "+" + Convert::ToString(a.ImaginarySum()) + "i";
				label12->Text = Convert::ToString(a.ValidSubtraction()) + "+" + Convert::ToString(a.ImaginarySubtraction()) + "i";
				label14->Text = Convert::ToString(a.ValidMultiplication()) + "+" + Convert::ToString(a.ImaginaryMultiplication()) + "i";
				try
				{
					if (textBox5->Text != "")
					{
						label19->Text = Convert::ToString(b.ValidPower() + "+" + b.ImaginaryPower()+"i");
						label18->Text = Convert::ToString(c.ValidPower() + "+" + c.ImaginaryPower() + "i");
					}
				}
				catch (...)
				{
					label19->Text = "Error";
					label18->Text = "Error";
				}
				label23->Text = Convert::ToString(b.Module());
				label24->Text = Convert::ToString(c.Module());
				label28->Text = Convert::ToString(b.Module() + "(" + b.TrigonometricFormCosinus() + "+i" + b.TrigonometricFormSinus() + ")");
				label29->Text = Convert::ToString(c.Module() + "(" + c.TrigonometricFormCosinus() + "+i" + c.TrigonometricFormSinus() + ")");
			}
		}
		catch (...)
		{
			textBox1->Text = "Error";
			textBox2->Text = "Error";
			textBox3->Text = "Error";
			textBox4->Text = "Error";
		}
	}
	};
}
