/*
Q : Write a C program to find out sum of the following series.
S=1.2+2.3+3.4+4.5+ ... +n.(n+1)
*/

# include <stdio.h>
int main(){
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int sum = 0, i = 1;
    for(i; i <= n; i++){
        sum += (i*(i+1));
    }
    printf("Sum = %d", sum);
    return 0;
}