#include <stdio.h>
int main()
{
    char s[100];  // Declare a charactor array named s that can hold up to 100 charactors
    printf("Hello world\n");
    fgets(s, 100, stdin); // Read a line of input from the user
}