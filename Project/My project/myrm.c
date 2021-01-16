#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 
#include <dirent.h>


int main(int argc, char *argv[]){
    
    char *str;

    str = argv[1];

    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir(".");
    if(folder == NULL)
    {
        printf("Unable to read directory\n");
        
    }

    while( (entry=readdir(folder)) )
    {
        files++;
        if(!strcmp(argv[1], entry->d_name)){
            remove(argv[1]);
        }
            
    }
    printf("\n");
    closedir(folder);

    return 0;
}



