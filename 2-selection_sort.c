#include "sort.h"

/**
 * swap - swaps values
 * @a: The first operand
 * @b: The second operand
 *
 * Return: nothing.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* selection_sort - sorts an array of integers in ascending order.
* @array: The array
* @size: The size of the array
*
* Return: nothing.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}

	}
}
