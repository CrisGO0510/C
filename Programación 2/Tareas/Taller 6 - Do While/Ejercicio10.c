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
 * Descripción: Programa que imprime la serie Motzkin hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>

long long int Motzkin(int);

int main()
{

    int termino = 0; // Cantidad de terminos
    int n = 0;       // Numero de termino en el que va

    printf("Este programa calcula la serie de Motzkin para la cantidad de terminos que desee.\n\n");

    printf("Ingrese la cantidad de terminos: ");
    scanf("%i", &termino);

    do
    {
        printf("%lld, ", Motzkin(n));
        // Hacemos el incremento de la variable n
        n++;
    } while (n < termino);

    return 0;
} // fin definición función main

// La función Motzkin toma un argumento entero n y retorna un entero largo

long long int Motzkin(int n)
{
    // k se inicializa a 0
    int k = 0;

    // Si n es igual a cero o uno, retorna 1
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Se inicializa la variable suma en 0
    long long int suma = 0;

    // Se realiza un ciclo desde k=0 hasta n-2, en intervalos de 1
    do
    {
        // Se realiza la suma de la multiplicación de las llamadas recursivas de Motzkin para ambos lados de la ecuación
        suma = suma + Motzkin(k) * Motzkin(n - 2 - k);

        // Hacemos el incremento de la variable k
        k++;
    } while (k <= n - 2);

    // Retorna la suma de las llamadas recursivas de Motzkin para n-1, más la suma de la multiplicación previa
    return Motzkin(n - 1) + suma;
}