#include "Credit.h"

namespace lab08 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Percent
	/// </summary>
	public ref class Percent : public System::Windows::Forms::Form
	{
	public:
		Percent(void)
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
		~Percent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox7;
	protected:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;



	protected:

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
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(268, 435);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(138, 38);
			this->textBox7->TabIndex = 31;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(7, 444);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(255, 29);
			this->label7->TabIndex = 30;
			this->label7->Text = L"Лишилось оплатити:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(200, 386);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(138, 38);
			this->textBox6->TabIndex = 29;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(6, 395);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(188, 29);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Уже оплачено:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 337);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(672, 43);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Оплатити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Percent::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(247, 244);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(138, 38);
			this->textBox5->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(11, 244);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(236, 29);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Кількість платежів:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(339, 194);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(138, 38);
			this->textBox4->TabIndex = 24;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(11, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(322, 29);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Сума оплати з відсотками:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 145);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(672, 43);
			this->button1->TabIndex = 22;
			this->button1->Text = L"Порахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Percent::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(551, 24);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 38);
			this->textBox3->TabIndex = 21;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(338, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 29);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Грошей на карті:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(344, 65);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 38);
			this->textBox2->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(11, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(327, 29);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Час, за який треба віддати:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(194, 24);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 38);
			this->textBox1->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 29);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Сума кредиту:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label8->Location = System::Drawing::Point(18, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(119, 29);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Відсоток:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(143, 101);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(138, 38);
			this->textBox8->TabIndex = 33;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label9->Location = System::Drawing::Point(391, 244);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(220, 29);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Відсоток від суми:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(617, 244);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(66, 38);
			this->textBox9->TabIndex = 35;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(327, 294);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(138, 38);
			this->textBox10->TabIndex = 37;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label10->Location = System::Drawing::Point(12, 294);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(309, 29);
			this->label10->TabIndex = 36;
			this->label10->Text = L"Сума рівномірної оплати:";
			// 
			// Percent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 489);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label8);
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
			this->Name = L"Percent";
			this->Text = L"Percent";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double sumToPay, moneyOnCard, percentToPay;
		int timeToPay;
		sumToPay = Convert::ToDouble(textBox1->Text);
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		timeToPay = Convert::ToInt16(textBox2->Text);
		percentToPay = Convert::ToDouble(textBox8->Text);
		PercentPayment a(sumToPay, moneyOnCard, percentToPay, timeToPay);
		textBox9->Text = Convert::ToString(a.PaymentPrecent());
		textBox4->Text = Convert::ToString(a.PercentSum());
		textBox5->Text = Convert::ToString(timeToPay);
		textBox6->Text = Convert::ToString(a.alreadyPayed);
		textBox7->Text = Convert::ToString(a.needToPay);
		textBox10->Text = Convert::ToString(a.EqualPartsPayment());
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double sumToPay, moneyOnCard, alreadyPayed, needToPay;
		int timeToPay;
		sumToPay = Convert::ToDouble(textBox10->Text);
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		timeToPay = Convert::ToInt16(textBox5->Text);
		alreadyPayed = Convert::ToDouble(textBox6->Text);
		needToPay = Convert::ToDouble(textBox7->Text);
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
