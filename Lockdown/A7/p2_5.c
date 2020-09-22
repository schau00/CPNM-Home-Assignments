/*
Q : Write  a  function  integrate  to  find  the  integration  of  a  function f within  the  limits and by Trapezoidal and Simpson's 1/3rdintegration method. f, aand bshould be provided as arguments of the function integrate. Write the main function to take the name of the integrand function and the limits of integration as command line arguments.
*/
/*
Suppose f(x) = exp(x) .
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

float trapezoidalRule(float *, float *, int);
float simpsonRule(float *, float *, int);
float function(float );
float integrate(float(*fxn)(float *, float *b, int n), float *, float *, int n);
void main(int argc,char*  argv[argc +1]){
    float a, b;
    int n;
    char *s;
    s = argv[1];
    a = strtod(argv[2], 0);
    b = strtod(argv[3], 0);
    n = strtod(argv[4], 0);
    
    float areaEnclosed = 0.0;
    if(strcmp(s, "simpsons") == 0){
        areaEnclosed = integrate(simpsonRule, &a, &b, n);
    }
    else if(strcmp(s, "trapezoidal") == 0){
        areaEnclosed = integrate(trapezoidalRule, &a, &b, n);
    }
    else{
        printf("Entered name does not match with function name.\n");
        return;
    }
    printf("Area enclosed by f(x) = exp(x) within range %f to %f is : %f\n", a, b, areaEnclosed);

}
float integrate(float (*fxn)(float* x, float* y, int z), float *a, float *b, int n){
    return fxn(a, b, n);
}
float function(float x){
    return (exp(x));
}

float trapezoidalRule(float *a, float *b, int n){
    float h = ((*b )- (*a))/n;
    float area = 0.0;
    int i;
    for(i = 1; i <= n-1; i++){
        area += 2*(function(*a + (i * h)));
    }
    area += (function(*a) + function(*b));
    area *= (h/(float)2);
    return area; 
}

float simpsonRule(float *a, float *b, int n){
    float h = ((*b)-(*a))/ n ;
    float area = 0.0;
    int i;
    for(i = 0; i <= n; i++){
        if(i == 0 || i == n){
            area += (function((*a )+ (i * h) ));
        }
        else if(i & 1 == 1){
            area += 4*(function((*a )+ (i * h)) );
        }
        else {
            area += 2 *(function((*a )+ (i * h) ));
        }
    }
    area = area * (h/3);
    return area;
}