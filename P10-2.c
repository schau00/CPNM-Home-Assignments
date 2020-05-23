/*
PS : search a word in a file
*/
# include <stdio.h>
# include <string.h>
# define MaxSize 100000 

int main(){
    FILE* f ;
    char filename[MaxSize] ;
    printf("Enter name of file: ") ;
    gets(filename) ;
    f = fopen(filename,"r") ;
    char word[MaxSize] ;
    printf("Enter word to search : " ) ;
    gets(word) ;
    if(f==NULL){
        printf("File does not exist .\n") ;
        return 0 ;
    } 

    int line = 1;
        char s[1000];
        int i = 0;
        while((fgets(s ,1000 , f)) != NULL){
            if(strstr(s , word)!=NULL){
                printf("Word found at line %d\n" , line);
                i = 1;
            }
            line++;
        }
        if(i == 0){
            printf("Word was not found\n");
        }
}