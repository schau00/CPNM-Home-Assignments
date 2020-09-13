/*
Q : Input two integer numbers and divide the larger number by the smaller one. Then display the result
using printf() function as a fractional number first and then as a real valued number. 
*/
# include <stdio.h>
int main(){
    int a, b;
    printf("Enter first number : ");
    scanf("%d",&a);
    printf("Enter second number : ");
    scanf("%d",&b);
    int max, min;
    if(a > b){
        max = a;
        min = b;
    }
    else{
        max = b;
        min = a;
    }
    printf("Fractional value = %d/%d\n", (max % min), min);
    printf("Real valued number = %0.2f\n", (max*1.00 / min));
    return 0;
}