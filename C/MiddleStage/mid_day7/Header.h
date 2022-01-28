#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef struct tag {
	BiTree p;
	struct tag *pnext;
}tag_t,*ptag_t;

//dahua
void PreOrderTraverse(BiTree T);
void CreateBiTree(BiTree & T);
//Wandao
void HirachicalBuild(BiTNode** T);