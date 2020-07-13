

/**
 \file openhash.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 06 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Tablas hash abierta por el metodo de la division:
 + llenar de forma aleatoria
 + llenar de forma manual
 + eliminar un dato
 + mostrar tabla
*/

#include"openhash.h"


// Mensaje por ERROR
void error(){
	printf("\n\t\aERROR: Memoria insuficiente...");
	exit(1);
}
//Crea un nuevo nodo del tipo de la estructura
nodo *Nuevo(){
	nodo *q = (nodo *)malloc(sizeof(nodo));//	Asignacion de memoria	
	if(q==NULL){//	Si esta vacio	error
	error();
	}else
	return(q);
}



// Funcion hashing 
int hashing(int dato){
	return (dato % table_tam);//	Metodo de la division
}

// Inserta un nodo en  la table
nodo *insertar(int dato){
nodo *p, *q;
int key;	//	Clave
key = hashing(dato);
p = Nuevo();
q = table_Hash[key];
table_Hash[key] = p;
p -> siguiente = q;
p -> dato = dato;
return p;
}

// Suprime un nodo de la tabla 
void suprimir(int dato){
	nodo *p, *q;
	int key;
	q = 0;
	key = hashing(dato);
	p = table_Hash[key];

	while(p && !(p -> dato == dato)){		// Busca el nodo a suprimir
		q = p;
		p = p -> siguiente; 
	}
	if(!p) return;
	if(q) q -> siguiente = p -> siguiente;
	else table_Hash[key] = p -> siguiente;
	free (p);
}

// Busca un dato en la tabla 
nodo *buscar(int dato){
	nodo *p;
	p = table_Hash[hashing(dato)];
	while(p && !(p -> dato == dato)) p = p -> siguiente;
	return p;
}


// Menu
void menu(){
	printf("\n\n");
	printf("1) Llenar una tabla con datos aleatorios. \n");
	printf("2) Llenar una tabla de forma manual. \n");
	printf("3) Buscar un dato. \n");
	printf("4) Eliminar un dato. \n");
	printf("5) Ver Datos de la tabla. \n");
	printf("6) Salir. \n");
	printf("\n\nElija una opcion: \n");
}
