/*Q125: Open an existing file in append mode and allow the user to enter a new line of text.
 Append the text at the end without overwriting existing content.

/*
Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.

*/
#include <stdio.h>
int main() {
    FILE *fp;
    char newLine[256];

    // Open the file in append mode
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Prompt user for new line of text
    printf("Enter a new line of text to append:\n");
    fgets(newLine, sizeof(newLine), stdin);

    // Append the new line to the file
    fputs(newLine, fp);

    // Close the file
    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}