#include "sort.h"

void swap_integers(int *a, int *b);
int qs_partition(int *array, size_t size, int left, int right);
void qs_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * qs_partition - ...
 * @array: ...
 * @size: ...
 * @left: ...
 * @right: ...
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int qs_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_integers(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * qs_sort - ...
 * @array: ...
 * @size: ...
 * @left: ...
 * @right: ...
 *
 * Description: Uses the Hoare partition scheme.
 */
void qs_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = qs_partition(array, size, left, right);
		qs_sort(array, size, left, partition - 1);
		qs_sort(array, size, partition, right);
	}
}

/**
 * quick_sort_hoare - ...
 * @array: ...
 * @size: ...
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_sort(array, size, 0, size - 1);
}
