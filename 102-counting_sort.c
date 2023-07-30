#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void print_arr_long(const size_t *, size_t);

/**
 * counting_sort - Implement Counting sort
 * @a: array to sort
 * @s: size of array
 * Return: None
 */
void counting_sort(int *a, size_t s)
{
	int mx = 0, *op;
	size_t i, k, oC = 0, *c;

	if (a == NULL || s <= 1)
		return;
	mx = a[0];
	for (i = 0; i < s; i++)
		if (a[i] > mx)
			mx = a[i];
	k = (size_t)mx;
	c = malloc(sizeof(size_t) * (k + 1));
	if (c == NULL)
		return;
	op = malloc(sizeof(int) * s);
	if (op == NULL)
	{
		free(c);
		return;
	}
	for (i = 0; i <= k; i++)
		c[i] = 0;
	for (i = 0; i < s; i++)
		op[i] = 0;
	for (i = 0; i < s; i++)
		c[a[i]]++;
	for (i = 1; i <= k; i++)
	{
		oC = c[i - 1];
		c[i] = oC + c[i];
	}
	print_arr_long((const size_t *)c, k + 1);
	for (i = 0; i < s; i++)
	{
		op[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	for (i = 0; i < s; i++)
		a[i] = op[i];
	free(c);
	free(op);
}

/**
 * print_arr_long - prints array of size_t (unsigned long)
 * @ar: array to print
 * @sz: size of `ar`
 */
void print_arr_long(const size_t *ar, size_t sz)
{
	size_t i;

	for (i = 0; i < sz; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%lu", ar[i]);
	}
	putchar('\n');
}
