/*
Q :  Write a C program to find out factorial of a given number. 
*/

#include <stdio.h>
int main(){
    int n ;
    printf("Enter a number n : ");
    scanf("%d", &n);
    int i;
    int fact[n+1];
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i-1]*i;
    }
    printf("Factorial of n = %d", fact[n]);
    return 0;
}