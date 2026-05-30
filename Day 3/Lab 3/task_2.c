/* Opening comment here
*/

#include <stdio.h>
#include <time.h>


int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }else{
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

int main() {

    time_t startTime = time(NULL); // Start the clock to measure the execution time of the program
    int count;
    int num = 0;
    int fibonacciNum;
    printf("The total seconds counted: %d\n", count); // Subtract 1 to get the actual seconds counted
    while (time(NULL) - startTime < 5) { // Loop until 5 seconds have passed
        printf("The %dth Fibonacci number is: %d\n", num, fibonacci(num));
        fibonacciNum = fibonacci(num);
        num += 1;
    }
    printf("The last Fibonacci number is: %d\n", fibonacciNum);
}