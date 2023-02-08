/* Una tienda ofrece un descuento del 15% sobre el total de la compra
y un cliente desea saber cuanto deberia pagar finalmente por su compra*/

#include<stdio.h>

int main(){
	
	float precio,total;
	
	printf("Ingrese el total de la compra: ");
	scanf("%f",&precio);
	
	total= precio-(precio*0.15);
	
	printf("El valor a pagar con el descuento seria: %.0f",total);
	
	return 0;
}
