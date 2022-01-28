#include "Header.h"
void InitQ(SqQuene &Q) {
	Q.rear = 0, Q.front = 0;
}
bool EnQuene(SqQuene& Q,  QElemType e) {
	//check full 0 1 2 _3r 4f or 0f 1 2 3 _4r
	if ((Q.rear+1)%Stacksize==Q.front) {
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear+1)%QueneSize;	
	return true;
}
bool DQuene(SqQuene& Q,QElemType&e) {
	//check empty _0 _1 2f _3r _4 -> _0 _1 _2 _3fr _4  
	if (Q.front == Q.rear)
		return false;
	e = Q.data[Q.front];
	Q.front=(Q.front+1)%QueneSize;
}
void CodeQune() {
	SqQuene Q; ElemType e;
	InitQ(Q);
	EnQuene(Q, 1);
	EnQuene(Q, 2);
	DQuene(Q, e);
	printf("%d", e);
}
