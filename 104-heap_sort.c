#include "sort.h"

void swap_integers(int *first, int *second);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - ..
 * @array: ...
 * @size: ...
 * @base: ...
 * @root: ...
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_integers(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - ...
 * @array: ...
 * @size: ...
 *
 * Description: Implements the sift-down heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_integers(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
