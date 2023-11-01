#include <stdio.h>
#include <string.h>
#include <process.h>
struct emp
{
    int eno, esal, dno;
    char ename[10];
};
int i, j, n;
struct emp e[20];
void read()
{
    for (i = 0; i < n; i++)
    {
        printf("\n\tEnter Details of Employee-%d", i + 1);
        printf("\n-----------------------------------------");
        printf("\nEmployee no:");
        scanf("%d", &e[i].eno);
        printf("\nEmployee name:");
        scanf("%s", &e[i].ename);
        printf("\nEmployee salary:");
        scanf("%d", &e[i].esal);
        printf("\nDno:");
        scanf("%d", &e[i].dno);
    }
}

void search()
{
    int em;
    printf("\n Enter the employee number to search:");
    scanf("%d", &em);
    for (i = 0; i < n; i++)
    {
        if (em == e[i].eno)
        {
            printf("\n SEARCHED EMPLOYEE DETAILS:");
            printf("\n --------------------------");
            printf("\n Employee No:%d", e[i].eno);
            printf("\n Employee Name:%s", e[i].ename);
            printf("\n Employee Salary:%d", e[i].esal);
            printf("\n DNo:%d", e[i].dno);
        }
    }
}
void sortname()
{
    struct emp t;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(e[i].ename, e[j].ename) == 1)
            {
                t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    printf("\nEMPLOYEE LIST(SORTED USING NAME):");
    printf("\n---------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\nName:%s", e[i].ename);
        printf("\nEmployee No:%d", e[i].eno);
        printf("\nEmployee Dno:%d", e[i].dno);
        printf("\nEmployee Salary:%d\n", e[i].esal);
    }
}
void sortsal()
{
    struct emp t;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (e[i].esal > e[j].esal)
            {
                t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    printf("\nEMPLOYEE LIST(SORTED USING SALARY) :");
    printf("\n-----------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\nEmployee Name:%s", e[i].ename);
        printf("\nEmployee No:%d", e[i].eno);
        printf("\nDno:%d", e[i].dno);
        printf("\nEmployee Salary:%d\n", e[i].esal);
    }
}
void delet(int en)
{
    if (n == 0)
        printf("\n No Employee!!!");
    else
    {
        printf("\nLIST OF EMPLOYEES");
        printf("\n-----------------");
        for (i = 0; i < n; i++)
        {
            if (en == e[i].eno)
            {
                for (j = i; j < n - 1; j++)
                    e[j] = e[j + 1];
            }
        }
        n--;
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEmployee No:%d", e[i].eno);
        printf("\nEmployee Name:%s", e[i].ename);
        printf("\nDno:%d", e[i].dno);
        printf("\nEmployee Salary:%d", e[i].esal);
    }
}
void main()
{
    int ch, ch1, en;
    printf("\n Enter number of employees:");
    scanf("%d", &n);
    read(n);
    do
    {
        printf("\n------\n MENU\n-------\n 1.Search\n 2.Sort\n 3.Delete\n 4.Exit\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            search();
            break;
        case 2:
            printf("\nSorting:");
            printf("\n---------");
            printf("\n 1.Sort by name\n 2.Sort by salary\n Enter your choice: ");
            scanf("%d", &ch1);
            switch (ch1)
            {
            case 1:
                sortname();
                break;
            case 2:
                sortsal();
                break;
            }
            break;
        case 3:
            printf("\nEnter eno to delete:");
            scanf("%d", &en);
            delet(en);

            break;
        case 4:
            exit(0);
        }
    } while (1);
}
