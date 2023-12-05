#include <stdio.h>
struct poly
{
  int coe;
  int ex;
};
int main()
{
  int i, j, n1, n2, k = 0;
  struct poly p1[10], p2[10], p3[10];
  printf("enter the no of terms: ");
  scanf("%d", &n1);
  printf("enter the polynomial 1\n");
  for (i = 0; i < n1; i++)
  {
    printf("enter the coeffient: ");
    scanf("%d", &p1[i].coe);
    printf("enter the exponent: ");
    scanf("%d", &p1[i].ex);
  }
  printf("enter the no of terms: ");
  scanf("%d", &n2);
  printf("enter the polynomial 2\n");
  for (i = 0; i < n2; i++)
  {
    printf("enter the coeffient: ");
    scanf("%d", &p2[i].coe);
    printf("enter the exponent: ");
    scanf("%d", &p2[i].ex);
  }
  i = j = 0;
  while (i < n1 && j < n2)
  {
    if (p1[i].ex == p2[j].ex)
    {
      p3[k].coe = p1[i].coe + p2[i].coe;
      p3[k].ex = p1[i].ex;
      i++;
      j++;
      k++;
    }
    else if (p1[i].ex > p2[j].ex)
    {
      p3[k].coe = p1[i].coe;
      p3[k].ex = p1[i].ex;
      i++;
      k++;
    }
    else
    {
      p3[k].coe = p2[j].coe;
      p3[k].ex = p2[j].ex;
      j++;
      k++;
    }
  }
  while (i < n1)
  {
    p3[k].coe = p1[i].coe;
    p3[k].ex = p1[i].ex;
    i++;
    k++;
  }
  while (j < n2)
  {
    p3[k].coe = p2[j].coe;
    p3[k].ex = p2[j].ex;
    j++;
    k++;
  }
  printf("\n POLYNOMIALS ADDITION");
  printf("\n---------------------------------\n");
  for (i = 0; i < k; i++)
  {
    printf("%dx^%d", p3[i].coe, p3[i].ex);
    if (i < k - 1)
    {
      printf(" + ");
    }
  }
  return 0;
}
