#include<stdio.h>
int bitamount(unsigned x);
int main(void)
{
    char x[7];
    int y;
    int z=0;
    for(y=0;y!=EOF;y++)
    {
        x[y]=getchar();
        if (x[y]=='\n')
            break;
        z=(z*10)+(x[y]-'0');
    }
    printf("the number of 1 is:%d\n",bitamount(z));
    return 0;
}
int bitamount(unsigned x)
{
    int b;
    for(b=0;x!=0;x>>=1)
    {
        if(x&1)
        b++;
    }
    return b;
}
