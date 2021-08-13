#include "Gamer.h"

Gamer::Gamer(string name, string colour) : name(name), colour(colour)
{
}

void Gamer::SetTurn(bool value)
{
	turn = value;
}

void Gamer::SetCastling(bool value)
{
	this->castling.second = value;
}

void Gamer::SetCastlingUsability(bool value)
{
	this->castling.first = value;
}
