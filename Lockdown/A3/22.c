/*
Q : Writte a program to print all the ASCII values and their equivalent characters using a while loop.
The ASCII values vary from 0 to 255.
*/

#include <stdio.h>
int main(){
    int i = 0;
    while (i != 256){
        char C = i;
        printf("ASCII Value of character %c = %d\n",C,i);
        i ++;
    }
    
}