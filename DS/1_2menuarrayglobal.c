#include<stdio.h>
int i,j,t;
int ar[10];
int n;
void insert()
{   
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
}
void display()
{
	printf("array elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",ar[i]);
	}
	
}
void delete()
{
	for(i=0;i<n;i++)
	{
		
	}
	
}
void sort()
{
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (ar[i]>ar[j]){
                t=ar[i];
                ar[i]=ar[j];
                ar[j]=t;
            }
        }
    }
	printf("array sorted");
}

int menu()
{
	int ch;
	printf("INSERT-1\nDELETE-2\nDISPLAY-3\nSORT-4\nEXIT-5\nENTER YOUR CHOICE");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("enter the no of elements to enter");
				scanf("%d",&n);
				printf("enter the elements");
				insert();
				break;
			case 2:
				printf("");
				delete();
				break;
		    case 3:
				display();
				break;
		    case 4:
			   sort();
			   break;
			default:
			   printf("Wrong choice\n");
			   break;
		
		}
	}
}
int main()
{
	
	process();
	return 0;
}
