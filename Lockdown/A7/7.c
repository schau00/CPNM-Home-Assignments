/*
Q : x     f(x)
    1       1
    2       8
    3       27
    4       64

    Find f(2.5) = ?
    
*/


# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

float LagraneInterpolation(float *, float *, float *, int);
float NewtonForward(float *, float *, float *, int);
float NewtonBackward(float *, float *, float *, int);

void main(){
    int n = 4;
    

    float *xValues, *fxValues;
    xValues = (float *)malloc( n * sizeof(float));
    fxValues = (float *)malloc(sizeof(float) * n);
    *(xValues + 0) = 1;
    *(fxValues + 0) = 1;
    *(xValues + 1) = 2;
    *(fxValues + 1) = 8;
    *(xValues + 2) = 3;
    *(fxValues + 2) = 27;
    *(xValues + 3) = 4;
    *(fxValues + 3) = 64;

    float x, fx;
    x = 2.5;
    fx = LagraneInterpolation(xValues, fxValues, &x, n);
    printf("The value of function by Lagrane's Interpolation : %f \n", fx);
    fx = NewtonForward(xValues, fxValues, &x, n);
    printf("The value of fuction by Newton's Forward Method : %f\n", fx);
    fx = NewtonBackward(xValues, fxValues, &x, n);
    printf("The value of fuction by Newton's Backward Method : %f\n", fx);

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

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < n ;j ++){
    //         printf("%f ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

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
