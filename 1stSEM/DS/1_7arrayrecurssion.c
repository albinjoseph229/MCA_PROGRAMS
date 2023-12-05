#include<stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
	int n,i;
void print_array(int start)
{
	if(start >= n)
		return;
	printf(" %d",arr[start]);
	print_array(start+1);
}
int main()
{
	
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter elements into the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("array elements are");
	print_array(0);
	return 0;
}

