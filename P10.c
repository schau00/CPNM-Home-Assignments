/*
PS : Search for a word
*/

# include <stdio.h>

# define MaxSize 10000

void lps_table(int n,char s[MaxSize],int lps[n]){

  
  int  len = 0 ;
  lps[0] = 0 ;
  int i ;
  for( i=1;i<n;i++){
    
    
     while(s[i] != s[len] && len > 0){
       len = lps[len-1] ;
 
       if(len== 0 && s[len]!=s[i]){
         lps[i] = 0 ;
         len = 0 ;
         break ;
       }
    }
    
    if(s[len]==s[i]){
      lps[i] = len+1 ;
      len ++ ;
    }
    if(len == 0 && s[len]!=s[i]){
      lps[i] = 0 ;
      len = 0 ;
    }
  
 }
}

int KmpSearch(int n,int t,int lps[n],char word[MaxSize],char text[MaxSize]){
   int len = 0, i=0 , x =-1 ;
   for(i;i<t;i++){
       if(text[i] == word[len]){
           len ++ ;
       }
       else{
           while(word[len] != text[i]){
               len = lps[len-1] ;

               if(len == 0){
                   break ;
               }
            }
            if(len==0 && word[len]!=text[i]){
                   len = 0 ;
            }
            else{
                   len ++ ;
            }
       }

            if(len == n){
                x = i+2 - n ;
                break ;
            }
       

   }
   return x ;
}



int main(){
    FILE *f ;
    char filename[MaxSize] ;
    printf("Enter the name of file to search in : ") ;
    gets(filename) ;
    char word[MaxSize] ;
    printf("Enter target word : ") ;
    gets(word) ;
    int n ;
    int i =0 ;
    for(i;i<MaxSize;i++){
        if(word[i+1] == '\0'){
            n = i+1 ;
            break ;
        }
    }
    f = fopen(filename,"r") ;
    char fileread[MaxSize] ;
    fgets(fileread,MaxSize,f) ;
    fclose(f) ;
    int lps[n] ;
    for(i=0;i<n;i++){
        lps[i] = 0 ;
    }
    lps_table(n,word,lps) ;
    // for(i=0;i<n;i++){
    //     printf("%d ",lps[i]) ;
    // }
    int t ;
    for(i=0;i<MaxSize;i++){
        if(fileread[i+1]=='\0'){
            t = i+1 ;
            break ;
        }
       // printf("%c",fileread[i]) ;
    }
    printf("%d",t) ;
    // for(i=0;i<t;i++){
    //     printf("%c",fileread[i]) ;
    // }
    int ans = KmpSearch(n,t,lps,word,fileread) ;
    if(ans != -1){
        printf("Word found at index %d",ans) ;
    }
    else{
        printf("Word not found \n") ;
    }

    return 0 ;


}