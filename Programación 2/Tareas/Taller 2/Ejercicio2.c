/*
 * Fecha de publicación: 25 de febrero del 2023
 * Hora: 16:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida un número e imprima si es par o impar.
 */

#include <stdio.h>

int main(){

    // Declaramos la variable donde se va a guardar el numero ingresado por el usuario
    int num = 0;

    // Pedimos un numero al usuario
    printf("Este programa, lee un número e imprime si es par o impar..\nEntre un número: ");
    scanf("%i", &num);

    // Condición para saber si es par o impar

    if (num % 2 == 0)
    {
        // Si es verdadera la condicional, el numero deberá ser par
        printf("El número es par");
    } else {
        // Si la condicional es falsa, entonces el numero será impar
        printf("El número es no par");
    }
    

    return 0;
}