#include"heap.h"
#include<stdio.h>
#include<stdlib.h>

Heap * initHeap(Data * d)					//Initializes the heap
{
	Heap * heap = malloc(sizeof(Heap));			//Allocates the space
	heap->data = NULL;					//Initialize to NULL

        heap->data = d;						//Initializes with the data created
	heap->current_size = 1000;
	heap->maximum_capacity = 1000;

	heapify(heap);

	return heap;
}

void * heapify(Heap * h)					//Converts the array into an Heap
{
	int i;

	for(i = ((h->current_size) - 2) / 2; i >= 0; i--)	//Gets the last non-leaf node
	{
		siftDown(h,i);
	}
}

void siftDown(Heap * h, int i)					//Implements the siftdown
{
	if((i < 0) || (i >= h->current_size))
	{
		return;
	}

	while(((2 * i) + 2 <= h->current_size) || ((2 * i) + 2 <= h->current_size))	//Checks the leaf condition.(Node should not be the leaf node)
	{
		int l = 2*i + 1;				//Left
		int r = 2*i + 2;				//Right
		int j = l;					//Flag for swapping

		if((j + 1 < h->current_size) && (h->data[j].value > h->data[j+1].value))
		{
			j = j + 1;
		}

		if(h->data[i].value < h->data[j].value)
		{
			return;
		}
		else						//Swapping the values
		{
			int temp = h->data[j].value;
			h->data[j].value = h->data[i].value;
			h->data[i].value = temp;

			i = j;
		}
	}
}

Data removePriority(Heap * h)					//Removes the priority from the heap
{
	Data temp = h->data[0];
	h->data[0] = h->data[h->current_size - 1];
	h->data[h->current_size - 1] = temp;

	h->current_size = h->current_size - 1;
	siftDown(h, 0);

	return h->data[h->current_size];
}

void deleteHeap(Heap * heap)					//Frees the memory
{
	free(heap);
	heap = NULL;
}
