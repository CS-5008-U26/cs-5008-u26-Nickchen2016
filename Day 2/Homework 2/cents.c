/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/
// Write a program that takes a number of cents and calculate the number into the quality of each types of coins.
int main() {
    int cents;
    int quarters = 0; // Initialize value to 0 to avoid garbade values
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    char s[100];

    printf("Enter the number of cents: ");
    scanf("%d", &cents);
    fgets(s, 100, stdin); // Clear the newline character from the input buffer
    
    // Calculate the number of each type of coin needed to make up the total cents
    if (cents >= 25) {
        quarters = cents / 25;
        cents = cents % 25;
    }
    if (cents >= 10) {
        dimes = cents / 10;
        cents = cents % 10;
    }
    if (cents >= 5) {
        nickels = cents / 5;
        cents = cents % 5;
    }
    pennies = cents; // The remaining cents are the number of pennies
        
    // Format the final output string with the calculated number of coins
    printf("That requires ");
    if(quarters == 1) {
        printf("%d quarter", quarters);
    }else if(quarters > 1) {
        printf("%d quarters", quarters);
    }
    if(quarters == 0) {
        if(dimes == 1) {
            printf("%d dime", dimes);
        }else if(dimes > 1) {
            printf("%d dimes", dimes);
        }
    }else{
        if(dimes == 1) {
            printf(", %d dime", dimes);
        }else if(dimes > 1) {
            printf(", %d dimes", dimes);
        }
    }
    if(dimes == 0 && quarters == 0) {
        if(nickels == 1) {
            printf("%d nickel", nickels);
        }else if(nickels > 1) {
            printf("%d nickels", nickels);
        }
    }else{
        if(nickels == 1) {
            printf(", %d nickel", nickels);
        }else if(nickels > 1) {
            printf(", %d nickels", nickels);
        }
    }
    if(nickels == 0 && dimes == 0 && quarters == 0) {
        if(pennies == 1) {
            printf("%d penny", pennies);
        }else if(pennies > 1) {
            printf("%d pennies", pennies);
        }
    }else{
        if(pennies == 1) {
            printf(", %d penny", pennies);
        }else if(pennies > 1) {
            printf(", %d pennies", pennies);
        }
    }

    printf(".\n"); // End the output with a period and newline
}