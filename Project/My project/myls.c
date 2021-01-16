#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 
#include <dirent.h>


int main(){

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
        printf("%3d: %s  ",
                files,
                entry->d_name
              );
    }
    printf("\n");
    closedir(folder);

    return 0;
}



