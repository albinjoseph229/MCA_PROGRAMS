#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};
typedef struct node node;
struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->next = NULL;
    if (head == NULL || ex > head->expo)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= ex)
            temp = temp->next;
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}
struct node *create(struct node *head)
{
    int n, i;
    float coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

void disp(struct node *head)
{
    if (head == NULL)
        printf("No Polynomial.");
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.0fx^%d)", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
void polyAdd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *sum = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            sum = insert(sum, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            sum = insert(sum, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            sum = insert(sum, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        sum = insert(sum, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        sum = insert(sum, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("\n*****************");
    printf("\nAdded polynomial");
    printf("\n*****************\n");
    disp(sum);
}
node *polyMult(node *head1, node *head2, node *pro)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    // Check if first or second polynomial is NULL
    if (head1 == NULL || head2 == NULL)
    {
        printf("\nNo polynomial\n");
        return;
    }
    // Multiplication of two polynomials
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            float coeffPro = ptr1->coeff * ptr2->coeff;
            int expoSum = ptr1->expo + ptr2->expo;
            pro = insert(pro, coeffPro, expoSum);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    return pro;
}
node *addLikeTerms(node *pro, node *res)
{
    node *temp1, *temp2;
    temp1 = pro;
    while (temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->expo == temp2->expo)
            {
                float coeffSum = temp1->coeff + temp2->coeff;
                res = insert(res, coeffSum, temp1->expo);
                temp1 = temp1->next;
                break;
            }
            else
            {
                res = insert(res, temp1->coeff, temp1->expo);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    res = insert(res, temp1->coeff, temp1->expo);
    return res;
}
void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    node *pro = NULL;
    node *res = NULL;
    printf("\nEnter the First polynomial");
    printf("\n========================\n");
    head1 = create(head1);
    printf("\nEnter the second polynomial");
    printf("\n=========================\n");
    head2 = create(head2);
    printf("\n******************");
    printf("\n First polynomial");
    printf("\n******************\n");
    disp(head1);
    printf("\n*******************");
    printf("\n Second polynomial");
    printf("\n*******************\n");
    disp(head2);

    polyAdd(head1, head2);
    pro = polyMult(head1, head2, pro);

    res = addLikeTerms(pro, res);
    printf("\n********");
    printf("\nProduct");
    printf("\n********\n");
    disp(res);
}
