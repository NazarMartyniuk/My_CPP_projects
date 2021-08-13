#pragma once
#include <iostream>
using namespace std;
class Gamer
{
private:
	string name;
	bool turn = false;
	string colour;
	pair<bool, bool> castling = { true, true };
public:
	Gamer(string name, string colour);
	string GetName() const { return name; }
	bool GetTurn() const { return turn; }
	string GetColour() const { return colour; }
	void SetTurn(bool value);
	bool GetCastling() const { return castling.second; }
	bool GetCastlingUsability() const { return castling.first; }
	void SetCastling(bool value);
	void SetCastlingUsability(bool value);
};

