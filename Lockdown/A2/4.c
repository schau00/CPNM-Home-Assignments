/*
Q : An integer is entered as an input through the keyboard. Write a program to find out whether it is an
odd number or an even number.
*/

# include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n & 1 == 1){
        printf("The number is Odd");
    }
    else{
        printf("The number is Even");
    }
    return 0;
}