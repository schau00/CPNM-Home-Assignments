/*
PS : Read from a file , write content to another file
*/

# include <stdio.h>
# define MaxSize 100000
int main(){
   FILE *rp , *wp ;
   char readFile[100],writeFile[100] ;
   char readText[MaxSize] ;
   printf("Enter the name of file to read from : ") ;
   gets(readFile);
   printf("Enter name of file to write in : ") ;
   gets(writeFile) ;
   rp = fopen(readFile,"r") ;
   wp = fopen(writeFile,"w") ;
   if(rp == NULL){
       printf("Reading file does not exist .\n") ;
       return 0 ;
   }
    
    fgets(readText,MaxSize,rp) ;
    fclose(rp) ;

    // for(int i=0;i<100;i++){
    //     printf("%c",readText[i]) ;
    // }

    fputs(readText,wp) ;
    fputs("\n\nAbove text is from another file \n",wp) ;
    fclose(wp) ;

}
