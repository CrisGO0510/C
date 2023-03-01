/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 15:18
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida 2 ángulos de un triangulo e imprima el valor del ángulo restante
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables

    int ang1 = 0;
    int ang2 = 0;

    // Pedimos los datos al usuario

    // Pedimos el valor del angulo 1
    printf("Ingrese el valor del primer ángulo: ");
    scanf("%i", &ang1);

    // Pedimos el valor del angulo 2
    printf("Ingrese el valor del segundo ángulo: ");
    scanf("%i", &ang2);

    // Imprimir los ángulos

    printf("El valor del tercer ángulo de un triangulo con ángulos de %i y %i, es de: %i", ang1, ang2, 180 - ang1 - ang2);

    return 0;
}