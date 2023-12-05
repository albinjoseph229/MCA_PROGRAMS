#include<stdio.h>
#define MAX_SIZE 100
void print_reverse(int arr[],int end)
{
	if(end<0)
		return;
	printf(" %d",arr[end]);
	print_reverse(arr,end-1);
}
int main()
{
	int arr[MAX_SIZE],n,i;
	int len,end;
	printf("ENTER THE SIZE OF THE ARRAY:");
	scanf("%d",&n);
	printf("ENTER ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("arary elements are: ");
	print_reverse(arr,n-1);
	return 0;
}
