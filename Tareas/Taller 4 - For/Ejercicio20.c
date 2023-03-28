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

void imp(int); // declaración de la función imp
void letras(int, char); // declaración de la función letras

int main()
{
    for (int i = 0; i < 25; i++) // ciclo for para imprimir 25 filas
    {
        letras(80 - i, ' '); // se llama a la función letras para imprimir los espacios
        letras(i, 'A'); // se llama a la función letras para imprimir las letras 'A'
        printf("\n"); // salto de línea
    }
    
    return 0; // retorno de la función main
}

void letras(int num, char caracter) // definición de la función letras
{
    for (int i = 0; i < num; i++) // ciclo for para imprimir num caracteres
    {
        printf("%c", caracter); // impresión del caracter
    }
}