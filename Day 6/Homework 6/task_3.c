#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This file contains Task 1 and Task 2. I created a struct for the candy, then extracted the candy data from the candy-data file. Then, I analyzed the data according to the task requirements
typedef struct candy_data {
    // the 1st field is reserved for the candy name
    char *competitorname;
    // fields 2 to 10 are boolean, 0 for ture / 1 for false
    int chocolate;
    int fruity;
    int caramel;
    int peanutalmondy;
    int nougat;
    int crispedricewafer;
    int hard;
    int bar;
    int pluribus;
    // fields 11 to 13 are stored percentages
    double sugarpercent;
    double pricepercent;
    double winpercent;
}candyData;

candyData *recordCandy(
    char competitorname[],
    int chocolate,
    int fruity,
    int caramel,
    int peanutalmondy,
    int nougat,
    int crispedricewafer,
    int hard,
    int bar,
    int pluribus,
    double sugarpercent,
    double pricepercent,
    double winpercent) {
        candyData *a_candy = 
                    (candyData*)malloc(sizeof(candyData));
        /*
            Because of the data type, we need to create another pointer by using Mallo for the value of the competitorname,
            So now we have a struct store on the Heap plus a competitorname value store separated on the heap too.   
        */
        a_candy -> competitorname = malloc(strlen(competitorname) + 1);
            strcpy(a_candy -> competitorname, competitorname);
        a_candy -> chocolate = chocolate;
        a_candy -> fruity = fruity;
        a_candy -> caramel = caramel;
        a_candy -> peanutalmondy = peanutalmondy;
        a_candy -> nougat = nougat;
        a_candy -> crispedricewafer = crispedricewafer;
        a_candy -> hard = hard;
        a_candy -> bar = bar;
        a_candy -> pluribus = pluribus;
        a_candy -> sugarpercent = sugarpercent;
        a_candy -> pricepercent = pricepercent;
        a_candy -> winpercent = winpercent;

        return a_candy;
}

void printSummary(candyData *candies[], int count, char attribute[])
{ // I used a loop to iterate through the candy data, extracting the useful information for each attribute. Then, I performed the calculations to determine the average for each attribute
    double sugarSum = 0;
    double priceSum = 0;
    double winSum = 0;
    int num = 0;

    for (int i = 0; i < count; i++) {

        int hasAttribute = 0;

        if (strcmp(attribute, "chocolate") == 0) // Check if the attribute is matching with the request
            hasAttribute = candies[i]->chocolate; // Once a match is found, we assign a value of 1 to hasAttribute. Then, on line 117, we calculate the total sum before performing the division
        else if (strcmp(attribute, "fruity") == 0)
            hasAttribute = candies[i]->fruity;

        else if (strcmp(attribute, "caramel") == 0)
            hasAttribute = candies[i]->caramel;

        else if (strcmp(attribute, "peanutalmondy") == 0)
            hasAttribute = candies[i]->peanutalmondy;

        else if (strcmp(attribute, "nougat") == 0)
            hasAttribute = candies[i]->nougat;

        else if (strcmp(attribute, "crispedricewafer") == 0)
            hasAttribute = candies[i]->crispedricewafer;

        else if (strcmp(attribute, "hard") == 0)
            hasAttribute = candies[i]->hard;

        else if (strcmp(attribute, "bar") == 0)
            hasAttribute = candies[i]->bar;

        else if (strcmp(attribute, "pluribus") == 0)
            hasAttribute = candies[i]->pluribus;

        if (hasAttribute == 1) {
            sugarSum += candies[i]->sugarpercent;
            priceSum += candies[i]->pricepercent;
            winSum += candies[i]->winpercent;
            num++;
        }
    }

    printf("%s\n", attribute);
    printf("Average Sugar: %.2f\n", sugarSum / num);
    printf("Average Price: %.2f\n", priceSum / num);
    printf("Average Win: %.2f\n\n", winSum / num);
}
// Function is used to print all candies whose sugar/price percent is higher than the average sugar/price percent.
void calculateAverage(candyData *candies[], int count, int useSugar) {

    double total = 0;

    // Calculate the overall average
    for (int i = 0; i < count; i++) {

        if (useSugar)
            total += candies[i]->sugarpercent;
        else
            total += candies[i]->pricepercent;
    }

    double average = total / count;

    double sugarSum = 0;
    double priceSum = 0;
    double winSum = 0;
    int num = 0;

    // Find candies above the average
    for (int i = 0; i < count; i++) {

        if ((useSugar && candies[i]->sugarpercent > average) ||
            (!useSugar && candies[i]->pricepercent > average)) {

            sugarSum += candies[i]->sugarpercent;
            priceSum += candies[i]->pricepercent;
            winSum += candies[i]->winpercent;
            num++;
        }
    }

    if (useSugar)
        printf("\nCandies Above Average Sugar Percent\n");
    else
        printf("\nCandies Above Average Price Percent\n");

    printf("Average Sugar: %.2f\n", sugarSum / num);
    printf("Average Price: %.2f\n", priceSum / num);
    printf("Average Win: %.2f\n", winSum / num);
}

int main() {
    char line[512];
    FILE *inFile = fopen("../../Resources/candy-data.csv", "r");
    if (inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }else{
        // Skip header
        fgets(line, sizeof(line), inFile);

        candyData *candies[100]; // Create a placeholder for the candy data we get from the CSV file
        int count = 0;
        
        while (fgets(line, sizeof(line), inFile) != NULL) {

            char *token = strtok(line, ",");

            char competitorname[50];
            strcpy(competitorname, token);
            // Convert the candy-data file from string to integer
            int chocolate = atoi(strtok(NULL, ","));
            int fruity = atoi(strtok(NULL, ","));
            int caramel = atoi(strtok(NULL, ","));
            int peanutalmondy = atoi(strtok(NULL, ","));
            int nougat = atoi(strtok(NULL, ","));
            int crispedricewafer = atoi(strtok(NULL, ","));
            int hard = atoi(strtok(NULL, ","));
            int bar = atoi(strtok(NULL, ","));
            int pluribus = atoi(strtok(NULL, ","));

            double sugarpercent = atof(strtok(NULL, ","));
            double pricepercent = atof(strtok(NULL, ","));
            double winpercent = atof(strtok(NULL, ","));

            candies[count] = recordCandy(
                competitorname,
                chocolate,
                fruity,
                caramel,
                peanutalmondy,
                nougat,
                crispedricewafer,
                hard,
                bar,
                pluribus,
                sugarpercent,
                pricepercent,
                winpercent
            );

            count++;
        }

        //Call the printSummary function and print the average numbers
        printSummary(candies, count, "chocolate");
        printSummary(candies, count, "fruity");
        printSummary(candies, count, "caramel");
        printSummary(candies, count, "peanutalmondy");
        printSummary(candies, count, "nougat");
        printSummary(candies, count, "crispedricewafer");
        printSummary(candies, count, "hard");
        printSummary(candies, count, "bar");
        printSummary(candies, count, "pluribus");

        calculateAverage(candies, count, 1);   // Sugar
        calculateAverage(candies, count, 0);   // Price


        // Clean up the Heap storage data
        for (int i = 0; i < count; i++) {
            free(candies[i]->competitorname);
            free(candies[i]);
        }
    }
    return 0;
}

