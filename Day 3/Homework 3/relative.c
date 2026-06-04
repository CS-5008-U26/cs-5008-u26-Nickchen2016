/* Write a program that takes a number and output the relative prime numbers from 2 to x-1
*/

#include <stdio.h>

// I did a Google search to find that we can use the Euclidean algorithm to calculate the greatest common divisor (GCD) of two numbers, if the GCD is 1, then those two numbers are relative prime numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }else{
        return gcd(b, a % b);
    }
}
// The ET function is used to get the relative prime numbers by using the GCD function
int et (int x) {
    int count = 0; // The count is used to determine wether to print " , " before the relative prime number or not
    for (int i = 2; i < x; i++) {
        if (gcd(x, i) == 1) {
            if( count == 0) {
                printf("%d", i); 
            }else{
                printf(", %d", i);
            }
            count += 1;
        }
    }
    return 0;
}
// The main function is used to gather the user input and call the ET function, then print the prime numbers in the reuqired format
int main () {
    int num;
    char s[100];

    printf("Enter a number: ");
    scanf("%d", &num);
    fgets(s, 100, stdin);

    printf("The relative prime numbers are: ");
    int result = et(num);
    if(result != 0){
        printf("%d\n", result);
    }
    fgets(s,100,stdin);
}