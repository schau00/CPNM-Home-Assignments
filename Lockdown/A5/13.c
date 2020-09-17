/*
Q : Write a C program which accepts a string from user and checks whether it is palindrome or not. Do
not use any string library function. [Example of a palindrome string: "abcba", "abba"]
*/

# include <stdio.h>
# include <stdlib.h>
int isPalindrome = 0;
void checkPalindrome(char *, int, int);
int numberOfCharacters(char *);
void main(){
    char* string = (char*)malloc(sizeof(char) * 1000);
    printf("Enter string : ");
    scanf("%[^\n]", string);
    int startingIndex = 0, lastIndex = numberOfCharacters(string)-1;
    checkPalindrome(string, startingIndex, lastIndex);
    if(isPalindrome == 0){
        printf("The Strng is a Palindrome.");
    }
    else{
        printf("String is Not a Palindrome.");
    }
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

void checkPalindrome(char *string, int start, int end){
    if(start >= end || isPalindrome != 0 ){
        return;
    }

    if(*(string + start) != *(string + end)){
        isPalindrome = 1;
    }

    return checkPalindrome(string, start+1, end-1);
}