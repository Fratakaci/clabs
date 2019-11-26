#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define BUFSIZE 100

int ince = 0;
char buf[BUFSIZE];
int getch(void)
{
    return (ince > 0) ? buf[--ince] : getchar();
}
void ungetch(int c)
{
    if (ince >= BUFSIZE)
    {
        printf("too much\n");
    }
    else
    {
        buf[ince++] = c;
    }
}

int getch(void);
int THETOP = 0;

char stack[BUFSIZE];
void ungetch(int);

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (isdigit(s[i]))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
    if (c == '-')
    {
        if (isdigit(s[++i] = c= getch()))
        {
            s[i] = c;
        }
        else
        {
            if (c != EOF)
            {
                ungetch(c);
            }
            return '-';
        }
    }
}

void push(int a)
{
    if (THETOP <= 98)
    {
        stack[THETOP++] = a;
    }
    else
    {
        printf("It is full\n");
    }
}

int pop(void)
{
    if (THETOP >= 0)
    {
        return stack[--THETOP];
    }
    else
    {
        printf("It is empty \n");
        return 0;
    }
}

int top(void)
{
    if (THETOP > 0)
    {
        return stack[THETOP];
    }
    else
    {
        printf("there is no number");
        printf("/n");
    }
}

void print(void)
{
    printf("%d\n", stack[THETOP - 1]);
}


int main()
{
    printf("there are some tips:\n");
    printf("a is copy the top result\n");
    printf("b is print the top result\n");
    printf("c is exchange two result\n");
    printf("d is delete the blank\n");
    char s[BUFSIZE];

    int op2;
    int type;
    
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atoi(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();
            if (op2 != 0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("the errror");
            break;
            }

        case '\n':
            printf("%d\n", pop());
            break;

        case '%':
            op2 = pop();
            if (op2 != 0)
                push(pop() % op2);
            else
            {
                printf("error");
            }

        case 'a':
            push(stack[THETOP - 1]);
            push(stack[THETOP - 1]);
            break;

        case 'b':
            print();
            break;

        case 'c':
            op2 = stack[THETOP - 1];
            stack[THETOP - 1] = stack[THETOP - 2];
            stack[THETOP - 2] = op2;
            break;

        case 'd':
            THETOP = 0;
            break;
        }
    }
}