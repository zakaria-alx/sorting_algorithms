#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sigdgt, int *bfr);
void radix_sort(int *array, size_t size);

/**
 * get_max - ..
 * @array: ...
 * @size: ...
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - ...
 * @array: ...
 * @size: ...
 * @sigdgt:  ...
 * @bfr: ...
 */
void radix_counting_sort(int *array, size_t size, int sigdgt, int *bfr)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sigdgt) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		bfr[count[(array[i] / sigdgt) % 10] - 1] = array[i];
		count[(array[i] / sigdgt) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = bfr[i];
}

/**
 * radix_sort - ...
 * @array: ...
 * @size: ...
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sigdgt, *bfr;

	if (array == NULL || size < 2)
		return;

	bfr = malloc(sizeof(int) * size);
	if (bfr == NULL)
		return;

	max = get_max(array, size);
	for (sigdgt = 1; max / sigdgt > 0; sigdgt *= 10)
	{
		radix_counting_sort(array, size, sigdgt, bfr);
		print_array(array, size);
	}

	free(bfr);
}
