#ifndef __DINAMIC_H__
#define __DINAMIC_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo Nodo;

struct nodo{
    int num;
    struct nodo *siguiente;
};

void push();
void pop();
void contar();
void imprimir();

#endif
