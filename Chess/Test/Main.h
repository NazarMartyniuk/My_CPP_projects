#pragma once
#include "Turn.h"
#include "Gamer.h"
#include "Map.h"
#include <msclr/marshal_cppstd.h>
#include <ctime>
#include <fstream>
#include <vector>

namespace Test {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			this->Size = System::Drawing::Size(1017, 1040);
			this->BackColor = Color::GreenYellow;
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container^ components;
		Button^ multiplayerButton;
		Button^ statisticButton;
		Button^ exitButton;
		Button^ castlingButton;
		TextBox^ name;
		Label^ label;
		Label^ whichTurn;
		pair<Gamer*, Gamer*>* gamers;
		Turn* turn = nullptr;
		Map* map;
		int countOfTurns;
		int xIndex;
		int yIndex;

#pragma region Own methods

		bool CheckWhiteWin(string name)
		{
			Turn* king;
			bool win = true;
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					if (map->GetNumberByIndexes(i, j) == 21)
					{
						win = false;
						king = new Turn(i, j, map);
					}
				}
				if (!win)
					break;
			}
			if (win)
				return win;
			int possibleAttackers = 0;
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					if (map->GetNumberByIndexes(i, j) < 20 && map->GetNumberByIndexes(i, j) > 10)
					{
						Turn* tmp = new Turn(i, j, map);
						for (size_t k = 0; k < tmp->GetPossibleCoordinates().size(); k++)
						{
							if (tmp->GetPossibleCoordinates()[k].first == king->GetCoordinates().first && tmp->GetPossibleCoordinates()[k].second == king->GetCoordinates().second)
							{
								possibleAttackers++;
								break;
							}
						}
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			for (size_t i = 0; i < king->GetPossibleCoordinates().size(); i++)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(king->GetCoordinates().first, king->GetCoordinates().second, 0);
				tmpMap->ChangeValue(king->GetPossibleCoordinates()[i].first, king->GetPossibleCoordinates()[i].second, 21);
				Turn* tmpKing = new Turn(king->GetPossibleCoordinates()[i].first, king->GetPossibleCoordinates()[i].second, tmpMap);
				for (size_t j = 0; j < 8; j++)
				{
					for (size_t k = 0; k < 8; k++)
					{
						if (tmpMap->GetNumberByIndexes(j, k) > 10 && tmpMap->GetNumberByIndexes(j, k) < 20)
						{
							Turn* tmpTurn = new Turn(j, k, tmpMap);
							for (size_t l = 0; l < tmpTurn->GetPossibleCoordinates().size(); l++)
							{
								if (tmpKing->GetCoordinates().first == tmpTurn->GetPossibleCoordinates()[l].first && tmpKing->GetCoordinates().second ==
									tmpTurn->GetPossibleCoordinates()[l].second)
								{
									check = true;
									break;
								}
							}
							delete tmpTurn;
							tmpTurn = nullptr;
						}
						if (check)
							break;
					}
					if (check)
						break;
				}
				delete tmpMap;
				delete tmpKing;
				tmpMap = nullptr;
				tmpKing = nullptr;
				if (!check)
				{
					if (possibleAttackers > 0)
						MessageBox::Show(marshal_as<String^>(name) + " made check!");
					return false;
				}
			}
			if (possibleAttackers == 0)
				return false;
			MessageBox::Show(marshal_as<String^>(name) + " made checkout!!! Congratulation!");
		}

		bool CheckBlackWin(string name)
		{
			Turn* king;
			bool win = true;
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					if (map->GetNumberByIndexes(i, j) == 11)
					{
						win = false;
						king = new Turn(i, j, map);
					}
				}
				if (!win)
					break;
			}
			if (win)
				return win;
			int possibleAttackers = 0;
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					if (map->GetNumberByIndexes(i, j) > 20)
					{
						Turn* tmp = new Turn(i, j, map);
						for (size_t k = 0; k < tmp->GetPossibleCoordinates().size(); k++)
						{
							if (tmp->GetPossibleCoordinates()[k].first == king->GetCoordinates().first && tmp->GetPossibleCoordinates()[k].second == king->GetCoordinates().second)
							{
								possibleAttackers++;
								break;
							}
						}
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			for (size_t i = 0; i < king->GetPossibleCoordinates().size(); i++)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(king->GetCoordinates().first, king->GetCoordinates().second, 0);
				tmpMap->ChangeValue(king->GetPossibleCoordinates()[i].first, king->GetPossibleCoordinates()[i].second, 11);
				Turn* tmpKing = new Turn(king->GetPossibleCoordinates()[i].first, king->GetPossibleCoordinates()[i].second, tmpMap);
				for (size_t j = 0; j < 8; j++)
				{
					for (size_t k = 0; k < 8; k++)
					{
						if (tmpMap->GetNumberByIndexes(j, k) > 20)
						{
							Turn* tmpTurn = new Turn(j, k, tmpMap);
							for (size_t l = 0; l < tmpTurn->GetPossibleCoordinates().size(); l++)
							{
								if (tmpKing->GetCoordinates().first == tmpTurn->GetPossibleCoordinates()[l].first && tmpKing->GetCoordinates().second ==
									tmpTurn->GetPossibleCoordinates()[l].second)
								{
									check = true;
									break;
								}
							}
							delete tmpTurn;
							tmpTurn = nullptr;
						}
						if (check)
							break;
					}
					if (check)
						break;
				}
				delete tmpMap;
				delete tmpKing;
				tmpMap = nullptr;
				tmpKing = nullptr;
				if (!check)
				{
					if (possibleAttackers > 0)
						MessageBox::Show(marshal_as<String^>(name) + " made check!");
					return false;
				}
			}
			if (possibleAttackers == 0)
				return false;
			MessageBox::Show(marshal_as<String^>(name) + " made checkout!!! Congratulation!");
		}

		void Init()
		{
			gamers = new pair<Gamer*, Gamer*>;
			map = new Map();
			NameInput();
		}

		void MakeMap()
		{
			castlingButton = (gcnew Button());
			castlingButton->Text = "Castling";
			castlingButton->Size = System::Drawing::Size(100, 100);
			castlingButton->Location = Point(800, 800);
			castlingButton->UseVisualStyleBackColor = true;
			castlingButton->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			castlingButton->Click += gcnew System::EventHandler(this, &Main::CastlingButton_Click);
			if (map->GetNumberByIndexes(0, 4) != 11 || map->GetNumberByIndexes(0, 0) != 15 && map->GetNumberByIndexes(0, 7) != 15)
			{
				if (gamers->first->GetColour() == "White")
					gamers->first->SetCastling(false);
				else
					gamers->second->SetCastling(false);
			}
			else
			{
				if (gamers->first->GetColour() == "White" && gamers->first->GetCastlingUsability())
					gamers->first->SetCastling(true);
				else if (gamers->second->GetCastlingUsability())
					gamers->second->SetCastling(true);
			}
			if (map->GetNumberByIndexes(7, 4) != 21 || map->GetNumberByIndexes(7, 0) != 25 && map->GetNumberByIndexes(7, 7) != 25)
			{
				if (gamers->first->GetColour() == "Black")
					gamers->first->SetCastling(false);
				else
					gamers->second->SetCastling(false);
			}
			else
			{
				if (gamers->first->GetColour() == "Black" && gamers->first->GetCastlingUsability())
					gamers->first->SetCastling(true);
				else if (gamers->second->GetCastlingUsability())
					gamers->second->SetCastling(true);
			}
			if (gamers->first->GetTurn() && gamers->first->GetColour() == "White")
			{
				if (CheckBlackWin(gamers->second->GetName()))
				{
					Winner(gamers->second->GetName(), gamers->first->GetName());
					return;
				}
			}
			else if (gamers->first->GetTurn() && gamers->first->GetColour() == "Black")
			{
				if (CheckWhiteWin(gamers->second->GetName()))
				{
					Winner(gamers->second->GetName(), gamers->first->GetName());
					return;
				}
			}
			else if (gamers->second->GetTurn() && gamers->second->GetColour() == "White")
			{
				if (CheckBlackWin(gamers->first->GetName()))
				{
					Winner(gamers->first->GetName(), gamers->second->GetName());
					return;
				}
			}
			else
			{
				if (CheckWhiteWin(gamers->first->GetName()))
				{
					Winner(gamers->first->GetName(), gamers->second->GetName());
					return;
				}
			}
			if (gamers->first->GetTurn())
			{
				if (turn != nullptr)
				{
					Label^ prevTurn = (gcnew Label());
					prevTurn->Text = marshal_as<String^>(gamers->second->GetName().c_str()) + " made turn to ";
					string coord;
					switch (xIndex)
					{
					case 0:
						coord = 'A';
						break;
					case 1:
						coord = 'B';
						break;
					case 2:
						coord = 'C';
						break;
					case 3:
						coord = 'D';
						break;
					case 4:
						coord = 'E';
						break;
					case 5:
						coord = 'F';
						break;
					case 6:
						coord = 'G';
						break;
					case 7:
						coord = 'H';
						break;
					}
					prevTurn->Text += marshal_as<String^>(coord) + Convert::ToString(yIndex + 1);
					prevTurn->Location = Point(810, 110);
					prevTurn->Size = System::Drawing::Size(200, 200);
					prevTurn->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
					this->Controls->Add(prevTurn);
				}
				whichTurn = (gcnew Label());
				whichTurn->Text = marshal_as<String^>(gamers->first->GetName().c_str()) + " now turn '" + marshal_as<String^>(gamers->first->GetColour().c_str()) + "'";
				whichTurn->Location = Point(810, 50);
				whichTurn->Size = System::Drawing::Size(200, 60);
				whichTurn->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
				this->Controls->Add(whichTurn);
				if (gamers->first->GetCastling())
					this->Controls->Add(castlingButton);
				else
				{
					castlingButton->Enabled = false;
					this->Controls->Add(castlingButton);
				}
			}
			else if (gamers->second->GetTurn())
			{
				if (turn != nullptr)
				{
					Label^ prevTurn = (gcnew Label());
					prevTurn->Text = marshal_as<String^>(gamers->first->GetName().c_str()) + " made turn to ";
					string coord;
					switch (xIndex)
					{
					case 0:
						coord = 'A';
						break;
					case 1:
						coord = 'B';
						break;
					case 2:
						coord = 'C';
						break;
					case 3:
						coord = 'D';
						break;
					case 4:
						coord = 'E';
						break;
					case 5:
						coord = 'F';
						break;
					case 6:
						coord = 'G';
						break;
					case 7:
						coord = 'H';
						break;
					}
					prevTurn->Text += marshal_as<String^>(coord) + Convert::ToString(yIndex + 1);
					prevTurn->Location = Point(810, 110);
					prevTurn->Size = System::Drawing::Size(200, 200);
					prevTurn->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
					this->Controls->Add(prevTurn);
				}
				whichTurn = (gcnew Label());
				whichTurn->Text = marshal_as<String^>(gamers->second->GetName().c_str()) + " now turn '" + marshal_as<String^>(gamers->second->GetColour().c_str()) + "'";
				whichTurn->Location = Point(810, 50);
				whichTurn->Size = System::Drawing::Size(200, 60);
				whichTurn->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
				this->Controls->Add(whichTurn);
				if (gamers->second->GetCastling())
					this->Controls->Add(castlingButton);
				else
				{
					castlingButton->Enabled = false;
					this->Controls->Add(castlingButton);
				}
			}
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					Button^ butt = (gcnew Button());
					butt->Size = System::Drawing::Size(100, 100);
					butt->Location = Point(i * 100, j * 100);
					if ((i + j) % 2 == 0)
						butt->BackColor = Color::White;
					else
						butt->BackColor = Color::Black;
					butt->Name = Convert::ToString(j) + Convert::ToString(i);
					switch (map->GetNumberByIndexes(j, i))
					{
					case 16:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wp.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 15:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wr.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 14:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wn.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 13:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wb.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 12:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wq.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 11:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wk.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 26:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bp.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 25:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\br.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 24:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bn.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 23:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bb.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 22:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bq.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					case 21:
						butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bk.png");
						butt->BackgroundImageLayout = ImageLayout::Stretch;
						break;
					default:
						break;
					}
					butt->Click += gcnew System::EventHandler(this, &Main::FigureButton_Click);
					this->Controls->Add(butt);
				}
			}

		}

		void NameInput()
		{
			label = (gcnew Label());
			label->Location = Point(300, 300);
			label->Size = System::Drawing::Size(250, 60);
			label->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			label->Text = L"Enter name of first player:";
			label->Name = L"Name";
			this->Controls->Add(label);
			name = (gcnew TextBox());
			name->Location = Point(550, 300);
			name->Size = System::Drawing::Size(200, 50);
			name->Multiline = true;
			name->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Italic);
			name->MaxLength = 8;
			name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Name_KeyPress);
			this->Controls->Add(name);
			Button^ okButton = (gcnew Button());
			okButton->Location = Point(450, 370);
			okButton->Size = System::Drawing::Size(150, 50);
			okButton->Text = "OK";
			okButton->UseVisualStyleBackColor = true;
			okButton->Click += gcnew System::EventHandler(this, &Main::OkButton_Click);
			this->Controls->Add(okButton);
		}

		void MainMenu()
		{
			delete gamers;
			gamers = nullptr;
			this->Controls->Clear();
			//
			this->multiplayerButton = (gcnew Button());
			this->multiplayerButton->Location = Point(300, 300);
			this->multiplayerButton->Name = L"multiplayerButton";
			this->multiplayerButton->Size = System::Drawing::Size(400, 100);
			this->multiplayerButton->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
			this->multiplayerButton->TabIndex = 1;
			this->multiplayerButton->Text = L"Multiplayer";
			this->multiplayerButton->UseVisualStyleBackColor = true;
			this->Controls->Add(multiplayerButton);
			this->multiplayerButton->Click += gcnew System::EventHandler(this, &Main::multiplayerButton_Click);
			//
			this->statisticButton = (gcnew Button());
			this->statisticButton->Location = Point(300, 400);
			this->statisticButton->Name = L"lastWinButton";
			this->statisticButton->Size = System::Drawing::Size(400, 100);
			this->statisticButton->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
			this->statisticButton->TabIndex = 2;
			this->statisticButton->Text = L"Last win";
			this->statisticButton->UseVisualStyleBackColor = true;
			this->Controls->Add(statisticButton);
			this->statisticButton->Click += gcnew System::EventHandler(this, &Main::lastWinButton_Click);
			//
			this->exitButton = (gcnew Button());
			this->exitButton->Location = Point(300, 500);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(400, 100);
			this->exitButton->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Quit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->Controls->Add(exitButton);
			this->exitButton->Click += gcnew System::EventHandler(this, &Main::exitButton_Click);
		}

		void Winner(string nameWinner, string nameLoser)
		{
			this->Controls->Clear();
			delete map;
			map = nullptr;
			Label^ anyKeyLabel = (gcnew Label());
			anyKeyLabel->Text = "Press LMB";
			anyKeyLabel->Size = System::Drawing::Size(250, 60);
			anyKeyLabel->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			anyKeyLabel->Location = Point(425, 800);
			this->Controls->Add(anyKeyLabel);
			Label^ winLabel = (gcnew Label());
			winLabel->Text = marshal_as<String^>(nameWinner) + " wins " + marshal_as<String^>(nameLoser) + "! Congratulations!!!";
			winLabel->Size = System::Drawing::Size(250, 60);
			winLabel->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			winLabel->AutoSize = false;
			winLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			winLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			winLabel->Click += gcnew System::EventHandler(this, &Main::Main_Click);
			this->Controls->Add(winLabel);
			remove("last_win.bin");
			string stat = nameWinner + " wins " + nameLoser + "\n";
			int length = stat.size();
			fstream out("last_win.bin", ios::out | ios::binary);
			out.write((char*)&length, sizeof(int));
			out.write((char*)stat.c_str(), stat.size());
			out.close();
		}
