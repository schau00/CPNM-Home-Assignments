/*
Q : Write a C program which accepts ten integers from user and prints them in ascending order. Use
array to store the integers.
*/

# include <stdio.h>
int main(){
    printf("Enter 10 integers : ");
    int i, j;
    int arr[10];
    for(i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 10; i++){
        for(j = i + 1; j < 10; j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[i]^arr[j];
                arr[j] = arr[i]^arr[j];
                arr[i] = arr[i]^arr[j];
            }
        }
    }

    printf("Array in ascending order : ");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}