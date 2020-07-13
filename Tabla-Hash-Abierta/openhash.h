#ifndef __OPENHASH_H__
#define __OPENHASH_H__

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

// Estructura de los nodos
typedef struct nodos nodo;
struct nodos{	
	int dato; 			//Contenido
	nodo *siguiente;
};

nodo **table_Hash;		//	Tabla hash
int table_tam;				//	Tamaño de la tabla

void menu();
nodo *buscar();
void suprimir();
nodo *insertar();
int hashing();
void error();
#endif
