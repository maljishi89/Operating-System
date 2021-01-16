#include <stdio.h>
#include <ctype.h> 

void convertTime(int input, int *hours, int *min, int *sec);

int main(){
    int entered_sec;
    int s;
    int m;
    int h;
    printf("Enter time in seconds: ");
    scanf("%d", &entered_sec);
    convertTime(entered_sec, &h, &m, &s);

    printf("The time after converting is: %d hours %d minutes %d seconds.\n", h, m, s);


    return 0;
}

void convertTime(int input, int *hours, int *min, int *sec){
    if(input < 60){
        *sec = input;
        *min=0;
        *hours=0;
    }
    else if(input <3600){
    *min = input/60;
    input = input%60;
    *sec = input;
    *hours=0;

    }
    else if(input > 3599){
       *hours = input/3600;
       input = input%3600;
       *min = input/60;
       input = input%60;
       *sec = input;
    }

}
