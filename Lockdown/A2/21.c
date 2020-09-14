# include <stdio.h>
# include <math.h>
int main(){
    float x, y, r, x1, y1;
    printf("Enter x coordinate of centre : ");
    scanf("%f",&x);
    printf("Enter y coordinate of centre : ");
    scanf("%f",&y);
    printf("Enter radius : ");
    scanf("%f",&r);

    printf("Enter x coordinate of point : ");
    scanf("%f",&x1);
    printf("Enter y coordinate of point : ");
    scanf("%f",&y1);

    float S = pow(x-x1, 2) + pow(y-y1, 2);
    S = sqrt(S);
    if(S < r){
        printf("The point lies within circle .");
    }
    else if(S > r){
        printf("The point lies outside the circle .");
    }
    else{
        printf("Point lies on the circle .");
    }
    return 0;

}