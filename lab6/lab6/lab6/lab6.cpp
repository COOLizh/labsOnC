#include "stdafx.h"
#include <tchar.h>
#include <stdio.h>
#include <malloc.h>

typedef struct 
{
	int num;

	struct Tree *left;
	struct Tree *right;
} Tree;

void AddNode(int data, Tree **node)
{
	if (*node == NULL) {
		*node = (Tree *)calloc(1, sizeof(Tree));
		(*node)->num = data;
		(*node)->left = (*node)->right = NULL;
	}
	else {
		if (data < (*node)->num)
			AddNode(data, &(*node)->left);
		else
			AddNode(data, &(*node)->right);
	}
}

void createTree(Tree **root, char *str) {
	while (*str) {
		if (*str >= '0' && *str <= '9') {
			AddNode(*str - '0', root);
		}
		str++;
	}
}

void LeftOrder(Tree *node)
{
	if (node->left)
		LeftOrder(node->left);
	printf("%d ", node->num);
	if (node->right)
		LeftOrder(node->right);
}

int main() {
	Tree *root = NULL;

	char *str = (char*) malloc(100*sizeof(char));
	printf("Enter string: ");
	gets(str);

	createTree(&root, str);

	printf("Your nums: \n");
	LeftOrder(root);

	return 0;
}
