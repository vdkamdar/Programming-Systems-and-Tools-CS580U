#include "heap.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	printf("\n\n\t-----------------------------------\n");
	printf("\t- Test 1: Initialize Heap -\n");
	printf("\t-----------------------------------\n");

	printf("\n\n\tInserting 1000 random Data objects in an Data array...\n\n\n");

	int i;
	Data data[1000];

	for(i = 0; i < 1000; i++)
	{
		data[i] = (Data){((rand() % 1000) + 1)};
	}

	printf("\tCreating heap through heapify and implementing siftdown...\n\n\n");

	Heap * h = initHeap(data);

	printf("\t--- Test 1 passed... ---\n\n\n");

	printf("\t-----------------------------------\n");
        printf("\t- Test 2: Remove Priority -\n");
        printf("\t-----------------------------------\n");

	printf("\n\n\tRemoving the priorities from the heap...\n\n\n");

	Data prev = data[0];

	for(i = 0; i < 1000; i++)
	{
		Data next = removePriority(h);
		assert(prev.value <= next.value);
		prev = next;
	}

	printf("\t--- Test 2 passed... ---\n\n\n");

	printf("\tDelete heap and deallocate the heap memory...\n\n\n");

	deleteHeap(h);

	printf("\tMemory freed successfully and ready to submit.\n\n\n");

	return 0;
}
