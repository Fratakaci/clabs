#include <stdio.h>
#include <ctype.h>
 
char arrary[100];
int number = 0;

int getch(void);
void ungetch(int c);
char getfloat(double *pn);

int main(void)
{
    int y = 0;
    double x[100];
    double z = 0;
 
    for (y = 0; y < 100 ; y++)
    {
      
        if(getfloat(&x[y]) == '\n')
        {
            z = z + x[y];
            break;
        }
         z = z + x[y];
    }
 
    printf("%f\n", z);
    return 0;
}

int getch(void)
{
    return (number > 0) ? arrary[--number] : getchar();
}

void ungetch(int c)
{
    if (number >= 100)
    {
        printf("too many characters\n");
    }
    else
    {
        arrary[number++] = c;
    }
}

char getfloat(double *pn)
{
    char c;
    int a;
    int b = 1;
    while (isspace(c = getch()))
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    a = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.')
    {
        c = getchar();
        if (!isdigit(c))
        {
            ungetch(c);
        }
        for (; isdigit(c); c = getchar())
        {
            b *= 10;
            *pn = 10 * *pn + (c - '0');
        }
    }
    
    *pn = *pn / b * a;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
 