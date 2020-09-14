/*
Q : Write a program in C to reverse the contents of the elements of an integer array.
*/

# include <stdio.h>
int main(){
    int n;
    int arr[n];
    printf("Enter the number of elements of array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    int i, j;
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    i = 0;
    j = n-1;
    while(i < j){
        printf("%d %d\n",arr[i], arr[j]);
        arr[i] = arr[i]^arr[j];
        arr[j] = arr[i]^arr[j];
        arr[i] = arr[i]^arr[j];
        i ++;
        j --;
    }

    printf("Reversed array : ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}