/*
Q : Write a program to sort some numbers in ascending order. The numbers are to be input from a file
named ‘input.txt’. The output should be written in a file named ‘output.txt’. Use bubble sort
algorithm and dynamic memory allocation for implementation.
*/

# include <stdio.h>
# include <stdlib.h>
void bubbleSort(int *, int );
void swap(int *, int *);
void main(){
    FILE *rf, *wf;
    int * num = (int *)malloc(sizeof(int) * 1000);
    rf = fopen("input.txt", "r");

    if(rf == NULL){
        printf("File not exists.\n");
    }
    else{
        int i = 0, n;
        while ((fscanf(rf, "%d", &n)) > 0){
            *(num + i) = n;
            i ++;
        }
        

        wf = fopen("output.txt", "w");
        bubbleSort(num, i-1);
        int j;
        for(j = 0; j < i; j++){
            printf("%d ", *(num + j));
            fprintf(wf, "%d ", *(num + j));
        }
        fclose(rf);
        fclose(wf);
    }
    
}

void bubbleSort(int *num, int lastIndex){
    int i, j;
    for(i = 0; i <= lastIndex; i++){
        for(j = i+1; j <= lastIndex; j++){
            if(*(num + i) > *(num + j)){
                swap(&(*(num + i)), &(*(num + j)));
            }
        }
    }
    return;
}

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}