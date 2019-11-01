#include<stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int i=0;
    int a[100];
    int count=0;
    printf("please give a positive number:\n");
    scanf("%d",&n);
    printf("the number is:");
    while (n){
        a[i]=n%2;
        i++;
        n/=2;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",a[j]);
        if(a[j]==1){
            count++;
        }
    }
    printf("\n\"1\"the number is%d\n",count);
    system("pause");
    return 0;
}

