/*
 * Fecha de publicación: 3 de Marzo del 2023
 * Hora: 16:00
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

int fibo(int, int, int);

int main()
{
    printf("Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.\n");
    printf("Los números a sumar son:\n");
    printf("y su suma es %i", fibo(0, 1, 0));

    return 0;
}

// Función para imprimir la sucesión fibonacci

int fibo(int x, int y, int aux)
{

    // Asignamos de manera temporal el valor de X a la variable auxiliar (aux) para poder recuperar ese valor luego
    aux = x;
    // Le asignamos el valor de la suma de X y Y a la variable X
    x = x + y;
    // Recuperamos el antiguo valor de x y lo guardamos en la variable Y
    y = aux;

    if (x > 100)
    {
        // Acaba el programa e imprime la suma
        return 0;
    }
    else
    {
        printf("%i, ", x);
        // Ejecuta la recursividad y a su ves retorna el valor actual de X
        return x + fibo(x,y,aux);
    }
}