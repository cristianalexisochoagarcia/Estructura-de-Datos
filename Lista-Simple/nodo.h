#ifndef __NODO_H__
#define __NODO_H__

#include<stdio.h>
#include<stdlib.h>
typedef struct nodo Nodo;

struct nodo{
        int dato;
        struct nodo* siguiente;
};


void insertar();
void buscar();
void modificar();
void eliminar();
void imprimir();
#endif
