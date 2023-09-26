#include<stdio.h>
#include<malloc.h>
int main()
{
	int i,j;
	int mean;
	int sum=0;
	int n;
	int *arr;
	
	printf("enter the no of elements: ");
	scanf("%d",&n);
	
	arr=(int *)calloc(n,sizeof(int));
	
	for(i=0;i<n;i++)
	{
		printf("Enter the %d Element: ",(i+1));
		scanf("%d",arr+i);
		sum=sum+*(arr+i);
	}
	
	int maxValue=0;
	int maxCount = 0;

    for (i = 0; i < n; i++) {
    	int count = 0;
      
       for (j = 0; j < n; j++) {
        	if (arr[j] == arr[i])
        	count++;
       }
      
       if (count >maxCount) {
	   		maxCount = count;
        	maxValue = arr[i];		
       }
       
    }

	printf("Mode is: %d",maxValue);

	
	return 0;
}
