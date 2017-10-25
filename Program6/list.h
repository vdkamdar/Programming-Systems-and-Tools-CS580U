#ifndef list_h
#define list_h

typedef struct data
{
        int value;
}Data;

typedef struct node
{
	Data data;
	struct node * next;
	struct node * prev;
}Node;

typedef struct list
{
	Node * head;
	Node * tail;
	int index;
}List;

List * createList();

void insertData(List * , int , Data );

//void printList(List *);

void removeData(List * , int );

Data * readData(List * , int );

int isEmpty(List *);	//returns 0 if empty and 1 if not empty

void deleteList(List * );	//deletes the entire list from memory

int searchForward(List *, Data);

int searchBackward(List *, Data);

typedef struct stack
{
	List * list;
}Stack;

void push(Stack *, Data);

Data pop(Stack *);

typedef struct queue
{
	List * list;
}Queue;

void enqueue(Queue *, Data);

Data dequeue(Queue *);

#endif
