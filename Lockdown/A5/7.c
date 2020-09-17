/*
Q : Write a C program which accepts a full name from user prints the initials. Eg. SRT for Sachin
Ramesh Tendulkar.
*/

# include <stdio.h>
# include <stdlib.h>

void printInitials(char *);

void main(){
    printf("Enter name : ");
    char * string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);
    printf("Initials : ");
    printInitials(string);
    free(string);
    return;
}
void printInitials(char *string){
    int i = 0;
    while(*(string + i) != '\0'){
        if(i == 0 ){
            printf("%c", *(string + i));
        }
        if(*(string + i) == ' ' && *(string + i) != '\0'){
            printf("%c", *(string + i + 1));
        }

        i ++;
    }
    return ;
}