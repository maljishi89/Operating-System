#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define READ 0
#define WRITE 1
char* phrase = "This is ICS431 lab time";

int main(void) {

    // crating two pipes.
    int fd[2], fd2[2], bytesread ;
    char message[100] ;
    char input[100];
    pipe(fd);
    pipe(fd2);
    if (fork() == 0) /* child, writer */
    {
        close(fd[READ]); /* close unused end */
        printf("Enter a string to check for palandrome: ");
        fgets(input, 100, stdin);
        write(fd[WRITE], input, 100);
        close(fd[WRITE]); /* close used end */

        // reading the recieved results from the other process
        close(fd2[WRITE]); /* close unused end */
        bytesread = read(fd2[READ], message, 100);
        printf("Read in child %d bytes : %s\n", bytesread, message);
        close(fd2[READ]); /* close used end */
        int i;
        int size;
        int start=0;
        for(i = 0; i< 100 && input[i] != '\0'; i++)
            size = i;
        for(  i = 0; i<100; i++){
            if(message[i] == input[0]){
                start = i;
                break;
            }                
        }
        printf("The length of the string is %d\n", size);        
        int cmp = 0;
        int j = start;
        for (i =0; i< size; i++){
            if(message[j] == input[i]);
            else cmp = cmp +1;
            j = j +1;
        }
        printf("\n--------------Results--------------\n");
        if(cmp == 0){
            printf("\nYes, it is a palandrome!\n");

        }
        else{
            printf("\nNo, it is not a palandrome!\n");
        }


    }
    else /* parent, reader */
    {
        close(fd[WRITE]); /* close unused end */
        bytesread = read(fd[READ], message, 100);
        printf("Read in parent %d bytes :\n%s\n", bytesread, message);
        close(fd[READ]); /* close used end */

        int end;
        int i;
        for(i = 0; i< 100 && message[i] != '\0'; i++)
            end = i;
        char result[100];
        int j=0;
        for (i = end; i >=0; i--){
            result[j] = message[i];
            j = j + 1;
        }
        // writing the results.
        close(fd2[READ]); /* close unused end */
        write(fd2[WRITE], result, 100);
        close(fd2[WRITE]); /* close used end */

    }

}
