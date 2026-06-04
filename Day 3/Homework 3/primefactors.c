/* Opening comment here
*/

#include <stdio.h>

// Write a program that takes a number and outputs the prime factors of that number.
int main () {
    int num;
    int currentPrimeFactor = 2; // Start with the smallest prime factor
    int count = 0;
    char s[100];
    // Save user input number into variable num and clear the buffer
    printf("Enter a number: ");
    scanf("%d", &num);
    fgets(s, 100, stdin);

    printf("The prime factors are ");
    // Do the prime factorization by continuously dividing the number by the current prime factor until it can no longer be divided, then move on to the next prime factor
    while (num > 1) {
        if (num % currentPrimeFactor == 0) {
            if(count == 0) {
                printf("%d", currentPrimeFactor);
            }else{
                printf(" * %d", currentPrimeFactor);
            }
            num = num / currentPrimeFactor;
        }else{

            currentPrimeFactor += 1;
        }
        count += 1; // Counter is used to determine whether to print " * " before the prime factor or not
    }
    fgets(s,100,stdin);
}