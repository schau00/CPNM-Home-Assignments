/*
PS : Determinant of a matrix
*/

# include <stdio.h>
# include <conio.h>
# include <math.h>


void swap(int a,int b){
    a = a^b ;
    b = b^a ;
    a = a^b ;
}
int Det(int n, int mat[n][n]){
    int num1,num2,det = 1,index,total = 1;
    int temp[n + 1];
    int i , j ,k ;
    for(i=0;i<n;i++){
        index = i ;
        while(mat[index][i]==0 && index<n){
            index ++ ;
        }
        if(index == n){
            continue ;
        }
        if(index != i){
            for(j=0;j<n;j++){
                swap(mat[index][j],mat[i][j]) ;
            }
            det = det * pow(-1,index-1) ;
        }
        for(j=0;j<n;j++){
            temp[j] = mat[i][j] ;
        }
        for(j=i+1;j<n;j++){
            num1 = temp[i] ;
            num2 = mat[j][i] ;

            for(k=0;k<n;k++){
                mat[j][k] = (num1*mat[j][k]) - (num2*temp[k]) ;
            }
            total = total*num1 ;
        }
    }


    for(i=0;i<n;i++){
        det *= mat[i][i] ;
    }

    return (det/total) ;
}



int main(){
    int n,m ;
    printf("Enter dimensions of matrix : ") ;
    scanf("%d",&n) ;
    scanf("%d",&m) ;
    if(n!=m){
      printf("Determinant not possible \n") ;
      return 0 ;

    }

    int mat[n][n] ;
    printf("Enter Matrix \n") ;
    int i , j ;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]) ;
        }
    }

    int ans = Det(n,mat) ;
    printf("%d",ans) ;

}
