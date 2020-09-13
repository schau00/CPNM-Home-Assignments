/*
Q : If a five-digit integer is input through the keyboard, write a program to print a new number by
adding one to each of its digits. For example if the number that is input is 12391 then the output
should be displayed as 23402.
*/

# include <stdio.h>
int main(){
    char digits[5];
    int i = 0;
    printf("Enter the number : ");
    for(i; i < 5; i++){
        scanf("%c",&digits[i]);
        if(digits[i] != '9'){
            digits[i] ++;
        }
        else{
            digits[i] = '0';
        }
    }
    printf("The output number is : ");
    for(i = 0; i < 5; i++){
        printf("%c",digits[i]);
    }
    return 0;
}