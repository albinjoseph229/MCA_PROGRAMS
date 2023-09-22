#include<stdio.h>
int a=5,b;               //global variables
void print()
{             
	printf("\nThe value of global variable a is %d which is assigned\n",a);
	printf("\nThe value of global variable b is %d default value is zero\n ",b);
}
void display()
{
	static int i;            //sattic variable
	printf("\nvalue of static variable i is %d which is the default value\n",i);
	static int k=1;
	printf("\nassigned value of static variable k=%d \n",k);
	k++;
}
void reg()                   //register
{
	int register h=3;          
	printf("\nThe value of h=%d which is a register\n",h);
}
int main()
{
	int c;                 //local variable
	printf("\nThe value of local variable c is %d which is a garbage value\n",c);
	print();
	display();
	reg();
	return 0;
}
