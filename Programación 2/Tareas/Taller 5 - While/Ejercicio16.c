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
    long long int num = 0;
    // Declaramos variable que usaremos para guardar el valor de la factorial
    long long int fac = 1;
    // Declaramos una variable que será usada para guardar el resultado
    long long int resultado = 0;
    // Declaramos una variable que será usada para controlar las iteraciones de la factorial
    int i = 1;

    // Le pedimos el número al usuario
    printf("Por favor ingrese el valor del que desea obtener la sumatoria de sus factoriales: ");
    scanf("%i", &num);

    // Ciclo con el cual obtendremos la sumatoria de un numero
    while (num >= 0)
    {

        // Bucle para generar la factorial
        while (i <= num)
        {
            // Multiplicamos el valor actual de resultado por i, hasta que i sea igual al num ingresado por el usuario
            fac *= i;
            // Hacemos el incremento de la variable i
            i++;
        }
        
        // Sumamos el valor actual de resultado, con el num
        resultado += fac;
        // Hacemos fac = 1 para reiniciar el valor antes de entrar al siguiente ciclo para la factorial
        fac = 1;
        // Hacemos i = 1 para reiniciar el valor antes de entrar al siguiente ciclo para la factorial
        i = 1;
        // Hacemos el decremento de num para seguir con la sumatoria
        num--;
    }

    // Imprimimos el valor de resultado
    printf("El resultado de la sumatoria de factoriales es: %lli", resultado);

    return 0;
}