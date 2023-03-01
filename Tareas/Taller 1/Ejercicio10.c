/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 15:59
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que convierta de mph a m/s
 */

#include <stdio.h>

int main(){

    // Declaramos las variables

    // Variable donde se guardará el valor de mph ingresado por el usuario
    float milla = 0;
    
    // Variable donde se guardará la conversión de mph a m/s
    float metros = 0;

    // Pedimos las mph que se desea convertir a m/s
    printf("Por favor ingrese la cantida de mph que deea convertir a m/s: ");
    scanf("%f", &milla);

    // Asignamos el valor de la conversión en la variable metros
    metros = milla /  2.237;

    // Imprimimos los datos
    printf("%.1f mph son %.1f m/s", milla, metros);

    return 0;
}