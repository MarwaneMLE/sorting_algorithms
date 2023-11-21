#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *	using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to sort
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t i, j;
	int tmp;

	interval = 1;
	/* Calculate the iniial interval using the Knuth sequence */
	while (interval <= size / 3)
		interval = interval * 3 + 1;

	/* Continue to reduce the interval */
	while (interval > 0)
	{
		/* Perform insertion sort with the current interval */
		for (i = interval; i < size; i++)
		{
			tmp = array[i];
			j = i;
			/*Shift elements until the correct position is found*/
			while (j >= interval && array[j - interval] > tmp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = tmp;
		}
		for (i = 0; i < size; i++)
			printf("%d%s", array[i], (i < size - 1) ? ", " : "");
		printf("\n");

		interval = (interval - 1) / 3;
	}
}
