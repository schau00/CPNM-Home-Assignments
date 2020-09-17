/*
Q : Write a C program which accepts a string from user and counts the number of characters in the
string without using string library functions.
*/

# include <stdio.h>
# include <stdlib.h>
int numberOfCharacters(char *);
int main(){
    printf("Enter string : ");
    char *string = (char *)malloc(1000*sizeof(char));
    scanf("%[^\n]", string);
    printf("The number of characters : %d", numberOfCharacters(string));
    free(string);
    return 0;
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