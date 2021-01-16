#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main(void){

    double radius;
    double side;
    double yellow_area;
    double red_area;
    
    printf("Enter the radius value <cm>:\n");
    scanf("%lf",&radius);
    
    side = 2*radius;
    red_area = PI*radius*radius;
    yellow_area = side*side - red_area; 
    
    printf("Yellow area = %.2lf square cm \n", yellow_area);
    printf("Red area = %.2lf square cm \n", red_area);
    printf("Enter to terminate . . .");



    return 0;
}

