 
#include"hanoi.h"

int main()
{
	int n_fil=3, col, *tablero = NULL;
	int f, c, disc=1, ultNum;
 
 
	printf( "Indique el numero de discos: " );
	scanf( "%i", &col );
 
 
	tablero = (int *)malloc( sizeof(int)*n_fil*col );
 
 
	// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
	for( f=0; f < n_fil; f++ )
		for( c=col-1; c >= 0; c-- )
			if( f==0 )
			{
				tablero[col*f+c] = disc;
				disc+=2;
			}
			else
				tablero[col*f+c] = 0;
 
	ultNum = disc;
 
	// Se imprime el tablero antes de iniciar ningún movimiento:
	system("cls");
	imprime( tablero, n_fil, col, ultNum );
        usleep(1000);//system("sleep 1");
 
 
	// Se llama a hanoi para comenzar "la partida":
	hanoi( tablero, n_fil, col, col, ultNum, 0, 1, 2 );
}

