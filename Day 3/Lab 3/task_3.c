/* Opening comment here
*/

#include <stdio.h>
#include <time.h>


int main() {

    time_t startTime = time(NULL); // Start the clock to measure the execution time of the program
    int count;
    int num = 0;
    int previousFibonacciNum1;
    int previousFibonacciNum2;
    int currentFibonacciNum;
    printf("The total seconds counted: %d\n", count); // Subtract 1 to get the actual seconds counted
    while (time(NULL) - startTime < 5) { // Loop until 5 seconds have passed
            if (num == 0 || num == 1) {
                currentFibonacciNum = 1;
                previousFibonacciNum1 = 1;
                previousFibonacciNum2 = 1;
            }else{
                currentFibonacciNum = previousFibonacciNum1 + previousFibonacciNum2;
                previousFibonacciNum2 = previousFibonacciNum1;
                previousFibonacciNum1 = currentFibonacciNum;
            }
        num += 1;
    }
    printf("The last Fibonacci number is: %d\n", currentFibonacciNum);
}