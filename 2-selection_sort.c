#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @first: ...
 * @second: ...
 */
void swap_integers(int *first, int *second)
{
	int snapshot;

	snapshot = *first;
	*first = *second;
	*second = snapshot;
}

/**
 * selection_sort - ...
 * @array: ...
 * @size: ...
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *low;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		low = array + i;
		for (j = i + 1; j < size; j++)
			low = (array[j] < *low) ? (array + j) : low;

		if ((array + i) != low)
		{
			swap_integers(array + i, low);
			print_array(array, size);
		}
	}
}
