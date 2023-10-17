/*
 * Fecha de publicación: 4 de Marzo del 2023
 * Hora: 15:36
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que, utilizando ciclos anidados se generen las parejas de enteros como muestra en el diseño de pantalla:
        0 1
        1 1
        2 2
        3 2
        4 3
        5 3
        6 4
        7 4
        8 5
        9 5
 */

#include <stdio.h>

void imp(int, int);

int main()
{
    imp(0,1);

    return 0;
}

// Haremos la función que genera las parejas usando la variable f1 para la fila 1 y f2 para la fila 2
void imp(int f1, int f2)
{

    // Condicional que parará el programa cuando f1 sea mayor a 9
    if (f1 > 9)
    {
        // Termina el prgrama
        printf("\nFIN DEL PROGRAMA");
    }
    else
    {
        printf("%i %i\n", f1, f2);
        // Esta condicional salió de analizar el patrón de las filas
        if (f1 % 2 == 1)
        {
            imp(f1 + 1, f2 + 1);
        } else {
            imp(f1 + 1, f2);
        }
        
    }
}