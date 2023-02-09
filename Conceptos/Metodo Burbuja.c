// En este programa realizaremos el método de la burbuja, el cual se basa (en)

#include <stdio.h>

int main (){

    // Declaramos las variables que usaremos para el ejemplo de intercambio de valores
    int x = 0,y = 0,aux = 0;

    printf("Ingrese el primer numero: ");
	scanf("%i", &x);
    printf("Ingrese el valor de y: ");
    scanf("%i", &y);

    // Usamos la variable aux para guardar el dato de x
    aux = x;
    // Tomamos el dato de y en la variable X
    x = y;
    // Le damos a y el valor del aux que antiguamente era x
    y = aux;

    

    return 0;
}