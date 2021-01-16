#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main() { 

    printf("Only one command word is excutable at a time.\n");
    pid_t pid;
    char normal[80] = "Terminated: Normally";
    char failed[80] = "Terminated: Failed!";
    char test[80];
    int status;

   while(1){
    strcpy(test,normal);
    char str[80];
    printf("201690160> ");
    fgets(str, 80, stdin);
    int len = strlen(str);
    // removing \n character
    if(len > 0 && str[len-1] == '\n')
    str[len-1] = '\0';


    if(!strcmp(str,"exit")){
        printf("Exiting...\n");
        break;

    } 
        // if other keywords is entered...
    else {
    pid = fork();
        if(pid == -1){
    printf("fork error");
    break;
    }
    // in child process
    else if(pid == 0){
    char n=0;
    char *arg[160] = {str,NULL};
    printf("Excuting..\n");
    execvp(arg[0], arg); 
    n = -1;
    return n;
    break;
        }

    else
    {
        // waiting for the child to finish       
        wait(&status); 
        if(status == 0)
            printf("Terminated: Normally\nExit status: %d\n",status);
        else
            printf("Terminated: Failed!\nExit status: %d\n",status);
    } 
 

        }
    


        

   } // for the while loop

   return 0;
}  
