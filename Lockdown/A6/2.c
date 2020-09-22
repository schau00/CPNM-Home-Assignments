/*
Q : Write a program in C to create and store information in a text file.
*/

#include <stdio.h>
# define MaxSize 100000
int main(){
    FILE *wf;
    char fileName[100];
    printf("Enter the name of the file to create : ");
    gets(fileName);
    wf = fopen(fileName, "w");
    char information[MaxSize];
    printf("Enter the information to store : ");
    scanf("%[^\n]", information);
    fputs(information, wf);
    fclose(wf);
    return 0;

}