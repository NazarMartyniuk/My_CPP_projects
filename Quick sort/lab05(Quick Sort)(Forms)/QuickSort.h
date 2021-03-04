#pragma once
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class QuickSort
{
private:
	pair<string, size_t>* students = nullptr;
	size_t size = 0;
public:
	QuickSort() = default;
	void AddStudent(string name, size_t averangeMark);
	pair<string, size_t>* GetStudents() { return students; }
	size_t GetSize() { return size; }
	void IndividualTask();
	void QuickSorting(size_t left, size_t right);
};

