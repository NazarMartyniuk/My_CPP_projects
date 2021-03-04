#pragma once
#include "classes.h"

namespace lab09 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Standart
	/// </summary>
	public ref class Standart : public System::Windows::Forms::Form
	{
	public:
		Standart(void)
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
		~Standart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::RichTextBox^ yourMoney;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ comision;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ transactionHistory;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ addMoney;
	private: System::Windows::Forms::Button^ addToAcc;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RichTextBox^ cartNumber;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RichTextBox^ moneyToTransfer;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;


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
			this->yourMoney = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comision = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->transactionHistory = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->addMoney = (gcnew System::Windows::Forms::RichTextBox());
			this->addToAcc = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cartNumber = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->moneyToTransfer = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ваші гроші:";
			// 
			// yourMoney
			// 
			this->yourMoney->Location = System::Drawing::Point(164, 13);
			this->yourMoney->Name = L"yourMoney";
			this->yourMoney->ReadOnly = true;
			this->yourMoney->Size = System::Drawing::Size(116, 25);
			this->yourMoney->TabIndex = 1;
			this->yourMoney->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(286, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Комісія:";
			// 
			// comision
			// 
			this->comision->Location = System::Drawing::Point(397, 12);
			this->comision->Name = L"comision";
			this->comision->ReadOnly = true;
			this->comision->Size = System::Drawing::Size(116, 25);
			this->comision->TabIndex = 3;
			this->comision->Text = L"2%";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(593, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(225, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Історія транзакцій";
			// 
			// transactionHistory
			// 
			this->transactionHistory->Location = System::Drawing::Point(571, 44);
			this->transactionHistory->Name = L"transactionHistory";
			this->transactionHistory->ReadOnly = true;
			this->transactionHistory->Size = System::Drawing::Size(271, 238);
			this->transactionHistory->TabIndex = 5;
			this->transactionHistory->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(191, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Дії з рахунком";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(12, 112);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(245, 29);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Поповнити рахунок:";
			// 
			// addMoney
			// 
			this->addMoney->Location = System::Drawing::Point(263, 116);
			this->addMoney->Name = L"addMoney";
			this->addMoney->Size = System::Drawing::Size(116, 25);
			this->addMoney->TabIndex = 8;
			this->addMoney->Text = L"";
			// 
			// addToAcc
			// 
			this->addToAcc->Location = System::Drawing::Point(385, 116);
			this->addToAcc->Name = L"addToAcc";
			this->addToAcc->Size = System::Drawing::Size(128, 23);
			this->addToAcc->TabIndex = 9;
			this->addToAcc->Text = L"Поповнити";
			this->addToAcc->UseVisualStyleBackColor = true;
			this->addToAcc->Click += gcnew System::EventHandler(this, &Standart::addToAcc_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(12, 178);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(266, 29);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Надіслати на рахунок:";
			// 
			// cartNumber
			// 
			this->cartNumber->Location = System::Drawing::Point(449, 182);
			this->cartNumber->Name = L"cartNumber";
			this->cartNumber->Size = System::Drawing::Size(116, 25);
			this->cartNumber->TabIndex = 11;
			this->cartNumber->Text = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(275, 178);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(168, 29);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Номер карти:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label8->Location = System::Drawing::Point(116, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(193, 29);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Сума переводу:";
			// 
			// moneyToTransfer
			// 
			this->moneyToTransfer->Location = System::Drawing::Point(315, 230);
			this->moneyToTransfer->Name = L"moneyToTransfer";
			this->moneyToTransfer->Size = System::Drawing::Size(116, 25);
			this->moneyToTransfer->TabIndex = 14;
			this->moneyToTransfer->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(437, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Надіслати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Standart::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(361, 261);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(204, 21);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"Включити комісію в платіж";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// Standart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(854, 290);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->moneyToTransfer);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cartNumber);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->addToAcc);
			this->Controls->Add(this->addMoney);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->transactionHistory);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comision);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->yourMoney);
			this->Controls->Add(this->label1);
			this->Name = L"Standart";
			this->Text = L"Звичайний банківський рахунок";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addToAcc_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double moneyToAdd, moneyOnCard;
		moneyToAdd = Convert::ToDouble(addMoney->Text);
		moneyOnCard = Convert::ToDouble(yourMoney->Text);
		StandartAcc a(moneyOnCard);
		yourMoney->Text = Convert::ToString(a.AddToCard(moneyToAdd, 2));
		transactionHistory->Text += "Вашу карту було поповнено на " + Convert::ToString(moneyToAdd * 98 / 100) + " гривень!\n";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double moneyToSend, moneyOnCard;
		moneyToSend = Convert::ToDouble(moneyToTransfer->Text);
		moneyOnCard = Convert::ToDouble(yourMoney->Text);
		if (cartNumber->Text != "" && moneyOnCard > moneyToSend)
		{
			StandartAcc a(moneyOnCard);
			if (checkBox1->Checked == false)
			{
				yourMoney->Text = Convert::ToString(a.SendToOtherCard(moneyToSend));
				transactionHistory->Text += "На карту з номером " + cartNumber->Text + " було відіслано кошти.\nЗ вашого рахунку було списано " + Convert::ToString(moneyToSend) + " гривень\n";
			}
			else
			{
				yourMoney->Text = Convert::ToString(a.SendToOtherCardWithPercent(moneyToSend, 2));
				transactionHistory->Text += "На карту з номером " + cartNumber->Text + " було відіслано кошти.\nЗ вашого рахунку було списано " + Convert::ToString(moneyToSend * 102 / 100) + " гривень\n";
			}
		}
		else
		{
			transactionHistory->Text += "Транзакція не була закінчена\n";
		}
	}
	};
}
