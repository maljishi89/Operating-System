#include <stdio.h> 
#include <signal.h> 
#include <unistd.h>
#include <math.h>
#include <stdlib.h> 
#include <pthread.h> 

int alarmFlag = 0; 
void alarmHandler(); 

int main() { 

    int answer = 0;
    int not_answered = 0;
    srand(time(0)); 

    printf("Solve this question:\n");
    int x =  rand() %10;
    int y =  rand() %10;
    int z;

    printf(" %d  +  %d  = ", x, y);
    int result = x + y;

    signal(SIGALRM, alarmHandler);
    alarm(10); 

    scanf("%d", &z);


    if( z == (x + y)){
        printf("Correct Answer!\n");
    }
    else if(alarmFlag){
        
        printf("\nThe correct Answer is %d\n", result);

    }
    else {
        printf("\nWrong!\nThe correct Answer is %d\n", result);
    }

   
    return 0; 
} 


void alarmHandler() 
{ 
    printf("\nYou didn't answer the question!\n");     
    alarmFlag = 1; 
}  


