#include<stdio.h>
#include<string.h>
char stack[10],top =-1;
char a[10];
int i;
void pop()
{
	printf("Reversed string is");
	for(i=top;top>-1;top--)
	{
		printf(" %c",stack[top]);
	}
}
void push()
{
	for(i=0;i<strlen(a);i++)
	{
		top++;
		stack[top]=a[i];				
	}	
	
}
int main()
{
	printf("Enter the string:");
	gets(a);
	push(a);
	pop();
}
