#include <stdio.h>
#include <ctype.h> 

void swap4(int *a, int *b, float *f1, float *f2);


int main(){
    int a;
    int b;
    float f1;
    float f2;

    printf("Enter 2 integers and 2 float variables: ");
    scanf("%d %d %f %f", &a,&b, &f1, &f2);
    swap4(&a,&b, &f1, &f2);
    printf("data swapped: %d, %d, %f, %f ", a,b,f1,f2);


    return 0;
}

void swap4(int *a, int *b, float *f1, float *f2){
    int c= *a;
    float f3 = *f1;
    *a= *b;
    *b = c;
    *f1 = *f2;
    *f2 = f3;

}
