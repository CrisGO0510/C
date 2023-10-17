/*
 * Fecha de publicación: 18 de Marzo del 2023
 * Hora: 13:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima la sumatoria de las factoriales del número ingresado por el usuario
 */

#include <stdio.h>

int main()
{

    // Declaramos una variable que será usada para guardar el número al que el usuario el quiere sacar la factorial
    int num = 0;
    // Declaramos variable que usaremos para guardar el valor de la factorial
    int fac = 1;
    // Declaramos una variable que será usada para guardar el resultado
    int resultado = 0;

    // Le pedimos el número al usuario
    printf("Por favor ingrese el valor del que desea obtener la sumatoria de sus factoriales: ");
    scanf("%i", &num);

    // Ciclo con el cual obtendremos la sumatoria de un numero
    for (; num >= 0; num--)
    {

        // Ciclo para la factorial del numero actual
        for (int i = 1; i <= num; i++)
        {
            // Multiplicamos el valor actual de resultado por i, hasta que i sea igual al num ingresado por el usuario
            fac *= i;
        }

        // Sumamos el valor actual de resultado, con el num
        resultado += fac;
        // Hacemos fac = 1 para reiniciar el valor antes de entrar al siguiente ciclo para la factorial
        fac = 1;
    }

    // Imprimimos el valor de resultado
    printf("El resultado de la sumatoria de factoriales es: %i", resultado);

    return 0;
}