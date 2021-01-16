#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 

// I tried using token, but they don't work I keep getting errors

int main() { 

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
        // array of commands
        
        
        int i;
        int count =0;

        for (i = 0; i<80; i++){
            if(str[i] == ' ')
                ++count;
        }
        char arg1[80];
        char arg2[80];
        char arg3[80];
        char arg4[80];
        char arg5[80];

        if(count ==0){
            strcpy(arg1, str);

        }
        else if (count ==1){
            
            for (i = 0; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg1[i] = str[i];
            }
            arg1[i+1] = '\0';
            int j=0;
            i = i+1;
            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg2[j] = str[i];
                ++j;
            }
            arg2[j+1] ='\0';
            //printf("string 1: %s, string2: %s\n", arg1, arg2);


        }
        else if (count ==2){

            for (i = 0; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg1[i] = str[i];
            }
            arg1[i+1] = '\0';
            int j=0;
            i = i+1;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg2[j] = str[i];
                ++j;
            }
            arg2[j+1] ='\0';
            i= i+1;
            j = 0;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg3[j] = str[i];
                ++j;
            }
            arg3[j+1] ='\0';
            //printf("string 1: %s, string2: %s, string3: %s\n", arg1, arg2, arg3);

        }
        else if (count ==3){
            for (i = 0; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg1[i] = str[i];
            }
            arg1[i+1] = '\0';
            int j=0;
            i = i+1;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg2[j] = str[i];
                ++j;
            }
            arg2[j+1] ='\0';
            i= i+1;
            j = 0;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg3[j] = str[i];
                ++j;
            }
            arg3[j+1] ='\0';
            i = i+1;
            j = 0;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg4[j] = str[i];
                ++j;
            }
            arg4[j+1] ='\0';
            //printf("string 1: %s, string2: %s, string3: %s, string4: %s\n", arg1, arg2, arg3, arg4);
        }
        else if (count ==4){
            for (i = 0; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg1[i] = str[i];
            }
            arg1[i+1] = '\0';
            int j=0;
            i = i+1;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg2[j] = str[i];
                ++j;
            }
            arg2[j+1] ='\0';
            i= i+1;
            j = 0;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg3[j] = str[i];
                ++j;
            }
            arg3[j+1] ='\0';
            i = i+1;
            j = 0;

            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg4[j] = str[i];
                ++j;
            }
            arg4[j+1] ='\0';
            j = 0;
            i = i+1;
            for (; i<80 ; i++){
                if(str[i] == ' ')
                    break;
                arg5[j] = str[i];
                ++j;
            }
            arg5[j+1] ='\0';
            //printf("string 1: %s, string2: %s, string3: %s, string4: %s, string5: %s\n", arg1, arg2, arg3, arg4, arg5);
        }

        // let's start the execuation here
        if(!strcmp(arg1,"exit\n")){
            printf("Exiting...\n");
            break;
        } 

        else {

            pid = fork();
            if(pid == -1){
                printf("fork error");
                break;
             }
            else if(pid == 0){

            char n=0;
            // having 2 cmd
            if(count ==0){

                int k;
                for (k=0; k<80; k++){
                    if(arg1[k] == '\n' || arg1[k] == '\0'  )
                    break;
                }
                arg1[k] = '\0';
                if (strcmp(arg1, "myls") ==0){

                    char *arg[160] = {"./myls",NULL};

                    execvp(arg[0], arg);

                }
                else if(strcmp(arg1, "myclear") ==0){
                    char *arg[160] = {"./myclear",NULL};

                    execvp(arg[0], arg);
                }
                else if(strcmp(arg1, "mypwd") ==0){
                    char *arg[160] = {"./mypwd",NULL};

                    execvp(arg[0], arg);
                }
                    
                else{
                    char *arg[160] = {arg1,NULL};
                    printf("Excuting..\n");
                    execvp(arg[0], arg); 
                    n = -1;
                    return n;
                    break;

                }


            }
            else if (count ==1){
                int k;
                for (k=0; k<80; k++){
                    if(arg2[k] == '\n')
                    break;
                }
                arg2[k] = '\0';
                if (strcmp(arg1, "mycat") ==0){
                    
                    // printf("You are using %s\n", arg1);
                    char *arg[160] = {"./mycat", "mycat",arg2,NULL};

                    execvp(arg[0], arg);


                }
                else if (strcmp(arg1, "myrm") ==0){
                    char *arg[160] = {"./myrm",arg2,NULL};

                    execvp(arg[0], arg);
                }
                else if (strcmp(arg1, "mymkdir") ==0){
                    char *arg[160] = {"./mymkdir",arg2,NULL};

                    execvp(arg[0], arg);
                }
                else if (strcmp(arg1, "mycd") ==0){
                    char *arg[160] = {"./mycd",arg2,NULL};

                    execvp(arg[0], arg);
                }


                else {
                    char *arg[160] = {arg1,arg2,NULL};
                    printf("Excuting..\n");
                    execvp(arg[0], arg); 
                    n = -1;
                    return n;
                    break;

                }

            }
            else if (count ==2){
                int k;
                for (k=0; k<80; k++){
                    if(arg3[k] == '\n')
                    break;
                }
                arg3[k] = '\0';
                if (strcmp(arg1, "mycat") ==0){
                
                printf("You are using %s\n", arg2);
                char *arg[160] = {"./mycat", "mycat",arg2, arg3,NULL};

                execvp(arg[0], arg);


                }
                else if(strcmp(arg1, "mycp")==0){
                    char *arg[160] = {"./mycat", "mycat",arg2,"oo", arg3,NULL};

                    execvp(arg[0], arg);
                }

                else if(strcmp(arg1, "myhead")==0){

                    char *arg[160] = {"./myhead", "textlines",arg3,arg3, arg2, "head",NULL};

                    execvp(arg[0], arg);
                }
                else if(strcmp(arg1, "mytail")==0){
                    char *arg[160] = {"./mytail", "textlines",arg3,arg3, arg2,NULL};

                    execvp(arg[0], arg);
                }
                
                else{

                    char *arg[160] = {arg1,arg2,arg3,NULL};
                    printf("Excuting..\n");
                    execvp(arg[0], arg); 
                    n = -1;
                    return n;
                    break;
                
                }
                
            }
            else if (count ==3){
                int k;
                for (k=0; k<80; k++){
                    if(arg4[k] == '\n')
                    break;
                }
                arg4[k] = '\0';
                if (strcmp(arg1, "mycat") ==0){
                
                    printf("You are using %s\n", arg2);
                    char *arg[160] = {"./mycat", "mycat",arg2, arg3,arg4,NULL};

                    execvp(arg[0], arg);


                }
                else {
                    char *arg[160] = {arg1,arg2,arg3,arg4,NULL};
                    printf("Excuting..\n");
                    execvp(arg[0], arg); 
                    n = -1;
                    return n;
                    break;
                }
                
            }
            else if (count ==4){
                int k;
                for (k=0; k<80; k++){
                    if(arg5[k] == '\n')
                    break;
                }
                arg5[k] = '\0';
                
                char *arg[160] = {arg1,arg2,arg3,arg4,arg5,NULL};
                printf("Excuting..\n");
                execvp(arg[0], arg); 
                n = -1;
                return n;
                break;
                
            }
            
            

            }

        else {
        // waiting for the child to finish       
        wait(&status); 
        // if(status == 0)
        //     printf("Terminated: Normally\nExit status: %d\n",status);
        // else
        //     printf("Terminated: Failed!\nExit status: %d\n",status);

            } 

        }

        

        




        // to clear the strings
        memset(str, '\0', sizeof str);
        memset(arg1, '\0', sizeof arg1);
        memset(arg2, '\0', sizeof arg2);
        memset(arg3, '\0', sizeof arg3);
        memset(arg4, '\0', sizeof arg4);
        memset(arg5, '\0', sizeof arg5);
        
    } // while loop





    return 0;
}



