#include<stdio.h>

int main(){
	int u,d,c,um;
	int numero = 2436;
	
	u = numero%10; numero = numero/10; // EL % es el modulo de una division, como el remainder 
	d = numero%10; numero = numero/10;
	c = numero%10; numero = numero/10;
	um = numero%10; numero = numero/10;
	
	printf("Las unidades son: %i\nLas decenas son: %i\nLas centenas son: %i\nLas unidades de mil son: %i",u,d,c,um);
	
	return 0;
}
