#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the counting sort algorithm
 * @array: array to sort.
 * @size: size of the array.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count = NULL, *cpy = NULL;
	size_t j, tmp, total = 0;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(cpy);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 0; i <= max; i++)
	{
		tmp = count[i];
		count[i] = total;
		total += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[cpy[j]]] = cpy[j];
		count[cpy[j]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(cpy);
}
