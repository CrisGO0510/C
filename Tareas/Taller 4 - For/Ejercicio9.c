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
 * Descripción: Programa que imprime la serie Bell hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>
#include <math.h>

// Declaramos las funciones
long long int Bell(int, int, long long int);
long long int factorial(long long int);

// Función principal
int main()
{
    // Declaramos variables
    // Variable para controlar las iteraciones
    int n = 0;
    // Variable que guardará el número de terminos que desea el usuario
    int termino = 0;

    // Pedimos la cantidad de términos
    printf("Ingrese la cantidad de terminos que desea ver de la serie de Bell: ");
    scanf("%i", &termino);

    // Iteramos a través de cada término de la serie
    for (n = 0; n < termino; n++)
    {
        // Si es la primera o segunda iteración, imprimimos el valor 1
        if (n == 0 || n == 1)
            printf("1, ");
        else
        {
            // En otras iteraciones, calculamos el valor utilizando la función recursiva Bell
            printf("%lli, ", Bell(n, 0, 4));
        }
    }
    // Imprimimos un salto de línea después de imprimir los términos de la serie
    printf("\n");
    return 0;
}

// Función para calcular la serie de Bell
long long int Bell(int n, int k, long long int suma)
{
    // Declaramos la variable para el resultado
    long long int resultado = 0;

    // Iteramos desde k hasta n+3
    for (int i = k; i <= n + 3; i++)
    {
        // Calculamos el resultado utilizando la fórmula
        resultado = pow(i, n) / factorial(i);

        // Actualizamos la variable suma
        suma += resultado;
    }

    // Calculamos el resultado final
    resultado = (1.0 / 2.71828) * suma;
    return resultado;
}

// Función auxiliar para calcular el factorial de un número
long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}