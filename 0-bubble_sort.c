#include "sort.h"

/**
 * bubble_sort - function which sorts the array using bubble sort
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, optimize = size - 1;
	int swap = 0, temp;

	/* when empty or contains only one element */
	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		/*
		 * enhances the variable used to save on time
		 * everytime the largest object appears on the far most right
		 */
		for (j = 0; j < optimize; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		if (swap == 0)
			return;
		swap = 0;
		optimize--;
	}
}
