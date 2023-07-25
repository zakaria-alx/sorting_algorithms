#include "sort.h"

/**
 * insertion_sort_list - ...
 *
 * @list: ...
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	sorted = *list;
	current = sorted->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;

			if (temp->prev != NULL)
			{
				temp->prev->next = current;
			}
			temp->next = current->next;

			if (current->next != NULL)
			{
				current->next->prev = temp;
			}
			current->next = temp;
			temp->prev = current;

			if (current->prev == NULL)
			{
				*list = current;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
