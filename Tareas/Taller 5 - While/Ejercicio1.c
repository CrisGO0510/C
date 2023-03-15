/*
 * Fecha de publicación: 13 de Marzo del 2023
 * Hora: 15:09
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que imprime la serie fibonacci hasta llegar y sin sobre pasar el número 10,000.
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
    // Imprime un mensaje en pantalla
    printf("La serie de Fibonacci hasta 10,000 es: \n");

    // Bucle para generar e imprimir la sucesión de fibonacci
    while (num1 <= 10000)
    {
        // Imprime el valor actual de num1
        printf("%i, ", num1);

        // Almacena la suma de num1 y num2 en aux, de manera temporal para luego asignarselo a num 2
        aux = num1 + num2;
        // Le asignamos el valor de num2 a num1
        num1 = num2;
        // Le asignamos el valor de aux a num2
        num2 = aux;
    }
    return 0;
}
