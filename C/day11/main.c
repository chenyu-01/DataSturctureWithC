#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    scanf("%d", &i);
    char *c;
    c = (char *)malloc(i); // input "10\nxyz"
    scanf("%c", c);        // delete '\n'
    gets(c);
    puts(c); // output "xyz"
    return 0;
}