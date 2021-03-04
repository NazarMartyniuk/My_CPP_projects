#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class SelectionSort
{
private:
	size_t* arr = nullptr;
	size_t size;
public:
	SelectionSort(size_t size);
	size_t* GetArray() { return arr; }
	size_t GetSize() { return size; }
	void DeleteMostCommon();
	void Sorting();
};

