/*
 * Fecha de publicación: 3 de Marzo del 2023
 * Hora: 20:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que presente todas las tablas de multiplicar del 1 al 10
 */

#include <stdio.h>

int main()
{
    tablas(1, 1);
    return 0;
}

void tablas(int num1, int cont)
{

    // Si num1 es menor o igual que 10, imprime las tablas con normalidad, sino se acaba el programa
    if (num1 <= 10)
    {
        printf("%i x %i = %i\n", num1, cont, num1 * cont);

        // Para verificar que número imprimir usamos cont como el segundo a multiplicar, y si este es mayor a 10, salta a la siguiente tabla
        if (cont >= 10)
        {
            printf("\n");
            // Cambiamos el num y volvemos 1 a cont
            tablas(num1 + 1, 1);
        }
        else
        {
            tablas(num1, cont + 1);
        }
    }
}