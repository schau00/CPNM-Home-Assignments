/*
Q : Write a recursive function which returns the sum of individual digits of a number passed as
argument.
*/

# include <stdio.h>

int sumOfDigits(int *);

int main(){
    int n, t;
    printf("Enter number : ");
    scanf("%d", &n);
    t = n;
    int sum = sumOfDigits(&t);
    printf("Sum of Digits : %d", sum);
    return 0;
}

int sumOfDigits(int *n){
    if(*n == 0){
        return 0;
    }
    int t = *n % 10;
    *n = *n / 10;
    return t + sumOfDigits(n);
}