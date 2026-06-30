#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// I created a struct for the candy, then extracted the candy data from the candy-data file. Then, I analyzed the data according to the task requirements
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

void printCandy (candyData *candy) {
    int num_of_both = 0;
    int num_of_chocolate = 0;
    if(candy -> chocolate == 1) {
        // I looped through the candy struct, filtered the caramel section, and converted the letter cases
        for (int i = 0; candy -> competitorname[i] != '\0'; i++) {
            if(candy -> caramel == 1) {
                    putchar(toupper(candy -> competitorname[i]));
            }else{
                    putchar(tolower(candy -> competitorname[i]));
            }
        }
        printf("\n");
    }
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

        // Count for the percent of chocolate candies that also have caramel
        int num_of_chocolate = 0;
        int num_of_both = 0;
        
        for (int i = 0; i < count; i++) {

            printCandy(candies[i]); // Print the required competitornames

            if (candies[i]->chocolate == 1) {
                num_of_chocolate++;

                if (candies[i]->caramel == 1) {
                    num_of_both++;
                }
            }
        }
        // The percent of chocolate candies that also have caramel
        double percent = (double)num_of_both / num_of_chocolate * 100;

        printf("The percent of chocolate candies that also have caramel is %.2f%%\n",
            percent);

        // Clean up the Heap storage data
        for (int i = 0; i < count; i++) {
            free(candies[i]->competitorname);
            free(candies[i]);
        }
    }
    return 0;
}

