#include <stdio.h>
#include <stdlib.h>
int main()
{
 int *p;

 p = (int *) malloc(sizeof(int)); //memroy allocated for one location

 *p =10;


 p = (int *)realloc(p,sizeof(int) * 2); //the memory is increased to two locations

 *(p+1) = 20;

 printf("%d %d",*p, *(p+1));

 printf("\n\n%d %d",p[0],p[1]);

 free(p);
 return 0;
}