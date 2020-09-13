/*
Q : The length and breadth of a rectangle and radius of a circle are input through the keyboard. Write
a program to calculate the area and perimeter of the rectangle, and the area and circumference of
the circle .
*/

# include <stdio.h>
# include <math.h>
int main(){
    float l, b, r;
    printf("Enter length of rectangle : ");
    scanf("%f",&l);
    printf("Enter breadth of rectangle : ");
    scanf("%f",&b);
    double areaRectangle = l*b;
    double perimeter = 2 * (l + b);
    printf("Enter radius of circle : ");
    scanf("%f",&r);
    double areaCircle = (22.0 / 7.0) * pow(r, 2);
    double circumference = 2 * (22.00 / 7.00) * r;
    //printf("%f %f %f",l,b,r);
    printf("Area of Rectangle = %f\nPerimeter of Rectangle = %f\nArea of Circle = %f\nCircumference of Circle = %f",areaRectangle,perimeter,areaCircle,circumference);
    return 0;
}
