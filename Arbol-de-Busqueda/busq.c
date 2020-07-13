/**
 \file busq.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 06 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de un Arbol de busqueda:
 
 + arb *Nuevo();
 + arb *borrar();
 + arb *buscar();
 + arb *min();
 + arb *max();
 + arb *insertar();
 + int Max();
 + int altura();
 + int n_Nodos();
 + void menu();
 + void preorden();
 + void inorden();
 + void postorden();
 + void ver();
 + void error();
*/

#include "busq.h"

//	Mensaje de ERROR 
void error(){
	printf("\n\t\aERROR: Memoria insuficiente...");
	exit(1);//	Error
}

//	Crea un nuevo nodo del tipo de la estructura 
arb *Nuevo(){
	arb *x = (arb *)malloc(sizeof(arb));
	if(!x){
	error(); //Error al asignar memoria
	}
	else{
	return(x);
	}
}


int n_Nodos(arb *p){
	int numer;
	if(p == NULL){
	return;
	}
	else{
		numer=n_Nodos(p -> izquierdo) + 1 + n_Nodos(p -> derecho);
	}
	return(numer);
}

//	Borra todo el árbol arb 
arb *borrar(arb *p){
	if(p == NULL){
	return;
	}
	else{
	borrar(p -> izquierdo);
	borrar(p -> derecho);
	free(p);//	libera memoria
	}
	return(NULL);
}

//	Busca un dato en el árbol 
arb *buscar(int dato, arb *p) {
	if(p == NULL){
	return(NULL);//	Arbol vacio
	}
	if(dato < p -> dato) {//	Si dato es menor que p
	return(buscar(dato, p -> izquierdo));//	Buscar en Subarbol izquierdo
	}
    else if(dato > p -> dato){//	Si no dato es mayor que "p"
	return(buscar(dato, p -> derecho));//	Buscar en Subarbol derecho
	}
	return(p);
}



/* Busca el mínimo en el árbol */
arb *min(arb *p) {
	if(p == NULL){
	return(NULL);
	}
	else if(p -> izquierdo == NULL){
	return(p);
	}
	else{	
	return(min( p -> izquierdo ));
	}
}

/* Busca el máximo en el árbol */
arb *max(arb *p) {
	if(p != NULL){ //Si "p" No esta vacio
	while(p -> derecho != NULL) // Mientras "p" No este vacia
	p = p -> derecho;	
	return(p);
	}
}

// Calcula la altura del árbol 
int altura(arb *p){
	if(p == NULL ){
	return;//Arbol vacio
	}
	else{
	return(p -> altura);
	}

	return(altura);
}


// Regresa el máximo entre
int Max(int a, int b) {
	if(a>b){//Si "a" es mayor que "b"
		
	return(a);//Regresa "a"
}
}

// Recorre el árbol en Pre-Orden
void preorden(arb *p){
	if(p == NULL){
	return;//	Si  No esta vacia
	} 
 else{
	printf("%d ",p->dato);//	Recorre primero por la Raiz
	preorden(p -> izquierdo);//	Recorre por hijo izquierda
	preorden(p -> derecho);//	Recorrido por hijo derecho
}
}
//Imprime en orden Simetrico(hijo izquierdo - Raiz - hijo derecho
void inorden(arb *p){
	if(p == NULL){//	Si arbol esta vacio
	return;
	}
	else{
	inorden(p -> izquierdo);//	Inicia Recorrido por el hijo izquierdo
	printf("%d ",p -> dato);//	Pasa por Raiz
	inorden(p -> derecho);//	Termina Recorrido por el hijo derecho
	}	
}



// Recorre el árbol en Post-Orden 
void postorden(arb *p){
	if(p == NULL){
	return;//	Si "p" No esta vacio
	}
	else{
	postorden(p -> izquierdo);// Recorrido inicia en hijo izquierdo
	postorden(p -> derecho);//	Reccorrido continua con hijo derecho
	printf("%d ",p -> dato);// Termina con la Raiz
	}
}

//Inserta un dato en el árbol p
arb *insertar(int dato, arb *p){
	
	if(p == NULL) {//	Si arbol esta vacio
	p = Nuevo();//Se Crea Nuevo espacio
	p -> dato = dato; 
	p -> altura = 0;
	p -> izquierdo = NULL;
	p -> derecho = NULL;
	}
	else if(dato < p->dato) {//	Si el dato es menor que el  valor de la raiz
	p -> izquierdo = insertar(dato, p -> izquierdo);//	Insertamos en el hijo izquierdo
	}	//return(p)
	else if(dato > p->dato) {//	Si el dato es mayor a la raiz
	p -> derecho = insertar(dato, p -> derecho);//	Insertamos en la derecha
	}
	p -> altura = Max(altura(p -> izquierdo), altura(p -> derecho)) + 1;//Altura del arbol
	return(p);
}



void menu(){
	printf("\n\n\n\tOperaciones con Arboles arb");
	printf("\n\nA)	Llenar un arbol de forma aleatoria");
	printf("\n\nB)	Llenar un arbol de forma manual");
	printf("\n\nC)	Mostrar arbol");
	printf("\n\nD)	Mostrar Recorridos");
	printf("\n\nE)	Buscar un dato");
	printf("\n\nF)	Minimo y Maximo");
	printf("\n\nG)	Contar Nodos y Altura");
	printf("\n\nH)	Borrar un nodo");
	printf("\n\nI)	Salir");
	printf("\n\nElija una Opcion : ");
}


void ver(int cont,arb *p){
	int i;
	if(p ==NULL){//	Si el arbol esta vacio
	return;
	}	
	else{ 
	ver(cont + 1,p -> derecho);// Dejamos una sangria a cont	Imprimimos empezando por el hijo derecho
	printf("\n");
	for(i = 0;i < cont;i++) printf("   ");
	printf("%d\n",p -> dato);//	Imprimir el hijo derecho hasta la raiz 
	ver(cont + 1,p -> izquierdo);//	Imprimir ahora el hijo izquierdo
	}
}

