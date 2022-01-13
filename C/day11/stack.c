#include <stdio.h>
char *print_stack()
{
    char c[] = "hello world";
    return c;
}
int main()
{
    char c[] = "hello world";
    
    char *p; p=c;
    printf("%p\t%s\n", p,p);
    p=print_stack();
    printf("%p\t%s\n", p,p);

    return 0;
}