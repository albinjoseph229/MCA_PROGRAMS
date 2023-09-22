#include<stdio.h>
int s[5],top=-1;
void push(int e)
{
	if(top==6)
	{
		printf("stack is full");
		
	}
	else{
		s[++top]=e;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is underflow:");
		
	}
	else{
		s[top--];
	}
}
void peek()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		printf("\nElement at top is %d",s[top]);
	}
}
int menu()
{
	int ch;
	printf("\nEnter your choice\n 1-PUSH\n 2-POP\n 3-PEEK\n 4-EXIT\n");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int e,ch;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("enter the element");
				scanf("%d",&e);
				push(e);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			default:
				printf("wrong choice");
		}
	}
}
int main()
{
	process();
	return 0;
}
