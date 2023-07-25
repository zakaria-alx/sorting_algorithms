#include "sort.h"

void merge_subarr(int *subarr, int *bfr, size_t front, size_t middle,
		size_t back);
void ms_recursive(int *subarr, int *bfr, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - ...
 * @subarr: ...
 * @bfr: ...
 * @front: ...
 * @middle: ...
 * @back: ...
 */
void merge_subarr(int *subarr, int *bfr, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, middle - front);

	printf("[right]: ");
	print_array(subarr + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		bfr[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < middle; i++)
		bfr[k++] = subarr[i];
	for (; j < back; j++)
		bfr[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = bfr[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * ms_recursive - ...
 * @subarr: ...
 * @bfr: ...
 * @front: ...
 * @back: ...
 */
void ms_recursive(int *subarr, int *bfr, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		ms_recursive(subarr, bfr, front, middle);
		ms_recursive(subarr, bfr, middle, back);
		merge_subarr(subarr, bfr, front, middle, back);
	}
}

/**
 * merge_sort - ...
 * @array: ...
 * @size: ...
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *bfr;

	if (array == NULL || size < 2)
		return;

	bfr = malloc(sizeof(int) * size);
	if (bfr == NULL)
		return;

	ms_recursive(array, bfr, 0, size);

	free(bfr);
}
