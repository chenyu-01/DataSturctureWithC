#include "Header.h"

DLinkList Dcreate_h(DLinkList& DL) {
	//initialize
	DL = (DLinkList)malloc(sizeof(DNode));
	DL->next = NULL;
	
	ElemType data;
	scanf("%d", &data);
	//read s and head-plug to Dlink while a loop
	while (data != STOPSGIN) {//STOPSGIN is 9999
		DNode* s = (DLinkList)malloc(sizeof(DNode));
		s->data = data;
		s->next = DL->next;
		//s->next is not NULL
		if (s->next) {
			s->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		
		scanf("%d", &data);
	}

	return DL;
};
DLinkList Dcreate_t(DLinkList& DL) {
	//initialize
	DL = (DLinkList)malloc(sizeof(DNode));
	DL->next = NULL;
	ElemType data;
	scanf("%d", &data);
	DLinkList r = DL;
	//read s and tail-plug to Dlink while a loop
	while (data != STOPSGIN) {//STOPSGIN is 9999
		DNode* s = (DLinkList)malloc(sizeof(DNode));
		s->data = data;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &data);
	}
	r->next = NULL;
	return DL;
};
DLinkList DGetElem(DLinkList DL, int e_pos) {
	DLinkList p = (DLinkList)malloc(sizeof(DNode));
	if (0 == e_pos)
		return DL;
	if (1 > e_pos) {
		return NULL;
	}
	p = DL->next;
	int i;
	for ( i = 1;i< e_pos; i++) {
		if (p) {
			p = p->next;
		}
		else
			return NULL;
	}
	return p;
}
bool DlistInsert(DLinkList& DL, int e_pos, ElemType e) {
	DLinkList p = (DLinkList)malloc(sizeof(DNode));
	p = DGetElem(DL, e_pos - 1);
	if (!p) {
		return false;
	}
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	s->data = e;
	DLinkList q = p->next;
	s->next = q;
	s->prior = p;
	if (q) {//if q is not NULL
		q->prior = s;
	}
	p->next = s;
	return true;
}
bool DListDeleteElem(DLinkList& DL, int e_pos) {
	DLinkList p = DGetElem(DL, e_pos - 1);// if epos == 1 then p = L
	if (!p) {
		return false;
	}
	DLinkList q = p->next;// if this one execute , p exits. p is last one , p-
	if (!q) {//if q is NULL, then return false
		return false;
	}
	else // l = q->next exits  
	{
		DLinkList l = q->next;
		p->next = l; //p->l , l can be NULL
		if (l)
		l->prior = p; // p<->l
	}
	free(q);
	q = NULL;
	return true;
	
	
		
	
	
	
	
	
}
void DPrintList(DLinkList DL)
{
	DL = DL->next;
	while (DL != NULL) {
		printf("%d", DL->data);
		DL = DL->next;
		if (DL != NULL) {
			printf(" ");//print "1 2 3"
		}
	}
	printf("\n");
}
