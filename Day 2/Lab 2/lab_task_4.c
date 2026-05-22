#include <stdio.h>
#include <time.h>
#include <math.h>



// Task 4:
// Write a program that finds and prints all prime numbers between 1 and 100
int main() {
    clock_t startTime = clock(); // Start the clock to measure the execution time of the program
    int num = 3;
    int i;
    
    printf("2\n"); // Special case for 2, which is the only even prime number
    while(num <=100) {
        int prime = 1; // Assume num is prime until we find a divisor
        int sqrtI = (int)sqrt((double)num); // Calculate the square root of num to optimize the prime checking
        for (i=3; i<=sqrtI; i+=2) { // Check only odd numbers starting from 3
            if(num%i == 0) {
                prime = 0;
                break;
            }
        }
        if(prime) {
            printf("%d\n", num);
        }
        num += 2;
    }
    clock_t endtime = clock(); // End the clock after the program finishes
    double time = (double)(endtime - startTime)/CLOCKS_PER_SEC;
    printf("The time taken to execute the program is %f seconds\n", time);
}