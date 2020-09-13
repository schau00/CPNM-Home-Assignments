/*
Q : Accept three integer numbers and find their average. Next display which numbers are below and
above the average value.
*/

# include <stdio.h>
int main(){
    int a, b, c, sum = 0;
    printf("Enter first number : ");
    scanf("%d",&a);
    sum += a;
    printf("Enter second number : ");
    scanf("%d",&b);
    sum += b;
    printf("Enter third number : ");
    scanf("%d",&c);
    sum += c;

    float avg = sum*1.00/3.00;
    printf("Average = %.2f\n",avg);

    printf("Numbers greater than average : ");
    if(a > avg){
        printf("%d ",a);
    }
    if(b > avg){
        printf("%d ",b);
    }
    if(c > avg){
        printf("%d ",c);
    }
    printf("\nNumbers lesser than average : ");
    if(a < avg){
        printf("%d ",a);
    }
    if(b < avg){
        printf("%d ",b);
    }
    if(c < avg){
        printf("%d ",c);
    }

    return 0;

}