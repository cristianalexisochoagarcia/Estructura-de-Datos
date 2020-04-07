#include"dinamic.h"

int main(){
	
	 int opc=0;
	  
  do {
    printf("\n******-MENU: pila-******");
    printf("\nHaga una seleccion:");
    printf("\n 1. Insertar");
    printf("\n 2. Eliminar");
    printf("\n 3. Imprimir");
    printf("\n 4. Contar Datos");
    printf("\n 5. Salir.\n\n");
    printf("\n\n Escoja una opcion\n\n");
    scanf("%d", &opc);

    switch(opc) {
      case 1:
          push();
        break;
      case 2:
          pop();
        break;
      case 3:
          imprimir();
        break;
      case 4:
          contar();
        break;
      case 5:
	      printf("\n\n...Programa finalizado...\n\n");
		break;
		default:
		  printf("\n\n¡¡¡¡¡Opcion no Valida!!!!!\n\n");	
		}
	}while(opc!= 5);
	return 0;
}
