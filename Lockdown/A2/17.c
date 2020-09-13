/*
Q :  Read into the computer a five-letter word that has been encoded using the scheme described above.
Decode the word by reversing the above procedure, then write out the decoded word. 
*/

#include <stdio.h>
int main(){
    char eword[5];
    printf("Enter the encrypted word : ");
    int i = 0;
    for(i; i < 5; i++){
        scanf("%c",&eword[i]);
        eword[i] += 30;
    }
    printf("The decrypted wotrd : ");
    for(i = 0; i < 5; i++){
        printf("%c",eword[i]);
    }
    return 0;
}