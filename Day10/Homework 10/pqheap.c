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

// Move inserted element upward, smaller number on the top
void heapifyUp(int heap[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index] < heap[parent]) {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            index = parent;
        }else{
            break;
        }
    }
}

// Restore heap after removing root
void heapifyDown(int heap[], int size, int index) {
   while (1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

int main() {
    // Set up our priority queue with its initial values
    int *heap = NULL;
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
            int *temp = realloc(heap, capacity*sizeof(int));
            if(temp == NULL) {
                printf("Memory allocation failed.\n");
                free(heap);
                return 1;
            }
            heap = temp;
        }

        // Generate random numbers
        for(int i = 0; i < userInput; i++) {
            heap[size] = rand() % 100000;
            heapifyUp(heap, size);
            size++;
        }
        
        // Sort the priority queue using insertion sort
        insertionSort(heap, size);

        clock_t endTime = clock();          // get the end time
        double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf ("Elapsed time: %f seconds\n", elapsedTime);   // print the elapsed time

        // Print out the new PQ list after added new numbers
        for(int j=0; j<size; j++) {
            printf("%d\n", heap[j]);
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
        printf("The numbers we need to remove from the PQ list are:\n");
        for (int i = 0; i < userRemove; i++) {

            // Print smallest element
            printf("%d\n", heap[0]);

            // Replace root with last element
            heap[0] = heap[size - 1];

            size--;

            // Restore heap
            if (size > 0)
                heapifyDown(heap, size, 0);
        }

        printf("\n");

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
            printf("%d\n", heap[j]);
        }
    }

    free(heap);
    return 0;
}