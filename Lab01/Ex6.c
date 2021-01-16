#include <stdio.h>
#include <stdlib.h>

int main(void){

    int days;
    int loop=1;

    while (loop ==1){

        printf("Enter a number of days for a months (28,29,30,31): ");
        scanf("%d", &days);

        switch (days){

            case 28: 
                printf("February is the only month with 28 days in non leap year!");
                loop=0;
                break;
            
            case 29:
                printf("February is the only month with 29 days in leap year!");
                loop=0;
                break;
            case 30:
                printf("All 30 days months: September, April, June, and November.");
                loop=0;
                break;
            case 31:
                printf("All 31 days months: January, March, May, July, August, October, and December.");
                loop=0;
                break;

            default:
                printf("Invalid input!");
                printf("\n");

        }

    }
    printf("\n");

    return 0;
}




