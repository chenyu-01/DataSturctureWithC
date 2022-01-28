#include "Header.h"
// Get Linklist by position
LinkList GetElem(LinkList L, int e_pos) {
	LNode* p = L->next;
	if (0 == e_pos) {
		return L;
	}//first Node
	if (0 > e_pos) {
		return NULL;
	}
	int j = 1;
	while (p && j < e_pos) {
		p = p->next;
		j++;
	}
	return p; // if e_pos is out of range ,then we will get last p->next ,which is NULL. 
}
// Get Linklist by element
LinkList LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p != NULL && e != p->data)
	{
		p = p->next;
	}
	return p;
}
// insert Element to Linklist in front of position
bool ListFrontInsert(LinkList& L, int e_pos, ElemType e) {
	LNode* p = GetElem(L, e_pos - 1);//get the front position Linklist
	if (NULL == p) {
		return false;
	}//you can't find e_pos - 1 element 
	LinkList s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool ListDeleteElem(LinkList& L, int e_pos) {
	LNode* p = GetElem(L, e_pos - 1);//get the front position Linklist
	if (NULL == p) {
		return false;
	}//you can't find e_pos - 1 element so e_pos can't be find
	LinkList q = p->next;
	if (q) {
		p->next = q->next;
		free(q);
		q = NULL;//avoid wild pointer
		return true;
	}
	else
		return false;
	
}
// search elem and change elem
//Creating single linked list by headplug method
void create_h(LinkList& L) {
	LNode* s; int x;
	scanf("%d", &x);
	L = (LinkList)malloc(sizeof(LNode)); // initialize L 
	L->next = NULL;
	while (x != 9999) {//stop sign of reading data from stdin
		s = (LNode*)malloc(sizeof(LNode));//s=L_2;
		s->data = x;
		s->next = L->next;// s-> L_1(maybe NULL)
		L->next = s; //L -> add_s -> L_1(maybe NULL) // L->L_2->L_1
		scanf("%d", &x);
	}
}
//by tailplug method
void create_t(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L; int x; //L,r->NULL 
	scanf("%d", &x); //read x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//s=L_2;L->...->L_1
		s->data = x;
		r->next = s;//r=L_1->add_s=L_2 (L->...->L_1->L_2)
		r = s;//r=L_2,again
		scanf("%d", &x);
	}
	r->next = NULL;//Last position ->NULL
}
//Print the value of each node in the linked list
void PrintList(LinkList L )
{
	L = L->next;
	while (L != NULL) {
		printf("%d", L->data);
		L = L->next;
		if (L != NULL) {
			printf(" ");//print "1 2 3"
		}
	}
	printf("\n");
}
// Get Linklist by its position