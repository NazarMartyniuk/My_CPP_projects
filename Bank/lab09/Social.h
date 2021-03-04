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
	/// Сводка для Social
	/// </summary>
	public ref class Social : public System::Windows::Forms::Form
	{
	public:
		Social(void)
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
		~Social()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ checkBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ moneyToTransfer;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RichTextBox^ cartNumber;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ addToAcc;
	private: System::Windows::Forms::RichTextBox^ addMoney;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ transactionHistory;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ comision;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ yourMoney;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button2;

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->moneyToTransfer = (gcnew System::Windows::Forms::RichTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cartNumber = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->addToAcc = (gcnew System::Windows::Forms::Button());
			this->addMoney = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->transactionHistory = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comision = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->yourMoney = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(340, 260);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(204, 21);
			this->checkBox1->TabIndex = 33;
			this->checkBox1->Text = L"Включити комісію в платіж";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(434, 229);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"Надіслати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Social::button1_Click);
			// 
			// moneyToTransfer
			// 
			this->moneyToTransfer->Location = System::Drawing::Point(312, 229);
			this->moneyToTransfer->Name = L"moneyToTransfer";
			this->moneyToTransfer->Size = System::Drawing::Size(116, 25);
			this->moneyToTransfer->TabIndex = 31;
			this->moneyToTransfer->Text = L"";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label8->Location = System::Drawing::Point(113, 225);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(193, 29);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Сума переводу:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(272, 177);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(168, 29);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Номер карти:";
			// 
			// cartNumber
			// 
			this->cartNumber->Location = System::Drawing::Point(446, 181);
			this->cartNumber->Name = L"cartNumber";
			this->cartNumber->Size = System::Drawing::Size(116, 25);
			this->cartNumber->TabIndex = 28;
			this->cartNumber->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(9, 177);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(266, 29);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Надіслати на рахунок:";
			// 
			// addToAcc
			// 
			this->addToAcc->Location = System::Drawing::Point(382, 115);
			this->addToAcc->Name = L"addToAcc";
			this->addToAcc->Size = System::Drawing::Size(128, 23);
			this->addToAcc->TabIndex = 26;
			this->addToAcc->Text = L"Поповнити";
			this->addToAcc->UseVisualStyleBackColor = true;
			this->addToAcc->Click += gcnew System::EventHandler(this, &Social::addToAcc_Click);
			// 
			// addMoney
			// 
			this->addMoney->Location = System::Drawing::Point(260, 115);
			this->addMoney->Name = L"addMoney";
			this->addMoney->Size = System::Drawing::Size(116, 25);
			this->addMoney->TabIndex = 25;
			this->addMoney->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(9, 111);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(245, 29);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Поповнити рахунок:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(188, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 29);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Дії з рахунком";
			// 
			// transactionHistory
			// 
			this->transactionHistory->Location = System::Drawing::Point(568, 43);
			this->transactionHistory->Name = L"transactionHistory";
			this->transactionHistory->ReadOnly = true;
			this->transactionHistory->Size = System::Drawing::Size(271, 280);
			this->transactionHistory->TabIndex = 22;
			this->transactionHistory->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(590, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(225, 29);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Історія транзакцій";
			// 
			// comision
			// 
			this->comision->Location = System::Drawing::Point(394, 11);
			this->comision->Name = L"comision";
			this->comision->ReadOnly = true;
			this->comision->Size = System::Drawing::Size(116, 25);
			this->comision->TabIndex = 20;
			this->comision->Text = L"1%";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(283, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 29);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Комісія:";
			// 
			// yourMoney
			// 
			this->yourMoney->Location = System::Drawing::Point(161, 12);
			this->yourMoney->Name = L"yourMoney";
			this->yourMoney->ReadOnly = true;
			this->yourMoney->Size = System::Drawing::Size(116, 25);
			this->yourMoney->TabIndex = 18;
			this->yourMoney->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(9, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 29);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Ваші гроші:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label9->Location = System::Drawing::Point(9, 294);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 29);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Кешбек:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(124, 298);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(116, 25);
			this->richTextBox1->TabIndex = 35;
			this->richTextBox1->Text = L"0";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(248, 298);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(286, 23);
			this->button2->TabIndex = 36;
			this->button2->Text = L"Вивести кешбек на основний рахунок";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Social::button2_Click);
			// 
			// Social
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 338);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label9);
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
			this->Name = L"Social";
			this->ShowIcon = false;
			this->Text = L"Банківський рахунок \"Соціальний\"";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addToAcc_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double moneyToAdd, moneyOnCard;
		moneyToAdd = Convert::ToDouble(addMoney->Text);
		moneyOnCard = Convert::ToDouble(yourMoney->Text);
		SocialAcc a(moneyOnCard);
		yourMoney->Text = Convert::ToString(a.AddToCard(moneyToAdd, 1));
		transactionHistory->Text = "Ваш рахунок був поповнений на " + Convert::ToString(moneyToAdd) + " гривень\n";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		double moneyToSend, moneyOnCard;
		moneyToSend = Convert::ToDouble(moneyToTransfer->Text);
		moneyOnCard = Convert::ToDouble(yourMoney->Text);
		if (cartNumber->Text != "" && moneyOnCard > moneyToSend)
		{
			SocialAcc a(moneyOnCard);
			if (checkBox1->Checked == false)
			{
				yourMoney->Text = Convert::ToString(a.SendToOtherCard(moneyToSend));
				transactionHistory->Text += "На карту з номером " + cartNumber->Text + " було відіслано кошти.\nЗ вашого рахунку було списано " + Convert::ToString(moneyToSend) + " гривень\n";
				richTextBox1->Text = Convert::ToString(a.cashback + Convert::ToInt16(richTextBox1->Text));
			}
			else
			{
				yourMoney->Text = Convert::ToString(a.SendToOtherCardWithPercent(moneyToSend, 1));
				transactionHistory->Text += "На карту з номером " + cartNumber->Text + " було відіслано кошти.\nЗ вашого рахунку було списано " + Convert::ToString(moneyToSend * 102 / 100) + " гривень\n";
				richTextBox1->Text = Convert::ToString(a.cashback + Convert::ToInt16(richTextBox1->Text));
			}
		}
		else
		{
			transactionHistory->Text += "Транзакція не була закінчена\n";
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		double cashback = Convert::ToDouble(richTextBox1->Text);
		yourMoney->Text = Convert::ToString(Convert::ToDouble(yourMoney->Text) + cashback);
		richTextBox1->Text = "0";
		transactionHistory->Text += "З кешбек-рахунку було списано " + cashback + " гривень\n";
	}
};
}
