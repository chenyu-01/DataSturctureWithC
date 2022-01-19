#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int Elemtype;
typedef struct {
	Elemtype data[MaxSize];
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
bool ListDelete(Sqlist& L, int i, Elemtype& del) {
	if (i > L.lenth || i < 1) {
		return false;
	}// 超出范围

	del = L.data[i - 1];
	for (; i < L.lenth; i++) {
		L.data[i - 1] = L.data[i];
	}
	L.lenth--;
	return true;
}
bool ListInsert(Sqlist& L, int i, Elemtype e)//L.data[3]={1,2,3},i==2位置为例,L.lenth=3
{
	if (i<1 || i>L.lenth + 1)//判断i是否在1- lenth+1内,插入允许位置后移一格
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
	L.data[i - 1] = e;//进行修改
	L.lenth++;//顺序表长度+1

	return true;//走到这里插入成功
}
int main() 
{
	Sqlist L;
	Elemtype e;
	int pos_i;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.lenth = 3;
	scanf("%d", &e);
	bool ret = ListInsert(L, 2, e);
	PrintList(L);
	scanf("%d", &pos_i);
	ret = ListDelete(L, pos_i, e);
	if (ret) {
		PrintList(L);
	}
	else {
		printf("false");
	}
	return 0;
}
/*Description

初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，然后scanf读取一个整型数，是删除的位置（假如输入为1），然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。


Input
第一次输入插入的元素值，第二次输入删除的位置


Output
假如插入的元素为6，那么输出为
1  6  2  3

假如删除的位置为1，那么输出为


6  2  3


Sample Input 1 

6
1
Sample Output 1

  1  6  2  3
  6  2  3
Sample Input 2 

9
3
Sample Output 2

  1  9  2  3
  1  9  3
Sample Input 3 

9
6
Sample Output 3

  1  9  2  3
false*/