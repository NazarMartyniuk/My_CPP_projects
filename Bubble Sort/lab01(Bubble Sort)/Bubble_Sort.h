#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
class Bubble_Sort
{
private:
	size_t** matrix = nullptr;
public:
	Bubble_Sort(size_t rows, size_t cols);
	size_t** GetMatrix() { return matrix; }
	void Sorting(size_t rows, size_t cols);
};

