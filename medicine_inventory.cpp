#include <stdio.h>
#include <string.h>

// Structure for storing information of medicine
typedef struct {
    char ID[50];
    char nameMed[50];
    char nameMan[50];
    char manDate[20];
    char expDate[20];
    int quantity;
    float price;
    char type[20];
} medicine;

// Function prototypes
void addMedicine(medicine arr[], int *medCount);
void purchaseMedicine(medicine arr[], int medCount);
void removeMedicine(medicine arr[], int *medCount);
void displayMedicineStatistics(medicine arr[], int medCount);
void printBill(medicine buy[], int buyCount);

int main() {
    medicine arr[50];
    int choice, medCount = 0;

    do {
        // Printing the choices
        printf("\nCHOICES:\n");
        printf("1. Add Medicine\n");
        printf("2. Purchase Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Medicine Statistics\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(arr, &medCount);
                break;
            case 2:
                purchaseMedicine(arr, medCount);
                break;
            case 3:
                removeMedicine(arr, &medCount);
                break;
            case 4:
                displayMedicineStatistics(arr, medCount);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Enter a valid choice!\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

void addMedicine(medicine arr[], int *medCount) {
    char opt;

    do {
        char tempID[50];
        printf("Enter medicine ID: ");
        scanf("%s", tempID);

        int i;
        for (i = 0; i < *medCount; i++) {
            if (strcmp(tempID, arr[i].ID) == 0) {
                int addQuant;
                printf("Enter the quantity: ");
                scanf("%d", &addQuant);

                arr[i].quantity += addQuant;

                break;
            }
        }

        if (i == *medCount) {
            strcpy(arr[*medCount].ID, tempID);

            printf("Enter medicine name: ");
            scanf("%s", arr[*medCount].nameMed);

            printf("Enter manufacturer name: ");
            scanf("%s", arr[*medCount].nameMan);

            printf("Enter manufacturing date: ");
            scanf("%s", arr[*medCount].manDate);

            printf("Enter expiry date: ");
            scanf("%s", arr[*medCount].expDate);

            printf("Enter type: ");
            scanf("%s", arr[*medCount].type);

            printf("Enter quantity: ");
            scanf("%d", &arr[*medCount].quantity);

            printf("Enter price per quantity: ");
            scanf("%f", &arr[*medCount].price);

            (*medCount)++;
        }

        printf("Do you wish to add more medicine?\nAns (y/n): ");
        scanf(" %c", &opt);
    } while (opt == 'y');
}

void purchaseMedicine(medicine arr[], int medCount) {
    char opt;
    int buyCount = 0;
    medicine buy[50];

    do {
        char tempName[50], tempType[20];
        int tempQuant;

        printf("Enter medicine name: ");
        scanf("%s", tempName);
        printf("Enter medicine type: ");
        scanf("%s", tempType);

        int j, f=1;
        for (j = 0; j < medCount; j++) {
            if (strcmp(tempName, arr[j].nameMed) == 0 && strcmp(tempType, arr[j].type) == 0) {
                printf("Enter quantity: ");
                scanf("%d", &tempQuant);

                if (tempQuant > arr[j].quantity) {
                    printf("Stock-Over\n");
                } else {
                    arr[j].quantity -= tempQuant;
                    buy[buyCount] = arr[j];
                    buy[buyCount].quantity = tempQuant;
                    buyCount++;
                }
                f=0;
                break;
            }
        }

        if (f) {
            printf("Not-Found\n");
        }

        printf("Do you wish to purchase more medicine?\nAns (y/n): ");
        scanf(" %c", &opt);
    } while (opt == 'y');

    // Print the bill
    printBill(buy, buyCount);
}

void removeMedicine(medicine arr[], int *medCount) {
    char opt;

    do {
        char tempName[50], tempType[20];

        printf("Enter medicine name: ");
        scanf("%s", tempName);
        printf("Enter medicine type: ");
        scanf("%s", tempType);

        int j, f=1;
        for (j = 0; j < *medCount; j++) {
            if (strcmp(tempName, arr[j].nameMed) == 0 && strcmp(tempType, arr[j].type) == 0) {
                (*medCount)--;
                for (int k = j; k < *medCount; k++) {
                    arr[k] = arr[k + 1];
                }
                f=0;
                break;
            }
        }

        if (f) {
            printf("Not-Found\n");
        }

        printf("Do you wish to delete more medicine?\nAns (y/n): ");
        scanf(" %c", &opt);
    } while (opt == 'y');
}

void displayMedicineStatistics(medicine arr[], int medCount) {
    printf("SN.\t%-10s\t%-20s\t%-20s\t%-12s\t%-12s\t%-8s\t%-8s\t%-10s\t%-10s\n", 
           "ID", "NameOfMedicine", "NameOfManuf", "ManufDate", "ExpDate", 
           "Quantity", "Price", "Type", "TotalPrice");

    for (int k = 0; k < medCount; k++) {
        printf("%-4d\t%-10s\t%-20s\t%-20s\t%-12s\t%-12s\t%-8d\t%-8.2f\t%-10s\t%-10.2f\n", 
               k + 1, arr[k].ID, arr[k].nameMed, arr[k].nameMan,
               arr[k].manDate, arr[k].expDate, arr[k].quantity, arr[k].price, arr[k].type,
               arr[k].quantity * arr[k].price);
    }
}


void printBill(medicine buy[], int buyCount) {
    printf("\nBill:\n");
    printf("SN.\t%-10s\t%-20s\t%-20s\t%-12s\t%-12s\t%-8s\t%-8s\t%-10s\t%-10s\n", 
           "ID", "NameOfMedicine", "NameOfManuf", "ManufDate", "ExpDate", 
           "Quantity", "Price", "Type", "TotalPrice");

    for (int k = 0; k < buyCount; k++) {
        printf("%-4d\t%-10s\t%-20s\t%-20s\t%-12s\t%-12s\t%-8d\t%-8.2f\t%-10s\t%-10.2f\n", 
               k + 1, buy[k].ID, buy[k].nameMed, buy[k].nameMan, buy[k].manDate, 
               buy[k].expDate, buy[k].quantity, buy[k].price, buy[k].type, 
               buy[k].quantity * buy[k].price);
    }

    float totalAmount = 0.0;
    for (int k = 0; k < buyCount; k++) {
        totalAmount += buy[k].quantity * buy[k].price;
    }
    printf("\nTotal amount: %.2f\n", totalAmount);
}
