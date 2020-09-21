/*
Q : Write a menu-driven program for implementing Interpolation using Lagrange's formula,  Newton’s forward difference formula, and Newton’s backward difference formula. 
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

float LagraneInterpolation(float *, float *, float *, int);
float NewtonForward(float *, float *, float *, int);
float NewtonBackward(float *, float *, float *, int);

void main(){
    int n;
    printf("Enter how many points are given : ");
    scanf("%d", &n);

    float *xValues, *fxValues;
    xValues = (float *)malloc( n * sizeof(float));
    fxValues = (float *)malloc(sizeof(float) * n);
    printf("Values of x and corresponding values of f(x)\n");
    int i;
    float a;
    for(i = 0; i < n; i++){
        printf("Enter the value of x : ");
        scanf("%f", &a);
        *(xValues + i) = a;
        printf("Enter corresponding value of the function : ");
        scanf("%f", &a);
        *(fxValues + i) = a;
    }

    float x, fx;
    printf("Enter the target value of x : ");
    scanf("%f", &x);
    int options;
    printf("Enter 1 to use Lagrane Interpolation Method, 2 to use Newton's Forward Method, 3 to use Newton's Backward Method : ");
    scanf("%d", &options);
    switch(options){
        case 1 :
        {
            fx = LagraneInterpolation(xValues, fxValues, &x, n);
            break;
        }
        case 2 :
        {
            fx = NewtonForward(xValues, fxValues, &x, n);
            break;
        }
        case 3 :
        {
            fx = NewtonBackward(xValues, fxValues, &x, n);
            break;
        }

        default :
        {
            printf("Entered value do not match.\n");
        }
    }
    
    printf("The corresponding value of function : %f\n", fx);
    free(xValues);
    free(fxValues);
    
    return;

}

float LagraneInterpolation(float *xValues, float *fxValues, float *x, int n){
    float fx;
    fx = 0.0;
    int i, j;
    for(i = 0; i < n; i++){
        float f = 1;
        for(j = 0; j < n; j++){
            if(j != i){
                f *= ( ((*x) - (*(xValues + j)))/((*(xValues + i))- (*(xValues + j))) );
            }
        }
        f = f * (*(fxValues + i));
        fx += f;
    }
    return fx;
}

float NewtonForward(float *xValues, float *fxValues, float *x, int n){
    float h = 0.0, u;
    int i, j;
    for(i = 0; i < n-1; i++){
        h += fabs((*(xValues + i)) - (*(xValues + i + 1)));
    }
    h = h / (float)(n-1);
    u = (*x - (*(xValues + 0)))/h;

    float matrix[n][n];
    memset(matrix, -1.00, n*n*sizeof(matrix[0][0]));
    for(i = 0; i < n; i++){
        matrix[i][0] = *(fxValues + i);
    }
    for(i = 1; i < n; i++){
        for(j = 0; j < n-i; j++){
            matrix[j][i] = (matrix[j+1][i-1] - matrix[j][i-1]);
        }
    }

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < n ;j ++){
    //         printf("%f ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    float fx = 0.0;
    for(i = 0; i < n; i++){
        float f = matrix[0][i];
        for(j = 0; j < i; j++){
            f *= ((u - j)/(j + 1));
        }
        fx += f;
    }

    return fx;
}

float NewtonBackward(float *xValues, float *fxValues, float *x, int n){
    float h = 0.0, u;
    int i, j;
    for(i = 0; i < n-1; i++){
        h += fabs((*(xValues + i)) - (*(xValues + i + 1)));
    }
    h = h / (float)(n-1);
    printf("h  %f\n", h);
    u = (*x - (*(xValues + n - 1)))/h;

    float matrix[n][n];
    memset(matrix, -1.00, n*n*sizeof(matrix[0][0]));
    for(i = 0; i < n; i++){
        matrix[i][0] = *(fxValues + i);
    }
    for(i = 1; i < n; i++){
        for(j = n-1; j > 0; j--){
            matrix[j][i] = (matrix[j][i-1] - matrix[j-1][i-1]);
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n ;j ++){
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    float fx = 0.0;
    for(i = 0; i < n; i++){
        float f = matrix[n-1][i];
        for(j = 0; j < i; j++){
            f *= ((u + j)/(j + 1));
        }
        fx += f;
    }

    return fx;
}
