#include <stdlib.h>
#include <stdio.h>

typedef int KeyType;
typedef struct BSTNode
{
	KeyType key;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;
void BST_PreOrder(BiTree T)
{
	if (T)
	{
		printf("%d", T->key);
		BST_PreOrder(T->lchild);
		BST_PreOrder(T->rchild);
	}
}
void BST_InOrder(BiTree T)
{
	if (T)
	{
		BST_InOrder(T->lchild);
		printf("%d", T->key);
		BST_InOrder(T->rchild);
	}
}
void BST_Insert(BiTree &T, KeyType data)
{
	BiTree newnode = (BiTree)malloc(sizeof(BSTNode));
	newnode->key = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (T == NULL)
	{
		T = newnode;
		return;
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
void BST_Insert_NoRecursion(BiTree &T, KeyType data)
{
	BiTree newnode = (BiTree)malloc(sizeof(BSTNode));
	newnode->key = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (T == NULL)
	{
		T = newnode;
		return;
	}
	BiTree temp = T; // use temp node to loop through end
	while (temp)
	{
		if (data > temp->key)
		{
			if (NULL != temp->rchild)
				temp = temp->rchild;
			else
			{ // rchild not exist
				temp->rchild = newnode;
				return;
			}
		}
		else if (data < temp->key)
		{
			if (temp->lchild)
				temp = temp->lchild;
			else
			{
				temp->lchild = newnode;
				return;
			}
		}
	}
}
void Create_BST(BiTree &T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}
BSTNode *BST_Search(BiTree T, KeyType key, BiTree &parent)
{
	parent = NULL;
	while (T != NULL && key != T->key)
	{
		parent = T;
		if (key < T->key)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}
BSTNode *BST_Search2(BiTree T, KeyType key, BiTree &parent)
{
	if (T == NULL || T->key == key)
	{
		return T;
	}
	parent = T; // parent is the T's parent
	if (key > T->key)
	{
		return BST_Search2(T->rchild, key, parent);
	}
	else if (key < T->key)
		return BST_Search2(T->lchild, key, parent);
}

void DeleteNode(BiTree &T, KeyType key)
{
	BiTree search_node, parent_node;
	search_node = BST_Search(T, key, parent_node);
	if (NULL == search_node)
	{
		printf("not find!\n");
		return;
	}
	// specific situation
	if (search_node->lchild && search_node->rchild)
	{
		// find the largest node in left sub tree
		BiTree temp = search_node->lchild;
		BiTree temp_p = temp;
		while (temp->rchild)
		{
			temp_p = temp;
			temp = temp->rchild;
		}
		search_node->key = temp->key;
		temp_p->rchild = NULL;
		return;
	}
	// if search_node is the left child
	if (parent_node->lchild == search_node)
	{
		if (search_node->lchild)
			parent_node->lchild = search_node->lchild;
		else if (search_node->rchild)
			parent_node->lchild = search_node->rchild;
		else // serch node has no child
			parent_node->lchild = NULL;
		return;
	}
	// search node is the right child
	if (search_node->lchild != NULL)
	{
		parent_node->rchild =search_node->lchild;
	}
	else if (search_node->rchild != NULL)
	{
		parent_node->rchild = search_node->rchild;
	}
	else
	{ // serch node has no child
		parent_node->rchild = NULL;
	}
}
int main()
{
	BSTNode *tree, *node, *parent;
	KeyType arr[9] = {6, 1, 8, 2, 7, 4, 3, 9, 5}; // Binary Search Tree Data
	Create_BST(tree, arr, 9);
	node = BST_Search2(tree, 4, parent);
	printf("%d\t%d\n", node->key, parent->key);
	DeleteNode(tree, 3); // delete element 3
	BST_InOrder(tree);
	printf("\n");
	return 0;
}