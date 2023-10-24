#include "sort.h"

/**
 * swap - swap two integers
 * @a: int a
 * @b: int b
 * Return: Swaped int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partition an array
 * @array: Array
 * @low: int low
 * @high: int high
 * @size: size of array
 * Return: index of pivote
 */
int partition(int *array, int low, int high, size_t size)
{
	int pvt = array[high];
	int m = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pvt)
		{
			m++;
			if (m != y)
			{
				swap(&array[m], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (m);
}

/**
 * lomuto_qsort - Sorting Recursively
 * @array: Array to be sorted
 * @low: lowest value in the array
 * @high: highest value in the array
 * @size: Size of The Array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
