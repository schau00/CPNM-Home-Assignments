
/*
Q : Write a C program that reads two values from the keyboard, swaps their values and prints out the
result.
*/

# include <stdio.h>
int main(){
    char s1[100], s2[100];
    scanf("%s",&s1);
    scanf("%s",&s2);
    char temp[100];
    int i = 0;
    for(i; i < 100; i++){
        temp[i] = s1[i];
        s1[i] = s2[i];
        s2[i] = temp[i];
    }
    printf("%s %s",s1,s2);
    return 0;

}

