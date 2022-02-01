#include "Header.h"
void InitStack(SqStack& S)
{
	S.top = -1;
}
void PushStack(SqStack& S, SElemType e)
{
	S.top++;
	S.data[S.top] = e;
}
void PopStack(SqStack& S, SElemType& e)
{
	e = S.data[S.top];
	S.top--;
}