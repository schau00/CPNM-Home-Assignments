
/*
Q : Write  a  menu-driven  program  for  solving  a  system  of  linear  equations  using  Gauss-Elimination method, Jacobi’s method and Gauss Elimination with pivoting method.
*/

# include <stdio.h>
# include <string.h>
# include <math.h>
# define N 100
void gaussEliminationPivot(float [N][N], int *);
void gaussElimination(float [N][N], int *);
void Jacobi(float [N][N], int *);

void main(){
    
    printf("Enter number of linear equations : ");
    int n;
    scanf("%d", &n);
    float A[N][N];
    // memset(A, 0, sizeof(A[0][0]) * (N) * (N));
    int i, j ;
    for(i = 0; i < n; i ++){
        
        for (j = 0; j < n; j++){
            printf("Enter the coefficient of the %d th variable of %d th equation : ", j+1, i+1);
            scanf("%f", &A[i][j]);
        }

        printf("Enter the right hand side value of the %d th equation : ", i+1);
        scanf("%f", &A[i][n]);
    }

    int option;
    printf("Enter 1 to solve by Gauss-Elimination method, Enter 2 to solve by Jacobi method, Enter 3 to solve by Gauss Elimination with pivoting method : ");
    scanf("%d", &option);

    switch(option){
        case 1 :
        {
            gaussElimination(A, &n);
            break;
        }
        case 2 :
        {
            Jacobi(A, &n);
            break;
        }
        case 3 :
        {
            gaussEliminationPivot(A, &n);
            break;
        }

        default : {
            printf("Entered value does not match.");
            break;
        }
    }
    return;
}

void gaussEliminationPivot(float A[N][N], int *n){
    int i, j, k;
    for(i = 0; i < *n; i++){
        
        for(j = 0; j < i; j ++){
            float m = *(*(A + j) + i);
            float s = *(*(A + i) + i);

            for(k = 0; k <= *n; k ++){
            //    *(*(A + i) + k) *= m;
            //    *(*(A + j) + k) *= s;
               *(*(A + j) + k) = (*(*(A + j) + k) * s) - (*(*(A + i) + k) * m);
            }
        }

        

        for(j = i+1; j < *n; j ++){
            float m = *(*(A + j) + i);
            float s = *(*(A + i) + i);

            for(k = 0; k <= *n; k ++){
            //    *(*(A + i) + k) *= m;
            //    *(*(A + j) + k) *= s;
               *(*(A + j) + k) = (*(*(A + j) + k) * s) - (*(*(A + i) + k) * m);
            }
        }
    }
    // for(i = 0; i < *n; i++){
    //     for(j = 0; j <= *n; j++){
    //         printf("%f ", *(*(A + i) + j));
    //     }
    //     printf("\n");
    // }

    printf("Values of the variables : ");
    for(i = 0; i < *n; i++){
        printf("%f ", (*(*(A + i) + *n)/ *(*(A + i) + i)));
    }
}

void gaussElimination(float A[N][N], int *x){
    int i, j, k, l;
    int n = *x;

    for(i = 0; i < n; i ++){
        for(j = i + 1; j < n; j++){
            float s = *(*(A + i) + i);
            float m = *(*(A + j) + i);
            for(k = i; k <= n; k ++){
                *(*(A + j) + k) = (*(*(A + j) + k) * s) - (*(*(A + i) + k) * m) ;
            }
        }
    }

    // for(i = 0; i < n; i++){
    //     for(j = 0; j <= n; j++){
    //         printf("%f ", *(*(A + i) + j));
    //     }
    //     printf("\n");
    // }
    float var[n];
    for(i = n-1; i >= 0; i--){
        float S = *(*(A + i) + n);
        for(j = i + 1; j < n; j++){
            S -= (*(*(A + i) + j) * var[j]);
        }
        float c = S / *(*(A + i) + i);
        var[i] = c;
        
    }

    printf("Values of the variables : ");
    for(i = 0; i < n; i++){
        printf("%f ", var[i]);
    }
}

void Jacobi(float A[N][N], int *x){
    int n = *x;
    float E = 0.000001;
    int i, j, check = 0;
    // checking row , column dominance
    for(i = 0; i < n; i++){
        float sum = 0;
        for(j = 0; j < n; j ++){
            if(i != j){
                sum += (*(*(A + i) + j));
            }
        }
        if(sum > *(*(A + i) + i)){
            check = 1;
        }
    }

    for(i = 0; i < n; i++){
        float sum = 0;
        for(j = 0; j < n; j ++){
            if(i != j){
                sum += (*(*(A + j) + i));
            }
        }
        if(sum > *(*(A + i) + i)){
            check = 1;
        }
    }

    if(check == 1){
        printf("Coefficient matrix is not diagonally dominant.\nThe jacobi method does not converge.\n");
        return;
    }

    float var[n], tempvar[n];
    memset(var, 0, n * sizeof(var[0]));
    memset(tempvar, 0, n * sizeof(tempvar[0]));
    check = 0;
    int loop = 0;
    while(check != 1 && loop < 500){
        for(i = 0; i < n; i ++){
            float S = *(*(A + i) + n);
            for(j = 0; j < n; j++){
                if(i != j){
                    S = S - (*(*(A + i) + j) * var[j]);
                }
            }
            tempvar[i] = S/ (*(*(A + i) + i));
        }
        loop ++;
        if(loop > 5){
        check = 1;
        
        for(i = 0; i < n; i++){
            if(fabs((tempvar[i] - var[i]/ tempvar[i])) > E){
                check = 0;
            }
        }
        }
        for(i = 0; i < n; i++){
            var[i] = tempvar[i];
        }
    }

    printf("Values of the variables : ");
    for(i = 0; i < n; i++){
        printf("%f ", var[i]);
    }
    

}

