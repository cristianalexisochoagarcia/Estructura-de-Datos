#include"estatic.h"
	
int main(){
	int opcion;
	do{
		system("cls");
		
		printf("****Pila Estatica****\n\nMENU\n\n");
		printf("1. Ingresar datos\n\n");
		printf("2. Eliminar datos\n\n");
		printf("3. Pila vacia?\n\n");
		printf("4. Mostrar pila\n\n");
		printf("5. Salir\n\n");
		printf("\n\n Escoja una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				insertar();
				break;
			case 2:
				eliminar();
				break;
			case 3:
				pilavacia();
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("\n\n...Programa finalizado...\n\n");
				break;
			default:
				printf("Opcion no valida\n\n");
				system("PAUSE");
		}
	
	}while(opcion !=5 );
	
	return 0;
}
