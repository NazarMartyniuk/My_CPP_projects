#include "Turn.h"

Turn::Turn(int xCoordinates, int yCoordinates, const Map* map)
{
	this->coordinates.first = xCoordinates;
	this->coordinates.second = yCoordinates;
	this->map = new Map(map);
	this->MakePossibleCoordinates();
}

void Turn::MakePossibleCoordinates()
{
	int x = this->coordinates.first;
	int y = this->coordinates.second;
	switch (map->GetNumberByIndexes(this->coordinates.first, this->coordinates.second))
	{
	case 16: //White pawn
	{
		pair<int, int>* tmp = nullptr;
		if (this->coordinates.first == 1)
		{
			if (map->GetNumberByIndexes(2, y) == 0)
			{
				tmp = new pair<int, int>{ 2, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (map->GetNumberByIndexes(3, y) == 0)
			{
				tmp = new pair<int, int>{ 3, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y != 7)
				if (map->GetNumberByIndexes(x + 1, y + 1) != 0)
				{
					tmp = new pair<int, int>{ x + 1, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			if (y != 0)
				if (map->GetNumberByIndexes(x + 1, y - 1) != 0)
				{
					tmp = new pair<int, int>{ x + 1, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
		}
		else
		{
			if (map->GetNumberByIndexes(x + 1, y) == 0)
			{
				tmp = new pair<int, int>{ x + 1, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y != 7)
				if (map->GetNumberByIndexes(x + 1, y + 1) != 0)
				{
					tmp = new pair<int, int>{ x + 1, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			if (y != 0)
				if (map->GetNumberByIndexes(x + 1, y - 1) != 0)
				{
					tmp = new pair<int, int>{ x + 1, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
		}
		break;
	}
	case 26://Black pawn
	{
		pair<int, int>* tmp = nullptr;
		if (this->coordinates.first == 6)
		{
			if (map->GetNumberByIndexes(5, y) == 0)
			{
				tmp = new pair<int, int>{ 5, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (map->GetNumberByIndexes(4, y) == 0)
			{
				tmp = new pair<int, int>{ 4, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y != 7)
				if (map->GetNumberByIndexes(x - 1, y + 1) != 0)
				{
					tmp = new pair<int, int>{ x - 1, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			if (y != 0)
				if (map->GetNumberByIndexes(x - 1, y - 1) != 0)
				{
					tmp = new pair<int, int>{ x - 1, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
		}
		else
		{
			if (map->GetNumberByIndexes(x - 1, y) == 0)
			{
				tmp = new pair<int, int>{ x - 1, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y != 7)
				if (map->GetNumberByIndexes(x - 1, y + 1) != 0)
				{
					tmp = new pair<int, int>{ x - 1, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			if (y != 0)
				if (map->GetNumberByIndexes(x - 1, y - 1) != 0)
				{
					tmp = new pair<int, int>{ x - 1, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
		}
		break;
	}
	case 15://White castle
	{
		pair<int, int>* tmp = nullptr;
		if (x != 0)
			for (size_t i = 1; x - i >= 0 && map->GetNumberByIndexes(x - i, y) == 0 || map->GetNumberByIndexes(x - i, y) > 20; i++)
			{
				tmp = new pair<int, int>{ x - i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x - i, y) > 20)
					break;
			}
		if (x != 7)
			for (size_t i = 1; x + i <= 7 && map->GetNumberByIndexes(x + i, y) == 0 || map->GetNumberByIndexes(x + i, y) > 20; i++)
			{
				tmp = new pair<int, int>{ x + i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x + i, y) > 20)
					break;
			}
		if (y != 0)
			for (size_t i = 1; y - i >= 0 && map->GetNumberByIndexes(x, y - i) == 0 || map->GetNumberByIndexes(x, y - i) > 20; i++)
			{
				tmp = new pair<int, int>{ x, y - i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y - i) > 20)
					break;
			}
		if (y != 7)
			for (size_t i = 1; y + i <= 7 && map->GetNumberByIndexes(x, y + i) == 0 || map->GetNumberByIndexes(x, y + i) > 20; i++)
			{
				tmp = new pair<int, int>{ x, y + i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y + i) > 20)
					break;
			}
		break;
	}
	case 25://Black castle
	{
		pair<int, int>* tmp = nullptr;
		if (x != 0)
			for (size_t i = 1; x - i >= 0 && map->GetNumberByIndexes(x - i, y) < 20; i++)
			{
				tmp = new pair<int, int>{ x - i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x - i, y) > 10 && map->GetNumberByIndexes(x - i, y) < 20)
					break;
			}
		if (x != 7)
			for (size_t i = 1; x + i <= 7 && map->GetNumberByIndexes(x + i, y) < 20; i++)
			{
				tmp = new pair<int, int>{ x + i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x + i, y) > 10 && map->GetNumberByIndexes(x + i, y) < 20)
					break;
			}
		if (y != 0)
			for (size_t i = 1; y - i >= 0 && map->GetNumberByIndexes(x, y - i) < 20; i++)
			{
				tmp = new pair<int, int>{ x, y - i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y - i) > 10 && map->GetNumberByIndexes(x, y - i) < 20)
					break;
			}
		if (y != 7)
			for (size_t i = 1; y + i <= 7 && map->GetNumberByIndexes(x, y + i) < 20; i++)
			{
				tmp = new pair<int, int>{ x, y + i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y + i) > 10 && map->GetNumberByIndexes(x, y + i) < 20)
					break;
			}
		break;
	}
	case 14://White horse
	{
		pair<int, int>* tmp = nullptr;
		if (x - 2 >= 0)
		{
			if (y + 1 <= 7 && (map->GetNumberByIndexes(x - 2, y + 1) == 0 || map->GetNumberByIndexes(x - 2, y + 1) > 20))
			{
				tmp = new pair<int, int>{ x - 2, y + 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y - 1 >= 0 && (map->GetNumberByIndexes(x - 2, y - 1) == 0 || map->GetNumberByIndexes(x - 2, y - 1) > 20))
			{
				tmp = new pair<int, int>{ x - 2, y - 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (x + 2 <= 7)
		{
			if (y + 1 <= 7 && (map->GetNumberByIndexes(x + 2, y + 1) == 0 || map->GetNumberByIndexes(x + 2, y + 1) > 20))
			{
				tmp = new pair<int, int>{ x + 2, y + 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y - 1 >= 0 && (map->GetNumberByIndexes(x + 2, y - 1) == 0 || map->GetNumberByIndexes(x + 2, y - 1) > 20))
			{
				tmp = new pair<int, int>{ x + 2, y - 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (y - 2 >= 0)
		{
			if (x + 1 <= 7 && (map->GetNumberByIndexes(x + 1, y - 2) == 0 || map->GetNumberByIndexes(x + 1, y - 2) > 20))
			{
				tmp = new pair<int, int>{ x + 1, y - 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (x - 1 <= 7 && (map->GetNumberByIndexes(x - 1, y - 2) == 0 || map->GetNumberByIndexes(x - 1, y - 2) > 20))
			{
				tmp = new pair<int, int>{ x - 1, y - 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (y + 2 >= 0)
		{
			if (x + 1 <= 7 && (map->GetNumberByIndexes(x + 1, y + 2) == 0 || map->GetNumberByIndexes(x + 1, y + 2) > 20))
			{
				tmp = new pair<int, int>{ x + 1, y + 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (x - 1 <= 7 && (map->GetNumberByIndexes(x - 1, y + 2) == 0 || map->GetNumberByIndexes(x - 1, y + 2) > 20))
			{
				tmp = new pair<int, int>{ x - 1, y + 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		break;
	}
	case 24://Black horse
	{
		pair<int, int>* tmp = nullptr;
		if (x - 2 >= 0)
		{
			if (y + 1 <= 7 && map->GetNumberByIndexes(x - 2, y + 1) < 20)
			{
				tmp = new pair<int, int>{ x - 2, y + 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y - 1 >= 0 && map->GetNumberByIndexes(x - 2, y - 1) < 20)
			{
				tmp = new pair<int, int>{ x - 2, y - 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (x + 2 <= 7)
		{
			if (y + 1 <= 7 && map->GetNumberByIndexes(x + 2, y + 1) < 20)
			{
				tmp = new pair<int, int>{ x + 2, y + 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (y - 1 >= 0 && map->GetNumberByIndexes(x + 2, y - 1) < 20)
			{
				tmp = new pair<int, int>{ x + 2, y - 1 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (y - 2 >= 0)
		{
			if (x + 1 <= 7 && map->GetNumberByIndexes(x + 1, y - 2) < 20)
			{
				tmp = new pair<int, int>{ x + 1, y - 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (x - 1 <= 7 && map->GetNumberByIndexes(x - 1, y - 2) < 20)
			{
				tmp = new pair<int, int>{ x - 1, y - 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		if (y + 2 >= 0)
		{
			if (x + 1 <= 7 && map->GetNumberByIndexes(x + 1, y + 2) < 20)
			{
				tmp = new pair<int, int>{ x + 1, y + 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
			if (x - 1 <= 7 && map->GetNumberByIndexes(x - 1, y + 2) < 20)
			{
				tmp = new pair<int, int>{ x - 1, y + 2 };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
			}
		}
		break;
	}
	case 13://White bishop
		for (size_t i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if (map->GetNumberByIndexes(x - i, y - i) < 20 && map->GetNumberByIndexes(x - i, y - i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y - i) > 20)
				break;
		}
		for (size_t i = 1; x - i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x - i, y + i) < 20 && map->GetNumberByIndexes(x - i, y + i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y + i) > 20)
				break;
		}
		for (size_t i = 1; x + i >= 0 && y - i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y - i) < 20 && map->GetNumberByIndexes(x + i, y - i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y - i) > 20)
				break;
		}
		for (size_t i = 1; x + i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y + i) < 20 && map->GetNumberByIndexes(x + i, y + i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y + i) > 20)
				break;
		}
		break;
	case 23://Black Bishop
		for (size_t i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if (map->GetNumberByIndexes(x - i, y - i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y - i) < 20 && map->GetNumberByIndexes(x - i, y - i) > 10)
				break;
		}
		for (size_t i = 1; x - i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x - i, y + i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y + i) < 20 && map->GetNumberByIndexes(x - i, y + i) > 10)
				break;
		}
		for (size_t i = 1; x + i >= 0 && y - i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y - i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y - i) < 20 && map->GetNumberByIndexes(x + i, y - i) > 10)
				break;
		}
		for (size_t i = 1; x + i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y + i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y + i) < 20 && map->GetNumberByIndexes(x + i, y + i) > 10)
				break;
		}
		break;
	case 12://White queen
		if (x != 0)
		{
			for (size_t i = 1; x - i >= 0 && map->GetNumberByIndexes(x - i, y) == 0 || map->GetNumberByIndexes(x - i, y) > 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x - i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x - i, y) > 20)
					break;
			}
		}
		for (size_t i = 1; x - i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x - i, y + i) < 20 && map->GetNumberByIndexes(x - i, y + i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y + i) > 20)
				break;
		}
		if (y != 7)
		{
			for (size_t i = 1; y + i && map->GetNumberByIndexes(x, y + i) == 0 || map->GetNumberByIndexes(x, y + i) > 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x, y + i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y + i) > 20)
					break;
			}
		}
		for (size_t i = 1; x + i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y + i) < 20 && map->GetNumberByIndexes(x + i, y + i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y + i) > 20)
				break;
		}
		if (x != 7)
		{
			for (size_t i = 1; x + i <= 7 && map->GetNumberByIndexes(x + i, y) == 0 || map->GetNumberByIndexes(x + i, y) > 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x + i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x + i, y) > 20)
					break;
			}
		}
		for (size_t i = 1; x + i >= 0 && y - i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y - i) < 20 && map->GetNumberByIndexes(x + i, y - i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y - i) > 20)
				break;
		}
		if (y != 0)
		{
			for (size_t i = 1; y - i >= 0 && map->GetNumberByIndexes(x, y - i) == 0 || map->GetNumberByIndexes(x, y - i) > 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x, y - i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y - i) > 20)
					break;
			}
		}
		for (size_t i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if (map->GetNumberByIndexes(x - i, y - i) < 20 && map->GetNumberByIndexes(x - i, y - i) > 10)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y - i) > 20)
				break;
		}
		break;
	case 22://Black queen
		if (x != 0)
		{
			for (size_t i = 1; x - i >= 0 && map->GetNumberByIndexes(x - i, y) < 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x - i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x - i, y) > 10 && map->GetNumberByIndexes(x - i, y) < 20)
					break;
			}
		}
		for (size_t i = 1; x - i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x - i, y + i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y + i) < 20 && map->GetNumberByIndexes(x - i, y + i) > 10)
				break;
		}
		if (y != 7)
		{
			for (size_t i = 1; y + i && map->GetNumberByIndexes(x, y + i) < 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x, y + i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y + i) > 10 && map->GetNumberByIndexes(x, y + i) < 20)
					break;
			}
		}
		for (size_t i = 1; x + i >= 0 && y + i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y + i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y + i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y + i) < 20 && map->GetNumberByIndexes(x + i, y + i) > 10)
				break;
		}
		if (x != 7)
		{
			for (size_t i = 1; x + i <= 7 && map->GetNumberByIndexes(x + i, y) < 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x + i, y };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x + i, y) > 10 && map->GetNumberByIndexes(x + i, y) < 20)
					break;
			}
		}
		for (size_t i = 1; x + i >= 0 && y - i <= 7; i++)
		{
			if (map->GetNumberByIndexes(x + i, y - i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x + i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x + i, y - i) < 20 && map->GetNumberByIndexes(x + i, y - i) > 10)
				break;
		}
		if (y != 0)
		{
			for (size_t i = 1; y - i && map->GetNumberByIndexes(x, y - i) < 20; i++)
			{
				pair<int, int>* tmp = new pair<int, int>{ x, y - i };
				this->possibleCoordinates.push_back(*tmp);
				delete tmp;
				tmp = nullptr;
				if (map->GetNumberByIndexes(x, y - i) > 10 && map->GetNumberByIndexes(x, y - i) < 20)
					break;
			}
		}
		for (size_t i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if (map->GetNumberByIndexes(x - i, y - i) > 20)
				break;
			pair<int, int>* tmp = new pair<int, int>{ x - i, y - i };
			this->possibleCoordinates.push_back(*tmp);
			delete tmp;
			tmp = nullptr;
			if (map->GetNumberByIndexes(x - i, y - i) < 20 && map->GetNumberByIndexes(x - i, y - i) > 10)
				break;
		}
		break;
	case 11://White king
		if (x != 0)
		{
			if (map->GetNumberByIndexes(x - 1, y) == 0 || map->GetNumberByIndexes(x - 1, y) > 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x - 1, y, 11);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == y)
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x - 1, y };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
			if (y != 0)
			{
				if (map->GetNumberByIndexes(x - 1, y - 1) == 0 || map->GetNumberByIndexes(x - 1, y - 1) > 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x - 1, y - 1, 11);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x - 1, y - 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			if (y != 7)
			{
				if (map->GetNumberByIndexes(x - 1, y + 1) == 0 || map->GetNumberByIndexes(x - 1, y + 1) > 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x - 1, y + 1, 11);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x - 1, y + 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
		}
		if (y != 0)
		{
			if (map->GetNumberByIndexes(x, y - 1) == 0 || map->GetNumberByIndexes(x, y - 1) > 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x, y - 1, 11);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == x && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
		}
		if (y != 7)
		{
			if (map->GetNumberByIndexes(x, y + 1) == 0 || map->GetNumberByIndexes(x, y + 1) > 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x, y + 1, 11);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == x && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
		}
		if (x != 7)
		{
			if (map->GetNumberByIndexes(x + 1, y) == 0 || map->GetNumberByIndexes(x + 1, y) > 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x + 1, y, 11);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == y)
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x + 1, y };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
			if (y != 0)
			{
				if (map->GetNumberByIndexes(x + 1, y - 1) == 0 || map->GetNumberByIndexes(x + 1, y - 1) > 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x + 1, y - 1, 11);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x + 1, y - 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			if (y != 7)
			{
				if (map->GetNumberByIndexes(x + 1, y + 1) == 0 || map->GetNumberByIndexes(x + 1, y + 1) > 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x + 1, y + 1, 11);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) > 20 && tmpMap->GetNumberByIndexes(i, j) != 21)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x + 1, y + 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
		}
		break;
	case 21://Black king
		if (x != 0)
		{
			if (map->GetNumberByIndexes(x - 1, y) < 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x - 1, y, 21);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == y)
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x - 1, y };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
			if (y != 0)
			{
				if (map->GetNumberByIndexes(x - 1, y - 1) < 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x - 1, y - 1, 11);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x - 1, y - 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			if (y != 7)
			{
				if (map->GetNumberByIndexes(x - 1, y + 1) < 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x - 1, y + 1, 21);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x - 1) && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x - 1, y + 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
		}
		if (y != 0)
		{
			if (map->GetNumberByIndexes(x, y - 1) < 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x, y - 1, 21);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == x && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x, y - 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
		}
		if (y != 7)
		{
			if (map->GetNumberByIndexes(x, y + 1) < 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x, y + 1, 21);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == x && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x, y + 1 };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
		}
		if (x != 7)
		{
			if (map->GetNumberByIndexes(x + 1, y) < 20)
			{
				bool check = false;
				Map* tmpMap = new Map(map);
				tmpMap->ChangeValue(x + 1, y, 21);
				tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
				for (size_t i = 0; i < 8; i++)
				{
					for (size_t j = 0; j < 8; j++)
					{
						if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
						{
							Turn* tmpTurn = new Turn(i, j, tmpMap);
							for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
							{
								if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == y)
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
				if (!check)
				{
					pair<int, int>* tmp = new pair<int, int>{ x + 1, y };
					this->possibleCoordinates.push_back(*tmp);
					delete tmp;
					tmp = nullptr;
				}
			}
			if (y != 0)
			{
				if (map->GetNumberByIndexes(x + 1, y - 1) < 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x + 1, y - 1, 21);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == (y - 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x + 1, y - 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
			if (y != 7)
			{
				if (map->GetNumberByIndexes(x + 1, y + 1) < 20)
				{
					bool check = false;
					Map* tmpMap = new Map(map);
					tmpMap->ChangeValue(x + 1, y + 1, 21);
					tmpMap->ChangeValue(coordinates.first, coordinates.second, 0);
					for (size_t i = 0; i < 8; i++)
					{
						for (size_t j = 0; j < 8; j++)
						{
							if (tmpMap->GetNumberByIndexes(i, j) < 20 && tmpMap->GetNumberByIndexes(i, j) != 11)
							{
								Turn* tmpTurn = new Turn(i, j, tmpMap);
								for (size_t k = 0; k < tmpTurn->possibleCoordinates.size(); k++)
								{
									if (tmpTurn->possibleCoordinates[k].first == (x + 1) && tmpTurn->possibleCoordinates[k].second == (y + 1))
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
					if (!check)
					{
						pair<int, int>* tmp = new pair<int, int>{ x + 1, y + 1 };
						this->possibleCoordinates.push_back(*tmp);
						delete tmp;
						tmp = nullptr;
					}
				}
			}
		}
		break;
	default:
		break;
	}
}
