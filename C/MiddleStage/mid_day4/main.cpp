#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

LinkList create_h(LinkList& L) {
	LNode* s; int x;
	scanf("%d", &x);
	L = (LinkList)malloc(sizeof(LNode)); // initialize L 
	L->next = NULL;
	while (x != 9999) {//stop sign of reading data from stdin
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
int main() {
	LinkList L;
	create_h(L);

	return 0;
}