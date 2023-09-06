#include<stdio.h>
int i;
struct poly{
	int coeff;
};
struct poly s[10];
int read(int degree)
{

	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("enter the constant");
			scanf("%d",&s[i].coeff);
			break;
		}
		printf("enter the coefficient");
		scanf("%d",&s[i].coeff);
	}
}
int disp(int degree)
{
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",s[i].coeff);
			break;
		}
		printf("%dx^%d+",s[i].coeff,i);
	}
}
int main()
{
	int degree;
	printf("enter the degree: ");
	scanf("%d",&degree);
	read(degree);
	disp(degree);
	return 0;
}
