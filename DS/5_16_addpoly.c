#include<stdio.h>
int coeff1[10];
int coeff2[10];
int coeff3[10];
int i;
int read1(degree)
{
	printf("enter the  1st polynomial\n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("Enter the constant\n");
			scanf("%d",&coeff1[i]);
			break;
		}
		printf("Enter the coefficient\n");
		scanf("%d",&coeff1[i]);
	}
	printf("\n1st polynomial:");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",coeff1[i]);
			break;
		}
		printf("%dx^%d+",coeff1[i],i);
	}
}
	
int read2(degree)
{
	printf("\nEnter the  2nd polynomial\n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("Enter the constant\n");
			scanf("%d",&coeff2[i]);
			break;
		}
		printf("Enter the coefficient\n");
		scanf("%d",&coeff2[i]);
	}
	printf("\n2nd ploynomial:");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",coeff2[i]);
			break;
		}
		printf("%dx^%d+",coeff2[i],i);
	}
}
int add(degree)
{
	for(i=degree;i>=0;i--)
	{
		coeff3[i]=coeff1[i]+coeff2[i];
	}
}
int disp(degree)
{
printf("\nAddition of polynomial\n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",coeff3[i]);
			break;
		}
		printf("%dx^%d+",coeff3[i],i);
	}
}
int main()
{
	int degree;
	printf("Enter the degree of polynomial\n");
	scanf("%d",&degree);
	read1(degree);
	read2(degree);
	add(degree);
	disp(degree);
}
