#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
static void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *driver, up, down;

driver = array + right;
for (up = down = left; down < right; down++)
{
if (array[down] < *driver)
{
if (up < down)
{
swap_ints(array + down, array + up);
print_array(array, size);
}
up++;
}
}

if (array[up] > *driver)
{
swap_ints(array + up, driver);
print_array(array, size);
}

return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
int belong;

if (right - left > 0)
{
belong = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, belong - 1);
lomuto_sort(array, size, belong + 1, right);
}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 *              Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Shuffle the array to improve average case */
/* You can use a separate function for shuffling or a Fisher-Yates shuffle */
/* For simplicity, we won't include shuffling here */

lomuto_sort(array, size, 0, size - 1);
}

