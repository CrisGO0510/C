/*
 * Fecha de publicación: 18 de Marzo del 2023
 * Hora: 17:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima la factorial del número ingresado por el usuario
 */

#include <stdio.h>

int main()
{

    // Declaramos una variable que será usada para guardar el número al que el usuario el quiere sacar la factorial
    int num = 0;
    // Declaramos una variable que será usada para guardar el resultado al que el usuario el quiere sacar la factorial
    int resultado = 1;
    // Declaramos la variable que se usará para controlar las iteraciones
    int i = 1;

    // Le pedimos el número al usuario
    printf("Por favor ingrese el valor del que desea obtener su factorial: ");
    scanf("%i", &num);

    // Ciclo con el cual multiplicaremos todos los numeros desde 0 a 1 y lo guardaremos en la variable resultado
    do
    {
        // Multiplicamos el valor actual de resultado por i, hasta que i sea igual al num ingresado por el usuario
        resultado *= i;
        // Hacemos el incremento de la variable i
        i++;
    } while (i <= num);

    // Imprimimos el valor de resultado
    printf("La factorial de %i es: %i", num, resultado);

    return 0;
}