/*
Append contetnt of a file with another file
*/

# include <stdio.h>
# define MaxSize 100000 
int main(){

    FILE* file1  ;
    FILE *file2 ;
    char f1name[100],f2name[100] ;
    printf("Enter name of file to read from : ") ;
    gets(f1name) ;
    printf("Enter name of file to append into : ") ;
    gets(f2name) ;
    file1 = fopen(f1name,"r") ;
    file2 = fopen(f2name,"a") ;

    if(file1 == NULL){
        printf("Reading file does not exist \n") ;
        return 0 ;
    }
    if(file2 == NULL){
        printf("File to append into does not exist \n") ;
    }

    char readText[MaxSize] ;
    fgets(readText,MaxSize,file1) ;
    fclose(file1) ;
    fputs(readText,file2) ;
    fclose(file2) ;

}