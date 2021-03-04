#include "Header.h"

void Menu()
{
	srand(time(nullptr));
	size_t size;
	do
	{
		cout << "Enter size of array: ";
		cin >> size;
		if (size <= 1)
		{
			cout << "Incorrect data input";
			system("cls");
		}
	} while (size <= 1);
	size_t* arr = new size_t[size];
	cout << "Your array:\t";
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 11;
		cout << arr[i] << " ";
	}
	cout << "\nIndividual task\n";
	size_t index = 0;
	size_t countMax = 0, count, numberMax;
	while (index < size)
	{
		count = 0;
		for (size_t i = 0; i < size; i++)
			if (arr[i] == arr[index])
				count++;
		if (countMax < count)
		{
			countMax = count;
			numberMax = arr[index];
		}
		index++;
	}
	if (countMax == 1)
	{
		cout << "There is no most common number\n";
		return;
	}
	size_t* newArr = new size_t[size - countMax];
	size_t countMissing = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == numberMax)
		{
			countMissing++;
			continue;
		}
		newArr[i - countMissing] = arr[i];
	}
	size -= countMissing;
	cout << "The most common number is: " << numberMax << endl;
	cout << "New array with no most common number:\t";
	for (size_t i = 0; i < size; i++)
	{
		cout << newArr[i] << " ";
	}
	cout << "\n\nSELECTION SORT\n";
	size_t flag = 0;
	size_t indexMin;
	size_t iter = 1;
	size_t tmp;
	auto t1 = std::chrono::high_resolution_clock::now();
	while (flag != size - 1)
	{
		indexMin = flag;
		for (size_t i = flag; i < size; i++)
		{
			if (newArr[i] < newArr[indexMin])
				indexMin = i;
		}
		if (indexMin != flag)
		{
			tmp = newArr[flag];
			newArr[flag] = newArr[indexMin];
			newArr[indexMin] = tmp;
		}
		flag++;
		cout << endl << iter << " iteration:\t";
		for (size_t i = 0; i < size; i++)
		{
			cout << newArr[i] << " ";
		}
		iter++;
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	cout << "\n\nResult:\t";
	for (size_t i = 0; i < size; i++)
	{
		cout << newArr[i] << " ";
	}
	cout << "\nCount of iterations: " << iter << "\nTime for sorting(miliseconds): " << int_ms.count() << "\n";
}
