/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 22:34
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pedirá minutos y e imprimirá las horas y minutos equivalentes
 */

#include <stdio.h>

int main(){

    // Declaramos las variables

    // Variable que recibe los minutos ingresados por el usuario
    int minutos = 0;
    
    // Variable que contendrá el total de horas después de convertir los minutos ingresados por el usuario
    int horas = 0;

    // Variable que contendrá el total de minutos después de conventir los minutos ingresados por el usuario
    int minRes = 0;

    // Pedimos los minutos al usuario
    printf("Ingrese los minutos: ");
    scanf("%i", &minutos);

    // Asignamos valores

    // Asignamos el total de horas a la variable horas

    horas = minutos / 60;
    
    // Asignamos el total de minutos a la variable minRes

    minRes = minutos % 60;

    // Imprimimos los datos

    printf("%i minutos equivalen a %i horas y %i minutos", minutos, horas, minRes);

    return 0;
}