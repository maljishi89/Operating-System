#include <stdio.h>
#include <stdlib.h>
#define PI 3.1429
#include <math.h>

int main(void){

    int number;
    int reminder=-1;
    int reverse = 0;
    int digits;


    printf("Enter an integer number to be displayed in reverse: ");
    scanf("%d", &number);
    reminder= number%10;
    while (reminder>0){
        
        digits = ((number == 0) ? 1  : (log10(number) + 1)) -1;
        if(digits ==-1){
            reverse= number;
            break;
        }
        reminder = number%10;
        number = number /10;
        reverse = reverse + reminder* pow(10,digits);



    }

    printf("Reversed value = %d", reverse);



    printf("\n");

    return 0;
}





