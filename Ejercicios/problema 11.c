// En este problema haremos la secuencia de fibonacci con bucles

#include <stdio.h>

int main(){

    // Declaramos las variables que usaremos para el metodo burbuja
    int x = 0, y = 1, aux = 1;

    // Creamos un bucle para generar lus numeros
    for (int i = 0; i < 11; i++)
    {
        // Aquí guardaremos una variable de manera temporar para que no se pierda su valor
        aux = x;
        // Aquí sumamos las dos variables
        x = x + y;
        // Aquí retomamos el valor anterior de 'x' gracias a la variable auxiliar
        y = aux;
        // Imprimimos el valor de X y repetimos hasta que se acabe el bucle
        printf("%i, ",x);
    }

    // Consola: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
    return 0;
}
