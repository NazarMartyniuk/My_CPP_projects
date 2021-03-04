#include "Bubble_Sort.h"

Bubble_Sort::Bubble_Sort(size_t rows, size_t cols)
{
	srand(time(NULL));
	matrix = new size_t*[rows];
	for (size_t i = 0; i < rows; i++)
		matrix[i] = new size_t[cols];
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = rand() % 100;
}

void Bubble_Sort::Sorting(size_t rows, size_t cols)
{
	size_t flag = 0;
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
		}
		flag++;
	}
}
