#include "Header.h"

void Menu()
{
	size_t flag = 0;
	size_t iter = 0;
	srand(time(NULL));
	size_t rows, cols;
	do
	{
		cout << "Enter count of rows: ";
		cin >> rows;
		cout << "\nEnter count of cols: ";
		cin >> cols;
		if (rows < 1 || cols <= 1)
		{
			cout << "Incorrect data input";
			system("cls");
		}
	} while (rows < 1 || cols <= 1);
	double** matrix = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
	}
	cout << "Your matrix:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() & 1000;
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Process:\n";
	auto t1 = std::chrono::high_resolution_clock::now();
	while (flag != cols - 1)
	{
		for (size_t i = cols - 1; i != flag; i--)
		{
			if (matrix[0][i] < matrix[0][i - 1])
			{
				for (size_t j = 0; j < rows; j++)
				{
					double tmp = matrix[j][i - 1];
					matrix[j][i - 1] = matrix[j][i];
					matrix[j][i] = tmp;
				}
			}
			iter++;
			cout << iter << " iteration:\n";
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < cols; j++)
				{
					cout << matrix[i][j] << "\t";
				}
				cout << endl;
			}
		}
		flag++;
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	cout << "Result:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Count of iterations: " << iter << "\nTime for sorting(miliseconds): " << int_ms.count() << "\n";
}
