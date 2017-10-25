#ifndef vector_h
#define vector_h

typedef struct data
{
        int value;
}Data;

typedef struct vector
{
        Data * data;
        unsigned int current_size;
        unsigned int max_size;
	int * index_array;
}Vector;

Vector * initVector();

void vectorInsert(Vector * array, int index, Data value);

void vectorInsertIncremental(Vector * array, int index, Data value);

void vectorInsertMine(Vector * array, int index, Data value);

Data * vectorRead(Vector * array, int index);

void vectorRemove(Vector * array, int index);

void * deleteVector(Vector *);

#endif
