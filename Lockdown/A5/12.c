/*
Q : . Write a program that converts a string like “123” to integer 123. Do not use any string library
function.
*/

# include <stdio.h>
# include <stdlib.h>

int convertToInt(char []);

void main(){
    char string[3] = "123";
    int num = convertToInt(string);
    printf("%d", num);
    return;
}

int convertToInt(char c[]){
    int i = 1, j = 2;
    int num = 0;
    while(j >= 0){
        num += (i*(int)(c[j] - '0'));
        i *= 10;
        j --;
    }
    return num;
}