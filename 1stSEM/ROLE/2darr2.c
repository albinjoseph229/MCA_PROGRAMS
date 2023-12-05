#include <stdio.h>
#include <stdlib.h>
int main()
{
 int r, c, i, j, count;
 printf("Enter the no of rows and columns");
 scanf("%d%d",&r,&c);
 int *arr[r];
 for (i=0; i<r; i++)
 {
 arr[i] = (int *)malloc(c * sizeof(int));
 }
 // Note that arr[i][j] is same as *(*(arr+i)+j)
 count = 0;
 for (i = 0; i < r; i++)
 {
for (j = 0; j < c; j++)
{
arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
}
 }
 for (i = 0; i < r; i++)
 {
 for (j = 0; j < c; j++)
 {
 printf("%d\t", arr[i][j]);
 }
 printf("\n");
 }
 return 0;
}