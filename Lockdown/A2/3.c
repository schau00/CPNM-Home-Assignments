/*
Q : If a three-digit integer is input through the keyboard, write a program to calculate the sum of its
digits.
*/
# include <stdio.h>
int main(){
    int n ;
    scanf("%d",&n);
    int sum = 0;
    while (n != 0){
        sum += (n%10);
        n = n/10;
    }
    printf("%d",sum);
    return 0;
}