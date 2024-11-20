#include <stdio.h>

// Function to perform one pass of bubble sort
void singlePass(int array[], int size, int index) {
    if (index == size - 1) 
        return;

    if (array[index] > array[index + 1]) {
        int swap = array[index];
        array[index] = array[index + 1];
        array[index + 1] = swap;
    }

    singlePass(array, size, index + 1);
}

// Recursive bubble sort
void recursiveSort(int array[], int size) {
    if (size == 1) 
        return;

    singlePass(array, size, 0);

    recursiveSort(array, size - 1);
}

// Function to print the array
void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int length;
    printf("Enter the size of the array: ");
    scanf("%d", &length);

    int numbers[length];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Original array: ");
    displayArray(numbers, length);

    recursiveSort(numbers, length);

    printf("Sorted array: ");
    displayArray(numbers, length);

    return 0;
}

