#ifndef heap_h
#define heap_h

typedef struct data
{
	int value;
}Data;

typedef struct heap
{
	Data * data;
	int current_size;
	int maximum_capacity;
}Heap;

Heap * initHeap(Data * d);

void siftDown(Heap * h, int index);

void * heapify(Heap * h);

Data removePriority(Heap * h);

void deleteHeap(Heap *);

#endif
