#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class MergeSorting
{
private:
	double** matr = nullptr;
	size_t rows;
	size_t cols;
public:
	MergeSorting(size_t rows, size_t cols);
	void SetRows(size_t rows);
	void SetCols(size_t cols);
	void SetMatr();
	double** GetMatr() { return matr; }
	void IndividualTask();
	void MergeSort(size_t left, size_t right);
	void Merge(size_t left, size_t right);
};

