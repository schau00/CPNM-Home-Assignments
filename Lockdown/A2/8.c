/*
Q : Temperature of a city in Fahrenheit degrees is input through the keyboard. Write a program to
convert this temperature into Centigrade degrees.
*/

# include <stdio.h>
int main(){
    float fTemp, cTemp;
    printf("Enter the temperature in Farenheit : ");
    scanf("%f", &fTemp);
    cTemp = 5.00 * (fTemp - 32)/9.00;
    printf("Corresponding temperature in Centigrade : %0.2f degree Centigrade", cTemp);
    return 0;

}