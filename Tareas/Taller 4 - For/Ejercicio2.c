/*
 * Fecha de publicación: 13 de Marzo del 2023
 * Hora: 15:10
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que imprima el valor de la suma de los elementos de la serie de Fibonacci entre 0 y 100.
 */

#include <stdio.h>
    
int main()
{
    // Declaración de variables
    // Declaramos varaibles para hacer el método burbuja
    // Variables que usaremos para establecer el inicio del fibonacci
    int num1 = 0;
    int num2 = 1;
    // Variable donde guardaremos de manera temporal la suma de num1 y num2
    int aux = 0;
    // Variable que usaremos para parar el ciclo for
    int i = 0;
    // Variable donde guardaremos la suma de los numeros
    int sum = 0;
    // Imprime un mensaje en pantalla
    // Imprimimos un mensaje de presentación del programa
    printf("Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.\n");
    // Imprimimos los números que se van a sumar
    printf("Los números a sumar son:\n");

    // Bucle para generar e imprimir la sucesión de fibonacci
    for (i = 0; num1 <= 100; i++)
    {
        // Imprime el valor actual de num1
        printf("%i, ", num1);

        // Asignamos a sum el valor de la suma de sum y num1, para así ir conseguir el tottal e imprimirlos luego
        sum = sum + num1;
        // Almacena la suma de num1 y num2 en aux, de manera temporal para luego asignarselo a num 2
        aux = num1 + num2;
        // Le asignamos el valor de num2 a num1
        num1 = num2;
        // Le asignamos el valor de aux a num2
        num2 = aux;

    }

    // Imprimimos la suma de los elementos de la serie de Fibonacci
    printf("\nLa suma de los elementos es: %i\n", sum);

    return 0;
}