#include "Header.h"

int main() {
	LinkList L1;
	DLinkList D1,p;
	ElemType item = 1;
	bool insert_list, delete_list;
	int e_pos = 2;
	//create_h(L1);
	Dcreate_t(D1);
	DPrintList(D1);
	delete_list = DListDeleteElem(D1,e_pos);
	while (1) {

	}
	//PrintList(L1);
	/*LinkList search = GetElem(L1, e_pos);
	if (search != NULL) {
		printf("find element %d!", search->data);
	}
	else {
		printf("not find element in positon%d!", e_pos);
	}
	return 0;*/
	
	//insert_list = ListFrontInsert(L1, e_pos, item);
	//PrintList(L1);
	//delete_list = ListDeleteElem(L1, e_pos, item);
	//PrintList(L1);
	return 0;
}
