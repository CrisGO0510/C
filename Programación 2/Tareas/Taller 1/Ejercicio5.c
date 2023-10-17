/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 22:08
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pedirá horas y minutos e imprimirá el total en minutos 
 */

#include <stdio.h>

int main(){

    // Declaramos las variables

    // Variable que alojará las horas ingresadas por el usuario
    int horas = 0;
    // Variable que alojará las minutos ingresadas por el usuario
    int minutos = 0;
    // Variable que contendrá el total de minutos para poder imprimirlo en pantalla 
    int totalMinutos = 0;

    // Pedimos los datos

    // Pedimos las horas al usuario
    printf("Por favor digite la cantidad de horas: ");
    scanf("%i", &horas);

    // Pedimos los minutos
    printf("Por favor digite la cantidad de minutos: ");
    scanf("%i", &minutos);

    // Asignamos el valor total de minutos a la variable totalMinutos

    totalMinutos = horas * 60 + minutos;

    // Imprimir los datos

    printf("%i horas y %i minutos equivalen a %i minutos", horas, minutos, totalMinutos);

    return 0;
}