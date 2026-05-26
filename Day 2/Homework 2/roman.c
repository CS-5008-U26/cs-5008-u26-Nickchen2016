/* Standard Libraries */
#include <stdio.h>

/**** MAIN PROGRAM ****/
// write a program that takes an integer between 1 and 4000 and convert it to a Roman Numeral
int main() {
    int num;
    char s[100];

    printf("Enter a number between 1 and 4000: ");
    scanf("%d", &num);
    fgets(s, 100, stdin); // Clear the newline character from the input buffer

    if (num < 1 || num > 4000) { // Check if the input number is within the valid range
        printf("Invalid input. Please enter a number between 1 and 4000.\n");
        return 1; // Exit with an error code
    }else{ // Convert the number to a Roman numeral and print it
        printf("The Roman Numeral: ");
        if (num >= 1000) {
            int t = num / 1000;
            for (int i = 0; i < t; i++) { // Using a loop to print duplicate characters
                printf("M");
            }
            num = num % 1000; // Update the remaining number after extraction
        }
        if(num >= 100 && num <1000) {
            int h = num / 100;
            if (h == 9) {
                printf("CM");
            }else if(h >= 5) {
                printf("D");
                for (int i = 0; i < h-5; i++) {
                    printf("C");
                }
            }else if(h == 4) {
                printf("CD");
            }else{
                for (int i = 0; i < h; i++) {
                    printf("C");
                }
            }
            num = num % 100;
        }
        if(num >= 10 && num <100) {
            int t = num / 10;
            if (t == 9) {
                printf("XC");
            }else if(t >= 5) {
                printf("L");
                for (int i = 0; i < t-5; i++) {
                    printf("X");
                }
            }else if(t == 4) {
                printf("XL");
            }else{
                for (int i = 0; i < t; i++) {
                    printf("X");
                }
            }
            num = num % 10;
        }
        if(num >= 1 && num <10) {
            int u = num;
            if (u == 9) {
                printf("IX");
            }else if(u >= 5) {
                printf("V");
                for (int i = 0; i < u-5; i++) {
                    printf("I");
                }
            }else if(u == 4) {
                printf("IV");
            }else{
                for (int i = 0; i < u; i++) {
                    printf("I");
                }
            }
        }
        printf("\n");
    }
}