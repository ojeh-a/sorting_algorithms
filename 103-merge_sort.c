#include "sort.h"

/**
 * TDMerge - sorts and merges the sub arrays in source
 * @start: The starting index sor left sub array
 * @mid: end index for left and starting index for right sub array
 * @end: end index for the right sub array
 * @dest: destination for data.
 * @source: source of data.
 *
 * Reeturn: void
 */
void TDMerge(size_t start, size_t mid, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, mid - start);
	printf("[right]: ");
	print_array(source + mid, end - mid);
	i = start;
	j = mid;
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - Recursively splits the array and merges the sorted arrays.
 * @start: starting index
 * @end: end index
 * @array: array to sort
 * @cpy: a copy of the array
 *
 * Return: void.
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *cpy)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	TDSplitMerge(start, mid, array, cpy);
	TDSplitMerge(mid, end, array, cpy);
	TDMerge(start, mid, end, array, cpy);
	for (mid = start; mid < end; mid++)
		cpy[mid] = array[mid];
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *cpy;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (i = 0; i < size; i++)
		cpy[i] = array[i];
	TDSplitMerge(0, size, array, cpy);
	free(cpy);
}
