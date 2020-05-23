/*
PS : Multiply 2 matrix
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

    if(n!=x){
        printf("Multiplication cannot be done \n") ;
        return  0 ;
    }
    else{
        int arr[m][y] ;
        for(i=0;i<m;i++){
            for(j=0;j<y;j++){
                int s =0 , k=0;
                for(k;k<n;k++){
                    s += (m1[i][k]*m2[k][j]) ;
                }
                arr[i][j] = s ;
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
