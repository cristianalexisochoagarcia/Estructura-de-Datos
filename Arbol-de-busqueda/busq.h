#ifndef __BUSQ_H__
#define __BUSQ_H__

#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 100

// Estructura del nodo en un árbol de busqueda
typedef struct nodo arb;
struct nodo{
	
	int dato;
	int altura;
	
	arb *izquierdo;	//Apuntador a Subarbol "izqiuerdo"
	arb *derecho;//	Apuntador a Subarbol "derecho"
};

//Prototipos
arb *Nuevo();
arb *borrar();
arb *buscar();
arb *min();
arb *max();
arb *insertar();
int Max();
int altura();
int n_Nodos();
void menu();
void preorden();
void inorden();
void postorden();
void ver();
void error();

#endif  
