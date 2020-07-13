#include<stdio.h>
#include<stdlib.h>

int main()
{
    int cantidad;
    int i=0;
    int *p;

    printf("Cantidad de valores del array: ");
    scanf("%d",&cantidad);

    p = (int*)malloc(sizeof(int)*cantidad);

    for(i=0;i<cantidad;i++)
    {
        printf("Numero: ");
        scanf("%d",&p[i]);
    }

    //Visualizar Datos
    for(i=0;i<cantidad;i++)
    {
        printf(" %d",p[i]);
    }

    return 0;
}
