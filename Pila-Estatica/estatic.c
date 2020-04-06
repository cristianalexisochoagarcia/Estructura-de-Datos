/**
 \file estatic.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 04 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Pila Estatica de tamaño 5:
 + insertar
 + eliminar
 + verificar si se encuestra vacia
 + imprimir
*/


#include "estatic.h"

int pila[TAM], cabeza=-1;

void insertar(){
	if(cabeza<4){  //Si pila no esta llena
		printf("Introduzca el valor a meter a la pila: ");
		printf("\n->");
		scanf("%d", &pila[cabeza+1]);
		cabeza++;
		printf("El valor se ha introducido correctamente\n\n");
		system("PAUSE");
	}
	else{
		printf("Imposible meter datos, la pila esta llena\n\n");
		system("PAUSE");
	}
}

void eliminar(){
	if(cabeza>-1){ //Si pila esta vacia
		cabeza--;
		
		printf("Se ha eliminado el dato de la pila\n\nEl valor estimaod es %d\n\n", pila[cabeza+1]);
		system("PAUSE");
	}
	else{
		printf("Imposible sacar datos, la pila esta vacia\n\n");
		system("PAUSE");
	}
}

void pilavacia(){
	if(cabeza==-1){
		printf("La pila esta vacia\n\n");
		system("PAUSE");
	}
	else{
		printf("La pila NO esta vacia\n\n");
		system("PAUSE");
	}
}

void imprimir(){
	int a=0;
	if(cabeza>-1){	
		printf("\t->");
	
		for(a=cabeza;a>-1;a--){
			printf(" %d , ", pila[a]);
		}
		
		system("PAUSE");
		
	}
	else{
		printf("La pila esta vacia\n\n");
		system("PAUSE");
	}
}
