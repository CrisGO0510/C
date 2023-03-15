/*
 * Fecha de publicación: 26 de febrero del 2023
 * Hora: 14:15
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que tome tres números y diga si la multiplicación de los dos primeros es igual al tercero.
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables van a guardar los numeros que ingrese el usuario
    int num1 = 0;
    int num2 = 0;
    // Variable la cual será comparada para saber si num1 y num2 son iguales a num3
    int num3 = 0;

    // Pedimos los numeros al usuario
    printf("Este programa lee tres(3) números, e imprime si la multiplicación de los 2 primeros es igual al tercero\n");
    // Pedimos el valor del primer numero
    printf("\nIngrese el primer numero: ");
    scanf("%i", &num1);
    // Pedimos el valor del segundo numero
    printf("\nIngrese el segundo numero: ");
    scanf("%i", &num2);
    // Pedimos el valor del tercer numero
    printf("\nIngrese el tercer numero: ");
    scanf("%i", &num3);

    // Condicional para saber si la multiplicación de num1 y num2 es igual a num3
    if (num1 * num2 == num3)
    {
        // Son iguales
        printf("\nLa multiplicación del primer numero por el segundo numero es igual al tercer numero");
    }
    else
    {
        // NO son iguales
        printf("\nLa multiplicación del primer numero por el segundo numero es NO igual al tercer numero");
    }

    return 0;
}