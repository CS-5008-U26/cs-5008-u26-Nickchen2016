/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/

int main() {

    int x;                          // x will be the value entered by the user
    int y;                          // y will be the second value entered by the user
    int z;                          // z will be the third value entered by the user
    char s[100];                    // s is used to "pause" the console so it doesn't exit too quickly

    /* Ask for a number and print it out */
    printf("Enter a number: ");     // prompt the user
    scanf("%d", &x);                // read a number from the console ("stdin")
    fgets(s,100,stdin);             // sadly, we have to remove the \n that scanf leaves in stdin

    printf("You entered %d\n", x);  // tell the user what number they just entered

    printf("Enter the second number: ");
    scanf("%d", &y);
    /* Pause the console so we can look at it before it vanishes */
    fgets(s,100,stdin);
    printf("You entered %d\n", y);

    printf("Enter the third number: ");
    scanf("%d", &z);
    fgets(s,100,stdin);
    printf("You entered %d\n", z);

    printf("The sum of first two numbers is %d\n", x+y);
    printf("The division between the sum of first two numbers and the third number is %d\n", (x+y)/z);

    return 0;
}