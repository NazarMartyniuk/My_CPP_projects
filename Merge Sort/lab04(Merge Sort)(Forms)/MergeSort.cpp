#include "MergeSort.h"

MergeSorting::MergeSorting(size_t rows, size_t cols)
{
	SetRows(rows);
	SetCols(cols);
	SetMatr();
}

void MergeSorting::SetRows(size_t rows)
{
	if (rows > 1)
		this->rows = rows;
}

void MergeSorting::SetCols(size_t cols)
{
	if (cols > 1)
	{
		this->cols = cols;
	}
}

void MergeSorting::SetMatr()
{
	srand(time(nullptr));
	matr = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matr[i] = new double[cols];
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = rand() % 51;
		}
	}
}

void MergeSorting::IndividualTask()
{
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
}

void MergeSorting::MergeSort(size_t left, size_t right)
{
	if (left < right)
		if (right - left == 1)
		{
			if (matr[0][left] > matr[0][right])
			{
				size_t tmp;
				for (size_t i = 0; i < rows; i++)
				{
					tmp = matr[i][left];
					matr[i][left] = matr[i][right];
					matr[i][right] = tmp;
				}
			}
		}
		else
		{
			MergeSort(left, (left + right) / 2);
			MergeSort((left + right) / 2 + 1, right);
			Merge(left, right);
		}
}

void MergeSorting::Merge(size_t left, size_t right)
{
	size_t i = left, mid = left + (right - left) / 2, j = mid + 1, k = 0;
	double** tmpMatr = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		tmpMatr[i] = new double[cols];
	}
	while (i <= mid && j <= right)
	{
		if (matr[0][i] < matr[0][j])
		{
			for (size_t l = 0; l < rows; l++)
			{
				tmpMatr[l][k] = matr[l][i];
			}
			i++;
		}
		else
		{
			for (size_t l = 0; l < rows; l++)
			{
				tmpMatr[l][k] = matr[l][j];
			}
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		for (size_t l = 0; l < rows; l++)
		{
			tmpMatr[l][k] = matr[l][i];
		}
		i++;
		k++;
	}
	while (j <= right)
	{
		for (size_t l = 0; l < rows; l++)
		{
			tmpMatr[l][k] = matr[l][j];
		}
		j++;
		k++;
	}
	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			matr[j][left + i] = tmpMatr[j][i];
		}
	}
	delete[]tmpMatr;
	tmpMatr = nullptr;
}
