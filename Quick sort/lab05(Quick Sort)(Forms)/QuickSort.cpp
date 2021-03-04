#include "QuickSort.h"

void QuickSort::AddStudent(string name, size_t averangeMark)
{
	if (size == 0)
	{
		size++;
		students = new pair<string, size_t>[size];
		students[0].first = name;
		students[0].second = averangeMark;
	}
	else
	{
		size++;
		pair<string, size_t>* tmp = new pair<string, size_t>[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				tmp[i].first = name;
				tmp[i].second = averangeMark;
			}
			else
			{
				tmp[i].first = students[i].first;
				tmp[i].second = students[i].second;
			}
		}
		delete[]students;
		students = tmp;
	}
}

void QuickSort::IndividualTask()
{
	size_t newSize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].second > 3)
			newSize++;
	}
	pair<string, size_t>* tmp = new pair<string, size_t>[newSize];
	size_t checker = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].second < 4)
		{
			checker++;
			continue;
		}
		tmp[i - checker].first = students[i].first;
		tmp[i - checker].second = students[i].second;
	}
	size = newSize;
	delete[]students;
	students = tmp;
}

void QuickSort::QuickSorting(size_t left, size_t right)
{
	size_t baseElement = (right + left) / 2;
	size_t i = 0;
	size_t j = right;
	if (left < right)
	{
		if (right - left != 1)
		{
			while (i < baseElement && j >= baseElement)
			{
				if (students[i].second >= students[baseElement].second)
				{
					if (students[j].second < students[baseElement].second)
					{
						string tmpName = students[i].first;
						size_t tmpAverageMark = students[i].second;
						students[i].first = students[j].first;
						students[i].second = students[j].second;
						students[j].first = tmpName;
						students[j].second = tmpAverageMark;
					}
					else
					{
						j--;
						continue;
					}
				}
				else
				{
					i++;
					continue;
				}
			}
			QuickSorting(left, baseElement - 1);
			QuickSorting(baseElement, right);
		}
		else
		{
			if (students[left].second > students[right].second)
			{
				string tmpName = students[left].first;
				size_t tmpAverageMark = students[left].second;
				students[left].first = students[right].first;
				students[left].second = students[right].second;
				students[right].first = tmpName;
				students[right].second = tmpAverageMark;
			}
		}
	}
}