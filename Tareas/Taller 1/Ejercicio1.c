/*
 * Fecha de publicación: 17 de febrero del 2023
 * Hora: 19:31
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa para pasar de grados centigrados a grados farenheit
 */

#include <stdio.h>

int main()
{

    // Definimos variables

    /*
    Variable que usaremos para asignarle el valor de los grados
    centigrados ingresados por el usuario
    */
    float cen = 0;
    /*
    Variable en la cual usaremos para alojar el valor convertido de grados
    centigrados a grados farenheit
    */
    float faren = 0;

    /*
    Imprimimos en pantalla un mensaje para el usuario y creamos un scanf
    para poder que el usuario ingrese los grados
    */
    printf("Por favor ingrese los grados centigrados a convertir a Farenheit: ");
    scanf("%f", &cen);

    /*
    Acá redefinimos la variable faren con la formula para pasar de centigrados a
    farenheit y obtenemos el valor del los farenheit
    */
    faren = cen * 9 / 5 + 32;

    /*
    Le mostramos el valor de los grados farenheit
    */
    printf("%.1f°C son %.1f grados Farenheit", cen, faren);
}