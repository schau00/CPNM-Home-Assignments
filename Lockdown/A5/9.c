/*
Q : Write a program that reads a line and converts it into all capitals without using any string library
function. (input string may also contain capital letters).
*/

# include<stdio.h>
# include <stdlib.h>

char* convertToUpper(char *);

void main(){
    printf("Enter a string : ");
    char *string = (char*)malloc(sizeof(char) * 1000);
    scanf("%[^\n]", string);
    printf("String with all capitals : %s", convertToUpper(string));
    free(string);
    return;
}

char* convertToUpper(char *string){
    int i = 0;
    while (*(string + i) != '\0'){  
        int asciiEquivalent = (int) *(string + i);
        if(asciiEquivalent >= 97 && asciiEquivalent <= 122){
            asciiEquivalent -= 32;
            *(string + i) = (char) asciiEquivalent;
        }
        i ++; 

    }
    return string;
}