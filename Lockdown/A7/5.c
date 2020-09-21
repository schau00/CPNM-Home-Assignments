/*
Q : Using the above program solve the following system of equations :
i.  x + y + z = 6
    x + y - z = 0
    x - y + z = 2

ii. x + y + z = 3
    2x + 3y + z = 6
    x - y - z = -3

iii. 2x + 4y + 2z = 15
     2x + y + 2z = -5
     4x + y - 2z = 0

*/


# include <stdio.h>
# include <string.h>
# include <math.h>
# define N 5
void gaussEliminationPivot(float [N][N], int *);
void gaussElimination(float [N][N], int *);
void Jacobi(float [N][N], int *);

void main(){
    float A[N][N];
    memset(A, 0, sizeof(A[0][0]) * N * N);
    int n = 3;

    // 1st eqn
    A[0][0] = 1;
    A[0][1] = 1;
    A[0][2] = 1;
    A[1][0] = 1;
    A[1][1] = 1;
    A[1][2] = -1;
    A[2][0] = 1;
    A[2][1] = -1;
    A[2][2] = 1;
    A[0][3] = 6;
    A[1][3] = 0;
    A[2][3] = 2;
    printf("\nSolution of first equation : \n");
    printf("\nSolution by Gauss Elimination Method : ");
    gaussElimination(A, &n);
    printf("\nSolution by Gauss Elimination Method using pivot : ");
    gaussEliminationPivot(A, &n);
    printf("\nSolution by Jacobi Method : ");
    Jacobi(A, &n);

    // 2nd eqn
    A[0][0] = 1;
    A[0][1] = 1;
    A[0][2] = 1;
    A[1][0] = 2;
    A[1][1] = 3;
    A[1][2] = 1;
    A[2][0] = 1;
    A[2][1] = -1;
    A[2][2] = -1;
    A[0][3] = 3;
    A[1][3] = 6;
    A[2][3] = -3;
    printf("\n");
    printf("\nSolution of second equation : \n");
    printf("\nSolution by Gauss Elimination Method : ");
    gaussElimination(A, &n);
    printf("\nSolution by Gauss Elimination Method using pivot : ");
    gaussEliminationPivot(A, &n);
    printf("\nSolution by Jacobi Method : ");
    Jacobi(A, &n);

    // 3rd eqn
    A[0][0] = 2;
    A[0][1] = 4;
    A[0][2] = 2;
    A[1][0] = 2;
    A[1][1] = 1;
    A[1][2] = 2;
    A[2][0] = 4;
    A[2][1] = 1;
    A[2][2] = -2;
    A[0][3] = 15;
    A[1][3] = -5;
    A[2][3] = 0;
    printf("\nSolution of third equation : \n");
    printf("\nSolution by Gauss Elimination Method : ");
    gaussElimination(A, &n);
    printf("\nSolution by Gauss Elimination Method using pivot : ");
    gaussEliminationPivot(A, &n);
    printf("\nSolution by Jacobi Method : ");
    Jacobi(A, &n);

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
