#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void buildHeap(int *, size_t);
void percolateDown(int *, size_t, size_t, size_t);
void heap_sort(int *, size_t);

/**
 * buildHeap - transforms an unsorted array into a complete
 * binary tree with heap property.
 * @inputArray: array to be converted
 * @arraySize: size of the array
 */
void buildHeap(int *inputArray, size_t arraySize)
{
	size_t rootIndex;

	if (!inputArray || arraySize < 2)
		return;
	rootIndex = arraySize / 2;
	do {
		rootIndex--;
		percolateDown(inputArray, rootIndex, arraySize, arraySize);
	} while (rootIndex);
}

/**
 * percolateDown - positions the root at index `rootIndex` in `heapArray`
 * correctly
 * @heapArray: heap structure to sift
 * @rootIndex: index of root to sift
 * @endIndex: last index to consider
 * @arraySize: size of heap
 */
void percolateDown(
	int *heapArray,
	size_t rootIndex,
	size_t endIndex,
	size_t arraySize)
{
	int buffer;
	size_t leftChildIndex, rightChildIndex, largestIndex;

	leftChildIndex = 2 * rootIndex + 1;
	rightChildIndex = 2 * rootIndex + 2;
	largestIndex = rootIndex;

	if (leftChildIndex < endIndex
		&& heapArray[leftChildIndex] > heapArray[largestIndex])
		largestIndex = leftChildIndex;
	if (rightChildIndex < endIndex
		&& heapArray[rightChildIndex] > heapArray[largestIndex])
		largestIndex = rightChildIndex;
	if (largestIndex != rootIndex)
	{
		buffer = heapArray[rootIndex];
		heapArray[rootIndex] = heapArray[largestIndex];
		heapArray[largestIndex] = buffer;
		print_array(heapArray, arraySize);
		percolateDown(heapArray, largestIndex, endIndex, arraySize);
	}
}

/**
 * heap_sort - executes heap sort algorithm on `inputArray`
 * @inputArray: array to sort
 * @arraySize: size of `inputArray`
 */
void heap_sort(int *inputArray, size_t arraySize)
{
	size_t idx;
	int buffer;

	if (inputArray == NULL || arraySize < 2)
		return;
	buildHeap(inputArray, arraySize);
	for (idx = arraySize - 1; idx > 0; idx--)
	{
		buffer = inputArray[0];
		inputArray[0] = inputArray[idx];
		inputArray[idx] = buffer;
		print_array(inputArray, arraySize);
		percolateDown(inputArray, 0, idx, arraySize);
	}
}
