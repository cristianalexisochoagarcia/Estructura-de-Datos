
/**
 \file circd.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 04 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una lista circular doble:
 + insertar
 + buscar
 + modificar
 + eliminar
 + imprimirPU (del Primero al Ultimo)
 + imprimirUP (del Ultimo al Primero)
*/
#include "circd.h"

Nodo* primero = NULL;
Nodo* ultimo = NULL;


void insertar(){
	Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		nuevo->atras = ultimo;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	printf("\n Dato ingresado con exito\n\n");
}

void buscar(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato  %d  Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n Dato no encontrado\n\n");
		}
	}else{
		printf("\n La lista vacia!!!!!!!!\n\n");
	}	
}

void modificar(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato a modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d", &actual->dato);
				printf("\n Nodo Modificado con exito\n\n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\nDato no Encontrado\n\n");
		}
	}else{
		printf("\nLa lista vacia!!!!!!!!\n\n");
	}		
}
          

void eliminar(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	Nodo* anterior = (Nodo*) malloc(sizeof(Nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato  %d  Encontrado", nodoBuscado);
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = ultimo;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->atras = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Dato eliminado\n\n");
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n Dato no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\nLa lista vacia!!!!!!!!\n\n");
	}
}

void imprimirPU(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual != primero);
	}else{
		printf("\nLa lista vacia!!!!!!!!\n\n");
	}
}

void imprimirUP(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = ultimo;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->atras;
		}while(actual != ultimo);
	}else{
		printf("\nLa lista vacia!!!!!!!!\n\n");
	}
}
