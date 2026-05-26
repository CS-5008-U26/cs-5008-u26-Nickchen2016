/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/
// Write a program that takes a number from 1 to 10 and outputs the corresponding letter grade
int main() {
    int number; // Placeholder for user input number
    char s[100];

    printf("Enter a number from 1 to 10: ");
    scanf("%d", &number);
    fgets(s, 100, stdin);

    if((number > 10) || (number < 1)) { // Error handling for invalid input
        printf("Invalid input. Please enter a number between 1 and 10.\n");
    }else if((number == 9) || (number == 10)) {
        printf("Your letter grade is A\n");
    }else if(number == 8) {
        printf("Your letter grade is B\n");
    }else if(number == 7) {
        printf("Your letter grade is C\n");
    }else if(number ==6) {
        printf("Your letter grade is D\n");
    }else if((number == 4) || (number == 5)) {
        printf("Your letter grade is E\n");
    }else{
        printf("Your letter grade is F\n");
    }
}