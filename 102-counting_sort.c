#include "sort.h"

/**
 * counting_sort - sort using countingSort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *countArray;
	int *sortedArray;
	int i;
	size_t j;
	int max = 0;

	for (j = 0; j < size; j++)
		if (array[j] > max)
			max = array[j] + 1;

	countArray = malloc(sizeof(int) * max);
	sortedArray = malloc(sizeof(int) * size);

	for (i = 0; i < max; i++)
		countArray[i] = 0;
	for (i = 0; i < max; i++)
		for (j = 0; j < size; j++)
			if (i == array[j])
				countArray[i] += 1;

	for (i = 1; i < max; i++)
		countArray[i] += countArray[i - 1];
	for (i = 0; i < max - 1; i++)
		printf("%i, ", countArray[i]);
	printf("%i\n", countArray[i]);

	for (j = 0; j < size; j++)
		sortedArray[countArray[array[j] - 1]] = array[j];

	for (j = 0; j < size; j++)
		array[j] = sortedArray[j];

	free(countArray);
	free(sortedArray);
}
