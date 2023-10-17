/*
 * Fecha de publicación: 4 de Marzo del 2023
 * Hora: 15:56
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que genere las ternas de enteros como muestra en el diseño de pantalla:
        1 1 1
        2 1 2
        3 1 3
        4 2 1
        5 2 2
        6 2 3
        7 3 1
        8 3 2
        9 3 3
 */

#include <stdio.h>

void imp(int, int, int);

int main()
{
    imp(1, 1, 1);

    return 0;
}

// Haremos la función que genera las ternas usando la variable f1 para la fila 1, f2 para la fila 2 y f3 para la fila 3
void imp(int f1, int f2, int f3)
{

    // Condicional que parará el programa cuando f1 sea mayor a 9
    if (f1 > 9)
    {
        // Termina el prgrama
        printf("\nFIN DEL PROGRAMA");
    }
    else
    {
        printf("%i %i %i\n", f1, f2, f3);

        // Esta condicional salió de analizar el patrón de las filas
        if (f3 == 3)
        {
            imp(f1 + 1, f2 + 1, 1);
        }
        else
        {
            imp(f1 + 1, f2, f3 + 1);
        }
    }
}