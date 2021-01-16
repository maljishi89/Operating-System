#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// some of these methods are not used, because I wrote them with diffrent approach in mind then I redid it after doctor explanation with the other

void readfile(char a[80]);
void readfile_plus(char a[80]);
void w_new_file(char b[80]);
void w_new_file_plus(char b[80]);
void copy_file(char b[80], char b2[80]);
void copy_append(char b[80], char b2[80]);
void appendfile(char b[80]);
void appendfile_plus(char b[80]);


int main(int argc, char *argv[]){
    int i;
    // printf("\nExamples of inputs: \n1- ./Ex5.out mycat o <filename>\n2- ./Ex5.out mycat oo <filename>\n3- ./Ex5.out mycat <filename> o|oo <filename>\n3- ./Ex5.out mycat <filename>\n\n\n\n");
    
    if(!strcmp(argv[1], "mycat") && 3==argc){
        readfile(argv[2]);
    }

    else if(!strcmp(argv[1], "mycat") && 3<argc && argc<5){
        
        if(!strcmp(argv[2], "o")){
            w_new_file(argv[3]);
            
        }
        else if(!strcmp(argv[2], "oo")){
            appendfile_plus(argv[3]);
        }
        else{
            
        // printf("%s %s\n", argv[0], argv[1]);
        printf("\nThis word is not supported yet!\nmycat is the only supported word!\n");
        printf("\nExamples of inputs: \n1- ./Ex5.out o <filename>\n2- ./Ex5.out oo <filename>\n3- ./Ex5.out <filename> o|oo <filename>\n\n\n");      
        
        }
    }
    else {
         if(!strcmp(argv[1], "mycat") && 4<argc && argc<6){
        printf("Entered two files...\n");
            if(!strcmp(argv[3], "o") ){
                copy_file(argv[2], argv[4]);
            }
            
            else if(!strcmp(argv[3], "oo")){
                copy_append(argv[2], argv[4]);

            }
            
        }
        else{
        printf("%d", argc);
        printf("\nThis word is not supported yet!\nmycat is the only supported word!\n");
        printf("\nExamples of inputs: \n1- ./Ex5.out o <filename>\n2- ./Ex5.out oo <filename>\n3- ./Ex5.out <filename> o|oo <filename>\n\n\n");        }
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
void copy_file(char b[80], char b2[80]){
    // first we need to read the first file
        FILE *in;
        FILE *out;
        in = fopen(b,"r+");
        out = fopen(b2,"w+");
        if(in == NULL || out == NULL){
        printf("Error: Failed to open %s or %s\n", b, b2);
        system("PAUSE");
        exit(1);
        }
        char ch;
        char str[180] = " ";
        while((ch = fgetc(in)) != EOF)
        {   
            fprintf(out, "%c", ch);
        }
        printf("This file has been copied!\n");
        
        fclose(in);
        fclose(out);  
}

void copy_append(char b[80], char b2[80]){

    // first we need to read the first file
        FILE *in;
        FILE *out;
        in = fopen(b,"r+");
        out = fopen(b2,"a+");
        if(in == NULL || out == NULL){
        printf("Error: Failed to open %s or %s\n", b, b2);
        system("PAUSE");
        exit(1);
        }
        char ch;
        char str[180] = " ";
        while((ch = fgetc(in)) != EOF)
        {   
            fprintf(out, "%c", ch);
        }
        printf("This file data has been copied and appended to the file %s!\n", b2);
        
        fclose(in);
        fclose(out);  
    

}
