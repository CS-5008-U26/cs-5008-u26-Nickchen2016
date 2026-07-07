#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct singleNode {
    void *data; // void pointer function as a placeholder for city data
    struct singleNode *next;
} sNode;

typedef struct city_data {
    char city[100];
    char state[100];
    char population[100];
} cityData;

// Create a new node
sNode *createNode (void *data) {
    if (data == NULL) {
        return NULL;
    }
    sNode *node = malloc(sizeof(sNode));
    // Check if the malloc was successful 
    if(node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
// Insert a node to the front of the list
void insertFront (sNode **head, sNode *newNode) { // single astrisk is the actual node point to, double astrisk is a pointer that you can modify, so you can change the head of the list
    if (head == NULL || newNode == NULL) {
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// Insert a node to the end of the list
void insertEnd (sNode **head, sNode *newNode) {
    if(head == NULL || newNode == NULL) {
        return;
    }
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    sNode *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current ->next = newNode;
}

// Get the nth node
sNode *getNode(sNode *head, int n) {
    if(n<0) {
        return NULL;
    }
    int i = 0;
    while (head != NULL) {
        if(i == n) {
            return head;
        }
        head = head->next;
        i+=1;
    }
    return NULL;
}

// Delete a node from the list
void deleteNode(sNode **head, sNode *target) {
    if (head == NULL || *head == NULL || target == NULL) {
        return;
    }
    if (*head == target) {
        *head = target->next;
        return;
    }
    sNode *current = *head;
    while (current->next != NULL && current->next != target) {
        current = current->next;
    }
    if (current->next == target) {
        current->next = target->next;
    }
    // free(target->data); // Free the city data before free the node
    // free(target);
}

// Reverse the list
void reverseList(sNode **head) {
    if(head == NULL || *head == NULL) {
        return;
    }
    sNode *prev = NULL;
    sNode *current = *head;
    sNode *next = NULL;
    while(current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        // Move the pointers forward
        prev = current; 
        current = next;
    }
    *head = prev;
}

// Count the list length
int length(sNode *head) {
    int count = 0;
    while (head != NULL) {
        count +=1;
        head = head->next;
    }
    return count;
}

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
            int lengthOfTheList = 0;
            char inputLine[5000];
            fgets(inputLine, sizeof(inputLine), inFile); //Read the header line and ignore it
            sNode *head = NULL; // Create a link list and set the head to NULL
            for (int lineCount = 0; lineCount <20; lineCount++) {
                // Process each city data line
                if(!fgets(inputLine, sizeof(inputLine), inFile)) {
                    break; // Break if we reach the end of the file
                }else{
                    int col = 1;
                    char field[2000];
                    int fieldIndex = 0;
                    cityData *newCity = malloc(sizeof(cityData)); // Create a new city data]
                    if (newCity == NULL) {
                        fclose(inFile);
                        return 1; // Exit if Malloc fails
                    }

                    for (int i = 0; inputLine[i] != '\0'; i++) {
                        if(inputLine[i] == ',' || inputLine[i] == '\n') {
                            field[fieldIndex] = '\0'; // Null-terminate the field
                            if (col == 2) { // City name is in the second column
                                stripQuotes(field);
                                strcpy(newCity->city, field);
                            }else if(col == 3) { // State name is in the third column
                                stripQuotes(field);
                                strcpy(newCity->state, field);
                            }else if (col == 9) { // Population is in the ninth column
                                stripQuotes(field);    
                                strcpy(newCity->population, field);                            
                            }
                            col++;
                            fieldIndex = 0; // Reset field index for the next field
                        }else{
                            field[fieldIndex++] = inputLine[i]; // Add character to the current field
                        }
                    }
                    sNode *newNode = createNode(newCity); // Create a new node with the city data
                    insertEnd(&head, newNode); // Insert the new node at the end
                }
            }

            // Console command to interact with the link list
            char command[20];
            int secondaryCommand; // The user entered number right after the first command
            int isGoing = 1;
            while(isGoing) {
                printf("size, delete, reverse, get, or print: \n");
                scanf("%s", command);
                if(strcmp(command, "size") == 0) {
                    printf("Size is %d\n", length(head));
                }else if(strcmp(command, "delete") == 0) {
                    printf("Please enter the number you want to delete: ");
                    scanf("%d", &secondaryCommand);
                    sNode *n = getNode(head, (secondaryCommand-1));
                    deleteNode(&head, n);
                }else if(strcmp(command, "reverse") == 0) {
                    reverseList(&head);
                }else if(strcmp(command, "get") == 0) {
                    printf("Please enter the number you want to get: ");
                    scanf("%d", &secondaryCommand);
                    sNode *node = getNode(head, (secondaryCommand-1));
                    if(node == NULL) {
                        printf("Invalide node number\n");
                        continue;
                    }
                    cityData *city_data = node->data;
                    printf("The %dth node is: %s %s, Population %s\n", secondaryCommand, city_data->city, city_data->state, city_data->population);
                    deleteNode(&head, node); // Delete the node from the list
                    insertFront(&head, node); // Move the node to the front of the list
                }else if(strcmp(command, "print") == 0) {
                    printf("Please enter the number you want to print to: ");
                    scanf("%d", &secondaryCommand);
                    sNode *n = getNode(head, (secondaryCommand-1));
                    if(n == NULL) {
                        printf("Invalide node number\n");
                        continue;
                    }
                    printf("The %dth node is: %p\n", secondaryCommand, n);
                    sNode *current = head;
                    while(current != NULL && current != n->next) {
                        cityData *city_data = current->data;
                        printf("%s %s, Population %s\n", city_data->city, city_data->state, city_data->population);
                        current = current->next;
                    }
                }
                else{
                    isGoing = 0;
                }  
            }
        }
        fclose(inFile);
        return 0;
}