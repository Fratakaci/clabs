#include <stdio.h>

main()
{
    printf("celsius to fahrenheit\n");

    int celsius, fahrenheit;
    int lower, upper, step;

    lower=0;
    upper=100;
    step=5;

    celsius=lower;
    while(celsius<=upper){
        fahrenheit=celsius*9/5+32;
        printf("%d\t%d\n",celsius,fahrenheit);
        celsius=celsius+step;
    }
}
