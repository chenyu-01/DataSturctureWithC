#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STOPSGIN 9999
//single list
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

void PrintList(LinkList L);
void create_h(LinkList &L);
void create_t(LinkList& L);
LinkList GetElem(LinkList L, int e_pos);
bool ListDeleteElem(LinkList& L, int e_pos);
bool ListFrontInsert(LinkList& L, int e_pos, ElemType e);
//Double List
typedef struct DNode {
	ElemType data;
	struct DNode* prior, *next;
}DNode, *DLinkList;
bool DListDeleteElem(DLinkList& DL, int e_pos);
bool DListInsert(DLinkList&DL,int e_pos, ElemType e);
DLinkList Dcreate_h(DLinkList& DL);
DLinkList Dcreate_t(DLinkList& DL);
DLinkList DGetElem(DLinkList DL, int e_pos);
void DPrintList(DLinkList DL);
