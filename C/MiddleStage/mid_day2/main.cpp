#include <stdio.h>
#include <stdlib.h>
void read_cpp(char*& p) {
	p = (char*)malloc(100);
	fgets(p, 100, stdin);

}
int main()
{
	char* p;
	read_cpp(p);//c++ reference
	printf("%s", p);
}
/*Description

ʹ��C++�����ã�ע���ύʱ�Ѵ���ѡΪC++���������������ַ�ָ�� char *p,Ȼ�����Ӻ�����malloc����ռ䣬ͨ��fgets��ȡ�ַ�����Ȼ�����������н��������Ҫ���Ӻ���ʹ��C++�����ã�ע����C++�дӱ�׼�����ȡ�ַ�������Ҫʹ��fgets(p,100,stdin)


Input
����һ���ַ��������� I love C language


Output
����������I love C language����ô���Ҳ��I love C language


Sample Input 1 

I love C language
Sample Output 1

I love C language
Sample Input 2 

how are you
Sample Output 2*/