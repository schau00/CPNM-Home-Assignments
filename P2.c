/*
PS : Transpose of a matrix
*/

#include <stdio.h>



int main(){
    int m,n ;
    printf("Enter dimensions of matrix :")
    scanf("%d",&m) ;
    scanf("%d",&n) ;
    int mat[m][n] ,tmat[n][m] ;
    int i = 0 , j = 0 ;
    printf("Enter matrix \n") ;
    for(i;i<m;i++){
        j = 0 ;
        for(j ;j<n;j++){
            scanf("%d",&mat[i][j]) ;
        }
    }

     i = 0 , j = 0 ;
   for(i;i<m;i++){
       j = 0 ;
       for(j;j<n;j++){
           tmat[j][i] = mat[i][j] ;
       }
   }
   printf("ANSWER : \n") ;
    for(i =0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",tmat[i][j]) ;
        }
        printf("\n") ;
    }
    

}