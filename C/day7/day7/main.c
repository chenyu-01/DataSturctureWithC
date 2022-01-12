# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
int main()
{
	int i=1,result=1;
	int n;
	scanf("%d", &n);
	while (i<=n) {
		result = result * i;
		i++;
	}
	printf("%d", result);
	return 0;
}