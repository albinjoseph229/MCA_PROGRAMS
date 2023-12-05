#include<stdio.h>

int arr1[10][10],arr2[10][10],arr3[10][10],i,j,k;

void read(int r1,int c1,int r2,int c2)
{
    printf("\nEnter the elements of 1st matrix: ");
    for(i=0;i<r1;i++)
    {
   	 for(j=0;j<c1;j++)
   	 {
   		 scanf("%d",&arr1[i][j]);
   	 }
    }
    printf("\nEnter the elements of 2nd matrix: ");
    for(i=0;i<r2;i++)
    {
   	 for(j=0;j<c2;j++)
   	 {
   		 scanf("%d",&arr2[i][j]);
   	 }
    }
}

void disp(int r1,int c1,int r2,int c2)
{
    printf("\nThe elements of 1st matrix are: \n");
    for(i=0;i<r1;i++)
    {
   	 for(j=0;j<c1;j++)
   	 {
   		 printf("%d ",arr1[i][j]);
   	 }
   	 printf("\n");
    }

    printf("\nThe elements of 2nd matrix are: \n");
    for(i=0;i<r2;i++)
    {
   	 for(j=0;j<c2;j++)
   	 {
  		 	printf("%d ",arr2[i][j]);
   	 }
   	 printf("\n");
    }
}

void add(int r1,int c1,int r2,int c2)
{
    printf("\nAddition: \n");
    if(r1==r2 && c1==c2)
    {
    for(i=0;i<r1;i++)
    {
   	 for(j=0;j<c1;j++)
   	 {
   		 arr3[i][j]=arr1[i][j]+arr2[i][j];
   		 printf("%d\t",arr3[i][j]);
   	 }
   	 printf("\n");
    }
	}
    else
    {
   	 printf("For addition matrix should be of same size");
    }
}


void sub(int r1,int c1,int r2,int c2)
{
   
    printf("\nSubtraction: \n");
    if(r1==r2 && c1==c2)
    {
   	 for(i=0;i<r1;i++)
   	 {
   		 for(j=0;j<c1;j++)
   		 {
       		 arr3[i][j]=arr1[i][j]-arr2[i][j];
       		 printf("%d\t",arr3[i][j]);
   		 }
   		 printf("\n");
   	 }
	}
    else
    {
   	 printf("For subtraction matrix should be of same size");
    }
}

void mul(int r1,int c1,int r2,int c2)
{
    printf("\nMultiplication: \n");
    if(c1==r2)
    {
   	 for(i=0;i<r1;i++)
   	 {
   		 for(j=0;j<c2;j++)
   		 {
       		 arr3[i][j]=0;
       		 for(k=0;k<c2;k++)
       		 {
           		 arr3[i][j]=arr3[i][j]+ arr1[i][k] * arr2[k][j];
       		 
       		 }
         		 printf("%d\t",arr3[i][j]);
   		 }
   		 printf("\n");
   	 }
	}
    else
    {
   	 printf("Multiplication not possible the size should be of the form((axb)(bxc)");
	}
}

void tran(int r1,int c1,int r2,int c2)
{
    printf("\nTransponse of 1st matrix: \n");
    for(i=0;i<c1;i++)
    {
   	 for(j=0;j<r1;j++)
   	 {
   		 printf("%d ",arr1[j][i]);
   	 }
   	 printf("\n");
    }
    printf("\nTransponse of 2nd matrix: \n");
    for(i=0;i<c2;i++)
    {
   	 for(j=0;j<r2;j++)
   	 {
   		 printf("%d ",arr2[j][i]);
   	 }
   	 printf("\n");
    }
}

int menu()
{
    int ch;
    printf("\nChoices:\n1.Display\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Transpose\n6.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}

void process(int r1,int c1,int r2,int c2)
{
    int ch;
    for(ch=menu();ch!=6;ch=menu())
    {
   	 switch(ch)
   	 {

   		 case 1: disp(r1,c1,r2,c2);
   				 break;
   		 case 2: add(r1,c1,r2,c2);
   				 break;
   		 case 3: sub(r1,c1,r2,c2);
   				 break;
   		 case 4: mul(r1,c1,r2,c2);
   				 break;
   		 case 5: tran(r1,c1,r2,c2);
   				 break;
   		 default:printf("Invalid Choice");
   				 break;

    	}
    }
}
int main()
{
    int r1,c1,r2,c2;
    printf("Enter the row size and column size of the 1st matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the row size and column size of the 2nd matrix: ");
    scanf("%d %d",&r2,&c2);
    read(r1,c1,r2,c2);
    process(r1,c1,r2,c2);
}

