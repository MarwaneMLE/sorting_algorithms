#include "sort.h"

/**
 * insertion_sort_list - Implementation of the insertion sort algorithm
 * @list: Pointer to the head of a linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int tmp_value;

	/* Check if the list is empty or has only one element */
	if (!list || !(*list) || !((*list)->next))
		return;

	/* Iterate through the list */
	current = *list;

	while (current)
	{
		/* Loop to compare and swap elements */
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				/* Swap values without changing the node structure */
				tmp_value = current->n;
				current->n = current->next->n;
				current->next->n = tmp_value;

				/* Reset the current pointer to the beginning for rechecking */
				current = *list;

				/* Display the current state of the list */
				print_list(*list);

				/* Break out of the inner loop after a swap */
				break;
			}
			/* Move to the next node in the inner loop */
			current = current->next;
		}
		/* Move to the next node in the outer loop */
		current = current->next;
	}
}
