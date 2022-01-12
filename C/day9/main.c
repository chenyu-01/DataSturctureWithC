#include <stdio.h>
#include <string.h>
int main()
{
    int result;
    char c[50];
    char d[50]="";
    int i=0,j;
    fgets(c,sizeof(c),stdin);
    j = strlen(c);
    c[j-1]=0;
    while(c[i])
    {
        j=strlen(c)-i-1;
        d[j]=c[i];
        i++;
    }
    // printf("c is %s, and d is %s\n",c,d);
    result = strcmp(c,d);
    if (result<0){
        printf("-1");
    }
    else if (result==0){
        printf("0");
    }
    else
    {
        printf("1");
    }
    return 0;
}