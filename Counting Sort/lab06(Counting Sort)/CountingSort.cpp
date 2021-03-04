#include "CountingSort.h"

CountingSort::CountingSort(size_t size)
{
	SetSize(size);
	SetArr();
}

void CountingSort::SetArr()
{
	srand(time(nullptr));
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 6;
	}
	arr[0] = -10;
	arr[size - 1] = -20;
}

void CountingSort::SetSize(size_t size)
{
	if (size > 1)
		this->size = size;
}

void CountingSort::IndividualTask()
{
	size_t startIndex;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			startIndex = i;
			break;
		}
	}
	size_t endIndex;
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			endIndex = i;
			break;
		}
	}
	size_t newSize = size - (size - endIndex - 1) - startIndex;
	size_t checker = 0;
	int* tmp = new int[newSize];
	for (size_t i = 0; i <= endIndex; i++)
	{
		if (i < startIndex)
		{
			checker++;
			continue;
		}
		tmp[i - checker] = arr[i];
	}
	size = newSize;
	delete[]arr;
	arr = tmp;
}

void CountingSort::Sorting()
{
	int min = arr[0];
	int max = arr[0];
	size_t numberToAdd;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	if (min < 0)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] -= min;
		}
		numberToAdd = -min;
		min -= min;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	sizeOfSecondArr = max - min + 1;
	countOfNumbers = new size_t[sizeOfSecondArr];
	size_t k = 0;
	int* tmp = new int[size];
	for (size_t i = 0; i < sizeOfSecondArr; i++)
	{
		countOfNumbers[i] = 0;
		for (size_t j = 0; j < size; j++)
			if (arr[j] == min)
				countOfNumbers[i]++;
		if (countOfNumbers[i] != 0)
		{
			for (size_t j = 0; j < countOfNumbers[i]; j++)
			{
				tmp[k] = min;
				k++;
			}
		}
		min++;
	}
	delete[]arr;
	arr = tmp;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] -= numberToAdd;
	}
}
