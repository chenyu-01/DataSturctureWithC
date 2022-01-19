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

输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出


Input
学号，姓名，性别，例如输入 101 xiongda m


Output
输出和输入的内容一致，如果输入的是101 xiongda m，那么输出也是101 xiongda m


Sample Input 1

101 xiongda m
Sample Output 1

101 xiongda m
*/