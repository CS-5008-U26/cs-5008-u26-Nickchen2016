#include <stdio.h>
#include <time.h>
#include <math.h>


// Task 3:
// Write a program that finds and prints all prime numbers between 1 and 100
int main() {
    clock_t startTime = clock(); // Start the clock to measure the execution time of the program
    int num = 2;
    int i;
    
    while(num <=100) {
        int prime = 1; // Assume num is prime until we find a divisor
        for (i=2; i<num; i++) {
            if(num%i == 0) { // If num is divisible by any number between 2 and num-1, it is not prime
                prime = 0;
                break;
            }
        }
        if(prime) {
            printf("%d\n", num);
        }
        num += 1;
    }
    clock_t endtime = clock(); // End the clock after the program finishes
    double time = (double)(endtime - startTime)/CLOCKS_PER_SEC;
    printf("The time taken to execute the program is %f seconds\n", time);
}