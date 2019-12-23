#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int a = 0, b = 0, c = 0;
int len = 0;
int d = 0, e = 0;
int f;

int day_of_year(int year, int month, int date);
void getop(char s[]);
int seconddate(void);
int year(int f, int a);

static char daytab[2][13] = 
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int date)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 0; i < month; i++)
    {
        date+= daytab[leap][i];
    }
    return date;
}

int main(int argc, char *argv[])
{
    len = strlen(argv[1]);
    getop(argv[1]);
    d = day_of_year(a, b, c);
    f = a;
    seconddate();
    len = strlen(argv[2]);
    getop(argv[2]);
    e = day_of_year(a, b, c);
    printf("%d\n", e - d + year(f, a));
}

void getop(char s[])
{
    int process = 0;
    if (process < len)
    {
        while (isdigit(s[process]))
        {
            a = a * 10 + s[process] - '0';
            process++;
        }
        if (s[process] == '/')
        {
            ++process;
        }
        while (isdigit(s[process]))
        {
            b = b * 10 + s[process] - '0';
            process++;
        }
        if (s[process] == '/')
        {
            ++process;
        }
        while (isdigit(s[process]))
        {
            c = c * 10 + s[process] - '0';
            process++;
        }
        if (s[process] == '/')
        {
            ++process;
        }
    }
}

int seconddate(void)
{
    a = b = c = 0;
    return 0;
}

int year(int f, int a)
{
    int g = 0;
    int h = 0;
    h = f;
    while(h < a)
    {
        if(h / 4 == 0)
        {
            g += 366;
        }
        else 
        {
            g += 365;
        }
        ++h;
    }
    return g;
}