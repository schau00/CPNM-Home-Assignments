/*
PS : Count number of spaces
*/

# include <stdio.h>

# define N 900007 

int main(){
    printf("Enter paragraph : \n") ;
    char s[N] ;
    gets(s) ;
    int i = 0 , sp = 0 ;
    for(i;i<N;i++){
        if(s[i]==' '){
            sp ++ ;
        }
        if(s[i+1]=='\0'){
            break ;
        }
    }
    printf("The number of spaces are = ") ;
    printf("%d",sp) ;
    
}