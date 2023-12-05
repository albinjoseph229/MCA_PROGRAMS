#include<stdio.h>
#include<malloc.h>
int main()
{
	int i;
	int mean;
	int sum=0;
	int count;
	int *arr;
	
	printf("enter the no of elements: ");
	scanf("%d",&count);
	
	arr=(int *)malloc(count*sizeof(int));
	
	for(i=0;i<count;i++)
	{
		printf("Enter the %d Element: ",(i+1));
		scanf("%d",arr+i);
		sum=sum+*(arr+i);
	}
	mean=sum/count;
	printf("Mean=%d",mean);
	free(arr);
	return 0;
}
