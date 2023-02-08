// Scanner

#include<stdio.h>

int main(){
/*	int a;
	float b;
	char c;
	
	printf("Digite su entero: ");
	scanf("%i", &a);
	
	printf("El valor de a es: %i", a);
	
	
	printf("Digite su float: ");
	scanf("%f", &b);
	
	printf("El valor de b es: %.2f", b);

	printf("Digite su caracter: ");
	scanf("%c", &c);
	
	printf("El valor de c es: %c",c); */
	
	char a[50];
	
	// si es string se usa char y el numero de caracteres entre [] y...
	// para usarlo en vez de usar %c, se usa %s (pq es un string)
	
	printf("Digite su nombre: ");
	scanf("%s", a);
	// gets(a); esta funcion se usa si necesitamos una cadena de caracteres con space
	// debido a que con scanf("%s", a); solo tomamos caracteres hasta que ve un space
	
	printf("Su nombre es: %s",a);
	
	return 0;
		}
