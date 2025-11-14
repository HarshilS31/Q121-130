/*Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

/*
Sample Test Cases:
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

*/
#include <stdio.h>
int main() {
    FILE *fp;
    char name[50];
    int roll;
    float marks;
    int n, i;

    // Open file to store student records
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Get number of students
    printf("Enter number of students:\n");
    scanf("%d", &n);

    // Input student records and write to file
    for (i = 0; i < n; i++) {
        printf("Enter name, roll number and marks of student %d:\n", i + 1);
        scanf("%s %d %f", name, &roll, &marks);
        fprintf(fp, "%s %d %.2f\n", name, roll, marks);
    }

    fclose(fp);

    // Open file to read student records
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Read and display student records
    printf("\nStudent Records:\n");
    while (fscanf(fp, "%s %d %f", name, &roll, &marks) != EOF) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n", name, roll, marks);
    }

    fclose(fp);
    return 0;
}