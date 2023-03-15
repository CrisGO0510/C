/*
 * Fecha de publicación: 14 de Marzo del 2023
 * Hora: 18:21
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que imprime la serie Catalán hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>

long long int fac(int);
int main()
{
    // Declaración de variables
    // Variable que usaremos para parar el ciclo for
    int stop = 0;
    // Pedimos la cantidad de datos a mostrar al usuario
    printf("Ingresa la cantidad de términos que desea ver: ");
    scanf("%i", &stop);
    // Variable que será utilizada para incrementarla cada iteración y así pare el ciclo
    int i = 0;
    // Bucle para generar e imprimir la sucesión de Catalán
    do
    {
        // Imprimimos lo que nos retorne la fórmula de catalan = (fac(2 * i) / (fac(i) * fac(i + 1)))
        printf("%i, ", fac(2 * i) / (fac(i) * fac(i + 1)));
        // Hacemos el incremento para poder parar las iteraciones
        i++;
    } while (i < stop);
    return 0;
}

/*
    Función para obtener la factorial de un número
    X será el parametro a utilizar para generar y multiplicar los numeros
*/
long long int fac(int x)
{
    // Creamos una condicional que nos dirá si el numero es mayor a cero
    if (x > 0)
    {
        /* Si la condicional es cierta multiplicamos el valor que tenga X por
        el que tenga la función "fac(x - 1)", haciendo así una recursividad*/
        return x * fac(x - 1);
    }
    else
    {
        /* Esta parte es para cuando el numero llegue a 0 retorne 1 siendo así el punto de para de la recursividad. Ej X * X-1 ... * 3 * 2 * "1", Este uno es el mismo que el que retorna abajo*/
        return 1;
    }
}