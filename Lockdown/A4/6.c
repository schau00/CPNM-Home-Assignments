/*
Q : Write a C program which accepts number obtained by five students in five subjects. Print the total
marks obtained by all the students. Also determine the highest total marks.
*/

# include <stdio.h>
int main(){
    int marks[5][5], totalMarks[5];
    int i, j, HighestTotal = -500;
    for(i = 0; i < 5; i++){
        int total = 0;
        for(j = 0; j < 5; j++){
            printf("Enter the marks obtained by Student %d in Subject %d : ",i+1, j+1);
            scanf("%d", &marks[i][j]);
            total += marks[i][j];
        }
        totalMarks[i] = total;
        if(HighestTotal < totalMarks[i]){
            HighestTotal = totalMarks[i];
        }
    }

    printf("The total marks are : \n");
    for(i = 0; i < 5; i++){
        printf("Student %d  =  %d\n", i+1, totalMarks[i]);
    }

    printf("Highest Total Marks = %d", HighestTotal);
    return 0;

    
}