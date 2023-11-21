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
* partition - implement the hoare partition scheme
* @array: The array to be sorted
* @l: The left side of the array
* @r: The right side of the array
* @size: The size of the array
*
* Return: Integer.
*/
int partition(int *array, int l, int r, size_t size)
{
	int pivot = array[r];

	while (l <= r)
	{
		while (array[l] < pivot)
		{
			l++;
                }

		while (array[r] > pivot)
		{
			r++;
		}

		if (l <= r)
		{
			if (l != r)
			{
				swap(&array[l], &array[r]);
				print_array(array, size);
			}
			r++;
			l--;
		}
	}
	return (r);
}

/**
* hoare_sort_recursion - sorts arrays recursively
* @array: The array to be sorted
* @l: The left side of the array
* @r: The right side of the array
* @size: The size of the array
*
* Return: nothing.
*/
void hoare_sort_recursion(int *array, int l, int r, size_t size)
{
	int pivot_index;

	if (l < r)
	{
		pivot_index = partition(array, l, r, size);
		hoare_sort_recursion(array, l, pivot_index, size);
		hoare_sort_recursion(array, pivot_index + 1, r, size);
	}
}

/**
* quick_sort_hoare - sorts an array of integers in ascending order
* @array: The array to be sorted
* @size: The size of the array
*
* Return: nothing.
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort_recursion(array, 0, size - 1, size);
}

