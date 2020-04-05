#ifndef __CIRCS_H__
#define __CIRCS_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo Nodo;
struct nodo{
	int dato;
	struct nodo* siguiente;
};


void get();
void buscar();
void modificar();
void put();
void imprimir();

#endif
