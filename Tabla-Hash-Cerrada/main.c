
#include"closehash.h"


int main(){
	int op, s, ky, dt;

	printf("Tabla hash cerrada. \n");
	printf("Ingrese el tamaño de la tabla: ");
	scanf("%d", &s);

	int nodoIdx = -1;
	nodo_t* nodo = NULL;

	hashTable_t* table = newHashTable(s);

	while(op != 5){
		printf("1) Agregar dato. \n");
		printf("2) Buscar dato. \n");
		printf("3) Eliminar dato. \n");
		printf("4) Ver tabla. \n");
		printf("5) Salir. \n");
		printf("\n\nSeleccione una opcion: ");
		scanf("%d", &op);

		switch(op){
			case(1):
				printf("\nIngrese el dato: ");
				scanf("%d", &dt);
				printf("Ingrese un numero: ");
				scanf("%d", &ky);

				ht_insert(table, dt, ky);
			break;

			case(2):
				printf("\nIngrese el dato a buscar: ");
				scanf("%d", &dt);

				nodoIdx = ht_search(table, dt);
				if(nodoIdx != -1){
					nodo = table->array[nodoIdx];
					printf("Elemento: (%d,%d) \n", nodo->key, nodo->dato);
				}else{
					printf("No se encontro.\n");
				}
			break;

			case(3):
				printf("\nIngrese el dato a eliminar: ");
				scanf("%d", &dt);

				nodoIdx = ht_search(table, dt);
				if(nodoIdx != -1){
					nodo = table->array[nodoIdx];
					ht_remove(table, dt);
					printf("Elemento eliminado");
				}else{
					printf("No existe el dato.\n");
				}				
			break;

			case(4):
				ht_display(table);
			break;

			case(5):
			freeHashTable(table);
			printf("Programa finalizado!!!!");
			break;

			default: 
				printf("Ingrese una opcion valida. \n");
			break;
		}
	}


	return 0;
}


