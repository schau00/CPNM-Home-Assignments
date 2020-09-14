/*
Q : C program to find out sum of the following series.
S=1!+2!+3!+4!+ ... +n!
*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int i, sum = 0;
    int fact[n+1];
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i-1]*i;
    }
    for(i = 1; i <= n; i++){
        sum += fact[i];
    }
    printf("Sum = %d", sum);
    return 0;
}


