
#include"circd.h"
int main(){
	int opc = 0;
	do{
		printf("\n-------------------------------------");
		printf("\n********Lista circular doble********");
		printf("\n 1. Insertar");
		printf("\n 2. Buscar");  
		printf("\n 3. Modificar");
		printf("\n 4. Elimiar");
		printf("\n 5. Imprimir del primero al ultimo");
		printf("\n 6. Imprimir del ultimo al primero");
		printf("\n 7. Salir");        
		printf("\n-------------------------------------");
		printf("\n\n Escoja una opcion: ");
		
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("\n\n Dato ingresado en la lista\n\n");
				insertar();
				break;
			case 2:
				printf("\n\n Busca dato en la lista\n\n");
				buscar();
				break;	
			case 3:
				printf("\n\n Modificar dato de la lista\n\n");
				modificar();
				break;
			case 4:
				printf("\n\n Dato eliminado de la lista\n\n");
				eliminar();
				break;
			case 5:
				printf("\n\n Imprimir lista del primero al ultimo\n\n");
				imprimirPU();
				break;
			case 6:
				printf("\n\n Imprimir lista del ultimo al primero\n\n");
				imprimirUP();
				break;
			case 7:
				printf("\n\n...Programa finalizado...\n\n");
				break;
			default:
				printf("\n\n¡¡¡¡¡Opcion no Valida!!!!!\n\n");	
		}
	}while(opc != 7);
	return 0;
}
