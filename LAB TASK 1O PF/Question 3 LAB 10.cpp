#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_RECORDS 100

// Structure to store car details
struct Vehicle {
    char maker[50];
    char type[50];
    int manufactureYear;
    float priceTag;
    float distanceCovered;
};

void addVehicle(struct Vehicle records[], int *total);
void listVehicles(const struct Vehicle records[], int total);
void searchVehicle(const struct Vehicle records[], int total);

int main() {
    struct Vehicle records[MAX_RECORDS];
    int totalVehicles = 0;
    int selection;

    do {
        printf("\n--- Dealership Management System ---\n");
        printf("1. Add a new vehicle\n");
        printf("2. Display all vehicles\n");
        printf("3. Search for a vehicle by maker or type\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &selection);
		
        switch (selection) {
            case 1:
                addVehicle(records, &totalVehicles);
                break;
            case 2:
                listVehicles(records, totalVehicles);
                break;
            case 3:
                searchVehicle(records, totalVehicles);
                break;
            case 4:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (selection != 4);

    return 0;
}

void addVehicle(struct Vehicle records[], int *total) {
    if (*total >= MAX_RECORDS) {
        printf("The dealership has reached its capacity. No more vehicles can be added.\n");
        return;
    }

    printf("Enter vehicle maker: ");
    scanf("%s", records[*total].maker);
    printf("Enter vehicle type: ");
    scanf("%s", records[*total].type);
    printf("Enter manufacturing year: ");
    scanf("%d", &records[*total].manufactureYear);
    printf("Enter price tag: ");
    scanf("%f", &records[*total].priceTag);
    printf("Enter distance covered (mileage): ");
    scanf("%f", &records[*total].distanceCovered);

    (*total)++;
    printf("Vehicle added to the system successfully!\n");
}

void listVehicles(const struct Vehicle records[], int total) {
    if (total == 0) {
        printf("No vehicles are currently available in the system.\n");
        return;
    }

    printf("\n--- List of Vehicles ---\n");
    for (int i = 0; i < total; i++) {
        printf("Vehicle %d:\n", i + 1);
        printf("  Maker: %s\n", records[i].maker);
        printf("  Type: %s\n", records[i].type);
        printf("  Year: %d\n", records[i].manufactureYear);
        printf("  Price: $%.2f\n", records[i].priceTag);
        printf("  Mileage: %.2f km\n", records[i].distanceCovered);
        printf("----------------------\n");
    }
}

void searchVehicle(const struct Vehicle records[], int total) {
    char query[50];
    int isFound = 0;

    if (total == 0) {
        printf("No vehicles are currently available in the system.\n");
        return;
    }

    printf("Enter maker or type to search: ");
    scanf("%s", query);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < total; i++) {
        if (strstr(records[i].maker, query) || strstr(records[i].type, query)) {
            printf("Vehicle %d:\n", i + 1);
            printf("  Maker: %s\n", records[i].maker);
            printf("  Type: %s\n", records[i].type);
            printf("  Year: %d\n", records[i].manufactureYear);
            printf("  Price: $%.2f\n", records[i].priceTag);
            printf("  Mileage: %.2f km\n", records[i].distanceCovered);
            printf("----------------------\n");
            isFound = 1;
        }
    }

    if (!isFound) {
        printf("No vehicles found matching '%s'.\n", query);
    }
}

