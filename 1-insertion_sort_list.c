#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap nodes */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;

			/* Print the list after swapping elements */
			print_list(*list);
		}

		current = current->next;
	}
}
