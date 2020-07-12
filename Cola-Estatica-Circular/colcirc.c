#include<>
#define TRUE 1
#define FALSE 0
#define MAX_ELEMENTS 1000


typedef char boolean;

typedef struct{
	int ent;
	char car;
	float flot;
	int x;
	int y;
	int ID;
	int tipo;
	char nombre[45], actividad[200], id[45];
	int tiempo, contador;
} elemento;

typedef struct{
	elemento *A;
	int frente;
	int final;
	int tamano;
} cola;

void inicializar(cola *c);
void Destroy(cola *c);
int n_Nodos(cola *c);
boolean vacia(cola *c);
boolean Queue(elemento e, cola *c);
elemento Dequeue(cola *c);
elemento Front(cola *c);
elemento Final(cola *c);
elemento Element(int n, cola *c);


void inicializar(cola *c){
	c->frente = 0;
	c->final = -1;
	c->tamano = 0;
	c->A = malloc(MAX_ELEMENTS * sizeof(elemento));
	return;
}

void Destroy(cola *c){
	c->frente = 0;
	c->final = -1;
	c->tamano = 0;
	free(c->A);
	return;
}

int n_Nodos(cola *c){
	return c->tamano;
}

boolean vacia(cola *c){
	return n_Nodos(c) == 0;
}

boolean Queue(elemento e, cola *c){
	boolean r = FALSE;
	if(n_Nodos(c) != MAX_ELEMENTS){
		c->final = (c->final + 1) % MAX_ELEMENTS;
		c->A[c->final] = e;
		c->tamano++;
		r = TRUE;
	}
	return r;
}

elemento Dequeue(cola *c){
	elemento e;
	if(!vacia(c)){
		e = c->A[c->frente];
		c->frente = (c->frente + 1) % MAX_ELEMENTS;
		c->tamano--;
	}
	return e;
}

elemento Front(cola *c){
	elemento e;
	if(!vacia(c))
		e = c->A[c->frente];
	return e;
}

elemento Final(cola *c){
	elemento e;
	if(!vacia(c))
		e = c->A[c->final];
	return e;
}

elemento Element(int n, cola *c){
	elemento e;
	if(n <= n_Nodos(c)){
		e = c->A[(c->frente + n - 1) % MAX_ELEMENTS];
	}
	return e;
}
