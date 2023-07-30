#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * mergeSplits - Merges an array that has been divided using the
 * top-down merge sort approach.
 * @dataArray: The array to merge.
 * @copyArray: The temporary array.
 * @leftIdx: The left index of the divided-array.
 * @middleIdx: The middle point of the divided-array.
 * @rightIdx: The right index of the divided-array.
 */
void mergeSplits(
	int *dataArray,
	int *copyArray,
	size_t leftIdx,
	size_t middleIdx,
	size_t rightIdx)
{
	size_t leftCounter = leftIdx, rightCounter = middleIdx, combinedCounter;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(dataArray + leftIdx, middleIdx - leftIdx);
	printf("[right]: ");
	print_array(dataArray + middleIdx, rightIdx - middleIdx);
	for (combinedCounter = leftIdx; combinedCounter < rightIdx;
		 combinedCounter++)
	{
		if ((leftCounter < middleIdx)
			&& ((rightCounter >= rightIdx)
				|| (copyArray[leftCounter] <= copyArray[rightCounter])))
		{
			dataArray[combinedCounter] = copyArray[leftCounter++];
		} else
		{
			dataArray[combinedCounter] = copyArray[rightCounter++];
		}
	}
	printf("[Done]: ");
	print_array(dataArray + leftIdx, rightIdx - leftIdx);
}

/**
 * partitionAndMerge - Sorts a divided array using the
 * merge sort algorithm.
 * @dataArray: The divided array.
 * @copyArray: The temporary array.
 * @arrayLength: The length of the original array.
 * @leftIdx: The left index of the divided-array.
 * @rightIdx: The right index of the divided-array.
 */
void partitionAndMerge(
	int *dataArray,
	int *copyArray,
	size_t arrayLength,
	size_t leftIdx,
	size_t rightIdx)
{
	size_t index, middleIdx;

	if ((rightIdx - leftIdx) <= 1)
		return;
	middleIdx = (leftIdx + rightIdx) / 2;
	partitionAndMerge(dataArray, copyArray, arrayLength, leftIdx, middleIdx);
	partitionAndMerge(dataArray, copyArray, arrayLength, middleIdx, rightIdx);
	for (index = leftIdx;
		 index <= rightIdx + (rightIdx == arrayLength ? -1 : 0);
		 index++)
		copyArray[index] = dataArray[index];
	mergeSplits(dataArray, copyArray, leftIdx, middleIdx, rightIdx);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @dataArray: The array to sort.
 * @arrayLength: The length of the array.
 */
void merge_sort(int *dataArray, size_t arrayLength)
{
	size_t index;
	int *copyArray = NULL;

	if (dataArray != NULL)
	{
		copyArray = malloc(sizeof(int) * arrayLength);
		if (copyArray != NULL)
		{
			for (index = 0; index < arrayLength; index++)
				copyArray[index] = dataArray[index];
			partitionAndMerge(
				dataArray, copyArray, arrayLength, 0, arrayLength);
			free(copyArray);
		}
	}
}
