/*
Q : Write  a  menu-driven  program  for  finding  roots  of  a  nonlinear  equation  using  Bisection,  Regula Falsi and Newton-Raphson method.
*/

# include <stdio.h>
# include <math.h>
/*
Function Declarations
*/
float function(float *);
float dervFunction(float *);
void bisectionMethod();
void regulaFalsiMethod();
void newtonRhapsonMethod();
void bisectionRecursion(float*, float*, float*,int*, int);
void regFalsiRecursion(float*, float*, float*,int*, int);
void newRapRecursion(float*, float*, float*, int*, int);

/*
Main Method
*/

int main(){
    /*
    Function f(x) = x^5 + x^3 + 5*x^2 + x - 2
    Derivative f`(X) = 5x^4 + 3x^2 + 10*x + 1
    */

   printf("Root finding methods for equation x^5 + x^3 + 5*x^2 + x - 2 = 0\n");
   int option;
   printf("Enter 1 to use Bisection Method, 2 to use Regula Falsi method, 3 to use Newton Rhapson method : ");
   scanf("%d", &option);

   if(option == 1){
       bisectionMethod();
   }
   else if(option == 2){
       regulaFalsiMethod();
   }
   else{
       newtonRhapsonMethod();
   }

   return 0;

}

/*
Calculation of value of function at x
*/

float function(float *x){
    return (pow(*x, 5) + pow(*x, 3) + (5 * pow(*x, 2)) + pow(*x, 1) - (float)2);
}

/*
Calculation of Derivative of function a x
*/

float dervFunction(float *x){
    return ((5 * pow(*x, 4)) + (3 * pow(*x, 2)) + (10 * pow(*x, 1)) + (float)1);
}

/*
BISECTION METHOD
*/
void bisectionMethod(){
    float x1, x2, e;
    int currentIteration = 0, it;
    printf("Enter the desired level of accuracy : ");
    scanf("%f", &e);
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    printf("Guess left limit : ");
    scanf("%f", &x1);
    printf("Guess right limit : ");
    scanf("%f", &x2);
    bisectionRecursion(&x1, &x2, &e, &it, currentIteration);
    return;
}

void bisectionRecursion(float* x1, float* x2, float* e,int* it, int currentIteration){
    float f1 = function(x1);
    float f2 = function(x2);

    if(f1*f2 > 0){
        printf("No root exixts in the guessed limits .");
        return;
    }

    float x = (*x1 + *x2)/2.00;
    float currentError = abs((*x1 - *x2)/x);
    if(currentError == *e){
        printf("Root : %f", x);
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.", *it);
        return;
    }

    float f = function(&x);
    if(f*f1 > 0){
        *x1 = x;
    }
    else{
        *x2 = x;
    }
    return bisectionRecursion(x1, x2, e, it, currentIteration+1);

}

/*
REGULAR FALSI OR FALSE POSITION METHOD
*/

void regulaFalsiMethod(){
    float x1, x2, e;
    int currentIteration = 0, it;
    printf("Enter the desired level of accuracy : ");
    scanf("%f", &e);
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    printf("Guess left limit : ");
    scanf("%f", &x1);
    printf("Guess right limit : ");
    scanf("%f", &x2);
    regFalsiRecursion(&x1, &x2, &e, &it, currentIteration);
    return;
}

void regFalsiRecursion(float* x1, float* x2, float* e,int* it, int currentIteration){
    float f1 = function(x1);
    float f2 = function(x2);
    if(f1*f2 > 0){
        printf("No root exixts in the guessed limits .");
        return;
    }

    float x = (*x1) + ((f1) * ((*x1 - *x2)/(f2 - f1)));
    float currentError = abs((*x1 - *x2)/(float)x);
    if(currentError < *e){
        printf("Root : %f", x);
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.", *it);
        return;
    }

    float f = function(&x);
    if(f*f1 > 0){
        *x1 = x;
    }
    else{
        *x2 = x;
    }
    return regFalsiRecursion(x1, x2, e, it, currentIteration + 1);
}

/*
NEWTON RHAPSON METHOD
*/

void newtonRhapsonMethod(){
    float x, e, s;
    int it, currentIteration = 0;
    printf("Enter initial guess : ");
    scanf("%f", &x);
    printf("Enter desired accuracy : ");
    scanf("%f", &e);
    printf("Enter desired number of iterations : ");
    scanf("%d", &it);
    s = 0.00001;
    newRapRecursion(&x, &e, &s, &it, currentIteration);
}

void newRapRecursion(float* x, float* e, float* s, int* it, int currentIteration){
    float f = function(x);
    float f1 = dervFunction(x);

    if(abs(f1) < *s){
        printf("Slope is too small . No root can be determined for the guess.\n");
        return;
    }

    float x1 = *x - (f/f1);
    float currentError = (x1 - *x)/(*x);
    if(currentError < *e){
        printf("Root : %f", x1);
        return;
    }
    if(currentIteration >= *it){
        printf("Root could not be found within %d iterations.", *it);
        return;
    }
    
    *x = x1;
    return newRapRecursion(x, e, s, it, currentIteration + 1);
}