#include "Credit.h"

namespace lab08 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Parts
	/// </summary>
	public ref class Parts : public System::Windows::Forms::Form
	{
	public:
		Parts(void)
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
		~Parts()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Сума кредиту:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(194, 19);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 38);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(11, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(327, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Час, за який треба віддати:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(344, 60);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 38);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(338, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Грошей на карті:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(551, 19);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 38);
			this->textBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(672, 43);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Порахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Parts::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(12, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(309, 29);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Сума рівномірної оплати:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(327, 160);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(138, 38);
			this->textBox4->TabIndex = 8;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Parts::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(12, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(236, 29);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Кількість платежів:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(248, 210);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(138, 38);
			this->textBox5->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 254);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(672, 43);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Оплатити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Parts::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(11, 327);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(188, 29);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Уже оплачено:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(205, 318);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(138, 38);
			this->textBox6->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(12, 376);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(255, 29);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Лишилось оплатити:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(273, 367);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(138, 38);
			this->textBox7->TabIndex = 15;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Parts::textBox7_TextChanged);
			// 
			// Parts
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 435);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Parts";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double sumToPay, moneyOnCard;
		int timeToPay;
		sumToPay = Convert::ToDouble(textBox1->Text);
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		timeToPay = Convert::ToInt16(textBox2->Text);
		EqualParts a(sumToPay, moneyOnCard, timeToPay);
		double equalPartPayment = a.EqualPartsPayment();
		textBox4->Text = Convert::ToString(equalPartPayment);
		textBox5->Text = Convert::ToString(a.paymentCount);
		textBox6->Text = Convert::ToString(a.alreadyPayed);
		textBox7->Text = Convert::ToString(a.needToPay);
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		double moneyOnCard, needToPay, alreadyPayed, sumToPay;
		int timeToPay;
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		needToPay = Convert::ToDouble(textBox7->Text);
		alreadyPayed = Convert::ToDouble(textBox6->Text);
		sumToPay = Convert::ToDouble(textBox4->Text);
		timeToPay = Convert::ToInt16(textBox5->Text);
		if (moneyOnCard > sumToPay&& timeToPay != 0)
		{
			moneyOnCard -= sumToPay;
			timeToPay -= 1;
			alreadyPayed += sumToPay;
			needToPay -= sumToPay;
		}
		textBox3->Text = Convert::ToString(moneyOnCard);
		textBox5->Text = Convert::ToString(timeToPay);
		textBox6->Text = Convert::ToString(alreadyPayed);
		textBox7->Text = Convert::ToString(needToPay);
	}
};
}
