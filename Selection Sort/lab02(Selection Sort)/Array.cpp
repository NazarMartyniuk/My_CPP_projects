#include "Array.h"

SelectionSort::SelectionSort(size_t size)
{
	srand(time(nullptr));
	this->size = size;
	arr = new size_t[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 11;
	}
}

void SelectionSort::DeleteMostCommon()
{
	size_t counter = 0;
	size_t tmpCounter = 0;
	size_t commonNumber;
	for (size_t i = 0; i < size; i++)
	{
		tmpCounter = 0;
		for (size_t j = 0; j < size; j++)
		{
			if (arr[j] == arr[i])
				tmpCounter++;
		}
		if (tmpCounter > counter)
		{
			counter = tmpCounter;
			commonNumber = arr[i];
		}
	}
	size_t* tmpArr = new size_t[size - counter];
	size_t countMissing = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == commonNumber)
		{
			countMissing++;
			continue;
		}
		tmpArr[i - countMissing] = arr[i];
	}
	size -= counter;
	delete[]arr;
	arr = tmpArr;
}

void SelectionSort::Sorting()
{
	size_t flag = 0;
	size_t indexMin;
	size_t tmp;
	while (flag != size - 1)
	{
		indexMin = flag;
		for (size_t i = flag; i < size; i++)
		{
			if (arr[i] < arr[indexMin])
				indexMin = i;
		}
		if (indexMin != flag)
		{
			tmp = arr[flag];
			arr[flag] = arr[indexMin];
			arr[indexMin] = tmp;
		}
		flag++;
	}
}
