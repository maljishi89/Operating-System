#include <stdio.h>
#include <stdlib.h>


void reverse(char *line);

int main()
{
	char s[80]; 
    printf("Enter a string: ");
	gets(s);	
    printf("\n");
    printf("Non-reversed: ");
	puts(s);
    reverse(s);
    puts(s);
	return 0;
}


void reverse(char *line){
    int i;
    char c= ' ';
    char r[80];
    printf("\nReversed string:");
    i=0;
    int count =0;
    while(c != '\0'){

        c = *( line + (i*sizeof(char)) );
        r[i] = c;
        ++i;
        ++count;

    }
    
    i = count-1;
    c = ' ';
    int j=0;
    char *adr;
    while(0<=i){
        c = r[i];
        *adr = c;
        *(line + j*sizeof(char)) = *adr;
        --i;
        ++j;
        
    }
    *line = ' ';





}
