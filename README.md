# Estructura-de-Datos

/*PIRAMIDE DE NUMEROS*/
#include<stdio.h>

using namespace std;
  

int main()
{
	int num;
	int i=0, b=1;
	
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	
	for(i=1;i<=num;i++)
	{
		
		for(b=1;b<i+1;b++)
		{
			printf("%d", b);
		}
	printf("\n");
	}
	return 0;
}



/*LISTA*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct bloq{
   int valor;     
   struct bloq *siguiente;
};

typedef struct bloq *Lista; 



void get(Lista &l, int v  ); 
void pop(Lista &l, int v);
void VaciarLista(Lista &l);
int  ListaVacia(Lista l);
void MostrarLista(Lista l);
void Modificar(Lista l, int v,int n);



int ListaVacia(Lista lista)
{
   return (lista == NULL);
}

void get(Lista &lista, int valor)
{
   Lista nuevo;
   nuevo = new(struct bloq);
   nuevo->valor = valor;
   nuevo->siguiente = lista;
   lista  = nuevo;
}
 
void MostrarLista(Lista lista)
{
   Lista bloq = lista;

   if(ListaVacia(bloq)) printf("Lista vacia\n");
   else {
      while(bloq) {
         printf("%d -> ", bloq->valor);
         bloq = bloq->siguiente;
      }
      printf("\n");
   }
}
void Modificar(Lista lista, int v,int n)
{
   Lista bloq;
   int b = 0;
   bloq = lista;

   while(bloq)
   {
      if(bloq->valor == v)
      {
         bloq->valor=n;
         b=1;
         printf("Valor Modificado\n");
         MostrarLista(lista);
      }
      bloq = bloq->siguiente;
   }
   if(b== 0)
      printf("No se encontro el registro\n");

}

void pop(Lista &lista, int v)
{
   Lista bloq, anterior;
   bloq= lista;
   int b =0;

   if(lista!=NULL)
   {
      while(bloq!=NULL)
      {
         if(bloq->valor==v)
         {
            b=1;
            printf("Registro Eliminado\n");
            if(bloq==lista)
               lista = lista->siguiente;
            else
               anterior->siguiente = bloq->siguiente;
         
            delete(bloq);
            return;
         }
         anterior = bloq;
         bloq =bloq->siguiente;
      }
   }
   else
      printf(" Lista vacia..!\n");

   if(b==0 )
      printf("No se encontro el valor\n");
}



void VaciarLista(Lista &lista)
{
   Lista bloq;

   if(lista!=NULL)
   {
      while(lista!=NULL)
      {
         bloq =lista;
         lista = lista->siguiente;
         delete(bloq);
      
      }
   }
   else
      printf(" Lista vacia\n");

}



int main()
{
   Lista lista = NULL; 
   int op,x,n;
   Lista p;
  
   do
   {
      system("cls");
      printf("******-MENU-******\n\n");
      printf("1. Agregar dato\n");
      printf("2. Modificar dato\n");
      printf("3. Mostrar datos\n");
      printf("4. Eliminar dato\n");
      printf("5. Vaciar lista\n");
      printf("6. Salir\n\n");
      printf("Digite la opcion: ");
      scanf("%d",&op);
   
      switch(op)
      {
         case 1:
            do {  
               system("cls");
               printf("Digite  Cero (0) para salir\n");
               printf("Digite el dato que desea agregar:");
               scanf("%d",&x);
               if (x!=0)
                  get(lista,x);
            }while (x!=0);
         
            getch();
            break;
      
         case 2:
            MostrarLista(lista);   
            printf("\n Digite el dato que desea modificar:");
            scanf("%d",&x);      
            printf("\n Digite el dato nuevo:");
            scanf("%d",&n);   
            Modificar(lista,x,n); 
            getch();
            break;
      
         case 3:
            MostrarLista(lista);
            getch();
            break;
      
         case 4:
            MostrarLista(lista);
            printf("Digite el dato que desea eliminar:");
            scanf("%d",&x);
            pop(lista,x); 
            getch();
            break;
      
         case 5:
		             break;
      
         default:
            printf("Opcion no valida!\n");
            getch();
      }
   
   
   } while(op!=6);


   getchar();
   return 0;
}



/*PILA*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct persona{
    int ope;
    char *nombre;
    struct persona *siguiente;
};

typedef struct persona Bloq;

Bloq *inicio = NULL;	
Bloq *actual = NULL;

char* getNom();
void clearBuffer();
int getOpe();

void push();
void pop();
void Crear();
void ContarBloques();
void ImprimirPila();

int main(){
    return menu();
}

void push(){

    Bloq *bloq = (struct persona*)malloc(sizeof(struct persona));

    if(NULL == bloq){
        printf("\n Error en creacion de bloque\n");
    }

    bloq->ope = getOpe();
    clearBuffer();
    bloq->nombre=getNom();
    bloq->siguiente = inicio;
    inicio = bloq;

}

void pop(){

    if(NULL == inicio){
            printf("La pila esta vacia \n");
    }else{
        printf("\n ******-Elemento Top Removido-****** \n");
        Bloq *bloq = inicio;
        printf("\n Operador: %d ",bloq->ope);
        printf("Nombre: %s \n", bloq->nombre);

        inicio=bloq->siguiente;
        free(bloq);
    }

}

void ImprimirPila(void){

    if(NULL == inicio){
        printf("La pila esta vacia \n");
    }else{
        Bloq *bloq = inicio;
        printf("\n ******-Inicio de la Pila-****** \n");

        while(bloq != NULL)
        {
            printf("\n Ooperador: %d ",bloq->ope);
            printf("Nombre: %s \n", bloq->nombre);
            bloq = bloq->siguiente;
        }

        printf("\n ******-Final de la Pila-****** \n");

    }

}

void ContarBloques(void){
    Bloq *bloq = inicio;
    int i=0;

    while(bloq != NULL){
        i++;
        bloq = bloq->siguiente;
    }

    printf("\n Cantidad de Bloques: %d\n", i);

    return;
}

int getOpe() {
  int num;
  printf("\n Ingrese el numero de Operador: ");
  scanf("%d" , &num);
  return num;
}

char* getNom() {
  char d,*nuevo;

  int i = 0;

  nuevo = (char*) malloc(sizeof(char)*100);

  printf("\n Ingrese el nombre: ");
  while((d = getchar()) != EOF && d != '\n') {
    nuevo[i++] = d;
  }

  return nuevo;
}

void clearBuffer() {
  while(getchar() != '\n')
    ;
}

int menu() {
  char c;

  do {
    printf("\n******-MENU: pila-******");
    printf("\nHaga una seleccion:");
    printf("\n 1. push()");
    printf("\n 2. pop()");
    printf("\n 3. ImprimirPila()");
    printf("\n 4. ContarBloques()");
    printf("\n s: salir.\n");
    c = getchar();

    switch(c) {
      case '1':
          clearBuffer();
          push();
        break;
      case '2':
          clearBuffer();
          pop();
        break;
      case '3':
          clearBuffer();
          ImprimirPila();
        break;
      case '4':
          clearBuffer();
          ContarBloques();
        break;
      default:
        break;
    }
  } while(c != 's' && c != EOF);
}
        


