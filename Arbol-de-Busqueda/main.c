#include"busq.h"

int main(){
	int n,i,dato, op;
	arb *p = NULL,*x; /* Árbol Vacío */
	while(1){
	menu();	
	scanf("%d", &op);
	switch(op){
	case 1:
	printf("Numero de nodos del arbol: ");
	scanf("%d",&n);
	n = abs(n);//	Devuelve el valor aabsouto de (n)
		
	for(i = 0;i < n;i++) {
	printf("\n\tElemento No. %d: ",i + 1);
	dato = rand()%MAX;
	printf("%d",dato);
	p = insertar(dato,p);
	}
	break;
	case 2:
	printf("Numero de nodos del arbol: ");
	scanf("%d",&n);
	n = abs(n);//Devuelve el vaor absoluto de (n)
	
	for(i = 0;i < n;i++) {
	printf("\n\tdato No. %d: ",i + 1);
	scanf("%d",&dato);
	p = insertar(dato,p);//	Carga primer dato
}
	break;
	case 3:
	printf("Arbol de busqueda");
	ver(0,p);
	break;
	
	case 4:
	printf("\n\nRecorrido en Pre-Orden:");
	preorden(p);
	printf("\nRecorrido en Orden:");
	inorden(p);
	printf("\nRecorrido en Post-Orden:");
	postorden(p);
	break;
	
	case 5:
	printf("\n\tDato a Buscar: ");
	scanf("%d",&dato);
	x = buscar(dato,p);
	if(x != NULL) printf("Se encontro el dato %d",dato);
	else printf("No se encontro el dato %d",dato);	
	break;

	case 6:
	x = min(p);
	printf("\n\n\tMinimo = %d",x -> dato);
	x = max(p);
	printf("\n\n\tMaximo = %d",x -> dato);
	break;


	case 7:
	printf("\n\n\tNodos : %d\n\n\tAltura =%d",n_Nodos(p),altura(p));
	break;

	
	case 8:
	borrar(p); /* Borra el árbol */
	printf("Progarma finalizado!!!!");
	break;
}

}
