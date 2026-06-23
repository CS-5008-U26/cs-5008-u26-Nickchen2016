# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void stripQuotes(char *str) {
    int length = strlen(str);
    if(length >= 2 && str[0] == '"' && str[length-1] == '"') { // If the field is quoted, remove the quotes
        str[length-1] = '\0'; // Replace the last quote with \0
        for (int i = 0; i<length-1; i++) {
            str[i] = str[i+1]; // Shift the string to the left
        }
    }
}

int main() {
    FILE *inFile = fopen("../../Resources/uscities.csv", "r");
    if (inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }else{
        char inputLine[2000];
        long long sumOfPopulation = 0;
        char northernmostCity[100] = "";
        fgets(inputLine, sizeof(inputLine), inFile); // Read the header line and ignore it
        double maxLatitude = -100.0; // Initialize to the lowest possible latitude
        for (int lineCount = 0; lineCount <20; lineCount++) {
            if(!fgets(inputLine, sizeof(inputLine), inFile)) {
                break; // Break if we reach the end of the file
            }else{
                int col = 1;
                char field[2000];
                int fieldIndex = 0;

                char city[100] = "";
                double latitude = 0.0;
                int population = 0;

                for (int i = 0; inputLine[i] != '\0'; i++) {
                    if (inputLine[i] == ',' || inputLine[i] == '\n') {
                        field[fieldIndex] = '\0'; // Null-terminate the field
                        if (col == 2) { // City name is in the second column
                            strcpy(city, field);
                            printf("City: %s\n", field);
                        } else if (col == 7) { // Latitude is in the seventh column
                            stripQuotes(field);
                            latitude = atof(field);
                            if (latitude > maxLatitude) {
                                maxLatitude = latitude;
                                strcpy(northernmostCity, city);
                            }
                            printf("Latitude: %f\n", latitude);
                        } else if (col == 9) { // Population is in the ninth column
                            stripQuotes(field);
                            population = atoi(field);
                            sumOfPopulation += population;
                            printf("Population: %d\n", population);
                        }
                        col++;
                        fieldIndex = 0; // Reset field index for the next field
                    } else {
                        field[fieldIndex++] = inputLine[i]; // Add character to the current field
                    }
                }
            }
            printf("Sum of the populations: %lld\n", sumOfPopulation);
            printf("Northernmost city is %s\n", northernmostCity);
        }
    }
    fclose(inFile);
    return 0;
}