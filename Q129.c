/*Q129: A file numbers.txt contains a list of integers separated by spaces. 
Read all integers, compute their sum and average, and print both.

/*
Sample Test Cases:
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150
Average = 30.00

*/
#include <stdio.h>
int main() {
    FILE *fp;
    int number, sum = 0, count = 0;
    float average;

    // Open the file to read integers
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read integers from the file and compute sum and count
    while (fscanf(fp, "%d", &number) != EOF) {
        sum += number;
        count++;
    }

    fclose(fp);

    // Calculate average
    if (count > 0) {
        average = (float)sum / count;
        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", average);
    } else {
        printf("No integers found in the file.\n");
    }

    return 0;
}