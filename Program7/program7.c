#include "bst.h"
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("\t-----------------------------------\n");
	printf("\t-          Part1 : BST        -\n");
	printf("\t-----------------------------------\n");

	//test data
	int d[] = {5,3,10,4,8,2,1,7,9,6,12,11,13};
	int num_data = 13;
	Data test[num_data];
	int i;

	printf("\n\t=========Test #1: Creating your BST===========\n\n");

	Node * n = createNode((Data){1}, NULL);
	assert(n->parent == NULL);
	assert(n->left == NULL);
	assert(n->right == NULL);
	assert(n->data.value == 1);
	free(n);
	n = NULL;
	Tree *bst = createTree();
	assert(bst->root == NULL);

	printf("\n\t\tTest #1: Passed ...\n\n");

    printf("\n\t=========Test #2: BST Insertion===========\n\n");
	for (i = 0; i < num_data; i++){
		insert(bst, (Data){d[i]});
	}
	printf("\n\t\tTest #2: Passed ...\n\n");

	printf("\n\t=========Test #3: Insert Duplicates===========\n\n");
	assert(insert(bst, (Data){9}) == NULL);

	printf("\n\t\tTest #3: Passed ...\n\n");

	printf("\n\t=========Test #4: Sort search===========\n\n");

	sort(bst, test);
	Data prev = test[0];
	for (i = 1; i < num_data; i++){
		Data next = test[i];
		fprintf(stderr, "%d < %d\n ", prev.value, next.value);
		assert(prev.value <= next.value);
		prev = next;
	}

	printf("\n\t\tTest #4: Passed ...\n\n");

    printf("\n\t=========Test #5: BST Search===========\n\n");
	int search_test[] = {5,3,10,4,8,2,1,7,9,6,12,11,13,14};
	for(i = 0; i < num_data; i++){
		Data * result = search(bst, (Data) {search_test[i]});
		assert(result->value == search_test[i]);
	}
	printf("\n\t\tTest #5: Passed ...\n\n");

    printf("\n\t=========Test #6: BST Search for Missing Value===========\n\n");

	Data * result = search(bst, (Data) {search_test[i]});
	assert(result == NULL);

	printf("\n\t\tTest #6: Passed ...\n\n");

	printf("\n\t=========Test #7: Clone and Compare Tree===========\n\n");

	Tree * copy_bst = clone(bst);
	int compare_result = compare(NULL, copy_bst);
	assert(compare_result == 0);
	compare_result = compare(bst, copy_bst);
	assert(compare_result == 1);

	printf("\n\t\tTest #7: Passed ...\n\n");

	printf("\n\t=========Test #8: Remove Value not in Tree===========\n\n");

	removeData(bst, (Data) {14});
	compare_result = compare(bst, copy_bst);
	assert(compare_result == 1);

	printf("\n\t\tTest #8: Passed ...\n\n");

	printf("\n\t=========Test #9: Remove a Leaf Node ===========\n\n");

	removeData(bst, (Data) {1});
	Tree * test9 = createTree();
	int test9_data[] = {5,3,10,4,8,2,7,9,6,12,11,13};
	for (i = 0; i < num_data-1; i++){
		insert(test9, (Data){test9_data[i]});
	}
	compare_result = compare(bst, test9);
	assert(compare_result == 1);

	printf("\n\t\tTest #9: Passed ...\n\n");

	printf("\n\t=========Test #10: Remove Single Child Node using Short Circuit ===========\n\n");

	removeData(bst, (Data) {7});
	Tree * test10 = createTree();
	int test10_data[] = {5,3,10,4,8,2,9,6,12,11,13};
	for (i = 0; i < num_data-2; i++){
		insert(test10, (Data){test10_data[i]});
	}
	compare_result = compare(bst, test10);
	assert(compare_result == 1);
	printf("\n\t\tTest #10: Passed ...\n\n");

	printf("\n\t=========Test #11: Remove Two Child Node using Promotion with Leaf Node ===========\n\n");

	removeData(bst, (Data) {10});
	Tree * test11 = createTree();
	int test11_data[] = {5,11,3,4,8,2,9,6,12,13};
	for (i = 0; i < num_data-3; i++){
		insert(test11, (Data){test11_data[i]});
	}
	compare_result = compare(bst, test11);
	assert(compare_result == 1);
	printf("\n\t\tTest #11: Passed ...\n\n");

	printf("\n\t=========Test #12: Remove Two Child Node using promotion with Short Circuit ===========\n\n");

	removeData(bst, (Data) {11});
	Tree * test12 = createTree();
	int test12_data[] = {5,12,3,4,8,2,9,6,13};
	for (i = 0; i < num_data-4; i++){
		insert(test12, (Data){test12_data[i]});
	}
	compare_result = compare(bst, test12);
	assert(compare_result == 1);
	printf("\n\t\tTest #12: Passed ...\n\n");

	printf("\n\t=========Test #13: Remove Root with 2 Branches===========\n\n");

	removeData(bst, (Data) {5});
	Tree * test13 = createTree();
	int test13_data[] = {6,12,3,4,8,2,9,13};
	for (i = 0; i < num_data-5; i++){
		insert(test13, (Data){test13_data[i]});
	}
	compare_result = compare(bst, test13);
	assert(compare_result == 1);
	printf("\n\t\tTest #13: Passed ...\n\n");

	printf("\n\t=========Test #14: Remove Root with 1 Branch ===========\n\n");

	removeData(bst, (Data) {3});
	removeData(bst, (Data) {4});
	removeData(bst, (Data) {2});
	removeData(bst, (Data) {6});
	Tree * test14 = createTree();
	int test14_data[] = {12,8,9,13};
	for (i = 0; i < 4; i++){
		insert(test14, (Data){test14_data[i]});
	}
	compare_result = compare(bst, test14);
	assert(compare_result == 1);
	printf("\n\t\tTest #14: Passed ...\n\n");

	printf("\n\t=========Test #15: Remove Root as Leaf ===========\n\n");

	removeData(bst, (Data) {9});
	removeData(bst, (Data) {8});
	removeData(bst, (Data) {13});
	removeData(bst, (Data) {12});
	assert(bst->root == NULL);

	printf("\n\t\tTest #15: Passed ...\n\n");

	printf("\n\t=========Test #16: Delete Tree===========\n\n");

	deleteTree(bst);
	deleteTree(copy_bst);
	deleteTree(test9);
	deleteTree(test10);
	deleteTree(test11);
	deleteTree(test12);
	deleteTree(test13);
	deleteTree(test14);

	printf("\n\t\tTest #16 Passed: Don't Forget to run valgrind and submit ...\n\n");
	return 0;
}
