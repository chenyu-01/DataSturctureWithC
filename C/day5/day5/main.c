#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	//read integer i, character j, float k
	int i;
	char j;
	float k;
	//Sample Input:10 a 98.3
	//add i,j,k and keep 2 digits after decimal.
	//i = 10, j = 'a', k = 98.3;
	scanf("%d %c %f",&i,&j,&k);
	printf("%.2f", i+j+k);
	
	//Sample Output:205.30

		
}