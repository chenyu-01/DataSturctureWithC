#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i= 0,j=0;
	char c[11]; 
	scanf("%s", &c);
	/*while (scanf("%s", &c) != EOF)
	{*/
	//for "1221" i = 4 and the last num c[3]==1.
	//get string ranged from c0 to c3 "1221"and c[4] is '\0'
		while (c[i]!='\0')
		{
			i++;
		} 
		
		
		// u implies i is even or odd num
		int u;
		if (i % 2 == 0)
		{
			u = 0;//i is even num
		}
		else
		{
			u = 1;//i is odd num
		}
		//for "12321" 
		// compare c[i-1] with c[j]
		while (i-1 > j && c[i-1]==c[j])
		{

			i--,j++;
		}
		//if i == j , or (i-1)+1 == j
		if (i == j && u == 0 || i-1==j && u==1)
			//"1221" ,i==j==3;"12321" i-1==j==3
			
		{
			printf("yes\n");
		}
		else 
		{
			printf("no\n");
		}
		
		/*i=0,j = 0;
	}*/
	
		/*Sample Input 1
		12321
		Sample Output 1
		yes
		Sample Input 2
		1231
		Sample Output 2
		no*/
	return 0;
}