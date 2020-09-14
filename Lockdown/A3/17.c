/*
Q : Write a C program to print the first n numbers of the Fibonacci sequence. The Fibonacci sequence
is constructed by adding the last two numbers of the sequence so far to get the next number in the
sequence. The first and second numbers of the sequence are defined as 0 and 1. We get:
0, 1, 1, 2, 3, 5, 8, 13, 21…
*/

# include <stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int i = 2;
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for(i; i < n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("First %d numbers in Fibonacci Series are : ", n);
    for(i = 0; i < n; i++){
        printf(" %d",fib[i]);
        if(i == n-1){
            printf(".");
        }
        else{
            printf(",");
        }
    }
    
    return 0;
}

