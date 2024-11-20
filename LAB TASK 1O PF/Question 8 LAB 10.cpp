#include <stdio.h>

void printElements(int numbers[], int total, int currentIndex) {
    if (currentIndex == total) {
        return;
    }
    printf("%d ", numbers[currentIndex]);
    printElements(numbers, total, currentIndex + 1);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int numbers[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Array elements are:\n");
    printElements(numbers, size, 0);

    return 0;
}

