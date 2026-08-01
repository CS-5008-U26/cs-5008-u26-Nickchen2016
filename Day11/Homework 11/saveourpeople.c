#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 200


// Define the struct for each cities
typedef struct {
    char name[100];
    long long population;
    int length;
} City;

// Remove the quotes from the string
void stripQuotes(char *str) {
    int length = strlen(str);
    if(length >= 2 && str[0] == '"' && str[length-1] == '"') { // If the field is quoted, remove the quotes
        str[length-1] = '\0'; // Replace the last quote with \0
        for (int i = 0; i<length-1; i++) {
            str[i] = str[i+1]; // Shift the string to the left
        }
    }
}

// The helper function to perform the Knapsack algorithm part
long long dpTable(City cities[], int n, int capacity) {
    long long dp[n+1][capacity+1];

    // Initialize DP table
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            dp[i][w] = 0;
        }
    }
    // Build DP table
    for (int i = 0; i <= n; i++) {
        int weight = cities[i-1].length;
        long long val = cities[i-1].population;
        for(int w = 0; w <= capacity; w++) {
            // Cannot include this city
            if(weight > w) {
                dp[i][w] = dp[i-1][w];
            }else{
                // This will include the next city and its length into the DP
                long long include = dp[i-1][w-weight]+val;
                // If the next city won't fulfil the limit, we keep the previous value
                long long exclude = dp[i-1][w];

                if(include > exclude) {
                    dp[i][w] = include;
                }else{
                    dp[i][w] = exclude;
                }
            }
        }

    }
    // Back tracking to find selected cities
    int w = capacity;
    printf("Cities picked to save:\n");
    for (int i = n; i > 0; i--) {

        if (dp[i][w] != dp[i - 1][w]) {

            printf("%s (%lld)\n",
                   cities[i - 1].name,
                   cities[i - 1].population);

            w -= cities[i - 1].length;

        }
    }

    printf("Total population: %lld\n", dp[n][capacity]);
    return dp[n][capacity];
}

int main () {
    City cities[MAX_CITIES];

    // Read the cities data
    FILE *fp = fopen("../../Resources/uscities.csv", "r");
    if(fp == NULL) {
        printf("Cannot open file.\n");
        return 0;
    }
    
    char line[2500];
    int count = 0;

    // Skip the CSV header
    fgets(line, sizeof(line), fp);

    // Filter down the cities data and gather the city name with its population.
    /* The city struct will be look like:
        name: *****
        population: *****
        length: **
    */
    while(fgets(line, sizeof(line), fp) != NULL && count < MAX_CITIES) {
        int column = 1;
        cities[count].population = 0;

        char *token = strtok(line, ",");
        while(token != NULL) {
            if(column == 2) { // Col 2 gets the citites names
                stripQuotes(token);
                strcpy(cities[count].name, token);
            }
            if(column == 9) { // Col 9 gets the populations
                stripQuotes(token);
                cities[count].population = atoll(token);
            }
            token = strtok(NULL, ",");
            column++;
        }
        // We get the city name's length
        cities[count].length = strlen(cities[count].name);
        count++;
    }

    // You can print out the excerpted data by uncomment the code below:

    // for(int i=0;i<200;i++) {
    //     printf("%s\n", cities[i].name);
    // }

    // Call the helper function to perform the Knapsack algorithm part,
    // then print out the selected cities with total population
    long long totalPopulation = dpTable(cities, count, 200);

    fclose(fp);
    return 0;
}