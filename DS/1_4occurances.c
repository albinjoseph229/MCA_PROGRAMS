#include<stdio.h>
int main()
{
	int a[10],i,n,num,p[10];
	int count=0;
	printf("Enter the size of the array: ");  
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
	printf("Enter the array elment to find: ");  
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(a[i]==num)                           
		{
			p[count]=i;                         
			count++;
		}
	
	}
    printf("Occurrence of %d is: %d Times\n", num, count);  
    printf("Positions of %d are index: ", num);             
    for(i = 0; i < count; i++)
    {
        printf("%d ", p[i]); 
    }

	return 0;
}
