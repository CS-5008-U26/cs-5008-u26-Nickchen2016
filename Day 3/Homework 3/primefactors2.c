/* Opening comment here
*/

#include <stdio.h>
// The sub function is used to calculate the prime factors recursively
int primeFactors(int num, int currentPrimeFactor, int count) { // Sub function to calculate the prime factors of a number by using recursion;
    if(num == 1) {
        return 1;
    }else{
        if( num % currentPrimeFactor == 0) {
            if (count == 0) { // Counter is used to determine whether to print " * " before the prime factor or not
                printf("%d", currentPrimeFactor);
            }else{
                printf(" * %d", currentPrimeFactor);
            }
            // After finding a prime factor, we divide the number by that prime factor and continue to find the next prime factor until the number is reduced to 1
            return primeFactors(num / currentPrimeFactor, currentPrimeFactor, (count + 1));
        }else{
            currentPrimeFactor += 1;
            return primeFactors(num, currentPrimeFactor, (count + 1));
        }
    }
}

// Write a program that takes a number and outputs the prime factors of that number.
int main () { // The main function is used to gather the user input and call the primeFactors function to calculate the prime factors of the input number
    int num;
    int count = 0;
    int initialPrimeFactor = 2;
    char s[100];
    // Save user input number into variable num and clear the buffer
    printf("Enter a number: ");
    scanf("%d", &num);
    fgets(s, 100, stdin);
    // Call the helper function primeFactors to calculate the prime factors of the input number and print them out in the required format
    printf("The prime factors are ");
    int factor = primeFactors(num, initialPrimeFactor, count);
    if (factor != 1) {
        printf("%d", factor);
    }
    fgets(s,100,stdin);
}