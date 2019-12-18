#include<stdio.h>
#include<string.h>
#define NUMBER 100

void origin (char s[], int y, int i );
void converse (char s[]);

int i = 0;
int main(void)
{
    char s[NUMBER];
   while(s[i] != EOF)
   {
        s[i] = getchar();
        if(s[i] == '\n')
        {
            break;
        }
        i++;
    }
    converse(s);
    printf("%s", s);
    return 0;
}

void origin(char s[], int y, int i )
{
    int a=0;
    int b=0;
    b = i - (y + 1);
    if (y < b)
    {
        a = s[y];
        s[y] = s[b];
        s[b] = a;
        origin (s, ++y, i);
    }
}

void converse(char s[])
{
origin(s, 0, i);
}