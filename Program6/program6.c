#include"list.h"
#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(){

    printf("\t-----------------------------------\n");
	printf("\t-          Part1 : Lists        -\n");
	printf("\t-----------------------------------\n");

	printf("\n\t=========Test #1: Creating your Linked List===========\n\n");
    List * list = createList();
    assert(list->head == NULL && list->tail == NULL);
    printf("\n\t\tTest #1: Passed ...\n\n");

    printf("\n\t=========Test #2: Linked List Insertion===========\n\n");
    int index = 0;
    //add elements to the list
    for(index = 0 ; index < 10 ; index++ ){
        insertData(list , index, (Data){index+1});
    }
    assert(list->head != NULL && list->tail != NULL);
    assert(list->head->next != NULL && list->head->prev == NULL);
    assert(list->tail->next == NULL && list->tail->prev != NULL);
    Node * test = list->head;
    for(index = 0 ; index < 10 ; index++, test = test->next){
        assert(test->data.value == index +1);
    }
    //***** Test that out of bounds indexes are appended to the list ****/
    insertData(list , 20, (Data){11});
    assert(list->tail->data.value == 11);

    fprintf(stderr, "\n\t\tTest #2: Passed ...\n\n");

    printf("\n\t=========Test #3: Linked List Read===========\n\n");
    for(index = 0 ; index < 10 ; index++){
        Data * d = readData(list, index);
        assert(d->value == index +1);
    }
    Data * d = readData(list, 20);
    assert(d == NULL);
    printf("\n\t\tTest #3: Passed ...\n\n");

    printf("\n\t=========Test #4: Linked List Search===========\n\n");
    int steps = searchForward(list, (Data) {5});
    assert(steps == 4);
    steps = searchBackward(list, (Data) {5});
    assert(steps == 6);
    steps = searchBackward(list, (Data) {100});
    assert(steps == -1);

    printf("\n\t\tTest #4: Passed ...\n\n");

    printf("\n\t=========Test #5: Test Stack===========\n\n");
    Stack stack = {createList()};
    for(index = 0 ; index < 5 ; index++ ){
        Data data = {index+1};
        push(&stack, data);
    }
    for(index = 5 ; index > 0 ; index-- ){
        Data new_data = pop(&stack);
        assert(index == new_data.value);
    }
    assert(stack.list->head == NULL && stack.list->tail == NULL);
    printf("\n\t\tTest #5: Passed ...\n\n");
    printf("\n\t=========Test #6: Test Queue===========\n\n");
    Queue queue = {createList()};
    for(index = 0 ; index < 5 ; index++ ){
        Data data = {index+1};
        enqueue(&queue, data);
    }
    for(index = 1 ; index < 6 ; index++ ){
        Data new_data = dequeue(&queue);
        assert(index == new_data.value);
    }
    assert(queue.list->head == NULL && queue.list->tail == NULL);
    fprintf(stderr, "\n\t\tTest #6: Passed ...\n\n");
    fprintf(stderr, "\n\t=========Test #7: Linked List Remove===========\n\n");

    for(index = 0; !isEmpty(list); index++){
        index = index % 3;
        removeData(list , index );
    }
    assert(list->head == NULL && list->tail == NULL);
    deleteList(list);
    deleteList(queue.list);
    deleteList(stack.list);
    fprintf(stderr, "\n\t\tTest #7: Passed.\nDon't forget to check your code with Valgrind!\n\n");
    return 0;
}
