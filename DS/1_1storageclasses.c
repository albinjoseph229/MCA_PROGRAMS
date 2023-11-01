#include <stdio.h>

int a = 5, b; // Global variables

void print()
{
	printf("The value of global variable a is %d (assigned)\n", a);
	printf("The value of global variable b is %d (default value is undefined)\n", b);
}

void display()
{
	static int i; // Static variable
	printf("Value of static variable i is %d (default initialized value)\n", i);
	static int k = 1;
	printf("Assigned value of static variable k = %d\n", k);
	k++;
}

void reg()
{
	int h = 3; // Local variable
	printf("The value of h = %d (local variable)\n", h);
}

int main()
{
	int c; // Local variable
	printf("The value of local variable c is %d (garbage value)\n", c);
	print();
	display();
	reg();
	return 0;
}
