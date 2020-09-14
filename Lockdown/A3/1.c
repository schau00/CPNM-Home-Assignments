/*
Q :  Write a C program which prints all integers divisible by n between 1 and 100 where value of n is
provided by the user.
*/
# include <stdio.h>
int main(){
    int n;
    printf("Enter the divisor : ");
    scanf("%d",&n);
    if(n > 100){
        printf("Sorry no numbers between 1 - 100 are divisible by n .");
        return 0;
    }
    int i = 1;
    printf("The numbers divisible by n are : ");
    for(i; i <= 100; i++){
        if(i % n == 0){
            printf("%d ",i);
        }
    }

    return 0;
    
}