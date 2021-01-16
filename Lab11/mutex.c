#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <stdlib.h>
#define SIZE 5
void* threadroutine(void*); 
void* threadroutine2(void*); 


pthread_mutex_t m; 
pthread_mutex_t m2; 


int num[SIZE];

int main(void) 
{ 
    srand(time(NULL));   
    pthread_t tid, tid2;      
    pthread_mutex_init(&m, NULL);
    pthread_mutex_init(&m2, NULL);   

    pthread_create(&tid, NULL, threadroutine, NULL); 
    pthread_create(&tid2, NULL, threadroutine2, NULL); 
    
    
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);    
    pthread_mutex_destroy(&m);
    pthread_mutex_destroy(&m2); 

    return 0; 
} 

void* threadroutine(void* arg) 
{ 
    for(int i = 0; i < SIZE; i++){
        pthread_mutex_lock(&m);     
        num[i]= rand() % 100; 
        pthread_mutex_unlock(&m2); 

    }
}  

void* threadroutine2(void* arg) 
{ 
    for(int i = 0; i < SIZE; i++){
        pthread_mutex_lock(&m2);     
        printf("number[%d] is %d \n", i, num[i]);
        pthread_mutex_unlock(&m); 

    }
}  

