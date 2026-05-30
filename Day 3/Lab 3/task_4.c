/* Opening comment here
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int count(int p, int q, int r) {
    srand(time(NULL)); // Seed the random number generator with the current time
    int randomNum;
    for (int i = 0; i < p; i++) {
        randomNum = rand() % (q + 1);
        if (randomNum < r && randomNum >= 0) {
            printf("The random number is: %d\n", randomNum);
        }
    }
    return 0;
}


int main () {
    int p;
    int q;
    int r;
    char s[100];

    while ( p != 0 ) {
        printf("Enter a number for how many numbers your want to generate: ");
        scanf("%d", &p);
        if (p < 0) {
            printf("Invalid input. Please enter a non-negative number.\n");
            return -1; // Exit with an error code
        }else if (p == 0) {
            break; // Exit the loop if the user enters 0
        }
        printf("Enter a number for the first range: ");
        scanf("%d", &q);
        if (q < 0) {
            printf("Invalid input. Please enter a non-negative number.\n");
            return -1; // Exit with an error code
        }
        printf("Enter a number for the second range: ");
        scanf("%d", &r);
        if (r < 0) {
            printf("Invalid input. Please enter a non-negative number.\n");
            return -1; // Exit with an error code
        }
        fgets(s,100,stdin);
        count(p, q, r);
    }
}