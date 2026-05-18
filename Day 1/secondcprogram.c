#include <stdio.h>
int main() {
    char s[100];
    char t[100];
    printf ("What is your name? ");
    scanf("%s", s);
    fgets(t,100,stdin); // I saved the leftover buffer into char t to get rid of the \n -> Not overrides the char s
    printf("%s? That's a funny name!\n",s); // I added '\n' in the end of the string to leave space for the hint to exit the console
    printf("Press the enter key to quit..."); // The hint for user to exit the console
    getchar(); //Hit the Enter key to quit

    return 0; //End the program with a return value of 0, which means the program ended successfully
}