#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0, i, j, k;
    int *result, carry, n1, n2, sum;

    // Calculate the lengths of the input numbers
    while (num1[len1] != '\0')
        len1++;
    while (num2[len2] != '\0')
        len2++;

    // Allocate memory for the result array
    result = (int *)malloc(sizeof(int) * (len1 + len2));

    // Initialize the result array with 0s
    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    // Multiply each digit of num1 with each digit of num2
    for (i = len1 - 1; i >= 0; i--) {
        n1 = num1[i] - '0';
        carry = 0;
        k = len1 - 1 - i;

        for (j = len2 - 1; j >= 0; j--) {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[k] + carry;
            carry = sum / 10;
            result[k] = sum % 10;
            k++;
        }

        if (carry > 0)
            result[k] += carry;
    }

    // Find the first non-zero digit in the result array
    i = len1 + len2 - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // If the result is zero, print 0
    if (i == -1)
        printf("0");
    else {
        // Print the result
        while (i >= 0)
            printf("%d", result[i--]);
    }

    printf("\n");

    // Free the dynamically allocated memory
    free(result);

    return 0;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    // Check if the arguments are valid numbers
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                printf("Error\n");
                return 98;
            }
        }
    }

    // Multiply the numbers and print the result
    multiply(argv[1], argv[2]);

    return 0;
}