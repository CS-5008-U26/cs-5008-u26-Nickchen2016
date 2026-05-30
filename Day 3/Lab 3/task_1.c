/* Opening comment here
*/

#include <stdio.h>


int isHarshad(int num) {
    int sumOfDigits = 0;
    // Calculate the sum of the digits of the number
    sumOfDigits += num % 10 + num/10;
    if(num % sumOfDigits == 0) {
        return 1;
    }
    return 0;
}
// Write a program that checks if a 2-digits number is a Harshad number.
int main () {
    int userInput;
    char s[100];

    printf("Enter a 2-digits number: ");
    scanf("%d", &userInput);
    fgets(s, 100, stdin);
    // Call the helper function isHarshad to check if the input number is a Hashad number
    if (isHarshad(userInput)){
        printf("The harshad number is: %d\n", userInput);
    }

}
