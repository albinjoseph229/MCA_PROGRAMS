#include <stdio.h>

int ar[10];
int n; // Global variable to track the number of elements in the array
int x; // Global variable to store the search element

void insert(int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    printf("\nElements are inserted\n");
}

void display() {
    int i;
    if (n > 0) {
        printf("Array elements are: ");
        for (i = 0; i < n; i++) {
            printf("%d", ar[i]);
            if (i < n - 1)
                printf(", ");
        }
        printf("\n");
    } else {
        printf("Array is empty\n");
    }
}

void delete() {
    if (n == 0) {
        printf("Array is empty\n");
    } else {
        printf("Last element of the array is deleted\n");
        n--;
    }
}

void sort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}

void search() {
    int i, flag = 0;
    for (i = 0; i < n; i++) {
        if (ar[i] == x) {
            flag = 1;
            printf("Element %d found at index %d.\n", x, i);
            break;
        }
    }
    if (flag == 0) {
        printf("Element %d not found in the array.\n", x);
    }
}

int menu() {
    int ch;
    printf("INSERT-1\nDELETE-2\nDISPLAY-3\nSORT-4\nSEARCH-5\nEXIT-6\nENTER YOUR CHOICE: ");
    scanf("%d", &ch);
    return ch;
}

void process() {
    int ch;
    for (ch = menu(); ch != 6; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the value of n: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Invalid value of n\n");
                    break;
                }
                printf("Enter the elements: ");
                insert(n);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                sort();
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search();
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}

int main() {
    process();
    return 0;
}
