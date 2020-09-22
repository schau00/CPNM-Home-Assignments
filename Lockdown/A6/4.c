/*
Q : Write a program which accepts names, rolls and marks of 10 students in 6 subjects stores it in an array  of  structures. Write  a  separate  function  which  prints  in  ascending  order  the  rank  list  (roll, name, average) based on the average of 6 subjects.
*/

#include<stdio.h>
struct StudentData
{
    char name[100];
    int rollNumber;
    float marks[6];
    float averageMarks;
    
};
float average(float marks[]);
void printData(struct StudentData data[]);
void sortData(struct StudentData data[]);

int main(){
    int i;
    struct StudentData data[10];
    for(i = 0; i < 2; i++){
        printf("\nStudent %d Data\n",i+1);
        printf("Enter name of student : ");
        scanf(" %[^\n]",data[i].name);
        printf("Enter roll number : ");
        scanf(" %d",&data[i].rollNumber);
        printf("Enter marks \n");
        //float sum = 0;
        int j;
        for(j = 0; j < 6; j++){
            printf("Enter marks of Subject %d : ",j+1);
            scanf(" %f", &data[i].marks[j]);
            //sum += data[i].marks[j];
        }
        data[i].averageMarks = average(data[i].marks);
    }

    printData(data);
    return 0;
}
float average(float marks[6]){
    float sum = 0;
    int i;
    for(i = 0; i < 6; i++){
        sum += (marks[i]);
    }
    return sum/6;
}
void sortData(struct StudentData data[10]){
    int i , j;
    for(i = 0; i < 10; i++){
        for(j = i+1; j < 10; j++){
            if(data[i].averageMarks > data[j].averageMarks){
                struct StudentData temp;
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void printData(struct StudentData data[10]){
    sortData(data);
    int i;
    printf("RankList\n");
    for(i = 0; i < 10; i++){
        printf("%d. Name : %s , Roll Number : %d, Average Marks = %f",i+1,data[i].name,data[i].rollNumber,data[i].averageMarks);
        printf("\n");
    }
}


