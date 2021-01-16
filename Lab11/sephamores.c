#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <time.h>
#include <stdlib.h>
#define SIZE 5

sem_t s; 
int num[SIZE];

void* threadroutine(void*); 
void* threadroutine2(void*); 



int main() 
{ 
    pthread_t tid,tid2;      
    sem_init(&s, 0, 1); 
    pthread_create(&tid, NULL, threadroutine, NULL);
    pthread_create(&tid2, NULL, threadroutine2, NULL);

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);    
    
    sem_destroy(&s); 
    return 0; 
}  

void* threadroutine(void* arg) 
{ 
    for(int i = 0; i < SIZE; i++){

        sem_wait(&s);   
        num[i]= rand() % 100; 
        sem_post(&s); 


    }
}  


void* threadroutine2(void* arg) 
{ 
    for(int i = 0; i < SIZE; i++){
        sem_wait(&s);   
        printf("number[%d] is %d \n", i, num[i]); 
        sem_post(&s); 

    }
}  


