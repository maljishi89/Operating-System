#include <stdio.h>
#include <stdlib.h>

int main(void){

    int change;
    int a;
    int b;
    int c;
    int d;
    int n_bills;
    printf("Enter the amount of change in Saudi Riyals: ");
    scanf("%d", &change);

    a = change/50;
    change = change%50;
    b = change/10;
    change = change%10;    
    c = change/5;
    change = change%5;
    d = change;
    n_bills = a+b+c+d;

    printf("The minimum number of bills is %d \n", n_bills);
    printf("Number of 50 Riyal bills =  %d \n", a);
    printf("Number of 10 Riyal bills =  %d \n", b);
    printf("Number of 5 Riyal bills =  %d \n", c);
    printf("Number of 1 Riyal bills =  %d \n", d);
  

    return 0;
}


