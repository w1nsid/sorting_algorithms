#include <stdio.h>

#include "sort.h"

/**
 * bubble_sort - Orders an integer array in ascending sequence
 *
 * @num_array: The integer array to be sorted
 * @arr_size: The size of the array
 *
 * Return: None
 */
void bubble_sort(int *num_array, size_t arr_size)
{
	size_t index;
	int swap_temp, is_sorted;

	if (!num_array || arr_size == 0)
		return;

	do {
		is_sorted = 1;
		for (index = 0; index < arr_size - 1; index++)
		{
			if (num_array[index] > num_array[index + 1])
			{
				is_sorted = 0;
				swap_temp = num_array[index];
				num_array[index] = num_array[index + 1];
				num_array[index + 1] = swap_temp;
				print_array(num_array, arr_size);
			}
		}

	} while (is_sorted == 0);
}
