#pragma once
#include "Standart.h"
#include "Social.h"
#include "vip.h"
#include "classes.h"

namespace lab09 {

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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ standart;
	private: System::Windows::Forms::Button^ social;
	private: System::Windows::Forms::Button^ VIP;
	protected:






	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->standart = (gcnew System::Windows::Forms::Button());
			this->social = (gcnew System::Windows::Forms::Button());
			this->VIP = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(161, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ќбер≥ть ваш рахунок:";
			// 
			// standart
			// 
			this->standart->Location = System::Drawing::Point(12, 41);
			this->standart->Name = L"standart";
			this->standart->Size = System::Drawing::Size(555, 48);
			this->standart->TabIndex = 1;
			this->standart->Text = L"«вичайний";
			this->standart->UseVisualStyleBackColor = true;
			this->standart->Click += gcnew System::EventHandler(this, &MyForm::standart_Click);
			// 
			// social
			// 
			this->social->Location = System::Drawing::Point(12, 95);
			this->social->Name = L"social";
			this->social->Size = System::Drawing::Size(555, 48);
			this->social->TabIndex = 2;
			this->social->Text = L"—оц≥альний";
			this->social->UseVisualStyleBackColor = true;
			this->social->Click += gcnew System::EventHandler(this, &MyForm::social_Click);
			// 
			// VIP
			// 
			this->VIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->VIP->Location = System::Drawing::Point(12, 149);
			this->VIP->Name = L"VIP";
			this->VIP->Size = System::Drawing::Size(555, 48);
			this->VIP->TabIndex = 3;
			this->VIP->Text = L"|-->VIP<--|";
			this->VIP->UseVisualStyleBackColor = true;
			this->VIP->Click += gcnew System::EventHandler(this, &MyForm::VIP_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(579, 205);
			this->Controls->Add(this->VIP);
			this->Controls->Add(this->social);
			this->Controls->Add(this->standart);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Ѕанк≥вський рахунок";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void standart_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Standart^ newForm = gcnew Standart;
		newForm->Show();
	}
	private: System::Void social_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Social^ newForm = gcnew Social;
		newForm->Show();
	}
	private: System::Void VIP_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		vip^ newForm = gcnew vip;
		newForm->Show();
	}
};
}
