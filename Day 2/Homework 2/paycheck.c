/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/

// Write a program that calculates a paycheck based on wage and hours worked.
int main() {
    double x; // Placeholder for hourly wage
    double y; // Placeholder for hours worked
    char s[100];

    double isgoing = 1; // To determine termination of the loop, if the user entered a number smaller and equal to 0.
    while (isgoing > 0) {
        printf("Enter your hourly wage: ");
        scanf("%lf", &x); // Read and save the user input
        fgets(s, 100, stdin); // Remove the leftover \n in the buffer
        isgoing = x; // Reassign isgoing value, if the user entered a number smaller and equal to 0, the loop will be terminated. 
        if(isgoing <=0) {
            break; // Break the loop if invalid number is entered
        }

        printf("Enter the number of hours you worked: ");
        scanf("%lf", &y);
        fgets(s, 100, stdin);
        isgoing = y;
        if(isgoing <=0) {
            break; // Break the loop if invalid number is entered
        }

        if(y > 40) {
            printf("Your paycheck is $%.2lf\n", 40*x + (y-40)*1.5*x);
        }else{
            printf("Your paycheck is $%.2lf\n", x*y);
        }
    }
    fgets(s,100,stdin);
}