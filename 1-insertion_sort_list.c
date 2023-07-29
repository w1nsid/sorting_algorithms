#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 *
 * @list: Doubly linked list to be sorted
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *temp_node;

	if (!list)
		return;

	current_node = *list;

	while (current_node)
	{
		while (current_node->next && (current_node->n > current_node->next->n))
		{
			temp_node = current_node->next;
			current_node->next = temp_node->next;
			temp_node->prev = current_node->prev;

			if (current_node->prev)
				current_node->prev->next = temp_node;

			if (temp_node->next)
				temp_node->next->prev = current_node;

			current_node->prev = temp_node;
			temp_node->next = current_node;

			if (temp_node->prev)
				current_node = temp_node->prev;
			else
				*list = temp_node;

			print_list(*list);
		}
		current_node = current_node->next;
	}
}
