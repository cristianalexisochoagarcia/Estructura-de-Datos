
/**
 \file closehash.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 04 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Tabla Hash Cerrada:
 + Agregar 
 + buscar
 + eliminar
 + Ver tabla
*/

#include "closehash.h"

nodo_t* newnodo(int key, int dato){
	nodo_t* result = malloc(sizeof(nodo_t));
	result->key = key;
	result->dato = dato;

	return result;
}

void freenodo(nodo_t* nodo){
	if(nodo != NULL)
		free(nodo);
}


hashTable_t* newHashTable(int size){
	hashTable_t* result = malloc(sizeof(hashTable_t));
	result->count = 0;
	result->size = size;
	result->deletednodo = newnodo(-1,-1);

	result->array = malloc(sizeof(nodo_t*)*size);

	return result;
}

void freeHashTable(hashTable_t* table){
	int i;
	if(table != NULL){
		for(i=0;i<table->size;i++){
			nodo_t* nodo = table->array[i];
			if(nodo != NULL && nodo != table->deletednodo)
				freenodo(nodo);
		}
		free(table->array);
		freenodo(table->deletednodo);
		free(table);
	}
}

int ht_hasnodo(hashTable_t* table, int idx){
	return table->array[idx] != NULL && table->array[idx] != table->deletednodo;
}

int ht_isFull(hashTable_t* table){
	return table->count == table->size;
}

int hashing(int key, int size){
	return key % size;
}

void ht_display(hashTable_t* table){
	int i;
	for(i=0;i<table->size;i++){
		if(ht_hasnodo(table, i)){
			nodo_t* nodo = table->array[i];
			printf("[%d] (%d,%d) \n", i, nodo->key, nodo->dato);
		}else{
			printf("[%d] vacio \n", i);
		}
	}
	printf("\n");
}

int ht_insert(hashTable_t* table, int key, int dato){
	int result = 0;
	if(ht_isFull(table)){
		printf("La tabla esta llena.\n");
	}else{
		nodo_t* nodo = newnodo(key, dato);
		int idx = hashing(key, table->size);

		while(ht_hasnodo(table, idx))
			idx = hashing(idx + 1, table->size);
		table->array[idx] = nodo;
		table->count++;
	}

	return result;
}

int ht_search(hashTable_t* table, int key){
	int result = -1;
	int idx = hashing(key, table->size);
	int counter = table->size;

	while(table->array[idx] != NULL && counter > 0){
		if(table->array[idx]->key == key){
			result = idx;
			break;
		}
		counter--;
		idx = hashing(idx + 1, table->size);
	}

	return result;
}

nodo_t* ht_remove(hashTable_t* table, int key){
	nodo_t* result = NULL;
	int idx = ht_search(table, key);

	if(idx != -1){
		result = table->array[idx];
		table->array[idx] = table->deletednodo;
		table->count--;
	}

	return result; 
}


