/*
 * Fecha de publicación: 18 de Marzo del 2023
 * Hora: 13:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima una serie de numeros
 */

#include <stdio.h>

int main()
{

    // Declaramos una variable de la segunda columna
    int num2 = 1;

    for (int i = 0; i < 10;)
    {
        printf("%i %i\n", i, num2);

        // Hacemos el incremento de variables
        if (i % 2 != 0)
        {
            num2++;
        }

        i++;
    }

    return 0;
}