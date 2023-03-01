/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 20:20
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que nos dará el volumen de una esfera
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main()
{

    // Definimos las variables

    // Variable que alojará el radio que ingrese el usuario
    float radio = 0;
    // Variable que tendrá el valor del volumen de la esfera
    float volumen = 0;

    // Pedir al usuario los datos
    printf("Por favor digite el radio de la esfera: ");
    scanf("%f", &radio);

    // Ingresamos el valor de la formula de la esfera en la variable
    volumen = 4.0 / 3.0 * PI * pow(radio, 3);

    // Imprimimos los datos
    printf("El volumen de la esfera de radio %.1f, es %.5f", radio, volumen);

    return 0;
}