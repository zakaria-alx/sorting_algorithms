#include "sort.h"

/**
 * bubble_sort - ...
 *
 * @array: ...
 * @size: ...
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int img, moved;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		moved = 0;

		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				img = array[j];
				array[j] = array[j + 1];
				array[j + 1] = img;
				moved = 1;

				/* Print array after each swap */
				print_array(array, size);
			}
		}

/* If no moved element in the inner loop, the array is already sorted */
	if (moved == 0)
	break;
	}
}

