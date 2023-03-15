/*
 * Fecha de publicación: 13 de Marzo del 2023
 * Hora: 16:10
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que imprima el valor de la suma de los elementos de la serie de Fibonacci entre 0 y 100.
 */

#include <stdio.h>

int main()
{
    // Se definen las variables enteras x, y, temp y sum.
    int x = 0, y = 1, temp, sum = 0;

    // Se muestra un mensaje en pantalla utilizando la función printf().
    printf("Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.\n");
    printf("Los números a sumar son:\n");

    // Se inicia un bucle while para imprimir la serie de Fibonacci y calcular su suma.
    do
    {
        // Se imprime el valor actual de x utilizando la función printf().
        printf("%i, ", x);

        // Se añade el valor de x a la variable sum.
        sum += x;

        // Se calcula el siguiente número de Fibonacci sumando x e y y se almacena en la variable temp.
        temp = x + y;

        // Se actualiza el valor de x al valor de y.
        x = y;

        // Se actualiza el valor de y al valor de temp.
        y = temp;
    } while (x <= 100);

    // Se imprime la suma de los elementos de la serie de Fibonacci utilizando la función printf().
    printf("\nLa suma de los elementos es: %i\n", sum);

    // Se retorna 0 para indicar que el programa ha finalizado correctamente.
    return 0;
}
