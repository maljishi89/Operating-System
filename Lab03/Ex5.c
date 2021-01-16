#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readfile(char a[80]);
void readfile_plus(char a[80]);
void w_new_file(char b[80]);
void w_new_file_plus(char b[80]);
void appendfile(char b[80]);
void appendfile_plus(char b[80]);


int main(int argc, char *argv[]){
    int i;
    printf("\nExamples of inputs: \n1- reading:   ./Ex5.out r|r+ <filename>\n2- writing:   ./Ex5.out w|w+ <filename>\n3- appending: ./Ex5.out a|a+ <filename>\n\n\n");
    if(!strcmp(argv[1], "mycat") && 3<argc && argc<5){

        if(!strcmp(argv[2], "r")){
            readfile(argv[3]);
        }
        else if(!strcmp(argv[2], "w")){
            w_new_file(argv[3]);
            
        }
        else if(!strcmp(argv[2], "a")){
            appendfile(argv[3]);
        }
        else if(!strcmp(argv[2], "r+")){
            readfile_plus(argv[3]);
        }
        else if(!strcmp(argv[2], "w+")){
            w_new_file_plus(argv[3]);
        }
        else if(!strcmp(argv[2], "a+")){
            appendfile_plus(argv[3]);
        }
        else{
        printf("\nThis word is not supported yet!\nmycat is the only supported word!\n");
        printf("\nExamples of inputs: \n1- reading: ./Ex5.out r <filename>\n2- writing: ./Ex5.out w <filename>\n3- appending: ./Ex5.out a <filename>\n");
        }







    }
    else {
        printf("\nThis word is not supported yet!\nmycat is the only supported word!\n");
        printf("\nExamples of inputs: \n1- reading: ./Ex5.out r <filename>\n2- writing: ./Ex5.out w <filename>\n3- appending: ./Ex5.out a <filename>\n");
    }
    


    return 0;
}

void readfile(char a[80]){

    FILE *in;
    in = fopen(a,"r");
    if(in == NULL){
      printf("Error: Failed to open %s\n", a);
      system("PAUSE");
      exit(1);
    }
    printf("File texts:\n");
    char ch;
    while((ch = fgetc(in)) != EOF)
    fputc(ch, stdout);

    fclose(in);  
}
void readfile_plus(char a[80]){

    FILE *in;
    in = fopen(a,"r+");
    if(in == NULL){
      printf("Error: Failed to open %s\n", a);
      system("PAUSE");
      exit(1);
    }
    printf("File texts:\n");
    char ch;
    while((ch = fgetc(in)) != EOF)
    fputc(ch, stdout);
    printf("Start adding to the file:\n");
    char str[180];
    fgets(str, 180, stdin);
	fprintf(in, "%s\n", str);
    fclose(in);  
}


void w_new_file(char b[80]){

    
    FILE *in;
    in = fopen(b,"w");
    if(in == NULL){
      printf("Error: Failed to create %s\n", b);
      system("PAUSE");
      exit(1);
    }
    printf("Start writing new the file:\n");
    char c = ' ';
    char str[180];

    fgets(str, 180, stdin);
	fprintf(in, "%s\n", str);

    fclose(in);  

}
void w_new_file_plus(char b[80]){

    
    FILE *in;
    in = fopen(b,"w+");
    if(in == NULL){
      printf("Error: Failed to create %s\n", b);
      system("PAUSE");
      exit(1);
    }
    char str[180];
    char ch;
    while((ch = fgetc(in)) != EOF)
    fputc(ch, stdout);
    
    printf("Start writing to the file:\n");
    fgets(str, 180, stdin);
	fprintf(in, "%s\n", str);
    fclose(in);  

}

void appendfile(char b[80]){
   FILE *in;
    in = fopen(b,"a");
    if(in == NULL){
      printf("Error: Failed to open %s\n", b);
      system("PAUSE");
      exit(1);
    }
    printf("Start appending into the file:\n");
    char c = ' ';
    char str[180];

    fgets(str, 180, stdin);
	fprintf(in, "%s\n", str);

    fclose(in);  

}
void appendfile_plus(char b[80]){
   FILE *in;
    in = fopen(b,"a+");
    if(in == NULL){
      printf("Error: Failed to open %s\n", b);
      system("PAUSE");
      exit(1);
    }
    char c = ' ';
    char str[180];
    char ch;
    while((ch = fgetc(in)) != EOF)
    fputc(ch, stdout);
    
    printf("Start appending into the file:\n");
    fgets(str, 180, stdin);
	fprintf(in, "%s\n", str);

    fclose(in);  

}

