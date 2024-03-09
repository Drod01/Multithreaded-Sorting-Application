#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define NUM_THREADS 3

// Structure to hold thread parameters
typedef struct {
    int* array;
    int size;
} ThreadArgs;

// Function to calculate the average of an array segment
double calculateAverage(int* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Sorting function (e.g., insertion sort)
void insertionSort(int* array, int size) {
    // Implementation of insertion sort
    // ...
}

// Sorting thread function
void* sorting_avg(void* args) {
    ThreadArgs* targs = (ThreadArgs*)args;
    insertionSort(targs->array, targs->size);
    double avg = calculateAverage(targs->array, targs->size);
    printf("Sorting average: %.2f\n", avg);
    pthread_exit(NULL);
}

// Merging thread function
void* merging_avg(void* args) {
    // Calculate the overall average of the sorted arrays
    // ...
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <array_size>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int* array = (int*)malloc(N * sizeof(int));

    // Initialize and populate the array with random values
    // ...

    pthread_t threads[NUM_THREADS];
    ThreadArgs threadArgs[NUM_THREADS];

    // Divide the array into two segments for sorting threads
    int segment_size = N / 2;
    for (int i = 0; i < NUM_THREADS; i++) {
        threadArgs[i].array = &array[i * segment_size];
        threadArgs[i].size = segment_size;
        pthread_create(&threads[i], NULL, sorting_avg, &threadArgs[i]);
    }

    // Wait for sorting threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create a thread for merging and calculating the overall average
    // ...

    // Print the sorted array and execution time
    // ...

    free(array);
    return 0;
}