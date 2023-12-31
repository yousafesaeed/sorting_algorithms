#include "sort.h"

/**
 * heapify - Puts an array array in a heap.
 * @array: The array to be sorted
 * @min: Starting point of the array
 * @max: Ending point of the array
 * @size: Size of @array
 */
void heapify(int *array, int min, int max, size_t size)
{
	int root = min;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int tmp;

	if (left < max && array[left] > array[root])
		root = left;
	if (right < max && array[right] > array[root])
		root = right;

	if (min != root)
	{
		tmp = array[root];
		array[root] = array[min];
		array[min] = tmp;
		print_array(array, size);
		heapify(array, root, max, size);
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: The array to be sorted
 * @size: Size of @array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int tmp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size, size);

	i = size - 1;
	while (i > 0)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;

		print_array(array, size);
		heapify(array, 0, i, size);
		i--;
	}
}
