#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* Choose the pivot as the last element */
	int i = low - 1; /* Initialize index of the smaller element */
	int temp, j;

	/* Traverse the array and rearrange elements smaller than pivot to the left*/
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap array elements and print the array */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	/* Swap the pivot element to its correct position */
	if (array[i + 1] > array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	/* Return the index of the pivot after partitioning */
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick Sort.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	/* Get the pivot index after partitioning */
	if (low < high)
	{
		/* Get the pivot index after partitioning */
		int pivot;

		pivot = lomuto_partition(array, low, high, size);

		/* Recursively sort the subarrays */
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	/* Call the recursive Quick Sort function with the full array range */
	quicksort(array, 0, size - 1, size);
}

