// En este archivo hablaremos sobre los Punteros y paso por referencia

#include <stdio.h>

/*
* Hay 2 tipos de "simbolos" que usaremos:
* Primero que todo el "&" o "ampersand" es el parámetro de dirección que
* se usa para llamar la dirección, ejemplo &x estamos llamando a la dirección
* de memoria donde se encuentra la variable X.

* Luego usaremos "*" el cuál es el parámetro de indirección, el cual su
* Función es señalar el valor que hay en la dirección X.
*/

void cambio(int *, int *);

// * Ejemplo practico:

int main(){
    // * Declaramos 2 variables de tipo entero
    int x = 10, y = 15;
    // * Llamamos la función de cambio con los parámetros de dirección
    cambio(&x, &y);
    /*
        * Imprimimos los valores X ^ Y
        ? ¿Que valor imprimimirá?
        ? 1. x = 10 ^ y = 15
        ? 2. x = 15 ^ y = 10
        * La correcta será la segunda, ya que en la función cambio se cambiaron la 
        * DIRECCIÓN de las variables por medio de los parámetros de indirección
        * Si estos valores no tuvieran estos punteros la respuesta sería la 1
    */
   printf("El valor de X es: %i\n Y el valor de Y es: %i\n",x,y);
}

void cambio(int *a, int *b){
    // * Declaramos la variable aux para hacer el método burbuja 
    int aux;

    /* 
    * Metodo burbuja PERO usando los parámetros de indirección para lograr cambiar
    * los valores de la dirección asignada, es decir donde fueron declaradas
    */
    aux = *a;
    *a = *b;
    *b = aux;
}