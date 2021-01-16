#include <stdio.h> 
#include <signal.h> 
#include <unistd.h>
#include <math.h>
#include <stdlib.h> 
#include <pthread.h> 

int zeroFlag = 0; 
void zeroHandler();
int main() { 

    int x;
    int y;

    printf("Enter the first integer: ");
    scanf("%d", &x);
    printf("Enter the second integer: ");
    scanf("%d", &y);

    signal(SIGFPE , zeroHandler); 
    
    int z = x%y;

    printf("The reminder is %d\n", z);

    return 0;
}


void zeroHandler(){

    printf("\nOops! Division by zero\n");
    printf("\nexiting...\n");
    exit(0);
}
