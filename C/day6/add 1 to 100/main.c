# include <stdio.h>
int main()
{
	int i, total;
	for (i = 1, total = 0; i <= 100; i++)
	{
		if (i % 2 == 0) {
			continue;
			// if i is even then we jump out of the loop
		}
		if (total + i > 2000) {
			break;
		}
		total = total + i;
		
	}
	printf("add odd number from 1 to %d gives:%d\n", i,total);
	return 0;
}