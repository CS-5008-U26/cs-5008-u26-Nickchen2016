/* Standard Libraries */
#include <stdio.h>
#include <math.h>

/**** MAIN PROGRAM ****/
// Write a program that calculate the are of a circle based on the radius entered by the user.
int main() {
    int radius; // Placeholder for user input radius
    double pi = acos(-1); // Calculate Pi
    char s[100];

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    fgets(s, 100, stdin);

    // Calculate and print the area of the circle as an integer
    printf("For a circle of radius %.1f the area is %d\n", (float)radius, (int)(pi * radius * radius));
    fgets(s,100,stdin); // Pause the console so we can look at it before it vanishes
}