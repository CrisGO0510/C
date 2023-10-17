/*
 * Fecha de publicación: 25 de febrero del 2023
 * Hora: 17:45
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida un número del 1 al 5 e imprima si es primo o no.
 * Salvedades: Para números fuera del rango solicitado (1 a 5) no se asegura el resultado
 */

#include <stdio.h>

int main()
{

    // Declaramos la variable donde se guardará el numero ingresado por el usuario
    int num = 0;

    // Pedimos los datos al usuario
    printf("Este programa, lee un número entre uno(1) y cinco(5), e imprime si es primo o no.\n Entre un número: ");
    scanf("%i", &num);

    // Condicional para determinar si es primo o no

    if (num == 1 || num == 4)
    {
        // Si es cierto entonces no es un numero primo
        printf("El numero no es primo");
    }
    else
    {
        // Si es falso el numero es primo
        printf("El numero es primo");
    }

    return 0;
}