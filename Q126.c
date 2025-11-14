/*Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode.
 If the file pointer is NULL, print an error message; otherwise, read and display its content.

/*
Sample Test Cases:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!

*/
#include <stdio.h>
int main() {
    FILE *fp;
    char filename[100];
    char ch;

    // Ask user for the filename
    printf("Enter the filename to check:\n");
    scanf("%s", filename);

    // Try to open the file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    // File opened successfully, display its content
    printf("File opened successfully. Content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(fp);
    return 0;
}