#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node *next, *prev;
};

typedef struct node cdll;
cdll *head = NULL;

void insert(char e[]) {
    cdll *t;
    if (head == NULL) {
        head = (cdll *)malloc(sizeof(cdll));
        strcpy(head->data, e);
        head->next = head;
        head->prev = head;
    } else {
        for (t = head; t->next != head; t = t->next);
        t->next = (cdll *)malloc(sizeof(cdll));
        strcpy(t->next->data, e);
        t->next->next = head;
        t->next->prev = t;
        head->prev = t->next;
    }
}

void disp() {
    cdll *t;
    if (head == NULL) {
        printf("Empty Linked List");
    } else {
        t = head;
        do {
            puts(t->data);
            t = t->next;
        } while (t != head);
    }
}

void delete(char e[]) {
    cdll *t;
    if (head == NULL) {
        printf("Empty Linked List");
    } else if (strcmp(head->data, e) == 0 && head->next == head) {
        free(head);
        head = NULL;
    } else if (strcmp(head->data, e) == 0) {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        cdll *temp = head;
        head = head->next;
        free(temp);
    } else {
        t = head->next;
        while (t != head && strcmp(t->data, e) != 0) {
            t = t->next;
        }
        if (t == head) {
            printf("Not found\n");
        } else {
            t->next->prev = t->prev;
            t->prev->next = t->next;
            free(t);
        }
    }
}

int main() {
    char e[100];
    int ch;
    printf("\nCIRCULAR DOUBLY LINKED LIST");
    printf("\n---------------------------");
    do {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\nChoose your option:");
        scanf("%d", &ch);
        getchar(); 
        switch (ch) {
            case 1:
                printf("\nEnter name: ");
                fgets(e, sizeof(e), stdin);
                e[strcspn(e, "\n")] = '\0'; 
                insert(e);
                break;
            case 2:
                disp();
                break;
            case 3:
                printf("\nEnter name to delete: ");
                fgets(e, sizeof(e), stdin);
                e[strcspn(e, "\n")] = '\0'; 
                delete(e);
                break;
            case 4:
                while (head != NULL) {
                    cdll *temp = head->next;
                    free(head);
                    head = temp;
                }
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (1);
    return 0;
}
