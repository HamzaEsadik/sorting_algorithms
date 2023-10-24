#include "sort.h"

/**
 * locate_min - Locatin the min From Current index
 * @array: The Array to be Searched
 * @index: Starting Index of The Search
 * @size: Array size
 * Return: index of min if found
 */
int locate_min(int *array, int index, size_t size)
{
	int min, min_index;
	int i;

	min = array[index];
	min_index = index;
	for (i = index; i < (int)size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			min_index = i;
		}
	}
	if (min_index == index)
		return (-1);
	return (min_index);
}

/**
 * selection_sort - The Implementation of selection Sort Algrithme
 * @array: Array to sort type
 * @size: The Size of Array
 * Return: Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int min, temp;

	for (i = 0; i < (int)size; i++)
	{
		min = locate_min(array, i, size);
		if (min != -1)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
