
#ifndef __CLOSEHASH_H__
#define __CLOSEHASH_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	int key;
}nodo_t;


typedef struct hashTable{
	int count;
	int size;

	nodo_t* deletednodo;
	nodo_t** array;
}hashTable_t;

nodo_t* newnodo();
void freenodo();
void freeHashTable();
int ht_hasnodo();
int ht_isFull();
int hashing();
void ht_display();
int ht_insert();
int ht_search();
nodo_t* ht_remove();
hashTable_t* newHashTable();


#endif
