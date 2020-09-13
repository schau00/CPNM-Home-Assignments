/*
Q : Write a C program to find the maximum and minimum of three numbers.
*/

# include <stdio.h>
int main(){
    int a, b, c;
    int max, min;
    printf("Enter the first number : ");
    scanf("%d",&a);
    max = a;
    min = a;
    printf("Enter the second number : ");
    scanf("%d",&b);
    if(max < b){
        max = b;
    }
    if(min > b){
        min = b;
    }
    printf("Enter the third number : ");
    scanf("%d",&c);
    if(max < c){
        max = c;
    }
    if(min > c){
        min = c;
    }
    printf("Max number = %d\n",max);
    printf("Min number = %d",min);

    return 0;    
    
}