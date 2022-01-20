#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
//Creating single linked list by headplug method
LinkList create_h(LinkList& L) {
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
	return L;
}
//by tailplug method
LinkList create_t(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L; int x; //L,r->NULL 
	scanf("%d", &x); //read x;
	while (x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//s=L_2;L->...->L_1
		s->data = x;
		r->next = s;//r=L_1->add_s=L_2 (L->...->L_1->L_2)
		r = s;//r=L_2,again
		scanf("%d", &x);
	}
	r->next = NULL;//Last position ->NULL
	return L;
}
//Print the value of each node in the linked list
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");
}
int main() {	
	LinkList L1,L2;
	create_h(L1);
	PrintList(L1);
	create_t(L2);
	PrintList(L2);

	return 0;
}