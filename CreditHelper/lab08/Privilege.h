#pragma once
#include "Credit.h"
namespace lab08 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Privilege
	/// </summary>
	public ref class Privilege : public System::Windows::Forms::Form
	{
	public:
		Privilege(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Privilege()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox8;
	protected:
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
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
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox10;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
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
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(268, 96);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(138, 38);
			this->textBox8->TabIndex = 51;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label8->Location = System::Drawing::Point(21, 105);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(241, 29);
			this->label8->TabIndex = 50;
			this->label8->Text = L"ϳ������� �������:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(271, 434);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(138, 38);
			this->textBox7->TabIndex = 49;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(10, 443);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(255, 29);
			this->label7->TabIndex = 48;
			this->label7->Text = L"�������� ��������:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(203, 385);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(138, 38);
			this->textBox6->TabIndex = 47;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(9, 394);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(188, 29);
			this->label6->TabIndex = 46;
			this->label6->Text = L"��� ��������:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 336);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(672, 43);
			this->button2->TabIndex = 45;
			this->button2->Text = L"��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Privilege::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(554, 239);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(138, 38);
			this->textBox5->TabIndex = 44;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(14, 239);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(236, 29);
			this->label5->TabIndex = 43;
			this->label5->Text = L"ʳ������ �������:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(305, 189);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(138, 38);
			this->textBox4->TabIndex = 42;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(14, 189);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(285, 29);
			this->label4->TabIndex = 41;
			this->label4->Text = L"���� ������ � ������:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 140);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(672, 43);
			this->button1->TabIndex = 40;
			this->button1->Text = L"����������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Privilege::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(554, 19);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 38);
			this->textBox3->TabIndex = 39;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(341, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 29);
			this->label3->TabIndex = 38;
			this->label3->Text = L"������ �� ����:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(347, 51);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 38);
			this->textBox2->TabIndex = 37;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(14, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(327, 29);
			this->label2->TabIndex = 36;
			this->label2->Text = L"���, �� ���� ����� ������:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(197, 19);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 38);
			this->textBox1->TabIndex = 35;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(15, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 29);
			this->label1->TabIndex = 34;
			this->label1->Text = L"���� �������:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label9->Location = System::Drawing::Point(14, 293);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(215, 29);
			this->label9->TabIndex = 52;
			this->label9->Text = L"̳������ �����:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(231, 292);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(138, 38);
			this->textBox9->TabIndex = 53;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label10->Location = System::Drawing::Point(389, 239);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(159, 29);
			this->label10->TabIndex = 54;
			this->label10->Text = L"���� �����:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(256, 239);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(138, 38);
			this->textBox10->TabIndex = 55;
			// 
			// Privilege
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 481);
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
			this->Name = L"Privilege";
			this->Text = L"Privilege";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double sumToPay, moneyOnCard, privilegePrecent;
		int timeToPay;
		sumToPay = Convert::ToDouble(textBox1->Text);
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		privilegePrecent = Convert::ToDouble(textBox8->Text);
		timeToPay = Convert::ToInt16(textBox2->Text);
		PrivilegePayment a(sumToPay, moneyOnCard, privilegePrecent, timeToPay);
		textBox5->Text = Convert::ToString(a.PaymentPrecent());
		textBox4->Text = Convert::ToString(a.PrivilegeSum());
		textBox10->Text = Convert::ToString(timeToPay);
		textBox9->Text = Convert::ToString(a.EqualPartsPayment());
		textBox6->Text = Convert::ToString(a.alreadyPayed);
		textBox7->Text = Convert::ToString(a.needToPay);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double sumToPay, moneyOnCard, needToPay, alreadyPayed;
		int timeToPay;
		sumToPay = Convert::ToDouble(textBox9->Text);
		moneyOnCard = Convert::ToDouble(textBox3->Text);
		timeToPay = Convert::ToInt16(textBox10->Text);
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
		textBox6->Text = Convert::ToString(alreadyPayed);
		textBox7->Text = Convert::ToString(needToPay);
		textBox10->Text = Convert::ToString(timeToPay);
	}
	};
}
