#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t current, index, min_index;
	int temp;

	for (current = 0; current < size - 1; current++)
	{
		min_index = current;
		for (index = current + 1; index < size; index++)
		{
			if (array[index] < array[min_index])
				min_index = index;
		}

		if (min_index != current)
		{
			temp = array[current];
			array[current] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
