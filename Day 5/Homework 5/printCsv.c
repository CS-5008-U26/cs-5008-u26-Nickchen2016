# include <stdio.h>
# include <string.h>


void KillNewLine(char *str) { // To remove the newline character at the end of a string
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

char *GetNextField(char *start, char separator, char *out) {
    if (*start == '\0') {
        return NULL;
    }
    char *end = strchr(start, separator); // Find the next separator in the string
    if(end == NULL) { // If there is no separator, we are at the end of the string
        strcpy(out, start); // Copy the rest of the string to out
    }else {
        int len = end - start; // Calculate the length of the field
        out[len] = '\0';
        strncpy(out, start, len); // Copy the field to out
    }
    int length = strlen(out);
    if(length >= 2 && out[0] == '"' && out[length-1] == '"') { // If the field is quoted, remove the quotes
        out[length-1] = '\0'; // Replace the last quote with \0
        for (int i = 0; i<length-1; i++) {
            out[i] = out[i+1]; // Shift the string to the left
        }
    }
    if (end == NULL) {
        return start + strlen(start); // Return a pointer to the end of the string
    }else{
        return end + 1; // Return a pointer to the next character after the separator
    }


}

int main() {
    char buffer[1000];
    printf("Enter a filename: ");
    fgets(buffer, 1000, stdin);
    KillNewLine(buffer); // Remove the newline character from the end of the string

    FILE *inFile = fopen(buffer, "r"); // Read the file from the user inputed filename
    if(inFile == NULL) { // Validate the file
        printf("Error opening file %s\n", buffer);
    }else {
        char inputLine[1000];
        char nextField[1000];
        while (fgets(inputLine, 1000, inFile) != NULL) {
            KillNewLine(inputLine); // Remove the newline character from the end of the string
            printf(">%s<\n", inputLine);
            char *nextFieldStart = inputLine;
            while(nextFieldStart != NULL) {
                nextFieldStart = GetNextField(nextFieldStart, ',', nextField);
                if(nextFieldStart != NULL) {
                    printf(">%s<\n", nextField);
                }
            }
        }

        fclose(inFile);
    }
    return 0;
}