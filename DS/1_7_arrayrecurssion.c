#include<stdio.h>
#define MAX_SIZE 100
void print_array(int arr[], int start, int len)
{
	if(start >= len)
		return;
	printf(" %d",arr[start]);
	print_array(arr,start+1,len);
}
int main()
{
	int arr[MAX_SIZE];
	int n,i;
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter elements into the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("array elements are");
	print_array(arr,0,n);
	return 0;
}

