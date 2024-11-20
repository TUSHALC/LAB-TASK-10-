#include <stdio.h>

// Function to calculate the sum of digits
int digitSum(int num) {
    if (num == 0) 
        return 0;
    int partialSum = num % 10 + digitSum(num / 10);
    return partialSum;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int total = digitSum(number);
    printf("Sum of digits: %d\n", total);

    return 0;
}

