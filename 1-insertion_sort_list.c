#include "sort.h"

/**
 * insertion_sort_list - Implementation of the insertion sort algorithm
 * @list: Pointer to the head of a linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *inner, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		/* loop to compare and swap elements */
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			inner = temp->prev;

			/* Swap nodes without modifying the integer values */
			temp->prev = inner->prev;
			inner->next = temp->next;

			if (inner->prev != NULL)
				inner->prev->next = temp;
			else
				*list = temp;
			if (temp->next != NULL)
				temp->next->prev = inner;

			temp->next = inner;
			inner->prev = temp;

			/* Display the current state of the list */
			print_list((const listint_t *)*list);
		}
	}
}
