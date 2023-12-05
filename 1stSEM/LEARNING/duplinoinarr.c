//no of duplicate terms in array
//https://www.w3resource.com/c-programming-exercises/array/index.php
#include <stdio.h>
int ar[100];
int ar2[100];
int count;

int main()
{
    int n,i,j;
   printf("enter the no of elements: ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("enter the elemnt at %d: ", i);
       scanf("%d",&ar[i]);
   }
   for(i=0;i<n;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(ar[i]==ar[j])
          {
              count++;
          }
      }
   }
   printf("the count of duplicate terms is %d",count);
   return 0;
}
