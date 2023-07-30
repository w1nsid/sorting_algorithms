#include "sort.h"

/**
 * shell_sort - Implements shell sort algorithm using insertion sort on
 * sub-arrays.
 * @a: The array to be sorted.
 * @s: The size of the array.
 */
void shell_sort(int *a, size_t s)
{
	size_t g, o, i, t;
	int v;

	for (g = 1; g < s; g = 3 * g + 1)
		;
	for (g /= 3; g > 0; g /= 3)
	{
		for (o = 0; o < g; o++)
		{
			i = o;
			while (i < s - g)
			{
				if (a[i] > a[i + g])
				{
					v = a[i];
					a[i] = a[i + g];
					a[i + g] = v;
					for (t = i; t >= g; t -= g)
					{
					if (a[t] < a[t - g])
					{
						v = a[t];
						a[t] = a[t - g];
						a[t - g] = v;
					} else
						break;
					}
				} else
					i += g;
			}
		}
		print_array(a, s);
	}
}
