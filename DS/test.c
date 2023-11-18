#include<stdio.h>
#define maxsize 50

int reverse(arr[],int end)
{
    if(end<0){
        return;
    }
    printf("%d",arr[end],end-1);

}

int main()
{
	int arr[maxsize],n,i;
	int len,end;
	printf("ENTER THE SIZE OF THE ARRAY:");
	scanf("%d",&n);
	printf("ENTER ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("arary elements are: ");
    reverse(arr,n-1);
	return 0;
}

