/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 14:56
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pedirá nombre, apellido y año de nacimiento y luego los imprimirá juntos
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables

    // Variable que guardará el nombre ingresado por el usuario
    char nombre[30] = "";

    // Variable que guardará el apellido ingresado por el usuario
    char apellido[30] = "";

    // Variable que guardará el año de nacimiento
    int fecha = 0;

    // Pedimos los datos

    // Pedimos el nombre al usuario
    printf("Ingrese el nombre: ");
    scanf("%s", nombre);

    // Pedimos el apellido al usuario
    printf("Ingrese el apellido: ");
    scanf("%s", apellido);

    // Pedimos la fecha de nacimiento al usuario
    printf("Ingrese el año de nacimiento: ");
    scanf("%i", &fecha);

    // Imprimimos los datos

    printf("%s %s %i", nombre, apellido, fecha);

    return 0;
}