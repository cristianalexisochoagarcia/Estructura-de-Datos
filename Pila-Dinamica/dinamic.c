
#include"dinamic.h"

/**
 \file dinamic.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 04 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Pila Dinamica:
 + insertar	(push)
 + eliminar
 + imprimir
 + contar
*/

Nodo *inicio = NULL;
Nodo *actual = NULL;

void push(){
	
  int num;
  printf("\n Ingrese el numero de Operador: ");
  scanf("%d" , &num);

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));

    if(NULL == nuevo){
        printf("\n Error en creacion de bloque\n");
    }

    nuevo->num = num;
    nuevo->siguiente = inicio;
    inicio = nuevo;

}

void pop(){

    if(inicio==NULL){
            printf("La pila esta vacia \n");
    }else{
        printf("\n ****-Elemento Top Removido-**** \n");
        Nodo *nuevo = inicio;
        printf("\n Operador: %d ",nuevo->num);
        inicio=nuevo->siguiente;
        free(nuevo);
    }

}

void imprimir(void){

    if(inicio==NULL){
        printf("La pila esta vacia \n");
    }else{
        Nodo *nuevo = inicio;
        printf("\n ****-Inicio de la Pila-**** \n");

        while(nuevo != NULL)
        {
            printf("\n Operador: %d ",nuevo->num);
            nuevo = nuevo->siguiente;
        }

        printf("\n ****-Final de la Pila-**** \n");

    }

}

void contar(void){
    Nodo *nuevo = inicio;
    int i=0;

    while(nuevo != NULL){
        i++;
        nuevo = nuevo->siguiente;
    }

    printf("\n Cantidad de Datos: %d\n", i);
}
