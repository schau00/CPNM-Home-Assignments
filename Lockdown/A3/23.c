/*
Q : Write a program to find the octal equivalent of the entered integer
*/

# include <stdio.h>
int main(){
    int n;
    printf("Enter a number in decimal : ");
    scanf("%d",&n);
    int octal = 0;
    int i = 1;
    while(n != 0){
        octal += (n % 8)*i;
        i = i * 10;
        n = n/8;
    }

    printf("The octal equivalent is : %d",octal);
    return 0;

}