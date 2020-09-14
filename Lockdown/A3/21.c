/*
Q : Write a program which reads a positive integer value, and compute the following sequence: if the
number is even, halve it; if it’s odd, multiply by 3 and add 1. Repeat this process until the value is
1, printing out each intermediate value. Finally the program should print how many of these
operations were performed. Typical output might be:
Inital value is 3
Next value is 10
Next value is 5
Next value is 16
Next value is 8
Next value is 4
Next value is 2
Next value is 1
Number of operations is 7
*/

# include <stdio.h>
int main(){
    printf("Enter a positive integer value : ");
    int n;
    scanf("%d", &n);
    printf("Initial value is %d\n",n);
    int c = 0;
    while(n != 1){
        if(n & 1 == 1){
            n = n * 3;
            n += 1;
        }
        else{
            n = n / 2;
        }
        c ++ ;
        printf("Next value is %d\n",n);
    }
    printf("Number of operations is %d",c);
    return 0;

}