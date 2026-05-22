#include <stdio.h>
#include <time.h>
#include <math.h>


// Task 2:
// Write a program that finds and prints all numbers between 1 and 1500 that are divisible by both 7 and 9
int main() {
    int num = 0; // Start from 0 to include 1 in the loop

    while(num <= 1500) {
        if (num%7 == 0 && num%9 == 0) { // Check if num is divisible by both 7 and 9
            printf("%4d\n", num);
        }
        num += 1; // Increment num by 1 to check the next number
    }
}