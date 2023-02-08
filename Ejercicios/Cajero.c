// Hacer un cajero automatico con un saldo inicial de 1000 dolares

#include<stdio.h>

int main(){
	int opcion;
	float a,saldo=1000;
	
	printf("\tBienvenido a su cajero virtual");
	printf("\n1. Ingreso en cuenta");
	printf("\n2. Retirar dinero de la cuenta");
	printf("\n3. Salir");
	printf("\nOpcion: ");
	scanf("%i",&opcion);
	
	switch(opcion){
		case 1:
			printf("\nCuanto dinero desea ingresar?: ");
			scanf("%f",&a);
			saldo = saldo+a;
			printf("Su saldo es: %.1f",saldo);
			break;
		case 2:
			printf("\nCuanto dinero desea retirar?: ");
			scanf("%f",&a);
			if (saldo>=a){
				saldo = saldo-a;
				printf("Retiro exitoso\nSe retiro: %.f\nSu saldo actual es: %.1f",a,saldo);
			} else {
				printf("No se tiene suficiente saldo para retirar");
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("No existe esa opcion en el menu");
			break;
	}		
	return 0;
}
