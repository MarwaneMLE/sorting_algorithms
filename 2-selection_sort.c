#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 *	using the Selection sort algorithm
 * @array: list of value to pritn after ordering it
 * @size: sizee of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	/* Check if the array is not empty or has more than one element */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current index is the minimum */
		min_idx = i;

		/* Find the index of the min element inf unsorted part of the array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		/* Sawap the found min elt with the first elt in the unsorted part*/
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;

			/* the current state of the array after the swap */
			for (j = 0; j < size - 1; j++)
				printf("%d, ", array[j]);
			printf("%d\n", array[size - 1]);
		}
	}
}
