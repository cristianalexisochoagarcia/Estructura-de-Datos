#include<stdio.h>

void hanoi(int n,char A,char C,char B)
{
if(n==1)
{
printf("Mueva el bloque %d desde %c hasta %c\n",n,A,C);

}
else
{
hanoi(n-1,A,B,C); //Recursividad.
printf("Mueva el bloque %d desde %c hasta %c\n",n,A,C);
hanoi(n-1,B,C,A);
}
}




int main()
{
int n;
char A, C,B;
printf("Los torres son A B C\n");
printf("Numero de discos: ");
scanf("%d",&n); //Se cacha el valor de los discos.

if(n>3){
hanoi(n,'A','C','B'); //Las letras representan las torres.	hanoi(n-1, char origen, char detino)
return 0;
}
}
