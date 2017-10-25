#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

Node * createNode(Data d, Node * parent)
{
	Node * newNode = malloc(sizeof(Node));
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	return newNode;
}

Tree * createTree()
{
	Tree * tree = malloc(sizeof(Tree));
	tree->root = NULL;

	return tree;
}

Data * insert(Tree * bst, Data value)
{
	        if(bst->root == NULL)
	        {
	                bst->root = createNode(value, NULL);
        	        bst->root->parent = NULL;
			return &(bst->root->data);
        	}
	        else
        	{
			Node * temp = searchNode(bst->root, value);

			if(temp != NULL)
			{
				return NULL;
			}
			else
			{
				Data * temp = insertNode(bst->root, value);
				return &(bst->root->data);
			}
			free(temp);
	        }
}

Data * insertNode(Node * node, Data value)
{
	if(value.value < node->data.value)
	{
		if(node->left == NULL)
		{
			node->left = createNode(value, NULL);
			node->left->parent = node;
		}
		else
		{
			insertNode(node->left, value);
		}
	}
	else if(value.value > node->data.value)
	{
		if(node->right == NULL)
		{
			node->right = createNode(value, NULL);
			node->right->parent = node;
		}
		else
		{
			insertNode(node->right, value);
		}
	}
	return &(node->data);
}

void sort(Tree * bst, Data * data)
{
	int i = 0;
	int temp = sortAux(bst->root, data, i);
}

//Auxillary function for sort

int sortAux(Node * current, Data * data, int i)
{
	if(current == NULL)
	{
		return i;
	}

	else
	{
		if(current->left != NULL)
		{
			i = sortAux(current->left, data, i);
		}

		data[i].value = current->data.value;
		i++;

		if(current->right != NULL)
		{
			i = sortAux(current->right, data, i);
		}
	}
	return i;
}

Data * search(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
//		printf("\nEmpty tree.\n\n");
		return NULL;
	}
	else if(bst->root->data.value == value.value)
	{
		return &(bst->root->data);
	}
	else
	{
		Node * current = searchNode(bst->root, value);
		return &(current->data);
	}
}

// Required extra function used in removeNode


Node * searchTree(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
		return NULL;
	}

	else if(bst->root->data.value == value.value)
	{
		return bst->root;
	}

	else
	{
		Node * current = searchNode(bst->root, value);
		return current;
	}
}

//Auxillary function for search

Node * searchNode(Node * node, Data value)
{
	if(node->data.value == value.value)
	{
		return node;
	}
	else if(node->data.value > value.value)
	{
		if(node->left == NULL)
		{
			return NULL;
		}
		else
		{
			searchNode(node->left, value);
		}
	}
	else
	{
		if(node->right == NULL)
		{
			return NULL;
		}
		else
		{
			searchNode(node->right, value);
		}
	}
}

void removeData(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
//		printf("Empty tree.\n");
	}
	else
	{
		Node * current = searchTree(bst, value);

		if(current == NULL)
		{
//			printf("Value not found.\n");
		}
		else
		{
			if(current->left == NULL && current->right == NULL)
			{
				removeLeaf(bst, current);
			}
			else if(current->left == NULL || current->right == NULL)
			{
				shortCircuit(bst, current);
			}
			else
			{
				promotion(bst, current);
			}
		}
	}
}

//Auxillary function for remove

void removeLeaf(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
//		printf("Emptying the tree.\n\n");
		bst->root = NULL;
	}
	else if(d_node == d_node->parent->left)
	{
		d_node->parent->left = NULL;
	}
	else
	{
		d_node->parent->right = NULL;
	}

	free(d_node);
	d_node = NULL;
}

//Auxillary function for remove

void shortCircuit(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		if(d_node->left != NULL)
		{
			bst->root = d_node->left;
			d_node->left->parent = NULL;
		}
		else
		{
			bst->root = d_node->right;
			d_node->right->parent = NULL;
		}
	}
	else if(d_node == d_node->parent->left)
	{
		if(d_node->left != NULL)
		{
			d_node->parent->left = d_node->left;
			d_node->left->parent = d_node->parent;
			//printf("%ddfs", d_node->right->data.value);
		}
		else
		{
			d_node->parent->left = d_node->right;
			d_node->right->parent = d_node->parent;
			//printf("%ddfs", d_node->left->data.value);
		}
	}
	else
	{
		if(d_node->left != NULL)
		{
			d_node->parent->right = d_node->left;
			d_node->left->parent = d_node->parent;
		}
		else
		{
			d_node->parent->right = d_node->right;
			d_node->right->parent = d_node->parent;
		}
	}
	free(d_node);
	d_node = NULL;
}

//Auxillary function for remove

// USING 1st METHOD OF PROMOTION (LEFTMOST OF RIGHT SUBTREE)

void promotion(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		//printf("%d", d_node->data.value);
		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else if(d_node->right->left == NULL)
		{
				d_node->data.value = d_node->right->data.value;
				shortCircuit(bst, d_node->right);
		}
		else
		{
			Node * current = d_node->right;
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
	else if(d_node == d_node->parent->right)
	{
		Node * current = d_node->right;

		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
//			printf("Promoting %d. ", d_node->right->data.value);
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}
		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
	else
	{
		Node * current = d_node->right;
		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
//			printf("Promoting %d. ", d_node->right->data.value);
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}
		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
}

Tree * clone(Tree * original)
{
	Tree * t = createTree();
	t = traversen(original->root, t);
	return t;
}

//Auxillary function for clone

Tree * traversen(Node * node, Tree * t)
{
	if(node != NULL)
	{
		insert(t, node->data);
		traversen(node->left, t);
		traversen(node->right, t);
	}
	return t;
}

int compare(Tree * t, Tree * copy)
{
	if(t == NULL || copy == NULL)
	{
		return 0;
	}
	int flag = compared(t->root, copy->root);

	return flag;
}

//Auxillary function for compared

int compared(Node * node, Node * copy)
{
	int f = 1;

	if(node!= NULL && copy!= NULL)
	{
		if(node->data.value == copy->data.value)
		{
			f = 1;
			compared(node->left, copy->left);
			compared(node->right, copy->right);
		}
		else
		{
			return f;
		}
	}
	else if(node == NULL && copy == NULL)
	{
		f = 1;
	}
	return f;
}

void deleteTree(Tree * t)
{
		deleteData(t, t->root);
		free(t);
		t = NULL;
}

//Auxillary function for delete

void deleteData(Tree * t, Node * current)
{
	if(current != NULL)
	{
		deleteData(t, current->left);
		deleteData(t, current->right);
//		printf("%d %p\n", current->data.value, current);
		removeLeaf(t, current);
	}
}

//Required extra function used for displaying tree using Pre-Order traversal

void inOrder(Tree * t, Node * current)
{
	if(t->root == NULL)
	{
		printf("Empty tree.\n");
	}
	else if(current != NULL)
	{
                printf("%d\n", current->data.value);
		inOrder(t, current->left);
		inOrder(t, current->right);

	}
}
