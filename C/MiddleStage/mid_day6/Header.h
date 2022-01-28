#pragma once
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
void InitS(SqStack& S);
bool GetTop(SqStack S,ElemType&m);
bool Push(SqStack& S, ElemType m);
bool Pop(SqStack& S, ElemType& m);
void CodeStack();
//QUENE
#define QueneSize 3
typedef int QElemType;

typedef struct SqQuene
{
	int front, rear;
	QElemType data[QueneSize];
}SqQuene;

void CodeQune();