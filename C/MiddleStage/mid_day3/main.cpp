#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
#define MaxSize 10
//静态分配

typedef struct {
	Elemtype data[MaxSize];//存元素
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
	}// 超出范围

	del = L.data[i - 1];
	for (; i< L.lenth; i++) {
		L.data[i - 1] = L.data[i];
	}
	L.lenth--;
	return true;
}
bool ListInsert(Sqlist& L, int i, Elemtype e)//L.data[3]={1,2,3},i==2位置为例,L.lenth=3
{
	if (i<1 || i>L.lenth+1)//判断i是否在1- lenth+1内,插入允许位置后移一格
	{
		printf("Erro:i out of list\n");
		return false;
	}

	if (L.lenth >= MaxSize)//超出空间
	{
		printf("Erro:L.lenth >= MaxSize\n");
		return false;
	}
	
	for (int j = L.lenth; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}//移动L.data[2]->L.data[3],L.data[1]->L.data[2] j=1时退出
	//修改2位L.data[1]
	L.data[i-1] = e;//进行修改
	L.lenth++;//顺序表长度+1

	return true;//走到这里插入成功
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