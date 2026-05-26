/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/
// Write a program that takes a number from 1 to 100 and outputs the corresponding letter grade with +, -, or nothing
int main() {
    int number; // Placeholder for user input number
    char final_grade[50]; 
    char s[100];

    printf("Enter a number from 1 to 100: ");
    scanf("%d", &number);
    fgets(s, 100, stdin);

    // Error handling for invalid numbers and determining letter grades with +, -, or nothing
    if((number >= 61) && (number <= 100)) {
        if((number % 10 == 1) || (number % 10 == 2) || (number % 10 == 3)) {
            // Use sprintf to format the final letter grade string based on the number input
            sprintf(final_grade, "Your letter grade is %c-", (number >= 91) ? 'A' : (number >= 81) ? 'B' : (number >= 71) ? 'C' : 'D');
        }else if((number % 10 == 8) || (number % 10 == 9) || (number % 10 == 0)) {
            sprintf(final_grade, "Your letter grade is %c+", (number >= 91) ? 'A' : (number >= 81) ? 'B' : (number >= 71) ? 'C' : 'D');
        }else {
            sprintf(final_grade, "Your letter grade is %c", (number >= 91) ? 'A' : (number >= 81) ? 'B' : (number >= 71) ? 'C' :  'D');
        }
        printf("%s\n", final_grade); // Print the final letter grade
    }else if((number >= 0) && (number <= 60)) {
        printf("Your letter grade is F"); // Print F for numbers between 0 and 60
    }else{
        printf("Invalid input. Please enter a number between 1 and 100.");
    }
}