// 2D Array – Pointer to Pointer allocation
#include <stdio.h>
#include <stdlib.h>

int main()
{
 int r ,c, i, j, count;

 int **arr;
 printf("Enter the no of rows and columns");
 scanf("%d%d",&r,&c);
arr = (int **)malloc(r * sizeof(int *));
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
 arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count
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