#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef char TElemType;
typedef struct BiTNode {
	TElemType c;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef struct tag {
	BiTree p;
	struct tag *pnext;
}tag_t,*ptag_t;

//dahua
void PreOrderTraverse(BiTree T);
void CreateBiTree(BiTree* T);
//Wandao
void HirachicalBuild(BiTNode** tree);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void InOrder2(BiTree T);
void PostOrder(BiTree T);
void LevelOrder(BiTree T);
//Stack
typedef BiTree SElemType;
typedef struct SqStack {
	SElemType data[MAXSIZE];
	int top;
}SqStack;
void PushStack(SqStack& S, SElemType e);
void PopStack(SqStack& S, SElemType& e);
void InitStack(SqStack& S);

//LinkList Quene
typedef BiTree QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QuenePtr;
typedef struct LinkQuene {
	QuenePtr front, rear;
}LinkQuene;
bool IsEmpty(LinkQuene Q);
void InitQuene(LinkQuene& Q);
void EnQuene(LinkQuene& Q, QElemType e);
bool DeQuene(LinkQuene& Q, QElemType& e);
void code_quene();