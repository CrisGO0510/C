/*
 * Fecha de publicación: 14 de Marzo del 2023
 * Hora: 16:09
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que imprime la serie Perrin hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>

int main()
{
    // Declaración de variables
    // Declaramos varaibles para hacer el método burbuja
    // Variables que usaremos para establecer el inicio de Perrin
    int num1 = 3;
    int num2 = 0;
    int num3 = 2;
    // Variable donde guardaremos de manera temporal la suma de num1 y num2
    int aux = 0;
    // Variable que usaremos para parar el ciclo for
    int i = 0;
    // Pedimos la cantidad de datos a mostrar al usuario
    printf("Ingresa la cantidad de términos que desea ver de la serie de Perrin: ");
    scanf("%i", &i);
    // Bucle para generar e imprimir la sucesión de Perrin
    for (; i > 0; i--)
    {
        // Imprime el valor actual de num1
        printf("%i, ", num1);
        // Le asignamos a la variable "aux" la suma de num1 y num2
        aux = num1 + num2;
        // Le asignamos la siguiente posición a num1, que seria num2
        num1 = num2;
        // Le asignamos la siguiente posición a num2, que seria num3
        num2 = num3;
        // Le asignamos la suma de los la posición 1 y posición 2 a num3, que lo habiamos guardado en la variable "aux"
        num3 = aux;
    }
    return 0;
}
