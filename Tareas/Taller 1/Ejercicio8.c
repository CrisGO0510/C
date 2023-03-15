/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 15:04
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida 2 números e imprima la suma, resta, multiplicación y división de los números
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables

    float num1 = 0;
    float num2 = 0;

    // Pedimos los valores de las variables al usuario

    // Pedimos el valor de numero 1

    printf("Ingrese el valor de numero 1: ");
    scanf("%f", &num1);

    // Pedimos el valor de numero 2

    printf("Ingrese el valor de numero 2: ");
    scanf("%f", &num2);

    // Imprimimos los resultados de cada operación

    // Imprimimos suma

    printf("Suma: %.0f\n", num1 + num2);

    // Imprimimos resta

    printf("Resta: %.0f\n", num1 - num2);

    // Imprimimos multiplicación

    printf("Multiplicación: %.0f\n", num1 * num2);

    // Imprimimos resta

    printf("División: %.2f\n", num1 / num2);

    return 0;
}