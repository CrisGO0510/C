// Depende del vehiculo el peaje costará diferente

#include<stdio.h>

int main(){

	int v;
	
	printf("Que tipo de vehiculo pasa por el peaje: \n1. Vehiculo turistico \n2. Autobus \n3. Motocicleta:\n");
	scanf("%i",&v);
	
	switch(v){
		case 1: printf("El vehiculo debe pagar 500 de peaje");
			break;
		case 2:	printf("El vehiculo debe pagar 3000 de peaje");
			break;
		case 3: printf("El vehiculo debe pagar 300 de peaje");
			break;
		default: printf("Vehiculo no autorizado");
			break;
	}
	return 0;
}
