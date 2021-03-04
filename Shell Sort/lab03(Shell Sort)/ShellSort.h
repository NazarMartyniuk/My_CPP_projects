#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class ShellSort
{
private:
	double* arr = nullptr;
	size_t size;
public:
	ShellSort(size_t size);
	double* GetArray() const { return arr; }
	void Sorting();
	void IndividualTask();
};

