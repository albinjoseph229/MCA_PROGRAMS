// 2 D A – Continuous Memory allocation
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int r,c;
 int *arr;
 int i, j, count = 0;

 printf("Enter the no of rows and columns");
 scanf("%d%d",&r,&c);
 arr = (int *)malloc(r * c * sizeof(int));
 for (i = 0; i < r; i++)
 {
 for (j = 0; j < c; j++)
 {
 *(arr + i*c + j) = ++count;
 }
}
 for (i = 0; i < r; i++)
 {
 for (j = 0; j < c; j++)
 {
 printf("%d\t", *(arr + i*c + j));
 }
 printf("\n");
}
 return 0;
}