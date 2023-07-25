#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_integers(int *first, int *second)
{
	int snapshot;

	snapshot = *first;
	*first = *second;
	*second = snapshot;
}

/**
 * shell_sort - ...
 *
 * @array: ...
 * @size: ...
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_integers(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
