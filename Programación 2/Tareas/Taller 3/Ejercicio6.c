/*
 * Fecha de publicación: 4 de Marzo del 2023
 * Hora: 14:36
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que, lea un número e imprima su factorial
 * Salvedad: Para numeros negarivos no se garantiza el resultado
 */

#include <stdio.h>

// Declaramos la función principal, llamada "Main"
int main(){

    // Declaramos una variable que guardará el dato ingresado por el usuario
    int num = 0;

    // Pedimos los datos al usuario
    printf("Ingrese el numero que del que desea obtener su factorial: ");
    scanf("%i", &num);

    // Imprimimos el valor que retorna fac para mostrar así el valor de la factorial
    printf("La factorial de %i es: %i", num, fac(num));
}

/* Creamos una función fac para realizar las operaciones necesarias de la 
factorial, de manera recursiva */

// X será el parametro a utilizar para generar y multiplicar los numeros
int fac(int x)
{
    // Creamos una condicional que nos dirá si el numero es mayor a cero
    if (x > 0){
        /* Si la condicional es cierta multiplicamos el valor que tenga X por 
        el que tenga la función "fac(x - 1)", haciendo así una recursividad*/
        return x * fac(x - 1);
    } else {
        /* Esta parte es para cuando el numero llegue a 0 retorne 1 siendo así el punto de para de la recursividad. Ej X * X-1 ... * 3 * 2 * "1", Este uno es el mismo que el que retorna abajo*/
        return 1;
    }
}