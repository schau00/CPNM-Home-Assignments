/*
Q : Write a C program which accepts 100 integers and displays the counts of positives, negatives and
zeros entered.
*/

# include <stdio.h>
int main(){
    printf("Enter 100 numbers : ");
    int p = 0, n = 0, z = 0;
    int t, i;
    for(i = 0; i < 100; i++){
        scanf("%d", &t);
        if(t > 0){
            p ++;
        }
        else if(t < 0){
            n ++;
        }
        else{
            z ++;
        }
    }

    printf("Positive Numbers : %d\nNegative Numbers : %d\nZeroes : %d",p,n,z);
}