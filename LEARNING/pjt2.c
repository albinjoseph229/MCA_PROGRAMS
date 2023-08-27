#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Expense {
    char date[20];
    char description[100];
    float amount;
    char category[50];
    struct Expense *next;
};

struct Expense *head = NULL; // Head of the linked list

const char *spendingTips[] = {
    "Cook meals at home instead of eating out.",
    "Use public transportation or carpool to save on fuel costs.",
    "Cancel unnecessary subscription services.",
    "Buy items in bulk to save money in the long run.",
    "Plan your shopping trips with a list to avoid impulsive purchases.",
    // Add more tips here
};

void addExpense(float *totalExpenses) {
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    if (newExpense == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", newExpense->date);
    
    printf("Enter description: ");
    scanf(" %[^\n]", newExpense->description);
    
    printf("Enter amount: ");
    scanf("%f", &newExpense->amount);
    
    printf("Enter category: ");
    scanf("%s", newExpense->category);
    
    *totalExpenses += newExpense->amount;

    newExpense->next = head;
    head = newExpense;
    
    printf("Expense added successfully.\n");
}

void viewExpenses(float totalExpenses, float expenseGoal) {
    if (head == NULL) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Date\t\tDescription\tAmount\tCategory\n");
    printf("---------------------------------------------------\n");
    struct Expense *current = head;
    while (current != NULL) {
        printf("%s\t%s\t%.2f\t%s\n", current->date, current->description,
               current->amount, current->category);
        current = current->next;
    }

    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Expense Goal: %.2f\n", expenseGoal);

    if (totalExpenses >= expenseGoal) {
        printf("Congratulations! You have met or exceeded your expense goal.\n");
    } else {
        printf("You are %.2f away from reaching your expense goal.\n", expenseGoal - totalExpenses);
    }
}

void saveExpensesToFile(float totalExpenses) {
    FILE *file = fopen("expenses.txt", "w");
    if (file != NULL) {
        struct Expense *current = head;
        while (current != NULL) {
            fprintf(file, "%s|%s|%.2f|%s\n", current->date, current->description,
                    current->amount, current->category);
            current = current->next;
        }
        fclose(file);
        printf("Expenses saved to file.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

int loadExpensesFromFile(float *totalExpenses) {
    FILE *file = fopen("expenses.txt", "r");
    if (file != NULL) {
        char date[20];
        char description[100];
        float amount;
        char category[50];

        while (fscanf(file, "%s|%[^|]|%f|%s\n", date, description, &amount, category) != EOF) {
            struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
            if (newExpense == NULL) {
                printf("Memory allocation error.\n");
                fclose(file);
                return 0;
            }
            strcpy(newExpense->date, date);
            strcpy(newExpense->description, description);
            newExpense->amount = amount;
            strcpy(newExpense->category, category);
            newExpense->next = head;
            head = newExpense;
            *totalExpenses += amount;
        }
        fclose(file);
        printf("Expenses loaded from file.\n");
        return 1;
    } else {
        printf("No expenses file found. Starting with empty list.\n");
        return 0;
    }
}
void displayRandomSpendingTip() {
    int numTips = sizeof(spendingTips) / sizeof(spendingTips[0]);
    int randomIndex = rand() % numTips;

    printf("\nTip to Reduce Spending:\n%s\n\n", spendingTips[randomIndex]);
}

int main() {
    float totalExpenses = 0.0; // Total of all expenses
    float expenseGoal = 0.0; // User-defined expense goal

    int loaded = loadExpensesFromFile(&totalExpenses);

    srand(time(NULL)); // Initialize random number generator

    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Set Expense Goal\n");
        printf("4. View Expense Goal\n");
        printf("5. Check Expense Goal\n");
        printf("6. Save Expenses to File\n");
        printf("7. Display Spending Tip\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&totalExpenses);
                break;
            case 2:
                viewExpenses(totalExpenses, expenseGoal);
                break;
            case 3:
                printf("Enter your expense goal: ");
                scanf("%f", &expenseGoal);
                printf("Expense goal set to %.2f\n", expenseGoal);
                break;
            case 4:
                printf("Your expense goal is: %.2f\n", expenseGoal);
                break;
            case 5:
                if (totalExpenses >= expenseGoal) {
                    printf("Congratulations! You have met or exceeded your expense goal.\n");
                } else {
                    printf("You are %.2f away from reaching your expense goal.\n", expenseGoal - totalExpenses);
                }
                break;
            case 6:
                saveExpensesToFile(totalExpenses);
                break;
            case 7:
                displayRandomSpendingTip();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    // Free allocated memory before exiting
    struct Expense *current = head;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}