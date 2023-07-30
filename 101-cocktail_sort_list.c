#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * partition - Defines partition
 * @a: array
 * @l: lower
 * @h: higher
 * @s: array's size
 * Return: i
 */
int partition(int *a, int l, int h, size_t s)
{
	int i = l - 1, j = l;
	int p = a[h], t = 0;

	for (; j < h; j++)
	{
		if (a[j] < p)
		{
			i++;
			if (a[i] != a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				print_array(a, s);
			}
		}
	}
	if (a[i + 1] != a[h])
	{
		t = a[i + 1];
		a[i + 1] = a[h];
		a[h] = t;
		print_array(a, s);
	}
	return (i + 1);
}

/**
 * qs - Performs quick sort
 * @a: given array
 * @l: lower
 * @h: higher
 * @s: array's size
 * Return: void
 */
void qs(int *a, int l, int h, size_t s)
{
	int p;

	if (l < h)
	{
		p = partition(a, l, h, s);
		qs(a, l, p - 1, s);
		qs(a, p + 1, h, s);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @a: array
 * @s: array's size
 * Return: void
 */
void quick_sort(int *a, size_t s)
{
	if (a == NULL || s < 2)
		return;

	qs(a, 0, s - 1, s);
}
