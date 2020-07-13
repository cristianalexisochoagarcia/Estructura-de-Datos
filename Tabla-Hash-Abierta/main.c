

/**
 \file openhash.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 06 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Tablas hash abierta por el metodo de la division:
 + llenar de forma aleatoria
 + llenar de forma manual
 + eliminar un dato
 + mostrar tabla
*/

#include"openhash.h"

int main(){
	int i, op, *a, max, dato;
	nodo *p;
	table_tam = 30;
	max = 0;

	while(1){
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				for(i=max-1;i>=0;i--) suprimir(a[i]);
					printf("\n\nIntroduce el numero de datos: ");
					scanf("%d", &max);
					if((a = malloc(max * sizeof(*a))) == 0){
						printf("Memoria Insuficiente...\n");
						exit(1);
					}
					if((table_Hash = malloc(table_tam *sizeof(nodo *))) == 0){
						perror("Memoria Insuficiente...\n");
						exit(1);
					}
					for(i=1;i<=max;i++){
						a[i] = rand();
						printf("\n\nDato %d : %d", i, a[i]);
						insertar(a[i]);
					}
				
					break;
			case 2:
				printf("\n\nIntroduce el numero de datos: ");
					scanf("%d", &max);
					if((a = malloc(max * sizeof(*a))) == 0){
						perror("Memoria Insuficiente...\n");
						exit(1);
					}
					if((table_Hash = malloc(table_tam *sizeof(nodo *))) == 0){
						perror("Memoria Insuficiente...\n");
						exit(1);
					}
					for(i=1;i<=max;i++){
						printf("\n\nDato %d : ", i);
						scanf("%d", &a[i]);
						insertar(a[i]);
					}
					
					break;
			case 3:
				printf("\n\nIntroduce el dato a buscar: ");
				scanf("%d", &dato);
				p = buscar(dato);
				if(p) printf("\n\nDato %d encontrado.", p -> dato);
				else printf("\n\n\tDato %d no encontrado!!!.", dato);
			
				break;
			case 4:
				printf("\n\nIntroduce el dato a suprimir: ");
				scanf("%d", &dato);
				p = buscar(dato);
				if(p){
					suprimir(dato);
					printf("\n\nDato %d se elimino!!!.", dato);
				}
				else printf("\n\n\tDato %d no encontrado.", dato);
			
				break;
			case 5:
				printf("\n\nDato:  Hash :  Dato\n\n");
				for(i=max;i>=0;i--){
					p = buscar(a[i]);
					if(p) printf("\n\nDato: %02d : %d", hashing(p -> dato), p -> dato);
				}
				break;
			case 6: 
				for(i=max-1;i>=0;i--) suprimir(a[i]);
				exit(1);
				break;
		}
	}
}
