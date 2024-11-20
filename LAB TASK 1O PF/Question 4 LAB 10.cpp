#include <stdio.h>
#include <string.h>

#define MAX_OPTIONS 5

// Define the structure for a travel plan
typedef struct {
    char title[50];
    char location[50];
    int days;        
    float price;     
    int availableSeats;  
} TravelPlan;

// Function to show available plans
void showPlans(TravelPlan plans[], int totalPlans) {
    printf("\nAvailable Travel Plans:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < totalPlans; i++) {
        printf("Plan %d:\n", i + 1);
        printf("Title: %s\n", plans[i].title);
        printf("Location: %s\n", plans[i].location);
        printf("Duration: %d days\n", plans[i].days);
        printf("Price: PKR %.2f\n", plans[i].price);
        printf("Seats Available: %d\n", plans[i].availableSeats);
        printf("---------------------------------------------------\n");
    }
}

void reservePlan(TravelPlan plans[], int totalPlans) {
    int selected;
    printf("\nSelect a plan to book (1-%d): ", totalPlans);
    scanf("%d", &selected);

    if (selected < 1 || selected > totalPlans) {
        printf("Invalid selection! Please choose a valid plan number.\n");
        return;
    }

    // Adjust for 0-based indexing
    selected--;

    if (plans[selected].availableSeats > 0) {
        plans[selected].availableSeats--;
        printf("Booking confirmed! You have reserved '%s'.\n", plans[selected].title);
    } else {
        printf("Apologies, this plan is fully booked.\n");
    }
}

int main() {
    TravelPlan plans[MAX_OPTIONS] = {
        {"Northern Getaway", "Hunza Valley", 5, 45000.00, 5},    
        {"Mountain Retreat", "Skardu", 7, 65000.00, 5},          
        {"Urban Excursion", "Karachi", 3, 20000.00, 5},          
        {"Cultural Heritage", "Lahore", 4, 30000.00, 5},         
        {"Desert Adventure", "Cholistan Desert", 6, 40000.00, 5} 
    };

    int userChoice;
    do {
        printf("\nWelcome to the Travel Booking System\n");
        printf("1. View Available Plans\n");
        printf("2. Book a Travel Plan\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                showPlans(plans, MAX_OPTIONS);
                break;
            case 2:
                reservePlan(plans, MAX_OPTIONS);
                break;
            case 3:
                printf("Thank you for exploring the Travel Booking System. Have a great journey ahead!\n");
                break;
            default:
                printf("Invalid option! Please select a valid option from the menu.\n");
        }
    } while (userChoice != 3);

    return 0;
}

