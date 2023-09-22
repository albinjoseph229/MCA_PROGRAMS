#include<stdio.h>
int main()
{
	int a[10],i,n,num,p[10];
	int count=0;
	printf("Enter the size of the array: ");  //Takes input
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter array elements: ");
		scanf("%d",&a[i]);
    }
	printf("Enter the array elment to find: ");  //Takes the value of element to find
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(a[i]==num)                           //searches for the element in the array
		{
			p[count]=i;                         //stores the positions at which element is found into another array
			count++;
		}
	
	}
    printf("Occurrence of %d is: %d Times\n", num, count);  //Prints the no of occurances
    printf("Positions of %d are index: ", num);             
    for(i = 0; i < count; i++)
    {
        printf("%d ", p[i]); //print the positions
    }

	return 0;
}
