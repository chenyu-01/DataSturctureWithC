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
void PrintList(LinkList L)

{

	L = L->next;

	while (L != NULL)

	{

		printf("%3d", L->data);//打印当前结点数据

		L = L->next;//指向下一个结点

	}

	printf("\n");

}
void create_t(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	LinkList r = L; ElemType x;
	scanf("%d", &x);
	while (x!=STOPSGIN)
	{
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
}
LinkList GetElem(LinkList L, int pos) {
	if (0 == pos)
		return L;//first node
	if (1 > pos)
		return NULL;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = L->next; int i=1;// eg. L->1->2->3 
	while (p && i<pos) // p is NULL if list exhaust
	{
		i++;
		p = p->next;
	}
	return p;
}
bool ListFrontInsert(LinkList& L,int e_pos,ElemType e) {
	LinkList p = GetElem(L, e_pos - 1);
	if (NULL == p) {
		return false;
	}
	LinkList q = p->next;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	p->next = s;//p->s->q
	s->next = q;
	return true;
}
bool ListDelete(LinkList& L, int e_pos) {
	LinkList p = GetElem(L, e_pos - 1);
	if (NULL == p)
		return false;
	LinkList q = p->next;
	if (NULL == q)
		return false;
	p->next = q->next;
	// p->q->l to p->l
	free(q);
	q = NULL;
	return true;
}
int main() {
	LinkList L; int e_pos=2,d_pos =4;
	ElemType e = 99;
	create_t(L);
	LinkList p = GetElem(L, e_pos);
	if (NULL != p)
		printf("%d\n", p->data);
	ListFrontInsert(L, e_pos, e);
	PrintList(L);
	ListDelete(L, d_pos);
	PrintList(L);

	

	return 0;
}

