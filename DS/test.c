#include <stdio.h>
int main()
{
  int c1[10], c2[10], c3[20], e1[10], e2[10], e3[20];
  int n1, n2, i, j,k = 0;
  printf("enter the numberof terms for 1st polynomial\n");
  scanf("%d", &n1);

  printf("enter the terms of 1st polynomial\n");
  for (i = 0; i < n1; i++)
  {
    printf("enter the coefficient: ");
    scanf("%d", &c1[i]);
    printf("enter the exponent: ");
    scanf("%d", &e1[i]);
  }

  printf("enter th e number of terms in 2nd polynomail\n");
  sacnf("%d", &n2);

  for (i = 0; i < n1; i++)
  {
    printf("enter the coefficient: ");
    scanf("%d", &c2[i]);
    printf("enter the exponent: ");
    scanf("%d", &e2[i]);
  }

  i = 0;
  j = 0;
  int k = 0;

  while (i < n1 && j < n2)
  {
    if (e1[i] == e2[i])
    {
      c3[k] = c1[i] + c2[j];
      e3[k] = e2[j];
      i++;
      j++;
      k++;
    }
    else if (e1[i] > e2[j])
    {
      c3[k] = c1[i];
      e3[k] = e1[i];
      i++;
      k++;
    }
    else
    {
      c3[k] = c2[j];
      e3[k] = e2[j];
      j++;
      k++;
    }
  }
  while(i<n1){
    c3[k]=c1[i];
    e3[k]=e1[i];
    i++;
    k++;
  }
  return 0;