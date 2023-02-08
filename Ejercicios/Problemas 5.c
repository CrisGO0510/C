#include<stdio.h>

// Mayor de 2

int main(){

	int a,b;

	printf("Ingrese 2 numeros a comparar: ");
	scanf("%i %i",&a,&b);

	if(a>b){
		printf("\n%i es mayor que %i",a,b);	
	} else if(b>a) {
		printf("\n%i es mayor que %i",b,a);
	} else {
		printf("%i y %i son iguales",a,b);
	}
	
	
	return 0;
}
