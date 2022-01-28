#include "Header.h"
void InitS(SqStack& S) {
	S.top = -1;//stack is empty
}
bool GetTop(SqStack S, ElemType& m) {
	if (-1 == S.top)
		return false;
	m = S.data[S.top];
	return true;
}
bool Push(SqStack& S, ElemType m) {
	if (Stacksize - 1 == S.top) {
		return false;
	}//full stack
	S.top++;
	S.data[S.top] = m;
	return true;
}
bool Pop(SqStack& S, ElemType& m) {
	if (-1 == S.top) // empty stack
		return false;
	m = S.data[S.top];
	S.top--;
	return true;
}
//pop S, assign S.[top] to m ,top--;
void CodeStack() {
	SqStack S;
	ElemType m; //get top element
	InitS(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Pop(S, m);
	GetTop(S, m);
}