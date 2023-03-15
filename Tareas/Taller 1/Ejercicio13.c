/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 16:49
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Escribir un código donde pida al usuario el valor de x para ser aplicado en una ecuación
 */

#include <stdio.h>
#include <math.h>

int main()
{

    // Declaramos la variable que guardará el valor ingresado por el usuario

    float x = 0;

    // Declaramos variable donde guardaremos el resultado de la operación

    float res = 0;

    // Pedimos el valor de X al usuario
    printf("Ingrese el valor de X: ");
    scanf("%f", &x);

    // Asignamos a res la ecuación

    res = (x * 1.0/2.0 + 25) / ( sqrt(169) / sqrt(144) + sqrt(x) / x);

    // Imprimimos el resultado

    printf("El resultado de \"%.f\" en la ecuación es de: %f", x, res);

    return 0;
}