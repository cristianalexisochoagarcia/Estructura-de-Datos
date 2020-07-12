/**
 \file coladin.c
 \author Ochoa Garcia Cristian Alexis
 \version 1.0
 \date 01 / 06 /2020
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una Cola Dinamica:
 + insertar
 + buscar
 + modificar
 + eliminar
 + imprimir
*/

#include "coladin.h"

nodo* primero = NULL;
nodo* ultimo = NULL;

void enqueue(){
nodo* nuevo = (nodo*) malloc(sizeof(nodo));
printf(" Ingrese el dato que contendra el nuevo Nodo: ");
scanf("%d", &nuevo->dato);
if(primero == NULL){
primero = nuevo;
primero->siguiente = NULL;
ultimo = nuevo;
}else{
ultimo->siguiente = nuevo;
nuevo->siguiente = NULL;
ultimo = nuevo;
}
printf("\n Nodo ingresado con exito\n\n");
}

void buscarNodo(){
nodo* actual = (nodo*) malloc(sizeof(nodo));
actual = primero;
int nodoBuscado = 0, encontrado = 0;
printf(" Ingrese el valor del Nodo a Buscar: ");
scanf("%d", &nodoBuscado);
if(primero != NULL){

while(actual != NULL && encontrado != 1){

if(actual->dato == nodoBuscado){
printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
encontrado = 1;
}

actual = actual->siguiente;
}
if(encontrado==0){
printf("\n Nodo no Encontrado\n\n");
}
}else{
printf("\n La cola no existe\n\n");
}
}

void modificarNodo(){
nodo* actual = (nodo*) malloc(sizeof(nodo));
actual = primero;
int nodoBuscado = 0, encontrado = 0;
printf(" Ingrese el valor del Nodo a Buscar para Modificar: ");
scanf("%d", &nodoBuscado);
if(primero != NULL){

while(actual != NULL && encontrado != 1){

if(actual->dato == nodoBuscado){
printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
printf("\n Ingrese el nuevo dato para este Nodo: ");
scanf("%d" , &actual->dato);
printf("\n Nodo Modificado con exito\n\n");
encontrado = 1;
}

actual = actual->siguiente;
}
if(encontrado==0){
printf("\n Nodo no Encontrado\n\n");
}
}else{
printf("\n La cola no existe\n\n");
}
}

void dequeue(){
nodo* actual = (nodo*) malloc(sizeof(nodo));
actual = primero;
nodo* anterior = (nodo*) malloc(sizeof(nodo));
anterior = NULL;
int nodoBuscado = 0, encontrado = 0;
printf(" Ingrese el valor del Nodo a Buscar para Eliminar: ");
scanf("%d", &nodoBuscado);
if(primero != NULL){

while(actual != NULL && encontrado != 1){

if(actual->dato == nodoBuscado){
if(actual == primero){
primero = primero->siguiente;
}else if(actual == ultimo){
anterior->siguiente = NULL;
ultimo = anterior;
}else{
anterior->siguiente = actual->siguiente;
}
printf("\n El Nodo eliminado con exito\n\n");
encontrado = 1;
}
anterior = actual;
actual = actual->siguiente;
}
if(encontrado==0){
printf("\n Nodo no Encontrado\n\n");
}else{
free(anterior);
}
}else{
printf("\n La cola no existe\n\n");
}
}

void imprimirCola(){
nodo* actual = (nodo*) malloc(sizeof(nodo));
actual = primero;
if(primero != NULL){

while(actual != NULL){
printf("\n %d", actual->dato);
actual = actual->siguiente;
}
}else{
printf("\n La cola no existe\n\n");
}
}
