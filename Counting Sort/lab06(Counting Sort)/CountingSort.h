#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class CountingSort
{
private:
	int* arr = nullptr;
	size_t* countOfNumbers = nullptr;
	size_t size;
	size_t sizeOfSecondArr;
public:
	CountingSort(size_t size);
	void SetArr();
	void SetSize(size_t size);
	int* GetArr() { return arr; }
	size_t GetSize() { return size; }
	size_t GetSizeSecond() { return sizeOfSecondArr; }
	size_t* GetCountOfNumbers() { return countOfNumbers; }
	void IndividualTask();
	void Sorting();
};

