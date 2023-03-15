/*
 * Fecha de publicación: 13 de Marzo del 2023
 * Hora: 18:09
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que imprime la serie peli hasta llegar al número de términos deseado por el usuario.
 */

#include <stdio.h>

int main()
{
    // Declaración de variables
    // Declaramos varaibles para hacer el método burbuja
    // Variables que usaremos para establecer el inicio de peli
    int num1 = 0;
    int num2 = 1;
    // Variable donde guardaremos de manera temporal la suma de num1 y num2
    int aux = 0;
    // Variable que usaremos para parar el ciclo for
    int i = 0;
    // Pedimos la cantidad de datos a mostrar al usuario
    printf("Ingresa la cantidad de términos que desea ver: ");
    scanf("%i", &i);
    // Bucle para generar e imprimir la sucesión de peli
    do
    {
        // Imprime el valor actual de num1
        printf("%i, ", num1);

        // Almacena la suma de num1 y num2 en aux, de manera temporal para luego asignarselo a num 2
        aux = num1 + num2 * 2;
        // Le asignamos el valor de num2 a num1
        num1 = num2;
        // Le asignamos el valor de aux a num2
        num2 = aux;
        // Hacemos el decremento a la variable i
        i--;
    } while (i > 0);
    return 0;
}
