/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 21:15
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que convervierta Km/h (Kilometros por hora) a mph (Millas por hora)
 */

#include <stdio.h>

int main(){

    // Declaramos las variables

    // Variable donde el usuario ingresará los kilometros por hora que desea convertir
    float kmHora = 0;
    // Variable donde se alojará el resultado de la conversión
    float mph = 0;

    // Pedimos los datos al usuario
    
    printf("Ingrese los Km/h que desea convertir a mph: ");
    scanf("%f", &kmHora);

    // Convertimos los km/h a mph y lo guardamos en la variable mph

    mph = kmHora * 0.621371;

    // Imprimimos los datos

    printf("%.1f Km/h equivalen a %.2f mph.", kmHora, mph);


    return 0;
}