#include <stdio.h>
#include <stdlib.h>
#define PI 3.1429

int main(void){

    int loop=1;
    double radius;
    double area;
    double cir;
    while (loop == 1) {
        printf("Enter radius <0 to quit>: ");
        scanf("%lf", &radius);
        if(radius == 0)
            break;
        area = PI * radius * radius;
        cir = 2 * radius * PI;

        printf("radius = %.2lf cm, area = %.2lf square cm, circumference = %.2lf cm \n", radius, area, cir);
        printf("\n");
    }
    printf("\n");

    return 0;
}





