/*
 * Fecha de publicación: 19 de Marzo del 2023
 * Hora: 10:09
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que imprime la serie triangular hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>

int main()
{
    // Declaramos variable que será utilizada para imprimir los valores de la serie
    int num1 = 0;
    // Declaramos variable para saber cuando el usuario desea parar el programa
    int stop = 0;
    // Variable que usaremos para parar el ciclo y lo usaremos para sumar a num1
    int i = 0;
    // Pedimos la cantidad de datos a mostrar al usuario
    printf("Ingresa la cantidad de términos que desea ver de la serie Triangular: ");
    scanf("%i", &stop);

    // Bucle para generar e imprimir la serie triangular
    for (i = 0; i <= stop; i++)
    {
        // Sumamos num1 y i, para obtener la serie
        num1 += i;
        // Imprime el valor actual de num1
        printf("%i, ", num1);
    }
    return 0;
}
