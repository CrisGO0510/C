/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 16:16
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida horas, minutos y segundos e imprima en pantalla el total en milisegundos.
 */

#include <stdio.h>

int main()
{

    // Declaramos las variables
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    // Variable que alojará el total de todas las horas, minutos y segundos ingresados por el usuario
    int mSegundos = 0;

    // Pedimos los datos

    // Pedimos las horas que desea convertir a milisegundos al usuario
    printf("Digite las horas: ");
    scanf("%i", &horas);

    // Pedimos las minutos que desea convertir a milisegundos al usuario
    printf("Digite las minutos: ");
    scanf("%i", &minutos);

    // Pedimos las segundos que desea convertir a milisegundos al usuario
    printf("Digite las segundos: ");
    scanf("%i", &segundos);

    // Asignamos el valor a la variable segundos

    mSegundos = horas * 3600000 + minutos * 60000 + segundos *1000;

    // Imprimimos los datos

    printf("%i horas, %i minutos y %i segundos son equivalentes a %i milisegundos", horas, minutos, segundos, mSegundos);

    return 0;
}