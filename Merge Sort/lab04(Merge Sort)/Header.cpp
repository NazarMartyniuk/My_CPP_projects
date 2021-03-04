#include "Header.h"

void Menu()
{
	srand(time(nullptr));
	size_t rows, cols;
	do
	{
		cout << "Enter rows: ";
		cin >> rows;
		cout << "\nEnter cols: ";
		cin >> cols;
		if (rows < 1 || cols <= 1)
		{
			cout << "\nIncorrect data input\n";
			system("cls");
		}
	} while (rows < 1 || cols <= 1);
	double** matr = new double* [rows];
	for (size_t i = 0; i < rows; i++)
		matr[i] = new double[cols];
	cout << "Your matrix:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = rand() % 50 + 1;
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "INDIVIDUAL TASK\n";
	size_t tmp;
	for (size_t i = 0; i < cols; i++)
	{
		tmp = 0;
		for (size_t j = 0; j < rows; j++)
		{
			if (matr[j][i] < matr[tmp][i])
				tmp = j;
		}
		matr[tmp][i] = log(matr[tmp][i]);
	}
	cout << "New matrix:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}
	cout << "\tMERGE SORT\n";
	auto t1 = std::chrono::high_resolution_clock::now();
	MergeSort(matr, 0, cols - 1, rows, cols);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}
	cout << "Time for sorting(miliseconds): " << int_ms.count() << "\n";
}

void MergeSort(double** matr, size_t beg, size_t end, size_t rows, size_t cols)
{
	if (beg < end)
	{
		MergeSort(matr, beg, (beg + end) / 2, rows, cols);
		MergeSort(matr, (beg + end) / 2 + 1, end, rows, cols);
		Merge(matr, beg, end, rows, cols);
	}
}

void Merge(double** matr, size_t beg, size_t end, size_t rows, size_t cols)
{
	size_t mid, start, final, j;
	double** tmp = new double* [rows];
	for (size_t i = 0; i < rows; i++)
		tmp[i] = new double[cols];
	mid = (beg + end) / 2;
	start = beg;
	final = mid + 1;
	for (j = beg; j <= end; j++)
	{
		if ((start <= mid) && (final > end) || matr[0][start] < matr[0][final])
		{
			for (size_t i = 0; i < rows; i++)
				tmp[i][j] = matr[i][start];
			start++;
		}
		else
		{
			for (size_t i = 0; i < rows; i++)
				tmp[i][j] = matr[i][final];
			final++;
		}
	}
	for (j = beg; j <= end; j++)
	{
		for (size_t i = 0; i < rows; i++)
			matr[i][j] = tmp[i][j];
	}
	delete[]tmp;
	tmp = nullptr;
}


