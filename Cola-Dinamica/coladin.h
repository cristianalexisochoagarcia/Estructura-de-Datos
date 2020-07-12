#ifndef __COLADIN_H__
#define __COLADIN_H__


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
int dato;
struct nodo* siguiente;
} nodo;


void enqueue();// encolar
void buscarNodo();
void modificarNodo();
void dequeue();// desencolar
void imprimirCola();

#endif
