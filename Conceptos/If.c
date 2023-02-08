// Condicionales if

#include<math.h>
#include<stdio.h>

// Crearemos un programa para saber si un numero es divisible con otro

int main(){
	
	int a,b;
	
	printf("ingrese 2 numeros para comprobar su divisibilidad: ");
	scanf("%i %i",&a,&b);
	
	if (0 == remainder(a,b)){
		printf("%i y %i son divisibles \n%i",a,b,a/b);
	} else {
		printf("%i y %i no son divisibles",a,b);
	}
	
	return 0;
}
