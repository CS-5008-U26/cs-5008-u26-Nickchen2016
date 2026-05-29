/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/
// Write a program that takes a number from 1 to 10 and outputs the corresponding letter grade by using switch statement
int main() {
    int number; // Placeholder for user input number
    char s[100];

    printf("Enter a number from 1 to 10: ");
    scanf("%d", &number);
    fgets(s, 100, stdin);

    if((number > 10) || (number < 1)) { // Error handling for invalid numbers
        printf("Invalid input. Please enter a number between 1 and 10.\n");
    }else{
        // Switch statment to determine the letter grades
        switch (number) {
            case 9:
            case 10:
                printf("Your letter grade is A\n");
                break;
            case 8:
                printf("Your letter grade is B\n");
                break;
            case 7:
                printf("Your letter grade is C\n");
                break;
            case 6:
                printf("Your letter grade is D\n");
                break;
            case 4:
            case 5:
                printf("Your letter grade is E\n");
                break;
            default:        
                printf("Your letter grade is F\n");
                break;
        }
    }
    fgets(s,100,stdin); // Pause the console so we can look at it before it vanishes
}