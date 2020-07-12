/**
 \file din.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 06 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Cola dinamica:
 + insertar
 + eliminar
 + imprimir
*/

/**

El programa corrio en devc++ con .c, sin embargo
al compìlar en la terminal de linux no corre

*/

#include "din.h"

struct nodo *frente = NULL;
struct nodo *siguiente = NULL;


void ponerencola(int valor)
{// Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    struct nodo* nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (siguiente == NULL)
    {
        frente = nuevo;
        siguiente = nuevo;
    }
    else
    {
        siguiente->siguiente = nuevo;
        siguiente = siguiente->siguiente;
    }
}

void mostrar()
{
    struct nodo *temporal;
    temporal = frente;
    printf("\n");
    while (temporal != NULL)
    {
        printf("%d\t", temporal->dato);
        temporal = temporal->siguiente;
    }
}

void quitardelacola()
{
    if (frente == NULL)
    {
        printf("\n\nla cola esta vacia \n");
    }
    else
    {
        struct nodo *temporal;
        temporal = frente;
        frente = frente->siguiente;
        printf("\n\n%d quitado de la cola", temporal->dato);
        free(temporal);
    }
}

