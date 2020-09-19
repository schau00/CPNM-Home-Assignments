/*
Q : Use the above program to find 3 roots of the equation xtan(x)=c where c is a user-input constant. Use both bisection method and Newton-Raphson method.
*/

# include <stdio.h>
# include <math.h>
/*
Function Declarations
*/
float function(float *, float *);
float dervFunction(float *);
void bisectionMethod(float*);
void regulaFalsiMethod(float*);
void newtonRhapsonMethod(float*);
void bisectionRecursion(float*, float*, float*,int*, int, float*, int*);
void regFalsiRecursion(float*, float*, float*,int*, int, float*, int*);
void newRapRecursion(float*, float*, float*, int*, int, float*, int*);

void main(){
    /*
    Function f(x) = xtanx - c (c is user input)
    Derivative f`(x) = x*pow(secx,2) + tanx
    */

   printf("Enter the value of c : ");
   float c;
   scanf("%f", &c);

   printf("\nSolving by Bisection Method : \n");
   bisectionMethod(&c);
   printf("\nSolving by Regula Falsi Method : \n");
   regulaFalsiMethod(&c);
   printf("\nSolving by Newton Rhapson Method : \n");
   newtonRhapsonMethod(&c);
    return;

}


/*
Calculation of value of function at x
*/

float function(float *x, float *c){
    return ((*x * tan(*x)) -  *c);
}

/*
Calculation of Derivative of function a x
*/

float dervFunction(float *x){
    float secx = 1.00/ cos(*x);
    return (((*x) * pow(secx, 2)) + (tan(*x)));
}

/*
BISECTION METHOD
*/
void bisectionMethod(float *c){
    int guess = 0;
    float x1, x2, e;
    int currentIteration = 0, it;
    printf("Enter the desired level of accuracy : ");
    scanf("%f", &e);
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    while(guess != 3){
    
    printf("Guess left limit : ");
    scanf("%f", &x1);
    printf("Guess right limit : ");
    scanf("%f", &x2);
    bisectionRecursion(&x1, &x2, &e, &it, currentIteration,c, &guess);
    
    }
    return;
}

void bisectionRecursion(float* x1, float* x2, float* e,int* it, int currentIteration, float* c, int *guess){
    float f1 = function(x1, c);
    float f2 = function(x2, c);

    if(f1*f2 > 0){
        printf("No root exixts in the guessed limits .\n");
        return;
    }

    float x = (*x1 + *x2)/2.00;
    float currentError = abs((*x1 - *x2)/x);
    if(currentError == *e){
        printf("Root : %f\n", x);
        *guess = *guess + 1;
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.\n", *it);
        return;
    }

    float f = function(&x, c);
    if(f*f1 > 0){
        *x1 = x;
    }
    else{
        *x2 = x;
    }
    return bisectionRecursion(x1, x2, e, it, currentIteration+1, c, guess);

}

/*
REGULAR FALSI OR FALSE POSITION METHOD
*/

void regulaFalsiMethod(float *c){
    float x1, x2, e;
    int currentIteration = 0, it;
    printf("Enter the desired level of accuracy : ");
    scanf("%f", &e);
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    int guess = 0;
    while(guess != 3){
    printf("Guess left limit : ");
    scanf("%f", &x1);
    printf("Guess right limit : ");
    scanf("%f", &x2);
    regFalsiRecursion(&x1, &x2, &e, &it, currentIteration, c, &guess);
    
    }
    return;
}

void regFalsiRecursion(float* x1, float* x2, float* e,int* it, int currentIteration, float*c, int * guess){
    float f1 = function(x1, c);
    float f2 = function(x2, c);
    if(f1*f2 > 0){
        printf("No root exixts in the guessed limits .\n");
        return;
    }

    float x = (*x1) + ((f1) * ((*x1 - *x2)/(f2 - f1)));
    float currentError = abs((*x1 - *x2)/(float)x);
    if(currentError < *e){
        printf("Root : %f\n", x);
        *guess = *guess + 1;
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.\n", *it);
        return;
    }

    float f = function(&x, c);
    if(f*f1 > 0){
        *x1 = x;
    }
    else{
        *x2 = x;
    }
    return regFalsiRecursion(x1, x2, e, it, currentIteration + 1, c, guess);
}

/*
NEWTON RHAPSON METHOD
*/

void newtonRhapsonMethod(float *c){
    float x, e, s;
    int it, currentIteration = 0;
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    printf("Enter desired accuracy : ");
    scanf("%f", &e);
    int guess = 0;
    while(guess != 3){
    
    printf("Enter initial guess : ");
    scanf("%f", &x);
    s = 0.00001;
    newRapRecursion(&x, &e, &s, &it, currentIteration, c, &guess);
    }
    return;
}

void newRapRecursion(float* x, float* e, float* s, int* it, int currentIteration, float *c, int *guess){
    float f = function(x, c);
    float f1 = dervFunction(x);

    if(abs(f1) < *s){
        printf("Slope is too small . No root can be determined for the guess.\n");
        return;
    }

    float x1 = *x - (f/f1);
    float currentError = (x1 - *x)/(*x);
    if(currentError < *e){
        printf("Root : %f\n", x1);
        *guess = *guess + 1;
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.\n", *it);
        return;
    }
    
    *x = x1;
    return newRapRecursion(x, e, s, it, currentIteration + 1, c, guess);
}