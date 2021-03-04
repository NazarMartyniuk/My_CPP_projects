#include <iostream>
#include <ctime>
#include <string>
using namespace std;
void Merge(long** arr, size_t beg, size_t end, size_t size)
{
	size_t i = beg, mid = beg + (end - beg) / 2, j = mid + 1, k = 0;
	size_t* d = new size_t[size];
	while (i <= mid && j <= end)
	{
		if (arr[i][0] < arr[j][0])
		{
			d[k] = arr[i][0];
			i++;
		}
		else
		{
			d[k] = arr[j][0];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		d[k] = arr[i][0];
		i++;
		k++;
	}
	while (j <= end)
	{
		d[k] = arr[j][0];
		j++;
		k++;
	}
	for (size_t i = 0; i < k; i++)
		arr[beg + i][0] = d[i];
}
void MergeSort(long** arr, size_t beg, size_t end, size_t size)
{
	if (beg < end)
		if (end - beg == 1)
		{
			if (arr[beg][0] > arr[end][0])
			{
				size_t tmp = arr[beg][0];
				arr[beg][0] = arr[end][0];
				arr[end][0] = tmp;
			}
		}
		else
		{
			MergeSort(arr, beg, (beg + end) / 2, size);
			MergeSort(arr, (beg + end) / 2 + 1, end, size);
			Merge(arr, beg, end, size);
		}
}
int main(int argc, char* argv[])
{
	srand(time(nullptr));
	size_t SIZE = atoi(argv[1]);
	long** arr = new long* [SIZE];
	for (size_t i = 0; i < SIZE; i++)
		arr[i] = new long[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}
	MergeSort(arr, 0, SIZE - 1, SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}