/*
Q : . Write a C program which prints all prime numbers between 1 and 100.
*/

# include <stdio.h>
int main(){
    int prime[101];
    int i, j;
    for(i = 0; i <= 100; i++){
        prime[i] = 0;
    }

    for(i = 2; i <= 100; i++){
        if(prime[i] != 1){
            j = 2;
            while(i*j <= 100){
                prime[i*j] = 1;
                j ++;
            }
        }
    }

    printf("Prime Numbers between 1 to 100 are : ");
    for(i = 2; i <= 100; i++){
        if(prime[i] != 1){
            printf("%d ",i);
        }
    }
    return 0;
}