/*
Q : Write a function squeeze(s,c) which removes all occurrences of the character c from the string s .
*/
 
 # include <stdio.h>
 # include <stdlib.h>

 void removeChar(char* , char *);

 void main(){
     printf("Enter string : ");
     char *string = (char *)malloc(sizeof(char) * 1000);
     gets(string);
     char *ch = (char*)malloc(sizeof(char));
     printf("Enter character to remove : ");
     scanf("%c", ch);
     removeChar(ch, string);
     printf("New String : %s", string);
     free(string);
     return;
 }
 
void removeChar(char *ch, char *string){
    
    int i = 0, j = 0;
    while(*(string + i) != '\0'){
        if(*(string + i) != *ch){
            *(string + j) = *(string + i);
            j ++;
        }

        i ++;
    }

    *(string + j) = '\0';
    return;
}
