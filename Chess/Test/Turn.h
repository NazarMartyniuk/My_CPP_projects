#pragma once
#include "Map.h"
#include <iostream>
#include <vector>
using namespace std;

class Turn
{
	pair<int, int> coordinates;
	vector<pair<int, int>> possibleCoordinates;
	Map* map;
public:
	Turn(int xCoordinates, int yCoordinates, const Map* map);
	vector<pair<int, int>> GetPossibleCoordinates() const { return possibleCoordinates; }
	pair<int, int> GetCoordinates() const { return coordinates; }
private:
	void MakePossibleCoordinates();
};

