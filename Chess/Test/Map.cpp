#include "Map.h"

Map::Map(const Map* mapObj)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			this->map[i][j] = mapObj->map[i][j];
		}
	}
}

void Map::ChangeValue(int xIndex, int yIndex, int value)
{
    map[xIndex][yIndex] = value;
}

int Map::GetNumberByIndexes(int xIndex, int yIndex)
{
    return map[xIndex][yIndex];
}

void Map::AddTransformationBlack(int number)
{
	blackPawnTransformation[4]++;
	for (size_t i = 0; i < 4; i++)
		if (blackPawnTransformation[i] == number)
		{
			blackPawnTransformation[i] = 0;
			return;
		}
}

void Map::AddTransformationWhite(int number)
{
	whitePawnTransformation[4]++;
	for (size_t i = 0; i < 4; i++)
		if (whitePawnTransformation[i] == number)
		{
			whitePawnTransformation[i] = 0;
			return;
		}
}
