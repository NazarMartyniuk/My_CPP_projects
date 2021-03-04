#pragma once
#include "HandleStack.h"
#include <iostream>
namespace lab07 {
	HandleStack elem;
	size_t counter = 0;
	int j = 0;
	bool checker = false;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;



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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(376, 190);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(376, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Зчитати дані з таблиці";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(394, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(216, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введіть розмір стеку:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(619, 9);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(52, 35);
			this->textBox1->TabIndex = 3;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(758, 12);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(376, 190);
			this->dataGridView2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(677, 9);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 35);
			this->button2->TabIndex = 5;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(394, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введіть скаляр:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(558, 64);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 35);
			this->textBox2->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(628, 64);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 35);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Порахувати";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(399, 116);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(64, 35);
			this->textBox3->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(469, 116);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(283, 35);
			this->button4->TabIndex = 10;
			this->button4->Text = L"<- Додати це число до списку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(399, 167);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(353, 35);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Видалити останнє число зі списку";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(399, 208);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(353, 35);
			this->textBox4->TabIndex = 12;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(399, 249);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(353, 35);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Знайти максимальне";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(399, 290);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(353, 35);
			this->button7->TabIndex = 14;
			this->button7->Text = L"Знайти мінімальне";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(399, 331);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(353, 35);
			this->button8->TabIndex = 15;
			this->button8->Text = L"Знайти середнє арифметичне";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(399, 372);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(353, 35);
			this->button9->TabIndex = 16;
			this->button9->Text = L"Очистити стек";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(399, 413);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(353, 35);
			this->button10->TabIndex = 17;
			this->button10->Text = L"Перевірити чи стек пустий";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->listBox1->Location = System::Drawing::Point(12, 237);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(376, 164);
			this->listBox1->TabIndex = 18;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(758, 208);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(376, 164);
			this->listBox2->TabIndex = 19;
			// 
			// button11
			// 
			this->button11->Enabled = false;
			this->button11->Location = System::Drawing::Point(12, 407);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(376, 41);
			this->button11->TabIndex = 20;
			this->button11->Text = L"Додати число";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(758, 379);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(376, 69);
			this->richTextBox1->TabIndex = 21;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1146, 460);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"Stack";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		dataGridView1->ColumnCount = Convert::ToInt16(textBox1->Text);
		dataGridView1->RowCount = 1;
		dataGridView2->ColumnCount = Convert::ToInt16(textBox1->Text);
		dataGridView2->RowCount = 1;
		int size = Convert::ToInt16(textBox1->Text);
		HandleStack elem1(size);
		elem = elem1;
		button1->Enabled = true;
		button11->Enabled = true;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (checker == false)
		{
			for (size_t i = 0; i < elem.size; i++)
			{
				elem.mass[i] = Convert::ToInt16(dataGridView1->Rows[0]->Cells[i]->Value);
				listBox2->Items->Add(Convert::ToString(elem.mass[i]));
				richTextBox1->Text = richTextBox1->Text + " " + Convert::ToString(elem.mass[i]);
				dataGridView2->Rows[0]->Cells[i]->Value = elem.mass[i];
			}
			checker = true;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		elem* Convert::ToInt16(textBox2->Text);
		richTextBox1->Text = "";
		listBox2->Items->Clear();
		for (size_t i = 0; i < elem.size; i++)
		{
			dataGridView2->Rows[0]->Cells[i]->Value = elem.mass[i];
			listBox2->Items->Add(elem.mass[i]);
			richTextBox1->Text = richTextBox1->Text + " " + Convert::ToString(elem.mass[i]);
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox4->Text = "Найбільше число -> " + elem.FindMax();
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox4->Text = "Найменше число -> " + elem.FindMin();
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox4->Text = "Середнє арифметичне -> " + elem.FindAvg();
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e)
	{
		elem.StackClear();
		textBox4->Text = "Стек очищений";
		dataGridView1->RowCount = 1;
		dataGridView1->ColumnCount = 0;
		dataGridView2->RowCount = 1;
		dataGridView2->ColumnCount = 0;
		richTextBox1->Text = "";
		listBox2->Items->Clear();
		checker = false;
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (elem.IsEmpty())
		{
			textBox4->Text = "Стек пустий";
		}
		else
			textBox4->Text = "Стек не пустий";
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int number = Convert::ToInt16(textBox3->Text);
		elem.AddNew(number);
		dataGridView2->ColumnCount = elem.size - 1;
		listBox2->Items->Clear();
		richTextBox1->Text = "";
		for (size_t i = 0; i < elem.size - 1; i++)
		{
			dataGridView2->Rows[0]->Cells[i]->Value = elem.mass[i];
			listBox2->Items->Add(elem.mass[i]);
			richTextBox1->Text = richTextBox1->Text + " " + Convert::ToString(elem.mass[i]);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!elem.IsEmpty())
		{
			elem.DeleteLast();
			dataGridView2->ColumnCount = elem.size;
			listBox2->Items->RemoveAt(elem.size);
			richTextBox1->Text = "";
			for (size_t i = 0; i < elem.size - 1; i++)
			{
				richTextBox1->Text = richTextBox1->Text + " " + Convert::ToString(elem.mass[i]);
				dataGridView2->Rows[0]->Cells[i]->Value = elem.mass[i];
			}
		}
		else
			textBox4->Text = "Стек пустий";
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (counter < elem.size && checker == false)
		{
			listBox2->Items->Add(listBox1->Text);
			dataGridView2->Rows[0]->Cells[j]->Value = listBox1->Text;
			richTextBox1->Text = richTextBox1->Text + " " + listBox1->Text;
			elem.mass[j] = Convert::ToInt16(listBox1->Text);
			j++;
			counter++;
		}
		if (counter == elem.size)
		{
			checker = true;
		}
	}
	};
}
