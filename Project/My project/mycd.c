#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[]) {    
    printf("Entered %s\n", argv[1]);
    chdir(argv[1]); 
  
    // after chdir is executed 
    return 0; 
} 
