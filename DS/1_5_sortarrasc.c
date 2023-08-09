#include<stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE],n,i;
void read()
{	
	printf("enter array elements:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
}
void disp()
{
	printf("array elements are:");
	for(i=0;i<n;i++)
	{
	printf(" %d",arr[i]);
	}
}
void sort()
{
	int j,t;
	for(i=0;i<n;i++){
		for(j=0;j<(n-1)-i;j++){
			if(arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				
			}
		}
	}
}
void del()
{
	int i;
    if(n == -1){
        printf("ARRAY IS EMPTY");
    }
    else{
        printf("Enter the position of the element to delete: ");
        int pos;
        scanf("%d", &pos);
        if(pos < 0 || pos >= n){
            printf("Invalid position");
        }
        else{
            printf("Deleted element is %d: ", arr[pos]);
            for(i = pos; i < n - 1; i++){
                arr[i] = arr[i + 1];
            }
            n--;
        }
    }
}

int menu()
{
	int ch;
	printf("\nEnter your choice:\n INSERT-1\n DISPLAY-2\n SORT-3\n DELETE-4\n EXIT-5: ");
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
				printf("enter the number of elements to enter: ");
				scanf("%d",&n);
			    read();
			    break;
			case 2:
				disp();
				break;
			case 3:
				sort();
				break;
			case 4:
				del();
				break;
			default:
				printf("wrong choice");
				break;
		}
	}
}
int main()
{

    process();
}
