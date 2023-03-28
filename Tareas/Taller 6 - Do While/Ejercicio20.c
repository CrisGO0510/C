/*
 * Fecha de publicación: 19 de Marzo del 2023
 * Hora: 13:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima un triangulo que empiece en la columna 80 y tenga 25 filas
 */

#include <stdio.h>

void letras(int, char); // declaración de la función letras

int main()
{
    // Variable con la que controlaremos las iteraciones
    int i = 1;

    do // ciclo for para imprimir las 25 filas del triangulo
    {
        letras(80 - i, ' '); // se llama a la función letras para imprimir los espacios
        letras(i, 'A');      // se llama a la función letras para imprimir las letras 'A'
        printf("\n");        // salto de línea

        // Hacemos el incremento de la variable i
        i++;
    } while (i < 25);
    return 0; // retorno de la función main
}

void letras(int num, char caracter) // definición de la función letras
{

    // Variable con la que controlaremos las iteraciones
    int i = 0;

    do // ciclo for para imprimir num caracteres
    {
        printf("%c", caracter); // impresión del caracter

        // Hacemos el incremento de la variable i
        i++;
    } while (i < num);
}