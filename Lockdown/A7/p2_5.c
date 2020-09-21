/*
Q : Write  a  function  integrate  to  find  the  integration  of  a  function f within  the  limits and by Trapezoidal and Simpson's 1/3rdintegration method. f, aand bshould be provided as arguments of the function integrate. Write the main function to take the name of the integrand function and the limits of integration as command line arguments.
*/
/*
Suppose f(x) = exp(x) .
*/

# include <stdio.h>
# include <math.h>
float trapezoidalRule(float *, float *, int);
float simpsonRule(float *, float *, int);
float function(float );

void main(){
    float a, b;
    printf("Enter the left limit : ");
    scanf("%f", &a);
    printf("Enter the right limit : ");
    scanf("%f", &b);
    int n;
    printf("Enter the number of equal intervals to divide the range : ");
    scanf("%d", &n);
    float areaEnclosed = 0.0;
    printf("Area enclosed by function f(x) = exp(x) , \n");
    areaEnclosed = trapezoidalRule(&a, &b, n);
    printf("Applying Trapezoidal Rule : %f\n", areaEnclosed);
    areaEnclosed = simpsonRule(&a, &b, n);
    printf("Applying Simpson 1/3 rd Rule : %f\n", areaEnclosed);
    return;

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