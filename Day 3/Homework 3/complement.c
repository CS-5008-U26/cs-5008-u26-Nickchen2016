/* Opening comment here
*/

#include <stdio.h>
// Write a program that takes a number and output the 10's complement of that number
int complement(int num) { // Sub function to calculate the complement of a number by using recursion

    if(num >=0 && num <= 9) {
        printf("--kk%d\n", (9 - num));
        return 9 - num;
    }else{
        printf("--%d", (9 - num % 10));
        return (9 - num % 10) + 10 * complement(num / 10);
    }
}
// Main function is used to gether the user input and call the complement function to calculate
int main () {
    int num;
    char s[100];

    printf("Enter a number: ");
    scanf("%d", &num);
    fgets(s, 100, stdin);

    printf("Enter an integer: %d\n", num);
    int compNum = complement(num);
    printf("The complement is %d\n", compNum);

    fgets(s,100,stdin);
}