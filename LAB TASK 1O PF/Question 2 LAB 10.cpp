#include <stdio.h>

void printPercentage(int number, int percent) {
    if (percent > 100) 
        return;
    printf("%d percent of %d = %.2f\n", percent, number, (number * percent) / 100.0);
    printPercentage(number, percent + 1);
}

int main() {
    int value;
    printf("Enter the number: ");
    scanf("%d", &value);
    printPercentage(value, 1);
}

