/*
 * Fecha de publicación: 19 de febrero del 2023
 * Hora: 16:29
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Código que representa una serie de operaciones matematicas
 */

#include <stdio.h>
#include <math.h>

int main(){

    // Declaramos variable donde guardaremos el resultado de la operación

    float x = 0;

    // Asignamos a la variable la serie de operaciones matematicas

    x = (17.0/11.0 + 23.0/2.0) / (943.0/120.0 + sqrt(144));
    
    // Imprimimos el resultado

    printf("El resultado es %f", x);

    return 0;
}