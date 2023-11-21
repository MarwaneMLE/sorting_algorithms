#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *	Bubble Sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	/* Check if the array is NULL or if it has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			/* comparison of two consecutive elements */
			if (array[j] > array[j + 1])
			{
				/* Store and swap array[j] and array[j + 1]*/
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
