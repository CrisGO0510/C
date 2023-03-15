/*
 * Fecha de publicación: 26 de febrero del 2023
 * Hora: 12:47
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida un número y diga si es mayor de 100
 */

#include <stdio.h>

int main(){

    // Declaramos la variable donde se va a guardar el numero ingresado por el usuario
    int num = 0;

    // Le pedimos un numero al usuario
    printf("Este programa leyendo por teclado un numero ingresado por el usuario, define si es mayor a 100.\nIngrese un número: ");
    scanf("%i", &num);

    // Condicional para saber si el numero es mayor a 100
    if (num > 100)
    {
        printf("El numero es mayor a 100");
    }
    

    return 0;
}