#include "Header.h"
//DAHUA
// traversing binary tree
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	putchar(T->c);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void CreateBiTree(BiTree* T) {
	TElemType ch;
	int ret = scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)calloc(1, sizeof(BiTNode));
		if (!(*T))
			exit(0);
		(*T)->c = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}