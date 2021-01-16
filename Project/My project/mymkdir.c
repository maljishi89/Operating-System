#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
int main(int argc, char *argv[]) 
{ 
    int check; 
    char* dirname = argv[1]; 
  
    check = mkdir(dirname,0777); 

    return 0; 
} 
