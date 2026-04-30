#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto - Lomuto partition scheme
 * @array: The array to partition
 * @lo: Left index
 * @hi: Right index
 * @size: Size of the full array
 *
 * Return: The pivot index
 */
int lomuto(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive quicksort helper
 * @array: The array to sort
 * @lo: Left index
 * @hi: Right index
 * @size: Size of the full array
 */
void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition)
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
