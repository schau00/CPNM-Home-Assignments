/*
Hello World
How are you ?
*/
#include <stdio.h>
int main(){
    FILE *thisFile = fopen(__FILE__,"r");
    char c;
    while(c != EOF){
        c = fgetc(thisFile);
        putchar(c);
    }
    fclose(thisFile);
    return 0;
}