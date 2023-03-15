/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 21:15
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que nos dará el perimetro de un rectangulo 
 */

#include <stdio.h>

int main(){

    // Declaramos las variables

    int perimetro = 0;
    int altura = 0;
    int largo = 0;

    // Pedimos la variable altura

    printf("Ingrese el valor de la altura del rectangulo: ");
    scanf("%i", &altura);

    // Pedimos la variable largo

    printf("Ingrese el valor del largo del rectangulo: ");
    scanf("%i", &largo);

    // Ingresasamos el valor de perimetro

    perimetro = largo * 2 + altura * 2;

    // Imprmimos los datos

    printf("El perimetro del cuadrado con largo %i y altura %i es de: %i", largo, altura, perimetro);

    return 0;
}