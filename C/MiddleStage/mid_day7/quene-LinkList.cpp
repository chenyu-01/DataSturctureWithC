#include "Header.h"
void InitQuene(LinkQuene& Q) {
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;
}
bool IsEmpty(LinkQuene Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}
void EnQuene(LinkQuene &Q, QElemType e) {
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
	QuenePtr p= Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(p == Q.rear) {//delete last element
		Q.rear = Q.front;
	}
	free(p);
	p = NULL;
	return true;
}
void code_quene() {
	LinkQuene Q; 
	QElemType e=(QElemType)malloc(sizeof(BiTNode));
	QElemType f;
	e->c = 'a';
	//f->lchild = f->rchild = g->lchild = g->rchild = NULL;
	InitQuene(Q);
	EnQuene(Q, e);
	DeQuene(Q, f);
}