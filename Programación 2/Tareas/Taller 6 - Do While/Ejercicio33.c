/*
 * Fecha de publicación: 7 de Marzo del 2023
 * Hora: 16:09
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que mediante la serie de taylor imprima el resultado de ln(x) siendo x
 * una variable ingresada por el usuario.
 */

#include <stdio.h>
#include <math.h>

double logN(double, int);

int main()
{

    // Declaramos las variables
    // Variable donde guardaremos la "X" ingresado por el usuario
    double x = 0;

    // Variable donde guardaremos los términos que el usuario desea ver
    int terminos = 0;

    // Pedimos los datos de "x" al usuario
    printf("Ingrese el valor de X en la formula ln(x): ");
    scanf("%lf", &x);

    // Pedimos los terminos al usuario
    printf("Ingrese la cantidad de términos que desea usar: ");
    scanf("%i", &terminos);

    // Imprimimos el valor de resultado
    printf("ln(%.1f) = %.10f\n", x, logN(x, terminos));
    return 0;
}

// Funcíon de logN(x)
double logN(double x, int terminos)
{
    // Declaramos la variable que guardará las sumatorias de la serie de taylor
    double resultado = 0;

    // Declaramos la variable que usararemos para controlar las iteraciones
    int n = 1;

    do
    {
        resultado += (pow(-1, n - 1) * pow( x - 1, n)) / n;
        // Hacemos el incremento a la variable n
        n++;
    } while (n <= terminos);
    
    return resultado;
}