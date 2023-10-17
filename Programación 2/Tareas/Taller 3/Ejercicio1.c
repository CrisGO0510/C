/*
 * Fecha de publicación: 3 de Marzo del 2023
 * Hora: 15:35
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

void fibo(int, int, int);

int main()
{

    printf("Para este programa, se presentará la serie de Fibonacci hasta llegar sin sobrepasar el número 10,000.\n");

    fibo(1, 0, 0);

    return 0;
}

// Función para imprimir la sucesión fibonacci

void fibo(int x, int y, int aux)
{

    // Asignamos de manera temporal el valor de X a la variable auxiliar (aux) para poder recuperar ese valor luego
    aux = x;
    // Le asignamos el valor de la suma de X y Y a la variable X
    x = x + y;
    // Recuperamos el antiguo valor de x y lo guardamos en la variable Y
    y = aux;

    if (x > 10000)
    {
        // PARA EL FIBONACCI
    }
    else
    {
        // REALIZAMOS LA RECURSIVIDAD
        printf("%i, ", x);
        fibo(x, y, aux);
    }
}