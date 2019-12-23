#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char getop(char s[]);
double pop(void);
void push(double);

int n;
int m = 0;
double val[100];

int main(int argc, char *argv[])
{
    double op2;
    int n;

    for (n = 1; --argc > 0; n++)
    {
        switch (getop(argv[n]))
        {
        case '0':
            push(atof(argv[n]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error\n");
            }
            break;
        default:
            printf("error%s\n", argv[n]);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

char getop(char s[])
{

    if ((s[0] == '-' && isdigit(s[1])) || (isdigit(s[0])))
    {
        return '0';
    }
    else if (s[0] == '-' || s[0] == '+' || s[0] == '/' || s[0] == '*')
    {
        return s[0];
    }
    else
    {
        return 0;
    }
}

double pop(void)
{
    if (m > 0)
    {
        return val[--m];
    }
    else
    {
        printf("error\n");
        return 0.0;
    }
}

void push(double f)
{
    if (m < 100)
    {
        val[m++] = f;
    }
    else
    {
        printf("error%g\n", f);
    }
}