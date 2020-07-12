#ifndef __DIN_H__
#define __DIN_H__

#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};



void mostrar();
void ponerencola(int);
void quitardelacola();

#endif
