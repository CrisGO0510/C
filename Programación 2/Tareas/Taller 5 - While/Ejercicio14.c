/*
 * Fecha de publicación: 18 de Marzo del 2023
 * Hora: 17:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima las tablas de multiplicar del 1 al 10
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables
    // Variable que será usada para determinar el primer valor a multiplicar
    int num1 = 1;
    // Variable que será usada para determinar el segundo valor a multiplicar
    int num2 = 1;

    // Hacemos un ciclo anidado para imprimir las tablas
    while (num1 <= 10)
    {
        // Decimos que mientras num2 sea menor a 10 imprima la multiplicación de num1 y num2
        while (num2 <= 10)
        {
            printf("%i x %i = %i\n", num1, num2, num1 * num2);
            // Hacemos el incremento a num2 para avanzar las iteraciones y las tablas
            num2++;
        }

        // Cuando se acabe la primera tabla hacemos num2 = 1 de nuevo, pero ahora num1 será 2
        num2 = 1;
        // Printf para que se vea mas estetico el programa
        printf("\n");
        // Hacemos el incremento a num1
        num1++;
    }

    return 0;
}