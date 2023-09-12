#include<stdio.h>
struct poly{
    int coeff;
    int exp;
};
int main()
{
    int i,num;
    struct poly p[10];
    printf("enter the no of terms \n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("enter the coeff\n");
        scanf("%d",&p[i].coeff);
        printf("enter the degree\n");
        scanf("%d",&p[i].exp);
    }
    printf("the entered polynomial is :");
    for(i=0;i<num;i++)
    {
        printf("%dx^%d+",p[i].coeff,p[i].exp);
    }
    return 0;
}