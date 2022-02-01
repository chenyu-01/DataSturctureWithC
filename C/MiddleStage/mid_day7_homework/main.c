#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char TElemType;
typedef struct BiTNode {
	TElemType c;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef struct tag{
	BiTree p;
	struct tag* pnext;
}tag_t, * ptag_t;

void PreOrder(BiTree T) {
	if (NULL != T)
	{
		printf("%c", T->c);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void HirachicalBuild(BiTree* tree) {
	int i, j, pos;
	TElemType c;//read data of tree
	*tree = NULL;//root of tree
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur = NULL;//construct tree and quene
	BiTree pnew;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')//end of the input
		{
			break;
		}
		//single new data node of tree and quene
		listpnew = (ptag_t)calloc(1, sizeof(struct tag));
		pnew = (BiTNode*)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew->p = pnew;
		if (*tree == NULL) {//first element
			phead = ptail = pcur = listpnew;
			*tree = pnew;
			continue;
		}
		//not first element
		ptail->pnext = listpnew;
		ptail = ptail->pnext;
		if (pcur->p->lchild == NULL) {//no left child in cur level
			pcur->p->lchild = pnew;
		}
		else if (pcur->p->rchild == NULL) {//no right child in cur level
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
}
int main()
{
	BiTree tree;
	HirachicalBuild(&tree);
	PreOrder(tree);
	return 0;
}