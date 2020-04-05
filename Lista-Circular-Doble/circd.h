
#ifndef __CIRCD_H__
#define __CIRCD_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo Nodo;
struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
};



void insertar();
void buscar();
void modificar();
void eliminar();
void imprimirPU();
void imprimirUP();

#endif
