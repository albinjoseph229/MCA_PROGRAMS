#include <stdio.h>
int main()
{
    int j,i;
    int sparse[4][5] =
        {
            {0, 4, 0, 0, 0},
            {0, 3, 4, 6, 0},
            {1, 0, 3, 4, 0},
            {3, 2, 1, 8, 0}
        };

    int size = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (sparse[i][j] != 0)
            {
                size++;
            }
        }
    }
    int compact[3][size];
    int k=0;
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<5;j++)
            {
                if(sparse[i][j]!=0)
                {
                    compact[0][k]=i;
                    compact[1][k]=j;
                    compact[2][k]=sparse[i][j];
                    k++;
                }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<size;j++){
                printf("%d ",compact[i][j]);
                
            }
            printf("\n");
        }
    }
    return 0;
}
