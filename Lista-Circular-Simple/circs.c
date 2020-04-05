/**
 \file circs.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 04 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una lista circular simple:
 + insertar
 + buscar
 + modificar
 + eliminar
 + imprimir
*/
#include "circs.h"

Nodo* primero = NULL;
Nodo* ultimo = NULL;

void get(){
	Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
	printf(" Ingrese el dato que contendra la lista:  ");
	scanf("%d",&nuevo->dato);
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	printf("\n Dato ingresado con exito\n\n");
}

void buscar(){
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("  Ingrese el dato a Buscar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\nEl nodo con el dato  %d  Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			printf("\n\n Dato no encontrado\n\n");
		}
	}else{
		printf("\n La lista vacia!!!!!!!!\n\n");
	}	
}

void modificar(){
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("  Ingrese el dato a modificar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n El dato %d  Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d",&actual->dato);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			printf("\n La lista se encuentra vacia!!!!!!!!!\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia!!!!!!!!!\n\n");
	}	
}

void put(){
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	Nodo* anterior = (Nodo*)malloc(sizeof(Nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf("  Ingrese el dato a Buscar para Eliminar:");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato  %d  Encontrado", nodoBuscado);
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente  = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				printf("\nDato eliminado\n\n");		
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Dato no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia!!!!!!!!!\n\n");
	}
}

void imprimir(){
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("\n La lista se encuentra vacia!!!!!!!!!\n\n");
	}
}
