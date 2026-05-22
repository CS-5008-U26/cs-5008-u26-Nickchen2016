#include <stdio.h>
#include <time.h>
#include <math.h>

// Task 1:
// Write a program that takes an integer as input and outputs the sum of its digits
int main() {
    int placeholder;
    int last_digit;
    int sum = 0;
    char s[100];

    printf("Please enter a number: ");
    scanf("%d", &placeholder);
    fgets(s,100,stdin);
    printf("You entered %d\n", placeholder);

    // Loop to extract each digit and add it to the sum
    while(placeholder%10 !=0) {
        sum += placeholder%10;
        placeholder = placeholder/10;
    }

    printf("The sum of all the numbers is %d\n", sum);
}