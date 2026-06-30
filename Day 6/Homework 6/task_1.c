#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// I created a struct for the candy, then extracted the candy data from the candy-data file. Then, I print the names of all the candies
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

// Create candy struct by using Malloc
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
            Because of the competitorname's data type, we need to create another pointer by using Malloc for its value,
            So now we have a struct store on the Heap plus a competitorname value store separated on the heap too.   
        */
        a_candy -> competitorname = malloc(strlen(competitorname) + 1); // We need to include the '\0', so I added 1 on the total length
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

// Function used to print the competitornames
void printCandy (candyData *candy) {
    printf("The candy name is: %s\n", candy->competitorname);
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

        candyData *candies[100]; // Create a placeholder for the candy data we retrieved from the CSV file
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
        // Loop through the data field line by line and call the printCandy function to print the competitornames
       for (int i = 0; i < count; i++) {
            printCandy(candies[i]);
        }

        // Clean up the Heap storage data
        for (int i = 0; i < count; i++) {
            free(candies[i]->competitorname);
            free(candies[i]);
        }
    }
    return 0;
}

