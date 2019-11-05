#include<stdio.h>
char func(char n)
{
    char count=0;
    while(n>0)
    {
        count++;
        n&=(n-1);
    }
return count;
}
 int main(void)
{
    printf("give a positive number:");
    char n;
    n=getchar();
    char num = func (n);
    printf("the number of 1 is %d\n",num);
    putchar(num);
}