#pragma endregion

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->SuspendLayout();
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chess";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->Click += gcnew System::EventHandler(this, &Main::Main_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Void Main_Load(System::Object^ sender, System::EventArgs^ e)
		{
			MainMenu();
		}
		System::Void multiplayerButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Controls->Clear();
			this->Init();
		}
		System::Void lastWinButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Controls->Clear();
			string stat;
			fstream in("last_win.bin", ios::in | ios::binary);
			if (!in.is_open())
			{
				MessageBox::Show("Can't open file 'last_win.bin'");
				MainMenu();
				return;
			}
			int length;
			in.read((char*)&length, sizeof(int));
			stat.resize(length);
			in.read((char*)stat.data(), length);
			in.close();
			MessageBox::Show(marshal_as<String^>(stat.c_str()));
			MainMenu();
		}
		System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (MessageBox::Show("Are you sure?", "Are you sure?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				Application::Exit();
		}
		System::Void Main_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MainMenu();
		}
		System::Void Name_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (e->KeyChar.Equals(Convert::ToChar(Keys::Enter)))
			{
				OkButton_Click(sender, e);
				e->Handled = true;
			}
		}
		System::Void OkButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (name->Text == "")
			{
				MessageBox::Show("Name field can't be empty, try again");
				return;
			}
			if (gamers->first != nullptr)
			{
				if (gamers->first->GetTurn())
					gamers->second = new Gamer(marshal_as<string>(name->Text), "Black");
				else
				{
					gamers->second = new Gamer(marshal_as<string>(name->Text), "White");
					gamers->second->SetTurn(true);
				}
				this->Controls->Clear();
				Label^ firstPlayer = (gcnew Label());
				firstPlayer->Location = Point(425, 300);
				firstPlayer->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
				firstPlayer->Text = marshal_as<String^>(gamers->first->GetName().c_str()) + " is " + marshal_as<String^>(gamers->first->GetColour().c_str());
				firstPlayer->Size = System::Drawing::Size(500, 25);
				this->Controls->Add(firstPlayer);
				Label^ secondPlayer = (gcnew Label());
				secondPlayer->Location = Point(425, 330);
				secondPlayer->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
				secondPlayer->Text = marshal_as<String^>(gamers->second->GetName().c_str()) + " is " + marshal_as<String^>(gamers->second->GetColour().c_str());
				secondPlayer->Size = System::Drawing::Size(500, 25);
				this->Controls->Add(secondPlayer);
				Label^ anyKey = (gcnew Label());
				anyKey->Location = Point(425, 600);
				anyKey->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
				anyKey->Text = "Press any key";
				anyKey->Size = System::Drawing::Size(500, 25);
				this->Controls->Add(anyKey);
				this->Click -= gcnew System::EventHandler(this, &Main::Main_Click);
				this->Click += gcnew System::EventHandler(this, &Main::Main_Click_New);
				this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Main_KeyPress);
				return;
			}
			srand(time(nullptr));
			int result = rand() % 2;
			if (result == 0)
			{
				gamers->first = new Gamer(marshal_as<string>(name->Text), "White");
				gamers->first->SetTurn(true);
			}
			else
				gamers->first = new Gamer(marshal_as<string>(name->Text), "Black");
			this->label->Text = "Enter name of second player:";
			this->name->Text = "";
		}
		System::Void FigureButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			auto butt = (Button^)sender;
			string number = marshal_as<string>(butt->Name);
			xIndex = Convert::ToInt32(number[0]) - 48;
			yIndex = Convert::ToInt32(number[1]) - 48;
			if (map->GetNumberByIndexes(xIndex, yIndex) != 0)
			{
				if (gamers->first->GetTurn() && gamers->first->GetColour() == "White" && map->GetNumberByIndexes(xIndex, yIndex) < 20 && map->GetNumberByIndexes(xIndex, yIndex) > 10)
				{
					turn = new Turn(xIndex, yIndex, map);
				}
				else if (gamers->second->GetTurn() && gamers->second->GetColour() == "White" && map->GetNumberByIndexes(xIndex, yIndex) < 20 && map->GetNumberByIndexes(xIndex, yIndex) > 10)
				{
					turn = new Turn(xIndex, yIndex, map);
				}
				else if (gamers->first->GetTurn() && gamers->first->GetColour() == "Black" && map->GetNumberByIndexes(xIndex, yIndex) > 20)
				{
					turn = new Turn(xIndex, yIndex, map);
				}
				else if (gamers->second->GetTurn() && gamers->second->GetColour() == "Black" && map->GetNumberByIndexes(xIndex, yIndex) > 20)
				{
					turn = new Turn(xIndex, yIndex, map);
				}
				else if (gamers->first->GetTurn() && gamers->first->GetColour() == "White" && map->GetNumberByIndexes(xIndex, yIndex) > 20)
				{
					if (turn != nullptr)
					{
						for (size_t i = 0; i < turn->GetPossibleCoordinates().size(); i++)
						{
							if (turn->GetPossibleCoordinates()[i].first == xIndex && turn->GetPossibleCoordinates()[i].second == yIndex)
							{
								map->ChangeValue(xIndex, yIndex, map->GetNumberByIndexes(turn->GetCoordinates().first, turn->GetCoordinates().second));
								map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, 0);
								if (map->GetNumberByIndexes(7, yIndex) == 16 && map->GetWhitePawnTransformation()[4] < 4)
								{
									for (size_t i = 0; i < 4; i++)
									{
										if (map->GetWhitePawnTransformation()[i] != 0)
										{
											Button^ butt = (gcnew Button());
											butt->Name = Convert::ToString(map->GetWhitePawnTransformation()[i]);
											butt->Size = System::Drawing::Size(100, 100);
											butt->Location = Point(i * 100, 900);
											butt->UseVisualStyleBackColor = true;
											switch (Convert::ToInt16(map->GetWhitePawnTransformation()[i]))
											{
											case 15:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wr.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 14:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wn.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 13:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wb.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 12:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wq.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											default:
												break;
											}
											butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
											this->Controls->Add(butt);
										}
									}
									delete turn;
									turn = nullptr;
									turn = new Turn(xIndex, yIndex, map);
									return;

								}
								else
								{
									gamers->first->SetTurn(false);
									gamers->second->SetTurn(true);
									this->Controls->Clear();
									this->MakeMap();
									delete turn;
									turn = nullptr;
									return;
								}
							}
						}
						MessageBox::Show("You cannot kill this figure. Try again");
					}
					else
						MessageBox::Show("You cannot make turn by figure of opponent");
				}
				else if (gamers->second->GetTurn() && gamers->second->GetColour() == "White" && map->GetNumberByIndexes(xIndex, yIndex) > 20)
				{
					if (turn != nullptr)
					{
						for (size_t i = 0; i < turn->GetPossibleCoordinates().size(); i++)
						{
							if (turn->GetPossibleCoordinates()[i].first == xIndex && turn->GetPossibleCoordinates()[i].second == yIndex)
							{
								map->ChangeValue(xIndex, yIndex, map->GetNumberByIndexes(turn->GetCoordinates().first, turn->GetCoordinates().second));
								map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, 0);
								if (map->GetNumberByIndexes(7, yIndex) == 16 && map->GetWhitePawnTransformation()[4] < 4)
								{
									for (size_t i = 0; i < 4; i++)
									{
										if (map->GetWhitePawnTransformation()[i] != 0)
										{
											Button^ butt = (gcnew Button());
											butt->Name = Convert::ToString(map->GetWhitePawnTransformation()[i]);
											butt->Size = System::Drawing::Size(100, 100);
											butt->Location = Point(i * 100, 900);
											butt->UseVisualStyleBackColor = true;
											switch (Convert::ToInt16(map->GetWhitePawnTransformation()[i]))
											{
											case 15:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wr.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 14:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wn.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 13:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wb.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 12:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wq.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											default:
												break;
											}
											butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
											this->Controls->Add(butt);
										}
									}
									delete turn;
									turn = nullptr;
									turn = new Turn(xIndex, yIndex, map);
									return;

								}
								else
								{
									gamers->first->SetTurn(true);
									gamers->second->SetTurn(false);
									this->Controls->Clear();
									this->MakeMap();
									delete turn;
									turn = nullptr;
									return;
								}
							}
						}
						MessageBox::Show("You cannot kill this figure. Try again");
					}
					else
						MessageBox::Show("You cannot make turn by figure of opponent");
				}
				else if (gamers->first->GetTurn() && gamers->first->GetColour() == "Black" && map->GetNumberByIndexes(xIndex, yIndex) < 20 && map->GetNumberByIndexes(xIndex, yIndex) > 10)
				{
					if (turn != nullptr)
					{
						for (size_t i = 0; i < turn->GetPossibleCoordinates().size(); i++)
						{
							if (turn->GetPossibleCoordinates()[i].first == xIndex && turn->GetPossibleCoordinates()[i].second == yIndex)
							{
								map->ChangeValue(xIndex, yIndex, map->GetNumberByIndexes(turn->GetCoordinates().first, turn->GetCoordinates().second));
								map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, 0);
								if (map->GetNumberByIndexes(0, yIndex) == 26 && map->GetBlackPawnTransformation()[4] < 4)
								{
									for (size_t i = 0; i < 4; i++)
									{
										if (map->GetBlackPawnTransformation()[i] != 0)
										{
											Button^ butt = (gcnew Button());
											butt->Name = Convert::ToString(map->GetBlackPawnTransformation()[i]);
											butt->Size = System::Drawing::Size(100, 100);
											butt->Location = Point(i * 100, 900);
											butt->UseVisualStyleBackColor = true;
											switch (Convert::ToInt16(map->GetBlackPawnTransformation()[i]))
											{
											case 25:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\br.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 24:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bn.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 23:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bb.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 22:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bq.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											default:
												break;
											}
											butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
											this->Controls->Add(butt);
										}
									}
									delete turn;
									turn = nullptr;
									turn = new Turn(xIndex, yIndex, map);
									return;

								}
								else
								{
									gamers->first->SetTurn(false);
									gamers->second->SetTurn(true);
									this->Controls->Clear();
									this->MakeMap();
									delete turn;
									turn = nullptr;
									return;
								}
							}
						}
						MessageBox::Show("You cannot kill this figure. Try again");
					}
					else
						MessageBox::Show("You cannot make turn by figure of opponent");
				}
				else if (gamers->second->GetTurn() && gamers->second->GetColour() == "Black" && map->GetNumberByIndexes(xIndex, yIndex) < 20 && map->GetNumberByIndexes(xIndex, yIndex) > 10)
				{
					if (turn != nullptr)
					{
						for (size_t i = 0; i < turn->GetPossibleCoordinates().size(); i++)
						{
							if (turn->GetPossibleCoordinates()[i].first == xIndex && turn->GetPossibleCoordinates()[i].second == yIndex)
							{
								map->ChangeValue(xIndex, yIndex, map->GetNumberByIndexes(turn->GetCoordinates().first, turn->GetCoordinates().second));
								map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, 0);
								if (map->GetNumberByIndexes(0, yIndex) == 26 && map->GetBlackPawnTransformation()[4] < 4)
								{
									for (size_t i = 0; i < 4; i++)
									{
										if (map->GetBlackPawnTransformation()[i] != 0)
										{
											Button^ butt = (gcnew Button());
											butt->Name = Convert::ToString(map->GetBlackPawnTransformation()[i]);
											butt->Size = System::Drawing::Size(100, 100);
											butt->Location = Point(i * 100, 900);
											butt->UseVisualStyleBackColor = true;
											switch (Convert::ToInt16(map->GetBlackPawnTransformation()[i]))
											{
											case 25:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\br.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 24:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bn.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 23:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bb.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											case 22:
												butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bq.png");
												butt->BackgroundImageLayout = ImageLayout::Stretch;
												break;
											default:
												break;
											}
											butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
											this->Controls->Add(butt);
										}
									}
									delete turn;
									turn = nullptr;
									turn = new Turn(xIndex, yIndex, map);
									return;

								}
								else
								{
									gamers->first->SetTurn(true);
									gamers->second->SetTurn(false);
									this->Controls->Clear();
									this->MakeMap();
									delete turn;
									turn = nullptr;
									return;
								}
							}
						}
						MessageBox::Show("You cannot kill this figure. Try again");
					}
					else
						MessageBox::Show("You cannot make turn by figure of opponent");
				}
			}
			else
			{
				if (turn != nullptr)
				{
					for (size_t i = 0; i < turn->GetPossibleCoordinates().size(); i++)
					{
						if (turn->GetPossibleCoordinates()[i].first == xIndex && turn->GetPossibleCoordinates()[i].second == yIndex)
						{
							map->ChangeValue(xIndex, yIndex, map->GetNumberByIndexes(turn->GetCoordinates().first, turn->GetCoordinates().second));
							map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, 0);
							if (gamers->first->GetTurn())
							{
								if (gamers->first->GetColour() == "White")
								{
									if (map->GetNumberByIndexes(7, yIndex) == 16 && map->GetWhitePawnTransformation()[4] < 4)
									{
										for (size_t i = 0; i < 4; i++)
										{
											if (map->GetWhitePawnTransformation()[i] != 0)
											{
												Button^ butt = (gcnew Button());
												butt->Name = Convert::ToString(map->GetWhitePawnTransformation()[i]);
												butt->Size = System::Drawing::Size(100, 100);
												butt->Location = Point(i * 100, 900);
												butt->UseVisualStyleBackColor = true;
												switch (Convert::ToInt16(map->GetWhitePawnTransformation()[i]))
												{
												case 15:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wr.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 14:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wn.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 13:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wb.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 12:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wq.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												default:
													break;
												}
												butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
												this->Controls->Add(butt);
											}
										}
										delete turn;
										turn = nullptr;
										turn = new Turn(xIndex, yIndex, map);
										return;
									}
									else
									{
										gamers->first->SetTurn(false);
										gamers->second->SetTurn(true);
										this->Controls->Clear();
										this->MakeMap();
										delete turn;
										turn = nullptr;
										return;
									}
								}
								else
								{
									if (map->GetNumberByIndexes(0, yIndex) == 26 && map->GetBlackPawnTransformation()[4] < 4)
									{
										for (size_t i = 0; i < 4; i++)
										{
											if (map->GetBlackPawnTransformation()[i] != 0)
											{
												Button^ butt = (gcnew Button());
												butt->Name = Convert::ToString(map->GetBlackPawnTransformation()[i]);
												butt->Size = System::Drawing::Size(100, 100);
												butt->Location = Point(i * 100, 900);
												butt->UseVisualStyleBackColor = true;
												switch (Convert::ToInt16(map->GetBlackPawnTransformation()[i]))
												{
												case 25:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\br.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 24:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bn.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 23:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bb.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 22:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bq.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												default:
													break;
												}
												butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
												this->Controls->Add(butt);
											}
										}
										delete turn;
										turn = nullptr;
										turn = new Turn(xIndex, yIndex, map);
										return;
									}
									else
									{
										gamers->first->SetTurn(false);
										gamers->second->SetTurn(true);
										this->Controls->Clear();
										this->MakeMap();
										delete turn;
										turn = nullptr;
										return;
									}
								}
							}
							else
							{
								if (gamers->second->GetColour() == "White")
								{
									if (map->GetNumberByIndexes(7, yIndex) == 16 && map->GetWhitePawnTransformation()[4] < 4)
									{
										for (size_t i = 0; i < 4; i++)
										{
											if (map->GetWhitePawnTransformation()[i] != 0)
											{
												Button^ butt = (gcnew Button());
												butt->Name = Convert::ToString(map->GetWhitePawnTransformation()[i]);
												butt->Size = System::Drawing::Size(100, 100);
												butt->Location = Point(i * 100, 900);
												butt->UseVisualStyleBackColor = true;
												switch (Convert::ToInt16(map->GetWhitePawnTransformation()[i]))
												{
												case 15:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wr.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 14:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wn.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 13:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wb.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 12:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\wq.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												default:
													break;
												}
												butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
												this->Controls->Add(butt);
											}
										}
										delete turn;
										turn = nullptr;
										turn = new Turn(xIndex, yIndex, map);
										return;
									}
									else
									{
										gamers->first->SetTurn(true);
										gamers->second->SetTurn(false);
										this->Controls->Clear();
										this->MakeMap();
										delete turn;
										turn = nullptr;
										return;
									}
								}
								else
								{
									if (map->GetNumberByIndexes(0, yIndex) == 26 && map->GetBlackPawnTransformation()[4] < 4)
									{
										for (size_t i = 0; i < 4; i++)
										{
											if (map->GetBlackPawnTransformation()[i] != 0)
											{
												Button^ butt = (gcnew Button());
												butt->Name = Convert::ToString(map->GetBlackPawnTransformation()[i]);
												butt->Size = System::Drawing::Size(100, 100);
												butt->Location = Point(i * 100, 900);
												butt->UseVisualStyleBackColor = true;
												switch (Convert::ToInt16(map->GetBlackPawnTransformation()[i]))
												{
												case 25:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\br.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 24:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bn.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 23:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bb.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												case 22:
													butt->BackgroundImage = gcnew System::Drawing::Bitmap("..\\Photos\\bq.png");
													butt->BackgroundImageLayout = ImageLayout::Stretch;
													break;
												default:
													break;
												}
												butt->Click += gcnew System::EventHandler(this, &Main::TransformationButton_Click);
												this->Controls->Add(butt);
											}
										}
										delete turn;
										turn = nullptr;
										turn = new Turn(xIndex, yIndex, map);
										return;
									}
									else
									{
										gamers->first->SetTurn(true);
										gamers->second->SetTurn(false);
										this->Controls->Clear();
										this->MakeMap();
										delete turn;
										turn = nullptr;
										return;
									}
								}
							}
						}
					}
					MessageBox::Show("You cannot make this turn by this figure. Try again");
				}
				else
					MessageBox::Show("Choose figure startly");
			}
		}
		System::Void Main_Click_New(System::Object^ sender, System::EventArgs^ e)
		{
			this->Controls->Clear();
			MakeMap();
			this->Click -= gcnew System::EventHandler(this, &Main::Main_Click_New);
			this->KeyPress -= gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Main_KeyPress);
			this->Click += gcnew System::EventHandler(this, &Main::Main_Click);
		}
		System::Void Main_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			this->Controls->Clear();
			MakeMap();
			this->Click -= gcnew System::EventHandler(this, &Main::Main_Click_New);
			this->KeyPress -= gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Main_KeyPress);
			this->Click += gcnew System::EventHandler(this, &Main::Main_Click);
		}
		System::Void TransformationButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ butt = (Button^)sender;
			int number = Convert::ToInt16(butt->Name);
			if (number < 20)
			{
				map->AddTransformationWhite(number);
				map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, number);
			}
			else
			{
				map->AddTransformationBlack(number);
				map->ChangeValue(turn->GetCoordinates().first, turn->GetCoordinates().second, number);
			}
			if (gamers->first->GetTurn())
			{
				gamers->first->SetTurn(false);
				gamers->second->SetTurn(true);
			}
			else
			{
				gamers->first->SetTurn(true);
				gamers->second->SetTurn(false);
			}
			this->Controls->Clear();
			this->MakeMap();
			delete turn;
			turn = nullptr;
		}
		System::Void CastlingButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (gamers->first->GetTurn())
			{
				if (gamers->first->GetColour() == "White")
				{
					if (map->GetNumberByIndexes(0, 0) == 15 && map->GetNumberByIndexes(0, 7) == 15)
					{
						if (MessageBox::Show("Do you want to make castling with left castle?", "Castling", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows
							::Forms::DialogResult::Yes)
						{
							map->ChangeValue(0, 0, 11);
							map->ChangeValue(0, 4, 15);
							gamers->first->SetCastling(false);
							gamers->first->SetCastlingUsability(false);
							gamers->first->SetTurn(false);
							gamers->second->SetTurn(true);
						}
						else
						{
							map->ChangeValue(0, 7, 11);
							map->ChangeValue(0, 4, 15);
							gamers->first->SetCastling(false);
							gamers->first->SetCastlingUsability(false);
							gamers->first->SetTurn(false);
							gamers->second->SetTurn(true);
						}
					}
					else if (map->GetNumberByIndexes(0, 0))
					{
						map->ChangeValue(0, 0, 11);
						map->ChangeValue(0, 4, 15);
						gamers->first->SetCastling(false);
						gamers->first->SetCastlingUsability(false);
						gamers->first->SetTurn(false);
						gamers->second->SetTurn(true);
					}
					else
					{
						map->ChangeValue(0, 7, 11);
						map->ChangeValue(0, 4, 15);
						gamers->first->SetCastling(false);
						gamers->first->SetCastlingUsability(false);
						gamers->first->SetTurn(false);
						gamers->second->SetTurn(true);
					}
				}
				else
				{
					if (map->GetNumberByIndexes(7, 0) == 25 && map->GetNumberByIndexes(7, 7) == 25)
					{
						if (MessageBox::Show("Do you want to make castling with left castle?", "Castling", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows
							::Forms::DialogResult::Yes)
						{
							map->ChangeValue(7, 0, 21);
							map->ChangeValue(7, 4, 25);
							gamers->first->SetCastling(false);
							gamers->first->SetCastlingUsability(false);
							gamers->first->SetTurn(false);
							gamers->second->SetTurn(true);
						}
						else
						{
							map->ChangeValue(7, 7, 21);
							map->ChangeValue(7, 4, 25);
							gamers->first->SetCastling(false);
							gamers->first->SetCastlingUsability(false);
							gamers->first->SetTurn(false);
							gamers->second->SetTurn(true);
						}
					}
					else if (map->GetNumberByIndexes(7, 0))
					{
						map->ChangeValue(7, 0, 21);
						map->ChangeValue(7, 4, 25);
						gamers->first->SetCastling(false);
						gamers->first->SetCastlingUsability(false);
						gamers->first->SetTurn(false);
						gamers->second->SetTurn(true);
					}
					else
					{
						map->ChangeValue(7, 7, 21);
						map->ChangeValue(7, 4, 25);
						gamers->first->SetCastling(false);
						gamers->first->SetCastlingUsability(false);
						gamers->first->SetTurn(false);
						gamers->second->SetTurn(true);
					}
				}
			}
			else
			{
				if (gamers->second->GetColour() == "White")
				{
					if (map->GetNumberByIndexes(0, 0) == 15 && map->GetNumberByIndexes(0, 7) == 15)
					{
						if (MessageBox::Show("Do you want to make castling with left castle?", "Castling", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows
							::Forms::DialogResult::Yes)
						{
							map->ChangeValue(0, 0, 11);
							map->ChangeValue(0, 4, 15);
							gamers->second->SetCastling(false);
							gamers->second->SetCastlingUsability(false);
							gamers->second->SetTurn(false);
							gamers->first->SetTurn(true);
						}
						else
						{
							map->ChangeValue(0, 7, 11);
							map->ChangeValue(0, 4, 15);
							gamers->second->SetCastling(false);
							gamers->second->SetCastlingUsability(false);
							gamers->second->SetTurn(false);
							gamers->first->SetTurn(true);
						}
					}
					else if (map->GetNumberByIndexes(0, 0))
					{
						map->ChangeValue(0, 0, 11);
						map->ChangeValue(0, 4, 15);
						gamers->second->SetCastling(false);
						gamers->second->SetCastlingUsability(false);
						gamers->second->SetTurn(false);
						gamers->first->SetTurn(true);
					}
					else
					{
						map->ChangeValue(0, 7, 11);
						map->ChangeValue(0, 4, 15);
						gamers->second->SetCastling(false);
						gamers->second->SetCastlingUsability(false);
						gamers->second->SetTurn(false);
						gamers->first->SetTurn(true);
					}
				}
				else
				{
					if (map->GetNumberByIndexes(0, 0) == 15 && map->GetNumberByIndexes(0, 7) == 15)
					{
						if (MessageBox::Show("Do you want to make castling with left castle?", "Castling", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows
							::Forms::DialogResult::Yes)
						{
							map->ChangeValue(0, 0, 11);
							map->ChangeValue(0, 4, 15);
							gamers->second->SetCastling(false);
							gamers->second->SetCastlingUsability(false);
							gamers->second->SetTurn(false);
							gamers->first->SetTurn(true);
						}
						else
						{
							map->ChangeValue(0, 7, 11);
							map->ChangeValue(0, 4, 15);
							gamers->second->SetCastling(false);
							gamers->second->SetCastlingUsability(false);
							gamers->second->SetTurn(false);
							gamers->first->SetTurn(true);
						}
					}
					else if (map->GetNumberByIndexes(0, 0))
					{
						map->ChangeValue(0, 0, 11);
						map->ChangeValue(0, 4, 15);
						gamers->second->SetCastling(false);
						gamers->second->SetCastlingUsability(false);
						gamers->second->SetTurn(false);
						gamers->first->SetTurn(true);
					}
					else
					{
						map->ChangeValue(0, 7, 11);
						map->ChangeValue(0, 4, 15);
						gamers->second->SetCastling(false);
						gamers->second->SetCastlingUsability(false);
						gamers->second->SetTurn(false);
						gamers->first->SetTurn(true);
					}
				}
			}
			this->Controls->Clear();
			MakeMap();
		}
	};
}