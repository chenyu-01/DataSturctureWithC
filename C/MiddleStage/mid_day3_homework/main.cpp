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
	}// ������Χ

	del = L.data[i - 1];
	for (; i < L.lenth; i++) {
		L.data[i - 1] = L.data[i];
	}
	L.lenth--;
	return true;
}
bool ListInsert(Sqlist& L, int i, Elemtype e)//L.data[3]={1,2,3},i==2λ��Ϊ��,L.lenth=3
{
	if (i<1 || i>L.lenth + 1)//�ж�i�Ƿ���1- lenth+1��,��������λ�ú���һ��
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
	L.data[i - 1] = e;//�����޸�
	L.lenth++;//˳�����+1

	return true;//�ߵ��������ɹ�
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

��ʼ��˳���˳�����Ԫ��Ϊ���ͣ�����ߵ�Ԫ����1,2,3��Ȼ��ͨ��scanf��ȡһ��Ԫ�أ�����������6�������뵽��2��λ�ã���ӡ���˳���ÿ��Ԫ��ռ3���ո񣬸�ʽΪ1  6  2  3��Ȼ��scanf��ȡһ������������ɾ����λ�ã���������Ϊ1����Ȼ�����˳���  6  2  3�����������λ�ò��Ϸ������false�ַ��������ѣ�Languageһ��ҪѡΪC++��


Input
��һ����������Ԫ��ֵ���ڶ�������ɾ����λ��


Output
��������Ԫ��Ϊ6����ô���Ϊ
1  6  2  3

����ɾ����λ��Ϊ1����ô���Ϊ


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