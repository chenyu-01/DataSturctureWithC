#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef char TElemType;
typedef struct BiTNode {
	TElemType c;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef BiTree QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QuenePtr;
typedef struct LinkQuene {
	QuenePtr front, rear;
}LinkQuene;
typedef struct tag {
	BiTree p;
	struct tag* pnext;
}tag_t, * ptag_t;
void HirachicalBuild(BiTree* tree) {
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
void PostOrder(BiTree tree) {
	if (tree) {
		PostOrder(tree->lchild);
		PostOrder(tree->rchild);
		putchar(tree->c);
	}
}
void InOrder(BiTree tree) {
	if (tree) {
		InOrder(tree->lchild);
		putchar(tree->c);
		InOrder(tree->rchild);
	}
}
void InitQuene(LinkQuene& Q) {
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;
}
bool IsEmpty(LinkQuene Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}
void EnQuene(LinkQuene& Q, QElemType e) {
	//init s, new pointer
	QuenePtr s = (QuenePtr)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
bool DeQuene(LinkQuene& Q, QElemType& e) {
	if (Q.front == Q.rear)//Empty Quene
		return false;
	QuenePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (p == Q.rear) {//delete last element
		Q.rear = Q.front;
	}
	free(p);
	p = NULL;
	return true;
}
void LevelOrder(BiTree T) {
	LinkQuene Q;
	InitQuene(Q);
	EnQuene(Q, T);
	while (T && !IsEmpty(Q)) {
		DeQuene(Q, T);
		putchar(T->c);
		if (T->lchild) {
			EnQuene(Q, T->lchild);
		}
		if (T->rchild) {
			EnQuene(Q, T->rchild);
		}
	}
}
int main() 
{
	BiTNode* tree;
	tree = (BiTNode*)malloc(sizeof(BiTNode));
	HirachicalBuild(&tree);
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	printf("\n");
	LevelOrder(tree);
	return 0;
}