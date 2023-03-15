/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 16:56
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que presente lo siguiente en la pantalla:

                       Z                 Z
                        Z               Z
                         Z             Z
                          Z           Z
                           Z         Z
                            Z       Z
                             Z     Z
                              Z   Z
                               Z Z
                                Z
 */

#include <stdio.h>

void imp(int, int);
void esp(int, int);

int main()
{
    imp(0, 17);

    return 0;
}

// Haremos la función que hace el efecto de "Moverse" a las filas que imprima la función esp
void imp(int incio, int intermedio)
{
    if (intermedio >= 0)
    {
        esp(incio, 0);
        esp(intermedio, 1);
        imp(incio + 1, intermedio - 2);
    }
    else
    {
        // Cuanto la recursividad acabe, es decir, cuando el espacio entre las 2 "Z" sera 0, imprimiremos una sola "Z"
        esp(incio, 0);
    }
}
// Función que como parametro recibe: num que es la cantidad de espacios que se colocarán, y fin que definirá si la "Z" tendrá salto de linea o no.

void esp(int num, int fin)
{
    // Condicional para determinar cuantas veces(num) se imprimirá el espacio
    if (num > 0)
    {
        printf(" ");
        esp(num - 1, fin);
    }
    else
    {
        // Si fin es verdadero significa que se debe imprimir a y un salto de linea, pero si es falso solo se imprime a
        if (fin)
        {
            printf("Z\n");
        }
        else
        {
            printf("Z");
        }
    }
}