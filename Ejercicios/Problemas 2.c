//Problemas 2, Sacar la hipotenusa de un triangulo pidiendo sus 2 catetos

// Agregamos la libreria math.h, para mas informacion https://devdocs.io

#include<stdio.h>
#include<math.h>

int main(){

	// Se usa float ya que puede ser decimal

	float a,b;

	printf("Ingrese el valor de los 2 catetos de un triangulo: ");
	scanf("%f %f",&a,&b);

	//Gracias a la libreria podemos sacar potencias, raices y otras operaciones que podemos ver en la api
	// Le asigno a = a elevado a la 2, lo mismo con b
	
	a = pow(a,2);
	b = pow(b,2);

	printf("El valor de la hipotenusa es: %f",sqrt(a+b));

	return 0;
}
