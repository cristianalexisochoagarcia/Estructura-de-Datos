#include"coladin.h"
int main(){
int opcionMenu = 0;
do{
printf("\n\t\tCOLA");
printf("\n");
printf("\n1). Insertar");
printf("\n2). Buscar");
printf("\n3). Modificar");
printf("\n4). Eliminar");
printf("\n5). imprimir");
printf("\n6). Salir");
printf("\n\n Escoja una Opcion: ");
scanf("%d", &opcionMenu);
switch(opcionMenu){
case 1:
printf("\n\n Encolar \n\n");
enqueue();
break;
case 2:
printf("\n\n Buscar un nodo en la cola \n\n");
buscarNodo();
break;
case 3:
printf("\n\n Modificar un nodo de la cola \n\n");
modificarNodo();
break;
case 4:
printf("\n\nDesencolar\n\n");
dequeue();
break;
case 5:
printf("\n\n imprimir cola \n\n");
imprimirCola();
break;
case 6:
printf("\n\n ¡¡¡¡Programa finalizado!!!");
break;
default:
printf("\n\n Opcion No Valida \n\n");
}
}while(opcionMenu != 6);
return 0;
}

