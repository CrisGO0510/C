/*
 * Fecha de publicación: 13 de Marzo del 2023
 * Hora: 16:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que lea desde el teclado un numero entero y lo imprima al revés.
 */

#include <stdio.h>
#include <math.h>

int main()
{

    // Declaramos las variables

    // Variable donde se guardará el número ingresado por el usuario
    int numero = 0;
    // Variable donde se guardará cada uno de los dígitos del número a medida que se va dividiendo entre 10 en el ciclo
    int cifra = 0;
    // Pedimos el número al usuario
    printf("Este programa lee desde el teclado un número entero y lo imprime al revés.\nIngrese el número: ");
    scanf("%i", &numero);

    /*
        Con este ciclo contaremos la cantidad de cifras del número
        usamos i /= 10, para ir disminuyendo cifras: 100 -> 10 -> 1
        A su vez declaramos la variable "i" como un float para poder parar el programa cuando las divisiones lleguen a decimal
    */

    // Invierte el número
    for (int i = numero; i != 0; i /= 10)
    {
        cifra = i % 10;
        printf("%i", cifra);
    }

    return 0;
}