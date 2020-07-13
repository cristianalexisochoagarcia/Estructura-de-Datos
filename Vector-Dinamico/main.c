#include <stdio.h>
#include <stdlib.h>
int main()
{
    int fil, col, i=0, j=0;
    fil=col=0;
    int **m = NULL;

    printf("Digite el nmero de filas: ");
    scanf("%i",&fil);

    printf("Digite el número de columnas: ");
    scanf("%i",&col);

    m = (int **)malloc(sizeof(int*)*fil);
    for(i=0;i<fil;i++)
        m[i]=(int *)malloc(sizeof(int)*col);

    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("[%i][%i] = ",i,j);
            scanf("%i",&m[i][j]);
        }
    }

    printf("\n");

    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
        {
            printf(" %i\t",*(*(m+i)+j));
        }
        printf("\n");
    }

    printf("\n");

    free(m);

    return 0;
}
