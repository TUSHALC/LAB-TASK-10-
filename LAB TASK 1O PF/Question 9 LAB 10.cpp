#include <stdio.h>
#include <string.h>

#define MAX_WORKERS 100

typedef struct {
    int workerID;
    char fullName[50];
    char division[50];
    float pay;
} Worker;

void enterWorkerDetails(Worker *worker, int index);
void showAllWorkers(Worker workers[], int count);

int main() {
    int totalWorkers;

    printf("How many workers would you like to enter? ");
    scanf("%d", &totalWorkers);

    if (totalWorkers <= 0 || totalWorkers > MAX_WORKERS) {
        printf("Invalid number of workers. Please enter a value between 1 and %d.\n", MAX_WORKERS);
        return 1;
    }

    Worker workers[totalWorkers];

    for (int i = 0; i < totalWorkers; i++) {
        enterWorkerDetails(&workers[i], i + 1);
    }

    showAllWorkers(workers, totalWorkers);

    return 0;
}

void enterWorkerDetails(Worker *worker, int index) {
    printf("\n--- Enter details for Worker %d ---\n", index);

    printf("Worker ID: ");
    scanf("%d", &worker->workerID);

    getchar();

    printf("Full Name: ");
    fgets(worker->fullName, sizeof(worker->fullName), stdin);
    worker->fullName[strcspn(worker->fullName, "\n")] = 0;

    printf("Division: ");
    fgets(worker->division, sizeof(worker->division), stdin);
    worker->division[strcspn(worker->division, "\n")] = 0;

    printf("Pay: ");
    scanf("%f", &worker->pay);
}

void showAllWorkers(Worker workers[], int count) {
    printf("\n\n--- Worker Details ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nWorker %d:\n", i + 1);
        printf("  ID        : %d\n", workers[i].workerID);
        printf("  Name      : %s\n", workers[i].fullName);
        printf("  Division  : %s\n", workers[i].division);
        printf("  Pay       : %.2f\n", workers[i].pay);
    }
    printf("\n");
}

