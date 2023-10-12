#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense
{
    float amount;
    char description[100];
    char date[20];
    struct Expense *next;
};

struct Expense *head = NULL;

struct Note
{
    char title[100];
    char content[1000];
    struct Note *next;
};

struct Note *notes_head = NULL;

void add_expense(float amount, char *description, char *date)
{
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    new_expense->amount = amount;
    strcpy(new_expense->description, description);
    strcpy(new_expense->date, date);
    new_expense->next = NULL;

    if (head == NULL)
    {
        head = new_expense;
    }
    else
    {
        struct Expense *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_expense;
        printf("Expense added.\n");
    }
}
void remove_expense(int index)
{
    int i;
    if (head == NULL)
    {
        printf("Error: No expenses to remove.\n");
        return;
    }
    if (index == 0)
    {
        struct Expense *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Expense *current = head;
    for (i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {
            printf("Error: Invalid index.\n");
            return;
        }
        current = current->next;
    }
    struct Expense *temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Expense removed.\n");
}
void display_expenses()
{
    printf("Expenses:\n");
    struct Expense *current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("%d. Amount: %.2f, Description: %s, Date: %s\n", i, current->amount, current->description, current->date);
        current = current->next;
        i++;
    }
}
void display_spending_tips()
{
    printf("Spending Tips:\n");
    printf("- Reduce expenses on non-essential items.\n");
    printf("- Use coupons to save money.\n");
    printf("- Buy in bulk to save money.\n");
    printf("- Use Public Transport.\n");
}
float expense_goal = 0;
void set_expense_goal()
{
    printf("Enter expense goal: ");
    scanf("%f", &expense_goal);
    printf("Expense goal set to %.2f\n", expense_goal);
}
void view_expenses_and_goal()
{
    float total = 0;
    struct Expense *current = head;
    int i = 1;
    printf("\n");
    printf("Expenses:\n");
    while (current != NULL)
    {
        printf("%d. Amount: %.2f, Description: %s, Date: %s\n", i, current->amount, current->description, current->date);
        total += current->amount;
        current = current->next;
        i++;
    }
    printf("\n");
    printf("Total expenses: %.2f\n", total);
    printf("Expense goal: %.2f\n", expense_goal);
    if (total > expense_goal && expense_goal != 0)
    {
        printf("You have exceeded your expense goal.\n");
    }
    else if (expense_goal == 0)
    {
        printf("You have not set your expense goal.\n");
    }
    else if (total < expense_goal)
    {
        printf("Congratulations! You Are Within Your Expense Goal\n");
    }
}
void create_note()
{
    struct Note *new_note = malloc(sizeof(struct Note));
    printf("Enter note title: ");
    getchar();
    fgets(new_note->title, sizeof(new_note->title), stdin);
    //scanf("%s", new_note->title);
    printf("Enter note content: ");
    getchar();
    fgets(new_note->content, sizeof(new_note->content), stdin);
    new_note->next = NULL;

    if (notes_head == NULL)
    {
        notes_head = new_note;
    }
    else
    {
        struct Note *current = notes_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_note;
    }
    printf("Note Added\n");
}
void display_notes()
{
    printf("Notes:\n");
    struct Note *current = notes_head;
    while (current != NULL)
    {
        printf("Title: %s\nContent: %s\n\n", current->title, current->content);
        current = current->next;
    }
}
void savetofile()
{
    FILE *fp;
    fp = fopen("expense.txt", "w");
    struct Expense *current = head;
    while (current != NULL)
    {
        fprintf(fp, "%f %s %s\n", current->amount, current->description, current->date);
        current = current->next;
    }
    fclose(fp);
}
int main()
{
    int choice;
    char filename[100];
    while (1)
    {
        printf("\nExpense Manager\n");
        printf("1. Add expense\n");
        printf("2. Remove expense\n");
        printf("3. Display expenses And Expense Goal\n");
        printf("4. Set Expense Goal\n");
        printf("5. Add Notes\n");
        printf("6. Display Notes\n");
        printf("7. Display spending tips\n");
        printf("8. Exit\n");
        printf("9. Save to file\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            float amount;
            char description[100];
            char date[20];
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("Enter Category: ");
            scanf("%s", description);
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            add_expense(amount, description, date);
            break;
        }
        case 2:
        {
            int index;
            printf("Enter index: ");
            scanf("%d", &index);
            remove_expense(index - 1);
            break;
        }
        case 3:
        {
            view_expenses_and_goal();
            break;
        }
        case 4:
        {
            set_expense_goal();
            break;
        }
        case 5:
        {
            create_note();
            break;
        }
        case 6:
        {
            display_notes();
            break;
        }
        case 7:
        {
            display_spending_tips();
            break;
        }
        case 8:
        {
            exit(0);
        }
        case 9:
        {
            savetofile();
            break;
        }
        default:
        {
            printf("Invalid choice.\n");
            break;
        }
        }
    }
    return 0;
}