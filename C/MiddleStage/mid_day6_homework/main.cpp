#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
typedef  int ElemType;
#define Stacksize 10
//STACK
typedef struct SqStack
{
	int top;
	ElemType data[Stacksize];
}SqStack;
void InitS(SqStack& S) {
	S.top = -1;
}
bool Push(SqStack& S, ElemType m) {
	//check full
	if (S.top == Stacksize - 1)
		return false;
	S.top++;
	S.data[S.top] = m;
	return true;
}
bool Pop(SqStack& S, ElemType& m) {
	//check empty
	if (-1 == S.top)
		return false;
	m = S.data[S.top];
	S.top--;
	return true;
}
//QUENE
#define QueneSize 5
typedef int QElemType;
typedef struct SqQuene
{
	int front, rear;
	QElemType data[QueneSize];
}SqQuene;
void InitQ(SqQuene& Q) {
	Q.rear = 0, Q.front = 0;
}
bool FullQuene(SqQuene Q) {
	if((Q.rear + 1) % QueneSize == Q.front)
		return true;
	return false;
}
bool EmptyQuene(SqQuene Q) {
	if (Q.rear == Q.front)
		return true;
	return false;
}
bool EnQuene(SqQuene& Q, QElemType e) {
	//check full 0 1 2 _3r 4f or 0f 1 2 3 _4r
	if (FullQuene(Q)) {
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % QueneSize;
	return true;
}
bool DQuene(SqQuene& Q, QElemType& e) {
	//check empty _0 _1 2f _3r _4 -> _0 _1 _2 _3fr _4  
	if (EmptyQuene(Q))
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % QueneSize;
	return true;
}
int main() {
	SqStack S1;
	InitS(S1);
	for (int i = 0; i < 3; i++) {
		ElemType x;
		scanf("%d", &x);
		Push(S1, x);
	}
	for (int i = 0; i < 3; i++) {
		ElemType x;
		Pop(S1, x);
		printf("%2d", x);
	}
	printf("\n");
	SqQuene myQuene;
	InitQ(myQuene);
	ElemType x;
	scanf("%d", &x);
	while (false == FullQuene(myQuene))
	{
		EnQuene(myQuene, x);
		scanf("%d", &x);
	}
	printf("false\n");
	
	while (false == EmptyQuene(myQuene))
	{
		DQuene(myQuene, x);
		printf("%2d", x);
	}
	return 0;
}