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
 * Descripción: Hacer un programa que mediante la serie de taylor imprima el resultado de sen(x) siendo x
 * una variable ingresada por el usuario.
 */

#include <stdio.h>
#include <math.h>

double seno(double, int);

int main()
{

    // Declaramos las variables
    // Variable donde guardaremos la "X" ingresado por el usuario
    double x = 0;

    // Variable donde guardaremos los términos que el usuario desea ver
    int terminos = 0;

    // Pedimos los datos de "x" al usuario
    printf("Ingrese el valor de X en la formula sen(x): ");
    scanf("%lf", &x);

    // Pedimos los terminos al usuario
    printf("Ingrese la cantidad de términos que desea usar: ");
    scanf("%i", &terminos);

    // Imprimimos el valor de resultado
    printf("sen(%.1f) = %.10f\n", x, seno(x, terminos));
    return 0;
}

// Funcíon de seno(x)
double seno(double x, int terminos)
{
    // Declaramos la variable que guardará las sumatorias de la serie de taylo
    double resultado = 0;

    // Declaramos la variable con la que controlaremos las iteraciones
    int n= 0;

    while (n < terminos)
    {
        resultado += pow(-1, n) * pow(x, 2 * n + 1) / tgamma(2 * n + 2);
        // Hacemos el incremento a la variable n
        n++;
    }
    return resultado;
}