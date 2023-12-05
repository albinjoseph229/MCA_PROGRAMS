#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    float amount;
    char description[100];
    char date[20];
    struct Expense *next;
};

struct Expense *head = NULL;

void add_expense(float amount, char *description, char *date) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    new_expense->amount = amount;
    strcpy(new_expense->description, description);
    strcpy(new_expense->date, date);
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
    } else {
        struct Expense *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

void remove_expense(int index) {
    int i;
    if (head == NULL) {
        printf("Error: No expenses to remove.\n");
        return;
    }
    if (index == 0) {
        struct Expense *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Expense *current = head;
    for (i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            printf("Error: Invalid index.\n");
            return;
        }
        current = current->next;
    }
    struct Expense *temp = current->next;
    current->next = temp->next;
    free(temp);
}

void display_expenses() {
    printf("Expenses:\n");
    struct Expense *current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d. Amount: %.2f, Description: %s, Date: %s\n", i, current->amount, current->description, current->date);
        current = current->next;
        i++;
    }
}

void display_total() {
    float total = 0;
    struct Expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    printf("Total expenses: %.2f\n", total);
}

void display_date_range(char *start_date, char *end_date) {
    printf("Expenses between %s and %s:\n", start_date, end_date);
    struct Expense *current = head;
    while (current != NULL) {
        if (strcmp(current->date, start_date) >= 0 && strcmp(current->date, end_date) <= 0) {
            printf("Amount: %.2f, Description: %s, Date: %s\n", current->amount, current->description, current->date);
        }
        current = current->next;
    }
}

void display_keyword(char *keyword) {
    printf("Expenses with keyword '%s':\n", keyword);
    struct Expense *current = head;
    while (current != NULL) {
        if (strstr(current->description, keyword) != NULL) {
            printf("Amount: %.2f, Description: %s, Date: %s\n", current->amount, current->description, current->date);
        }
        current = current->next;
    }
}

void save_expenses(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    struct Expense *current = head;
    while (current != NULL) {
        fprintf(file, "%.2f,%s,%s\n", current->amount, current->description, current->date);
        current = current->next;
    }
    fclose(file);
}

void load_expenses(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char *amount_str = strtok(line, ",");
        char *description = strtok(NULL, ",");
        char *date = strtok(NULL, ",");
        float amount = atof(amount_str);
        add_expense(amount, description, date);
    }
    fclose(file);
}

int main() {
    int choice;
    char filename[100];
    while (1) {
        printf("\nExpense Manager\n");
        printf("1. Add expense\n");
        printf("2. Remove expense\n");
        printf("3. Display all expenses\n");
        printf("4. Display total expenses\n");
        printf("5. Display expenses within date range\n");
        printf("6. Display expenses with keyword\n");
        printf("7. Save expenses to file\n");
        printf("8. Load expenses from file\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                float amount;
                char description[100];
                char date[20];
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter description: ");
                scanf("%s", description);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                add_expense(amount, description, date);
                break;
            }
            case 2: {
                int index;
                printf("Enter index: ");
                scanf("%d", &index);
                remove_expense(index - 1);
                break;
            }
            case 3: {
                display_expenses();
                break;
            }
            case 4: {
                display_total();
                break;
            }
            case 5: {
                char start_date[20];
                char end_date[20];
                printf("Enter start date (YYYY-MM-DD): ");
                scanf("%s", start_date);
                printf("Enter end date (YYYY-MM-DD): ");
                scanf("%s", end_date);
                display_date_range(start_date, end_date);
                break;
            }
            case 6: {
                char keyword[100];
                printf("Enter keyword: ");
                scanf("%s", keyword);
                display_keyword(keyword);
                break;
            }
            case 7: {
                printf("Enter filename: ");
                scanf("%s", filename);
                save_expenses(filename);
                break;
            }
            case 8: {
                printf("Enter filename: ");
                scanf("%s", filename);
                load_expenses(filename);
                break;
            }
            case 9: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    return 0;
}
