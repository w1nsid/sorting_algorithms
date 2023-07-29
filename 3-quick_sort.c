#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * exchange_elements - Exchanges two elements within a given array.
 *
 * @input_array: The array to be modified.
 * @left_idx: The index of the left element.
 * @right_idx: The index of the right element.
 *
 * Return: Nothing.
 */
void exchange_elements(int *input_array, size_t left_idx, size_t right_idx)
{
	int temp_var;

	if (input_array != NULL)
	{
		temp_var = input_array[left_idx];
		input_array[left_idx] = input_array[right_idx];
		input_array[right_idx] = temp_var;
	}
}

/**
 * lomuto_quick_sort - Implements the quick sort algorithm on a subsection
 * of an array using Lomuto's partitioning method.
 *
 * @input_array: The array containing the sub-array.
 * @start_pos: The initial position of the sub-array.
 * @end_pos: The final position of the sub-array.
 * @array_len: The total length of the array.
 *
 * Return: The index of the pivot element.
 */
void lomuto_quick_sort(
	int *input_array,
	size_t start_pos,
	size_t end_pos,
	size_t array_len)
{
	size_t pivot_idx, iterator;
	int pivot_val;

	if ((start_pos >= end_pos) || (input_array == NULL))
		return;
	pivot_val = input_array[end_pos];
	pivot_idx = start_pos;
	for (iterator = start_pos; iterator < end_pos; iterator++)
	{
		if (input_array[iterator] <= pivot_val)
		{
			if (pivot_idx != iterator)
			{
				exchange_elements(input_array, pivot_idx, iterator);
				print_array(input_array, array_len);
			}
			pivot_idx++;
		}
	}
	if (pivot_idx != end_pos)
	{
		exchange_elements(input_array, pivot_idx, end_pos);
		print_array(input_array, array_len);
	}
	if (pivot_idx - start_pos > 1)
		lomuto_quick_sort(input_array, start_pos, pivot_idx - 1, array_len);
	if (end_pos - pivot_idx > 1)
		lomuto_quick_sort(input_array, pivot_idx + 1, end_pos, array_len);
}

/**
 * execute_quick_sort - Implements quick sort on an array using
 * the Lomuto's partitioning method.
 *
 * @input_array: The array to sort.
 * @array_len: The total length of the array.
 *
 * Return: Nothing.
 */
void execute_quick_sort(int *input_array, size_t array_len)
{
	if (input_array != NULL)
	{
		lomuto_quick_sort(input_array, 0, array_len - 1, array_len);
	}
}
