#include<stdio.h>

int main() { 

int num; int i=0, b=1;

printf("Ingrese un numero: ");
scanf("%d", &num);

for(i=1;i<=num;i++)
{
	
	for(b=1;b<i+1;b++)
	{
		printf("%d", b);
	}
printf("\n");
}
return 0;
}
