#include <stdio.h>
#include <string.h>
char *print_stack()
{
    char c[] = "hello world";
    return c;
}
char *print_malloc()
{
    char *c;
    c = (char*) malloc(20);
    strcpy(c,"hello world");
    return c;
}
int main()
{
    char c[] = "hello world";
    
    char *p; p=c;
    printf("%p\t%s\n", p,p);
    // p=print_stack();//function will free the stack
    // printf("%p\t%s\n", p,p);  
    p=print_malloc();
    printf("%p\t%s\n", p,p); //function do not free malloc
    
    return 0;
}