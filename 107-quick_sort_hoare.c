#include "sort.h"

void swap_elements(int *elem1, int *elem2);
int apply_hoare_partition(
	int *array,
	size_t array_size,
	int start_idx,
	int end_idx);
void hoare_quick_sort(
	int *array,
	size_t array_size,
	int start_idx,
	int end_idx);

/**
 * swap_elements - Swap two integers in an array.
 * @elem1: The first integer to swap.
 * @elem2: The second integer to swap.
 */
void swap_elements(int *elem1, int *elem2)
{
	int tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

/**
 * apply_hoare_partition - Order a subset of an array of integers
 *                          according to the hoare partition scheme.
 * @array: The array of integers.
 * @array_size: The size of the array.
 * @start_idx: The starting index of the subset to order.
 * @end_idx: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int apply_hoare_partition(
	int *array,
	size_t array_size,
	int start_idx,
	int end_idx)
{
	int pivot, upper, lower;

	pivot = array[end_idx];
	for (upper = start_idx - 1, lower = end_idx + 1; upper < lower;)
	{
		do
		{
			upper++;
		} while (array[upper] < pivot);
		do
		{
			lower--;
		} while (array[lower] > pivot);

		if (upper < lower)
		{
			swap_elements(array + upper, array + lower);
			print_array(array, array_size);
		}
	}

	return (upper);
}

/**
 * hoare_quick_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @array_size: The size of the array.
 * @start_idx: The starting index of the array partition to order.
 * @end_idx: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_quick_sort(int *array, size_t array_size, int start_idx, int end_idx)
{
	int partition_idx;

	if (end_idx - start_idx > 0)
	{
		partition_idx =
			apply_hoare_partition(array, array_size, start_idx, end_idx);
		hoare_quick_sort(array, array_size, start_idx, partition_idx - 1);
		hoare_quick_sort(array, array_size, partition_idx, end_idx);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @array_size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t array_size)
{
	if (array == NULL || array_size < 2)
		return;

	hoare_quick_sort(array, array_size, 0, array_size - 1);
}
