#include <stdio.h>
int bitcount(unsigned x);
int main()

{
    int n=0;
    printf("give a positive number:");
    scanf("%d",&n);
    printf("the number of 1 is:%d\n",bitcount(n));
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for(b=0;x!=1;x>>=1)
        if(x&1)
            b++;
    return b;
}
