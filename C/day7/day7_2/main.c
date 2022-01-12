# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define money 100
int main()
{

	//Eg1. 45yuan=2*c2+1*c1
	//Eg2. 32=c2+c1
	int test = 0;
	int c10=1, c5=1, c2=1, c1=1;
	int method_n = 0, paper_n =0;
	while (test < money) 
	{
		
		
		while (test<money ) 
		{
			//inicialize
			c2 = 1, c1 = 1;
			test = c1 * 1 + c2 * 2 + c5 * 5 + c10 * 10;
			// match
			while (test < money )
			{
				c1 = 40 - c10 - c5 - c2; 
				// if it is less than 0
				if (!c1) 
				{
					break;
				}
				test = c1 * 1 + c2 * 2 + c5 * 5 + c10 * 10; // calculate money
				//check 100 money
				if (test == money)
				{
					method_n++;
					//log
					//printf("method%d:c1=%d,c2=%d,c5=%d,c10=%d\n",method_n, c1, c2, c5, c10);
					test = 0;
					break;
				}

				c2++;
				
			}
			c5++;
			
		}
		c2 = 1, c1 = 1, c5 = 1;
		test = c1 * 1 + c2 * 2 + c5 * 5 + c10 * 10;
		c10++;
		
	}
	
	

	printf("%d", method_n);
	return 0;
}