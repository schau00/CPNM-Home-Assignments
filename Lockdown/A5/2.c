/*
Q : A positive integer is entered through the keyboard, write a C function to find the binary equivalent
of this number using recursion.
*/

# include <stdio.h>
# include <stdlib.h>

void binaryEquivalent(int *, char *);
int main(){
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    char *binary = (char *)malloc(8 * sizeof(char));
    binaryEquivalent(&n, binary);
    int i = 0;
    for(i; i < 8; i++){
        printf("%c", binary[i]);
    }
    free(binary);
    return 0;
}

void binaryEquivalent(int *n, char * binary){
    int i = 7;
    int t = *n;
    while(i >= 0){
        if(t % 2 == 0){
            *(binary+i) =  '0';
        }
        else{
            *(binary+i) = '1';
        }
        t = t/2;
        i --;
    }

}
