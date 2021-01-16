#include <stdio.h>
#include <stdlib.h>

int main(void){

    int first_number;
    int second_number;

    printf("Enter two integer numbers saperated by a space: ");
    scanf("%d %d", &first_number, &second_number);

    if(first_number%2 ==0 && second_number%2 == 0)
        printf("You have entered two even numbers.");
    else if ((first_number%2 ==0 && second_number%2 == 1) || (first_number%2 ==1 && second_number%2 == 0)  )
        printf("You have entered one even number and one odd number.");
    else if (first_number%2 ==1 && second_number%2 == 1)
        printf("You have entered two odd numbers.\n");
        printf("\n");
    return 0;
}



