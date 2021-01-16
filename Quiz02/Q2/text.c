#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define NUM_THREADS 20
#define NUM_FILES 20

int total_src = 0, total_uns = 0, alphanum_src = 0, alphanum_uns = 0, nonalpha_src = 0, nonalpha_uns = 0;

char* path = "/home/ubuntu/Q2";

void getFiles(char **, char *);

void *textAnalysis(void *threadid) {
    char fileName[80];

    strcpy(fileName, (char *) threadid);
    
    printf("FileName from threadid is %s is the filename\n", fileName);
    
    /* PROVIDE THE CODE TO FIND TEXT STATISTICS HERE */

} 

int main(void) 
{ 
    /*  
        PART 1: READS THE FILES IN 2-D ARRAY allFiles
        YOU DON'T HAVE TO PROGRAM THIS PART :)
    */
    
    char *allFiles[NUM_FILES];

    getFiles(allFiles, path);
    printf("All Files List is>>\n");
    for(int i = 0; i < NUM_FILES; i++)
        printf("Filename is %s\n", allFiles[i]);
    
    /* PROVIDE THE CODE FOR CREATING 20 PTHREADS EACH WITH A FILE NAME USING METHOD TEXTANALYSIS */
    
    /* PROVIDE THE CODE FOR DISPLAYING ABSOLUTE AND PERCENTAGE STATISTICS */	

}  

void getFiles(char* filesList[NUM_FILES], char* path) 
{
    struct dirent *dentry;
    DIR *dir = opendir(path); 
    
    if(dir == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open source directory" ); 
        return; 
    } 
  
    int count = 0;
    while ((dentry = readdir(dir)) != NULL) {
        if(strlen(dentry -> d_name) > 10) { //to ignore ".", ".." and "text.c"
            filesList[count] = (char *) malloc (sizeof(char) * (strlen(dentry -> d_name) + 1));
            strcpy(filesList[count++], dentry -> d_name);
        }
    }
    closedir(dir);
}