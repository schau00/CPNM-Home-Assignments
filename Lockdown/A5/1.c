/*
Q : Write a function to compute the distance between two points and use it to develop another function
that will compute the area of the triangle whose vertices are A(x1, y1), B(x2, y2), and C(x3, y3).
Use these functions to develop a function which returns a value 1 if the point (x, y) lies inside
the triangle ABC, otherwise a value 0.
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
typedef struct
{
    int x;
    int y;
} point;

float distance(point *, point *);
float area(point *, point *, point *);
int checkPoint(point *, point *, point *, point *);
void main(){
    point a, b, c, p, p1, p2;
    float x, y;
    point *A = (point *)malloc(sizeof(point));
    point *B = (point *)malloc(sizeof(point));
    printf("Enter x coordinate of first point : ");
    scanf("%f", &x);
    printf("Enter y coordinate of first point : ");
    scanf("%f", &y);
    p1.x = x;
    p1.y = y;

    printf("Enter x coordinate of second point : ");
    scanf("%f", &x);
    printf("Enter y coordinate of second point : ");
    scanf("%f", &y);
    p2.x = x;
    p2.y = y;
    
    printf("Distance between these two points is : %f\n", distance(&p1, &p2));

    printf("Enter x coordinate of A : ");
    scanf("%f", &x);
    printf("Enter y coordinate of A : ");
    scanf("%f", &y);
    a.x = x;
    a.y = y;
    printf("Enter x coordinate of B : ");
    scanf("%f", &x);
    printf("Enter y coordinate of B : ");
    scanf("%f", &y);
    b.x = x;
    b.y = y;

    printf("Enter x coordinate of C : ");
    scanf("%f", &x);
    printf("Enter y coordinate of C : ");
    scanf("%f", &y);
    c.x = x;
    c.y = y;

    printf("Area of triangle ABC : %f\n", area(&a, &b, &c));

    printf("Enter x coordinate of check point : ");
    scanf("%f", &x);
    printf("Enter y coordinate of check point : ");
    scanf("%f", &y);
    p.x = x;
    p.y = y;

    if(checkPoint(&p, &b, &a, &c) == 1){
        printf("It lies in ABC.\n");
    }
    else{
        printf("It lies outside ABC.\n");
    }
    




    return;
}

float distance(point *a, point *b){
    float dist = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    return dist;
}
float area(point *a, point *b, point *c){
    float area, semiperimeter;
    float AB = distance(a, b);
    float CA = distance(a, c);
    float BC = distance(c, b);

    semiperimeter = (AB + BC + CA)/2.0 ;

    area = sqrt(semiperimeter * abs(semiperimeter - AB) * abs(semiperimeter - BC) * abs(semiperimeter - CA));
    return (area);
}

int checkPoint(point *p, point *a, point *b, point *c){
    float areaABC = area(a, b, c);
    if(areaABC == (area(p, a, b) + area(p, a, c) + area(p, b , c))){
        return 1;
    }
    else{
        return 0;
    }
}

