#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
struct student {
	int id;
	char name[20];
	char sex;
};
int main()
{
	struct student student_i;
	scanf("%d%s %c", &student_i.id, &student_i.name, &student_i.sex);
	printf("%d %s %c", student_i.id, student_i.name, student_i.sex);
	return 0;
}




/*

Description

����һ��ѧ����ѧ�ţ��������Ա��ýṹ��洢��ͨ��scanf��ȡ��Ȼ����ͨ��printf��ӡ���


Input
ѧ�ţ��������Ա��������� 101 xiongda m


Output
��������������һ�£�����������101 xiongda m����ô���Ҳ��101 xiongda m


Sample Input 1

101 xiongda m
Sample Output 1

101 xiongda m
*/