// 20_PrintMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void PrintMatrixInCircle(int** matrix, int rows, int cols, int start);

void PrintMatrixClockwisely(int** matrix, int rows, int cols)
{
	if (matrix == NULL || rows <= 0 || cols <= 0)
		return;

	int start = 0;
	while (start * 2 < rows && start * 2 < cols)
	{
		PrintMatrixInCircle(matrix, rows, cols, start);
		++start;
	}
}

void PrintMatrixInCircle(int** matrix, int rows, int cols, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i <= endX; i++)
		printf("%d ", matrix[start][i]);

	if (start < endY)
	{
		for (int i = start + 1; i <= endY; i++)
			printf("%d ", matrix[i][endX]);

		if (start < endX)
		{
			for (int i = endX - 1; i >= start; i--)
				printf("%d ", matrix[endY][i]);

			if (start < endY - 1)
			{
				for (int i = endY - 1; i > start; i--)
					printf("%d ", matrix[i][start]);
			}
		}
	}
}

void test(int rows, int cols)
{
	int** matrix = new int*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = i*cols + j + 1;
	}

	PrintMatrixClockwisely(matrix, rows, cols);
	printf("\n");

	for (int i = 0; i < rows; i++)
		delete[] (int*)matrix[i];

	delete[] matrix;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 1  2  3  4 
	// 5  6  7  8
	// 9 10 11 12
	//13 14 15 16
	test(4,4);

	// 1  2  3
	// 4  5  6
	// 7  8  9
	//10 11 12
	test(4,3);

	// 1  2
	// 3  4
	// 5  6
	// 7  8
	test(4,2);

	// 1
	// 2
	// 3
	// 4
	test(4,1);

	test(3,4);
	test(2,4);
	test(1,4);
	return 0;
}

