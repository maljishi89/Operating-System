#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h> /* defines options flags */  
#include <sys/types.h> /* defines types used by sys/stat.h */  
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */  
#include <string.h>

int main(int argc, char *argv[]){

    char message[800];
    if(!strcmp(argv[1], "textlines")){
        int fd;
        int m = atoi (argv[2]);
        int n = atoi (argv[3]);

        FILE *in;
        in = fopen(argv[4],"r");
        if(in == NULL){
            printf("Error: Failed to open example2.c\n");
            system("PAUSE");
            exit(1);
            }

        int first = m;
        char ch;
        int c = 0;
        while((ch = fgetc(in)) != EOF){
            if(ch == '\n')
                    ++c;
        }
        fclose(in); 

        int last = c - m;
        in = fopen("r.txt","r");
        if(in == NULL){
        printf("Error: Failed to open example2.c\n");
        system("PAUSE");
        exit(1);
        } 
        else {
            int z = 0;
            int flag =1;
            while((ch = fgetc(in)) != EOF){
                if(flag ==0){
                    fputc(ch, stdout);
                }
                if(ch == '\n')
                        ++z;
                if(z==last)
                    flag =0;
        }
        fclose(in);


    }        
            


    }
    else {
        printf("Wrong input..");
    }
    

        

    return 0;
}
