/*
 * Fecha de publicación: 4 de Marzo del 2023
 * Hora: 15:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que lea un número entero N, no negativo y mostrar la suma de los factoriales de todos los números desde 0 hasta N.
 */

#include <stdio.h>

// Declaramos la función principal, llamada "Main"
int main()
{

    // Declaramos una variable que guardará el dato ingresado por el usuario
    int num = 0;

    // Pedimos los datos al usuario
    printf("Ingrese el numero que del que desea obtener la sumatoria de sus factoriales: ");
    scanf("%i", &num);

    // Condicional para validar el si el numero es positivo
    if (num >= 0)
    {
        // Imprimimos el valor que retorna fac para mostrar así el valor de la factorial
        printf("%i", sum(num, 0));
    }
    else
    {
        // En caso de que el numero ingresado por el usuario no sea positivo, volvemos a ejecutar la función principal
        printf("Error, ingrese un numero positivo\n");
        main();
    }
}

/* Creamos una función fac para realizar las operaciones necesarias de la
factorial, de manera recursiva */

// X será el parametro a utilizar para generar y multiplicar los numeros
int fac(int x)
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

/*
    Creamos la función para determinar la sumatoria y retornarla
    Se puede realizar con solo 1 parametro, pero nos interesaba que la función sumará hasta el valor de x, en vez de restar hasta 0
    es decir, que num tenga que alcanzar a X, para que a la hora de imprimir los numeros que que sumarán empezara desde abajo (1) y no desde el valor mas alto

    x = Variable que ingresará el usuario y será el punto de finalización de la recursividad
    num = Variable que se enviará a la función fac y se imprimirá, además de ser usada para que la función retorne la suma de los factoriales
*/
int sum(int x, int num)
{
    // Creamos una condicional para parar la recursividad
    if (num >= x)
    {
        // Imprimimos el valor de x, acorde al diseño de pantalla
        printf("%i = ", fac(num));
        // Para el programa ya que el valor minimo de un factorial es 0
        return fac(num);
    }
    else
    {
        // Imprimimos el valor de x, acorde al diseño de pantalla
        printf("%i + ", fac(num));
        // Generamos la sumatoria con recursividad y mandamos como numero a sumar lo que retorne la función fac
        return fac(num) + sum(x, num + 1);
    }
}