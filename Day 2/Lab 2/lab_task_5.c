#include <stdio.h>
#include <time.h>
#include <math.h>


// Task 5:
// Write a program that takes a price in dollars as input and outputs the value with tax. Assume the tax rate is 8%. The output should be formatted to two decimal places.
int main() {
    long double price;
    long double totalPrice;
    char s[100];

    printf("Enter a price in dollars: ");
    scanf("%Lf", &price); // Read and save the user input as long double type
    fgets(s, 100, stdin);

    totalPrice = price + (price * 0.08); // Calculate the toital price
    printf("The value with tax is $%.2Lf\n", totalPrice);
}