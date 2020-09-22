/*
Q : 1.Create a structure to specify data on students given below:Roll number, Name, Department, Course, Year of joiningAssume that there are not more than 100 students in the  college. a.Write a function to print the names of all students who joined  in a particular year.b.Write a function to print the data of a student whose roll number is given.
*/

#include <stdio.h>
typedef enum{
    F, T
}
boolean;

struct StudentData
{
    int rollNumber;
    char studentName [100];
    char department [100];
    char course [100];
    int joinYear;
};
void getNames(struct StudentData data[], int year);
void getData(struct StudentData data[], int rollNumber);
int main()
{
    struct StudentData data[100];
    int n;
    printf("The number of students in college : ");
    scanf("%d",&n);
    int i;
    for(i = 0; i < n; i++){
        int rollNumber;
        char studentName[100], department[100], course[100];
        int joinYear;
        printf("\nSTUDENT %d DATA\n",i+1);
        printf("Enter roll number : ");
        scanf("%d",&data[i].rollNumber);
        printf("Enter student name : ");
        scanf(" %[^\n]",data[i].studentName);
        printf("Enter department : ");
        scanf(" %[^\n]",&data[i].department);
        printf("Enter course : ");
        scanf(" %[^\n]",&data[i].course);
        printf("Enter year of joining : ");
        scanf("%d",&data[i].joinYear);

        
    }

    int q1, q2;
    printf("Enter the number of years to search : ");
    scanf("%d", &q1);
    
    for(i = 0; i < q1; i++){
        int year;
        printf("Enter year : ");
        scanf("%d",&year);
        getNames(data, year);
    }
    printf("Enter the number of student data to search : ");
    scanf(" %d", &q2);
    for(i = 0; i < q2; i++){
        int rollNumber;
        printf("Enter roll number : ");
        scanf("%d",&rollNumber);
        getData(data, rollNumber);
    }

    return 0;
}

void getNames(struct StudentData data[], int year){
    boolean check = F;
    int i;
    for(i = 0; i < 100; i++){
        if(data[i].joinYear == year){
            printf("%s ,", data[i].studentName);
            check = T;
        }
    }

    if(check == F){
        printf("There are no students of the given year .");
    }
    printf("\n");
  
}

void getData(struct StudentData data[], int rollNumber){
    boolean check = F;
    int i;
    for(i = 0; i < 100; i++){
        if(data[i].rollNumber == rollNumber){
            printf("Roll Number : %d\nName : %s\nDepartment : %s\nCourse : %s\nJoining Year : %d\n",data[i].rollNumber,data[i].studentName, data[i].department, data[i].course, data[i].joinYear);
            check = T;
            break;
        }

    }
    if(check == F){
        printf("No student exists with specified roll number .\n");
    }
    //printf("\n");
}

