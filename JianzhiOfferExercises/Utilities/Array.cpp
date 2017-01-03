
#include "stdafx.h"
#include <stdlib.h>
#include "Array.h"
#include <exception>

int RandomInRange(int start, int end)
{
	int random = rand() % (end - start + 1) + start;
	return random;
}

void Swap(int* a, int* b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int Partition(int* numbers, int length, int start, int end)
{
	if (numbers == NULL || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid input");

	int index = RandomInRange(start, end);
	Swap(&numbers[index], &numbers[end]);

	int small = start - 1;
	for (index = start; index < end; index++)
		if (numbers[index] < numbers[end])
			Swap(&numbers[++small], &numbers[index]);
	
	Swap(&numbers[++small], &numbers[end]);
	
	return small;
}