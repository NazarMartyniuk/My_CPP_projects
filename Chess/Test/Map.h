#pragma once
using namespace std;
class Map
{
	int map[8][8] =
	{
		{15, 14, 13, 12, 11, 13, 14, 15},
		{16, 16, 16, 16, 16, 16, 16, 16},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{26, 26, 26, 26, 26, 26, 26, 26},
		{25, 24, 23, 22, 21, 23, 24, 25}
	};
	int blackPawnTransformation[5] = { 22, 23, 24, 25, 0 };
	int whitePawnTransformation[5] = { 12, 13, 14, 15, 0 };
public:
	Map() = default;
	Map(const Map* map);
	void ChangeValue(int xIndex, int yIndex, int value);
	int GetNumberByIndexes(int xIndex, int yIndex);
	int* GetBlackPawnTransformation() { return blackPawnTransformation; }
	int* GetWhitePawnTransformation() { return whitePawnTransformation; }
	void AddTransformationBlack(int number);
	void AddTransformationWhite(int number);
};