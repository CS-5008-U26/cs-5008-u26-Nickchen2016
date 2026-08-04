# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include <time.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {

        int value = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > value) {
            // Compare it with the sorted portion
            a[j + 1] = a[j]; // Replace the small number
            j--; // Iterate through the sorted portion
        }

        a[j + 1] = value; // Swap the value
    }
}

int main() {
    // Set up our priority queue with its initial values
    int *pq = NULL;
    int size = 0;
    int capacity = 0;

    int placeholder;
    char s[100];

    // Initialize the random number generator
    srand((unsigned)time(NULL));

    while(1) {
        // Ask how many numbers to add on
        printf("How many numbers to add: ");

        if (fgets(s, sizeof(s), stdin) == NULL || s[0] == '\n') {
            break; 
        }
        clock_t startTime = clock();        // get the start time
        int userInput = atoi(s);

        // Increase capacity if needed
        while((size + userInput) > capacity) {
            if(capacity == 0) {
                capacity = 100;
            }else{ // Double the capacity everytime we need to increase it
                capacity *= 2;
            }
            // Re-allocate the PQ size
            int *temp = realloc(pq, capacity*sizeof(int));
            if(temp == NULL) {
                printf("Memory allocation failed.\n");
                free(pq);
                return 1;
            }
            pq = temp;
        }

        // Generate random numbers
        for(int i = 0; i < userInput; i++) {
            pq[size++] = rand() % 100000;
        }
        
        // Sort the priority queue using insertion sort
        insertionSort(pq, size);

        clock_t endTime = clock();          // get the end time
        double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf ("Elapsed time: %f seconds\n", elapsedTime);   // print the elapsed time

        // Print out the new PQ list after added new numbers
        for(int j=0; j<size; j++) {
            printf("%d\n", pq[j]);
        }

        // Ask how many numbers to remove
        printf("How many numbers to remove: ");

        if (fgets(s, sizeof(s), stdin) == NULL || s[0] == '\n') {
            break; 
        }
        clock_t startTimeToRemove = clock();        // get the start time
        int userRemove = atoi(s);

        // Do not remove more than the actual size
        if(userRemove > size) {
            userRemove = size;
        }

        // Print removed numbers
        printf("The numbers we need to remove from the PQ list are:\n");
        for(int i = 0; i < userRemove; i++) {
            printf("%d\n", pq[i]);
        }

        // Shift remaining elements left
        memmove(pq,
                pq + userRemove,
                (size - userRemove) * sizeof(int));

        size -= userRemove;

        // Stop if queue becomes empty
        if (size == 0) {
            printf("Priority queue is empty.\n");
            break;
        }

        clock_t endTimeToRemove = clock();          // get the end time
        double elapsedTimeToRemove = (double)(endTimeToRemove - startTimeToRemove) / CLOCKS_PER_SEC;
        printf ("Elapsed time: %f seconds\n", elapsedTimeToRemove);   // print the elapsed time

        // Print out the new PQ list after removed the numbers
        printf("The new PQ list is:\n");
        for(int j=0; j<size; j++) {
            printf("%d\n", pq[j]);
        }
    }

    free(pq);
    return 0;
}