// Problema 1,	Pedir 2 números: sumarlos , restarlos , multiplicarlos y dividirlos.
 
#include<stdio.h>

int main(){
	
	int a,b,op;
	
	printf("Ingrese el primer numero: ");
	scanf("%i", &a);
	
	printf("Ingrese el segundo numero: ");
	scanf("%i", &b);
	
	printf("Que operacion desea realizar?:\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n5-Todos\n");
	scanf("%i", &op);
	
	switch(op) {
		case 1 :
			printf ("\nLa respuesta de la suma de %i y %i es: %i",a,b,a+b);
			break;
		case 2 :
			printf ("\nLa respuesta de la resta de %i y %i es: %i",a,b,a-b);
			break;
		case 3:
			printf ("\nLa respuesta de la multiplicacion de %i y %i es: %i",a,b,a*b);
			break;
		case 4:
			printf ("\nLa respuesta de la division de %i y %i es: %i",a,b,a/b);
			break;
		case 5:
			printf ("\nLa respuesta de la suma de %i y %i es: %i",a,b,a+b);
			printf ("\nLa respuesta de la resta de %i y %i es: %i",a,b,a-b);
			printf ("\nLa respuesta de la multiplicacion de %i y %i es: %i",a,b,a*b);
			printf ("\nLa respuesta de la division de %i y %i es: %i",a,b,a/b);
			break;
		default:
			printf("Ingrese una operacion correcta");
			break;
	}
	return 0;
}
