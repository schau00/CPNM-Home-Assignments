/*
Q : . Write a program to count the number of occurrences of any two vowels in succession in a line of
text.
*/

# include <stdio.h>
# include <stdlib.h>
int countOfVowel(char , char *);

void main(){
    printf("Enter line : ");
    char *line = (char *)malloc(sizeof(char) * 1000);
    scanf("%[^\n]", line);

    printf("Count of a in line : %d\n", countOfVowel('a', line));
    printf("Count of e in line : %d\n", countOfVowel('e', line));
    free(line);
    return;
}


int countOfVowel(char c, char *line){
    int i = 0, count = 0;
    while (*(line + i) != '\0'){
        if(*(line + i) == c){
            count ++;
        }
        i ++;
    }
    return count;
}