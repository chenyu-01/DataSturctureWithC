#include <stdlib.h>
#include <stdio.h>

typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BiTree;
void BST_PreOrder(BiTree T) {
	if (T)
	{
		printf("%d", T->key);
		BST_PreOrder(T->lchild);
		BST_PreOrder(T->rchild);
	}
}
void BST_InOrder(BiTree T) {
	if (T)
	{
		BST_InOrder(T->lchild);
		printf("%d", T->key);
		BST_InOrder(T->rchild);
	}
}
void BST_Insert(BiTree& T, KeyType data) {
	BiTree newnode = (BiTree)malloc(sizeof(BSTNode));
	newnode->key = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (T == NULL) {
		T = newnode;
	}
	if (data > T->key)
	{
		BST_Insert(T->rchild, data);
	}
	else if (data < T->key)
	{
		BST_Insert(T->lchild, data);
	}
}
void BST_Insert_NoRecursion(BiTree& T, KeyType data) {
	BiTree newnode = (BiTree)malloc(sizeof(BSTNode));
	newnode->key = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (T == NULL) {
		T = newnode;
		return;
	}
	BiTree temp = T;
	while (temp) {
		if (data > temp->key)
		{
			if (temp->rchild)
				temp = temp->rchild;
			else {
				temp->rchild = newnode;
				return;
			}
		}
		else if (data < temp->key) {
			if (temp->lchild)
				temp = temp->lchild;
			else {
				temp->lchild = newnode;
				return;
			}
		}
	}
}
void Create_BST(BiTree& T, KeyType str[], int n) {
	T = NULL;
	int i = 0;
	while (i<n)
	{
		BST_Insert_NoRecursion(T, str[i]);
		i++;
	}
}
BSTNode* BST_Search;
int main() {
	BSTNode* tree ;
	KeyType arr[9] = { 2,7,4,3,9,5,6,1,8 };//Binary Search Tree Data
	Create_BST(tree, arr, 9);
	BST_InOrder(tree);
	return 0;

}