#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

int main(void){
    
    
    double radius;
    double height;
    double volume;
    double surface_area;

    printf("Enter the radius <cm>:\n");
    scanf("%lf",&radius);
    printf("Enter the height <cm>:\n");
    scanf("%lf",&height);

    volume = PI * pow(radius,2) * height;
    surface_area = 2 * (PI * radius * height + PI * pow(radius,2));

    printf("Volume = %.2lf cubic cm\n", volume);
    printf("Surface Area = %.2lf square cm\n", surface_area);

    printf("Enter to terminate . . .");


    return 0;
}


