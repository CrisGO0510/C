// Directivas del preporecesador y variables

/* 
	 si trae #include es una libreria
	 si trae #define es una macro
*/

#include<stdio.h>

#define PI 3.1416

// Así esa variable siempre será igual alrededor de todo el codigo y no cambia

int y = 5; //variable global

int main(){
	
	int x = 10;	// Variable local
	
	float suma = 0;
	
	suma = PI + x;
	
	printf("La suma es: %.2f",suma);
	
	// %i indica el dato que tenemos que a�adir, en este caso seria f pq es un entero (float)
	// el ".2" significa solo 2 decimales y redondea si es posible
	
	return 0;
}
