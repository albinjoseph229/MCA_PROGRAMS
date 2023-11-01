#include <stdio.h>

struct date
{
	int day1, month1, year1;
	int day2, month2, year2;
};
struct date d;

void insert()
{
	printf("Enter the first date in the format dd/mm/yyyy: ");
	scanf("%d/%d/%d", &d.day1, &d.month1, &d.year1);
	printf("Enter the second date in the format dd/mm/yyyy: ");
	scanf(" %d/%d/%d", &d.day2, &d.month2, &d.year2);
}

void display()
{
	printf("First Date: %d/%d/%d\n", d.day1, d.month1, d.year1);
	printf("Second Date: %d/%d/%d\n", d.day2, d.month2, d.year2);
}

void compare()
{
	if (d.day1 == d.day2 && d.month1 == d.month2 && d.year1 == d.year2)
	{
		printf("Both Date Are Same\n");
	}
	else
	{
		printf("Both Date Are Different\n");
	}
}

int main()
{
	int choice;

	while (1)
	{
		printf("\nDate Comparison Menu:\n");
		printf("1. Insert Dates\n");
		printf("2. Display Dates\n");
		printf("3. Compare Dates\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			compare();
			break;
		case 4:
			printf("Goodbye!\n");
			return 0;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
