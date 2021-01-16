#include <pthread.h> 
#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 

struct kidrec {     
    int *data1;
    int *data2;
    int *data3;
    pthread_t id; 
} ; 
void *add(void *x) {
    struct kidrec *k = (struct kidrec*) x;
    int *a = k->data1;
    int *b = k->data2;
    int *c = k->data3;
    *c = *a + *b;

}
struct arrays {
    int *A;
    int *B;
    int *C;
};


  int s = 1;
  
  void *Init_thread(void *y) {
	struct arrays *m = (struct arrays*) y;
    int *A = (int *)m->A;
    int *B = (int *)m->B;
    int *C = (int *)m->C;

    printf("A array: \n");
	for (int i=0; i<s; i++){
        A[i]= rand() %10;
		printf("%d ", A[i]);
	}

    printf("\nB array: \n");
	for (int i=0; i<s; i++){
        B[i]= rand() %10;
		printf("%d ", B[i]);
	}
    printf("\n");
    // after initializing the arrays we should create n thread to calculate C[i] = A[i] + B[i]
    struct kidrec kids[s] ; 

    for (int i=0; i<s; ++i) { 
        kids[i].data1 = &A[i];
        kids[i].data2 = &B[i];
        kids[i].data3 = &C[i];
        int c;
        c = pthread_create (&kids[i].id, NULL, add, &kids[i]) ;
        if(c){
            printf("Error in creation...");
            exit(0);
         }
    }  
    
    for (int i=0; i<s; ++i) 
        pthread_join (kids[i].id, NULL) ; 

    printf("C array\n");
    for (int i=0; i<s; ++i) 
        printf("%d ", C[i]);

    printf("\n");
}

int main(void) 
{         
    srand(time(0)); 
    printf("Enter the length of 1-d array you want to calculate values (1,100]: ");
    scanf("%d",&s);

    if(s> 0 && s<101){
    
    struct arrays m;
    int A[s];
    int B[s];
    int C[s];
    m.A = A;
    m.B = B;
    m.C = C;
    int i=0;

    pthread_t t1;        
    int c;
    
    c = pthread_create(&t1, NULL, Init_thread, &m);
    if(c){
        printf("Error in creation...");
        exit(1);
    }

    pthread_join(t1, NULL); 

    

    }
    else{
        printf("\nWrong input!\n");
    }
    
  
 
    return 0; 
} 


