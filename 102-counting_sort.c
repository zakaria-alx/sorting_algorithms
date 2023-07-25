#include "sort.h"

/**
 * get_max - ...
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
 * counting_sort - ...
 * @array: ...
 * @size: ...
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(counter);
}
