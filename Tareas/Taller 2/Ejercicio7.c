/*
 * Fecha de publicación: 26 de febrero del 2023
 * Hora: 13:47
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que tome dos números y diga si ambos son pares o ambos son impares.
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables donde el usuario va a guardar los datos
    int num1 = 0;
    int num2 = 0;

    // Le pedimos 2 numeros al usuario
    printf("Este programa lee dos(2) números, e imprime si los dos son pares o los 2 son impares\n");
    printf("Ingrese su primer numero: ");
    scanf("%i", &num1);
    printf("Ingrese su segundo numero: ");
    scanf("%i", &num2);

    // Condicional para determinar si ambos son pares

    if (num1 % 2 == 0 && num2 % 2 == 0)
    {
        // Ambos numeros son pares
        printf("Ambos son pares");
    }
    else if (num1 % 2 == 1 && num2 % 2 == 1)
    {
        // Ambos son impares
        printf("Ambos son impares");
    }

    return 0;
}