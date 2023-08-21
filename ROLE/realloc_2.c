#include <stdio.h>
#include <stdlib.h>
int main()
{
 int *p,n,i,m;

 printf("Enter the value for n");
 scanf("%d",&n);

 p = (int *) malloc(sizeof(int) * n); //memroy allocated for n location

 for(i = 0; i < n;i++)
 {
 printf("Enter the value for p[%d]",i);
 scanf("%d",(p+i));
 }
 for(i = 0;i < n;i++)
 {
 printf ("%d\t",*(p+i));
 }
 printf("\n\nEnter the new size");
 scanf("%d",&m);
 p = (int *)realloc(p,sizeof(int) * m); //the memory is increased or decreased to m location
 if(m > n)
 {
 for(i = n; i < m;i++)
 {
 printf("Enter the value for p[%d]",i);
 scanf("%d",(p+i));
 }
 }
 for(i = 0;i < m;i++)
 {
 printf ("%d\t",*(p+i));
 }
 free(p);
 return 0;
}