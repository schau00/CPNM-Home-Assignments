/*
Q : Write a C program which accepts a string from user and prints the reverse of the string without
using string library functions.
*/

# include <stdio.h>
# include <stdlib.h>

void stringReverse(char *);
int numberOfCharacters(char *);
void swap(char*, char*);
void main(){
    printf("Enter string : ");
    char *string = (char *)malloc(sizeof(char) * 1000);
    scanf("%[^\n]", string);
    stringReverse(string);
    printf("Reversed string : %s", string);
    free(string);
    return;
}
int numberOfCharacters(char *string){
    int i = 0;
    for(i; i < 1000; i++){
        if(*(string + i) == '\0'){
            break;
        }
    }

    return i;
} 
void stringReverse(char *string){
    int stringLength = numberOfCharacters(string);
    int i = 0, j = stringLength-1;
    while (i < j){
        swap((string + i), (string + j));
        i ++;
        j --;
    }
    return;
    
}
void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
    return;
}