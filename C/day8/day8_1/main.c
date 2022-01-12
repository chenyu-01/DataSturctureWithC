# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	
	int n,counts=0; 
	int a[100]; // input numbers
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 2)
		{
			counts++;
		}
	}
	printf("%d", counts);

	return 0;
}