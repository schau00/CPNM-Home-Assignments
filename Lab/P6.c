/*
PS : Inverse of a matrix
*/

#include<stdio.h>

float det(float mat[100][100] , int n){
    if(n==1){
        return mat[0][0];
    }
    else{
        float NM[100][100];
        float d = 0;
        int i = 0 , j = 0 , k = 0 , l = 0;
        for(i = 0 ; i < n ; i++){
            
            int sign = 1;
            if(i % 2 == 1){
                sign = -1;
            }
            int l = 0;
            for(j = 1 ; j < n ; j++){
                l=0;
                for(k = 0 ; l < n-1 ; k++){
                    if(k==i){
                        continue;
                    }else{
                        NM[j-1][l] = M[j][k];    
                        l++;
                    }
                }   
            }
            d = d + (sign*mat[0][i]*det(NM , n-1));
        }
        return d;
    }
}

void transpose(float matrix[100][100], float n , float transposed[100][100]){
    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            transposed[j][i] = matrix[i][j];
        }
    }
}

float cofactor(float M[100][100] , int n , int r , int c){
    int sign = 1;
    if((r+c)%2 == 1)
        sign = -1;
    float NM [100][100];
    int i , j , i1 , j1;
    i1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(i == r){
            continue;
        }
        else{
            j1 = 0;
            for(j = 0 ; j < n ; j++){
                if(j==c){
                    continue;
                }
                else{
                    NM[i1][j1] = M[i][j];
                    j1++;
                }
            }
            i1++;
        }
    }
    return sign*det(NM , n-1);
}

void cofactorM(float mat[100][100] , int n , float C[100][100]){
    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0; j < n ; j++){
            C[i][j] = cofactor(mat , n , i , j);
        }
    }
}

int main() {
    printf("Enter the size of square matrix  : ");
    int n;
    scanf("%d",&n);
    float mat[100][100];
    printf("Enter the elements of the matrix \n");
    int i = 0 , j = 0;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%f",&mat[i][j]);
        }
    }
    int d = det(mat , n);
    if(d == 0){
        printf("Determinant is 0\n");
    }
    else{
        float C[100][100];
        cofactorM(mat , n , C);
        float cof[100][100];
        transpose(C , n , cof);
        printf("Inverse matrix :\n");
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                CT[i][j] = cof[i][j]/d;
                printf("%0.2f\t",cof[i][j]);
            }
            printf("\n");
        }
    }

}
