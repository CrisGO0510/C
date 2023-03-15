/*
 * Fecha de publicación: 7 de Marzo del 2023
 * Hora: 16:25
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que mediante la serie de taylor (ter terminos) imprima el resultado de cos(x) siendo x
 * una variable ingresada por el usuario.
 */

#include <stdio.h>
#include <math.h>

int fac(int);
float coseno(int, int, int);

int main()
{
    // Declaramos la variable donde el usuario va a guardar X
    int x = 0;
    // Declaramos la variable donde el usuario va a guardar los términos que desea saber
    int term = 0;

    // Pedimos el valor de X al usuario
    printf("Ingrese el valor de X que desea obtener en la función cos(x): ");
    scanf("%i", &x);

    // Pedimos el valor de términos al usuario
    printf("Ingrese el valor de términos que desea usar en la serie de taylor: ");
    scanf("%i", &term);

    // Imprimimos lo que nos retorne la función de coseno
    printf("%f", coseno(x, 0, term));

    return 0;
}

// Función que retorna la factorial de X, siendo  X será el parametro a utilizar para generar y multiplicar los numeros
int fac(int x)
{
    // Creamos una condicional que nos dirá si el numero es mayor a cero
    if (x > 0)
    {
        /* Si la condicional es cierta multiplicamos el valor que tenga X por el que tenga la función "fac(x - 1)", haciendo así una recursividad*/
        return x * fac(x - 1);
    }
    else
    {
        // Si ya no se cumple la igualdad retornar 1 por qué 0! = 1
        return 1;
    }
}

// Función para obtener el valor de la función de cos(x) usando los términos ingresados por el usuario en la serie de taylor
/*
    x = Valor ingresado por el usuario para saber cuál es el resultado de la función
    den = Variable para contará los términos de la serie de taylor y a su vez será usada como denominador para la misma
    ter = Variable que parará la recursividad a los terminos ingresados por el usuario
*/
float coseno(int x, int den, int ter)
{
    if (den < ter)
    {
        // Si den es menor que ter significa que aún falta recorrido por llegar
        return ((pow(-1, den) * pow(x, den * 2)) / fac(den * 2)) + coseno(x, den + 1, ter);
    }
    else
    {
        // Si es mayor a 0 excede los terminos que le otorgamos(ter), así que retornamos 0 para parar la recursión y no afecte la suma
        return 0;
    }
}