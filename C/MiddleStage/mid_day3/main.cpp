#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
#define MaxSize 10
//��̬����

typedef struct {
	Elemtype data[MaxSize];//��Ԫ��
	int lenth;
}Sqlist;
void PrintList(Sqlist& L) {
	for (int i = 1; i <= L.lenth; i++) {
		printf("%3d", L.data[i - 1]);
	}
	printf("\n");
}
int ListSearch(Sqlist& L, Elemtype e) {
	//Loop through the List
	int i;
	for (i = 0; i < L.lenth; i++) {
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return NULL;
}
bool ListDelete(Sqlist& L,int i ,Elemtype &del) {
	if (i > L.lenth || i < 1) {
		return false;
	}// ������Χ

	del = L.data[i - 1];
	for (; i< L.lenth; i++) {
		L.data[i - 1] = L.data[i];
	}
	L.lenth--;
	return true;
}
bool ListInsert(Sqlist& L, int i, Elemtype e)//L.data[3]={1,2,3},i==2λ��Ϊ��,L.lenth=3
{
	if (i<1 || i>L.lenth+1)//�ж�i�Ƿ���1- lenth+1��,��������λ�ú���һ��
	{
		printf("Erro:i out of list\n");
		return false;
	}

	if (L.lenth >= MaxSize)//�����ռ�
	{
		printf("Erro:L.lenth >= MaxSize\n");
		return false;
	}
	
	for (int j = L.lenth; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}//�ƶ�L.data[2]->L.data[3],L.data[1]->L.data[2] j=1ʱ�˳�
	//�޸�2λL.data[1]
	L.data[i-1] = e;//�����޸�
	L.lenth++;//˳�����+1

	return true;//�ߵ��������ɹ�
}

bool ListChange(Sqlist& L, int i, Elemtype e) {
	L.data[i - 1] = e;
	return true;
}
int main() 
{
	bool ret;
	Sqlist L;
	Elemtype ins = 60;
	Elemtype del; //deleted element
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.lenth = 3;//all three elements
	PrintList(L);
	ret = ListInsert(L, 1, ins);//add element to the position
	PrintList(L);
	ret = ListDelete(L, 1,del);//remove position 1 and get the deleted
	ret = ListSearch(L, 60);
	return 0;
}