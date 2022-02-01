#include "Header.h"
void PreOrder(BiTree T) {
	if (NULL != T)
	{
		printf("%c", T->c);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T) {
	if (NULL != T)
	{
		InOrder(T->lchild);
		printf("%c", T->c);
		InOrder(T->rchild);
	}
}
void InOrder2(BiTree T) {
	SqStack S; 
	InitStack(S);
	//CHECK EVERY LCHILD OF TREE
	while (T||S.top!=-1)
	{
		if (T) {//left child exist
			PushStack(S, T);
			T = T->lchild;
		}
		else//right child exist but no left child
		{
			PopStack(S, T);
			printf("%c", T->c);
			T = T->rchild;
		}
	
	}
	
}
void PostOrder(BiTree T) {
	if (NULL != T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->c);	
	}
}
void LevelOrder(BiTree T) {
	LinkQuene Q;
	InitQuene(Q);
	QElemType p;
	EnQuene(Q, T);
	while (IsEmpty(Q) == false)
	{
		DeQuene(Q, p);
		putchar(p->c);
		if (p->lchild)
			EnQuene(Q, p->lchild);
		if(p->rchild)
			EnQuene(Q, p->rchild);
	}
}
void HirachicalBuild(BiTree* tree) {
	TElemType c;//read data of tree
	*tree = NULL;//root of tree
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur=NULL;//construct tree and quene
	BiTree pnew;
	while (scanf("%c", &c) != EOF)
	{
		if (c=='\n')//end of the input
		{
			break;
		}
		//single new data node of tree and quene
		listpnew = (ptag_t)calloc(1, sizeof(tag));
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
