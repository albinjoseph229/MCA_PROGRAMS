#include<stdio.h>
int coeff[10];
int i;
int read(degree)
{
	printf("ENTER THE ELEMENTS OF THE POLYNOMIAL\n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("enter the constant\n");
			scanf("%d",&coeff[i]);	
			break;
		}
		printf("enter the coefficient\n");
		scanf("%d",&coeff[i]);	
	}
}
int disp(degree)
{
	printf("the entered polynomial is\n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
		
			printf("%d",coeff[i]);
			break;
		}
		printf("%dx^%d+",coeff[i],i);	
	}
}
int main()
{
	int degree;
	printf("Enter the degree of polynomial");
	scanf("%d",&degree);
	read(degree);
	disp(degree);
	return 0;
}
