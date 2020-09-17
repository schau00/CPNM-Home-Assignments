/*
Q : Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and
zero otherwise.
*/

# include <stdio.h>
# include <stdlib.h>

int strend(char*, char*);
int numberOfCharacters(char *);
void main(){
    char * s = (char *)malloc(1000 * sizeof(char));
    char * t = (char *)malloc(1000 * sizeof(char));
    
    printf("Enter string s : ");
    gets(s);
    printf("Enter string t : ");
    gets(t);
    int ans = strend(s, t);
    if(ans == 1){
        printf("Occurs.");
    }
    else{
        printf("Not occurs.");
    }
    free(s);
    free(t);
    return;
}

int numberOfCharacters(char *string){
    int i = 0;
    for(i; i < 1000; i++){
        if(*(string + i) == '\0'){
            break;
        }
    }

    return i;
} 

int strend(char *s, char *t){
    int s_length = numberOfCharacters(s);
    int t_length = numberOfCharacters(t);
    int i = s_length - t_length;
    int j = 0;
    while (*(s + i) != '\0' || *(t + j) != '\0'){
        if (*(s + i) != *(t + j)){
            return 0;
        }
        i ++;
        j ++;
    }
    return 1;
    
}