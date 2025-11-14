/*Q128: Read a text file and count how many vowels and consonants are in the file.
 Ignore digits and special characters.

/*
Sample Test Cases:
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8
Consonants: 10

*/
#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *fp;
    char ch;
    int vowels = 0, consonants = 0;

    // Open the file in read mode
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read each character from the file
    while ((ch = fgetc(fp)) != EOF) {
        ch = tolower(ch); // Convert to lowercase for easier comparison
        if (ch >= 'a' && ch <= 'z') { // Check if it's an alphabet
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    // Close the file
    fclose(fp);

    // Display the counts
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
