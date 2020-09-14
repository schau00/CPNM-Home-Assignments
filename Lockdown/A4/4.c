/*
Q : Write a program to find the range of a set of integers entered by the user. Range is the difference
between the smallest and biggest number in the list.
*/

# include <stdio.h>
int main(){
    int n;
    printf("Enter the number of integers in set : ");
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    while (i < n){
        scanf("%d", &arr[i]);
        i ++;
    }
    int max = arr[0];
    int min = arr[0];
    for(i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }

    printf("Range = %d", (max - min));
    return 0;

}
    