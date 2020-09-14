/*
Q : Write a C program to find out sum of the following series.
S=1+2+3+4+ ... +n
*/

# include <stdio.h>
int main(){
    int n, S = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; i++){
        S += i;
    }
    printf("Required sum = %d",S);
    return 0;
}