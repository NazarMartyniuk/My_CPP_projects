#include "ShellSort.h"

ShellSort::ShellSort(size_t size)
{
	srand(time(nullptr));
	this->size = size;
	arr = new double[size];
	for (size_t i = 0; i < size; i++)
	{
		int rnd = rand() % 101;
		rnd -= 50;
		arr[i] = rnd;
	}
}

void ShellSort::Sorting()
{
	double tmp;
	for (size_t step = size / 2; step > 0; step /= 2)
	{
		for (size_t i = 0; i < size - step; i++)
		{
			if (arr[i] > arr[i + step])
			{
				tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
			}
		}
	}
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			Sorting();
		}
	}
}

void ShellSort::IndividualTask()
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			arr[i] = sin(arr[i]);
		}
	}
}
