/*
PS : Add two matrices
*/

#include <stdio.h>
int main(){
     printf("Dimensions of Matrix1 : ") ;
    int m,n ;
    scanf("%d",&m) ;
    scanf("%d",&n) ;
    printf("Enter Matrix1 \n") ;
    int m1[m][n] ;
    int i=0,j=0 ;
    for(i;i<m;i++){
        j=0;
        for(j;j<n;j++){
            scanf("%d",&m1[i][j]) ;
        }
    }
    int x,y ;
    printf("Dimensions of Matrix2 : ") ;
    scanf("%d",&x) ;
    scanf("%d",&y) ;
     printf("Enter Matrix2 \n") ;
    int m2[x][y] ;
    for(i=0;i<x;i++){
        j=0;
        for(j;j<y;j++){
            scanf("%d",&m2[i][j]) ;
        }
    }
   
   if(x!=m || y!=n){
      printf("Addition of matrices not possible\n") ;
      return 0 ;
   }
   else{
       int arr[x][y] ;
       for(i=0;i<x;i++){
           for(j=0;j<y;j++){
               arr[i][j] = (m1[i][j]+m2[i][j]) ;
           }
       }
        printf("ANSWER : \n") ;
        for(i=0;i<m;i++){
            for(j=0;j<y;j++){
                printf("%d ",arr[i][j]) ;
            }
            printf("\n") ;
        }
   }
   return 0 ;
}
