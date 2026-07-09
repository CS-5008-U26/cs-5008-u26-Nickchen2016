#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Create a struct for the Vector 3
typedef struct vectorNode {
    int size; // size of the array
    int used; // How many elements are using
    void **data;
} vector_3;

// Create the struct for city data
typedef struct city_data {
    char name[100];
    char state[100];
    int countryFips;
    double lat;
    double lng;
    int population;
} city;

// Ceate a BST node
typedef struct bstNode {
    city *cityData;
    struct bstNode *left;
    struct bstNode *right;
} bst;

// Create a new vector
vector_3 *createVector(int size) {
    vector_3 *vector = malloc(sizeof(vector_3));
    if(vector == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    } 
    vector->size = size;
    vector->used = 0;
    vector->data = malloc(vector->size * sizeof(void *)); // Allocate the memory for the array of void pointers. size * single array size in bytes = total size in bytes 
    return vector;
}

// Create node for the root of BST
bst *createNode(city *newCity) {
    bst *node = malloc(sizeof(bst));
    if(node == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    }
    node->cityData = newCity;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function used to insert city nodes into BST
bst *insertBST(bst *root, city *newCity) {
    if(root == NULL) {
        return createNode(newCity);
    }
    if(newCity->lat < root->cityData->lat) {
        root->left = insertBST(root->left, newCity);
    }else{
        root->right = insertBST(root->right, newCity);
    }
    return root;
}

// Insert a new element(the address of each city data) to the vector
void insertLast(vector_3 *vector, void *data) {
    if(vector->used == vector->size) {
        vector->size *= 2; // Double the size of the array
        void **newData = malloc(vector->size * sizeof(void *)); // Allocate the memory for the new array of void pointers(cities)
        if(newData == NULL) { // Check allocation failure
            printf("Memory allocation failed\n");
            return;
        }
        for(int i = 0; i < vector->used; i++) {
            newData[i] = vector->data[i]; // Copy old pointers into the new array
        }
        free(vector->data); // Delete the old pointer array
        vector->data = newData; // Point the vector to the new array
    }
    vector->data[vector->used] = data; // Add the new data
    vector->used++; // Increse the used count
}

// Function for BST inorder traversal
void inorder(bst *root, city **array, int *index) {
    if(root == NULL) {
        return;
    }
    inorder(root->left, array, index);
    array[*index] = root->cityData;
    (*index)++;
    inorder(root->right, array, index);
}

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

int main() {
    // Get the user input number of cities to read from the console
    printf("Enter the number of cities you want to read: ");
    int numCities;
    scanf("%d", &numCities);
    if(numCities <= 0) {
        printf("Invalid number of cities\n");
        return 1;
    }

    FILE *inFile = fopen("../../Resources/uscities.csv", "r");
        if (inFile == NULL) {
            printf("Error opening file\n");
            return 1;
        }else{
            char inputLine[32000];
            bst *root = NULL; // Initialize the root of our BST
            vector_3 *vector = createVector(1); // Initialize a vector with 1 city. So we can double the size of the vector when we reach the limit
            fgets(inputLine, sizeof(inputLine), inFile); //Read the header line and ignore it
            for (int lineCount = 0; lineCount < numCities; lineCount++) {
                // Process each city data line
                if(!fgets(inputLine, sizeof(inputLine), inFile)) {
                    break; // Break if we reach the end of the file
                }else{
                    int col = 1;
                    char field[2000];
                    int fieldIndex = 0;

                    city *newCity = malloc(sizeof(city)); // Create a new city data
                    // Check if malloc failed
                    if(newCity == NULL) {
                        printf("Memory allocation failed\n");
                        fclose(inFile);
                        return 1;
                    }
                    // Process each character in the line
                    for (int i = 0; inputLine[i] != '\0'; i++) {
                        if(inputLine[i] == ',' || inputLine[i] == '\n') {
                            field[fieldIndex] = '\0'; // Null-terminate the field
                            if (col == 2) { // City name is in the second column
                                stripQuotes(field);
                                strcpy(newCity->name, field);
                            }else if(col == 3) { // State name is in the third column
                                stripQuotes(field);
                                strcpy(newCity->state, field);
                            }else if(col == 5){
                                stripQuotes(field);
                                newCity->countryFips = atoi(field);
                            }else if(col == 7){
                                stripQuotes(field);
                                newCity->lat = atof(field);
                            }else if(col == 8){
                                stripQuotes(field);
                                newCity->lng = atof(field);
                            }else if (col == 9) { // Population is in the ninth column
                                stripQuotes(field);    
                                newCity->population = atoi(field);                            
                            }
                            col++;
                            fieldIndex = 0; // Reset field index for the next field
                        }else{
                            field[fieldIndex++] = inputLine[i]; // Add character to the current field
                        }
                    }
                    insertLast(vector, newCity); // Add the new city address to the vector
                    root = insertBST(root, newCity); // Insert the new city address into BST
                }
            }

            int index = 0; // Initialize the city array's index
            city **cityArr = malloc(vector->used * sizeof(city *)); // Create a city array for inorder traversal
            inorder(root, cityArr, &index); // Call the inorder function

            // Print the city data after reading the indicated number of cities
            for(int i = 0; i < vector->used; i++) {
                city *current_city = (city *)vector->data[i]; // Change the void pointer to city pointer
                // Print the city data
                printf("%s %s, population %d, at(%f, %f)\n", 
                    current_city->name, current_city->state, current_city->population, current_city->lat, current_city->lng);
                
                // Use the Task 1's for loop to do our linear search
                if(strcmp(cityArr[i]->name, "New York") == 0) {
                    printf("by latitude, New York is index %d\n", i);
                    break;
                }
            }

            // Free everything we allocated
            free(cityArr);
            for(int j = 0; j < vector->used; j++) {
                free(vector->data[j]); // Free each city
            }
            free(vector->data);
            free(vector);
        }
    fclose(inFile);
    return 0;
}