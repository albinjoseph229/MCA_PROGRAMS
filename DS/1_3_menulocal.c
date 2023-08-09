#include<stdio.h>

void insert(int ar[], int n)
{   
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
}
void display(int ar[], int n)
{
    int i; 
    if(n>0){

        printf("Array elements are: ");
        for(i=0;i<n;i++)
        {
            printf("%d",ar[i]);
            if(i<n-1) printf(", ");
        }
        printf("\n");
    }
    else
    {
        printf("Array is empty\n");
    }
}
int delete(int ar[], int n) 
{
	if(n==-1){
		printf("array is empty");
	}
	else{
		printf("last element of array is deleted");
		n=n-1;
	}
    return n;
}

void sort(int ar[], int n)
{
    int i, j; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
    return; 
}

void search(int ar[], int n, int x)
{
    int i, flag = 0; 
    for (i = 0; i < n; i++) {
        if (ar[i] == x) { 
            flag = 1;
            printf("Element %d found at index %d.\n", x, i);
            break; 
        }
    }
    if (flag == 0) { 
        printf("Element %d not found in the array.\n", x);
    }
    return; 
}


int menu()
{
    int ch;
    printf("\nINSERT-1\nDELETE-2\nDISPLAY-3\nSORT-4\nSEARCH-5\nEXIT-6\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}
void process() 
{
    int ch;
    
    int x;
    int ar[10]; 
    int n = -1; 
    for(ch=menu();ch!=6;ch=menu())
    {
        switch(ch)
        {
            case 1:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                if(n<=0){
                    printf("Invalid value of n\n");
                    break;
                }
                printf("Enter the elements: ");
                insert(ar,n);
                break;
            case 2:
               n = delete(ar,n);
               break;
            case 3:
                display(ar,n);
                break;
            case 4:
               sort(ar,n);
               break;
            case 5:
            	printf("enter element to search");
            	scanf("%d",&x);
                search(ar,n,x);
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

