/*
 * Fecha de publicación: 3 de Marzo del 2023
 * Hora: 16:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que lea desde el teclado un numero entero y lo imprima al revés.
 */

#include <stdio.h>
#include <math.h>

int main(){

    // Variable que alojará el numero ingresado por el usuario
    int numero = 0;

    printf("Este programa lee desde el teclado un número entero y lo imprime al revés.\nEntre el número: ");
    scanf("%i", &numero);

    // Imprimimos el numero ya invertido
    printf("\n%i", invertir(numero));

    return 0;
}

// Función para saber cuantos digitos tiene un número

int digitos(int num, int cont){

    if (num < 10)
    {
        // Retorna la cantidad que tenga el contador
        return cont;
    } else{
        // Volvemos a ejecutar la función y le aumentamos 1 al contador
        digitos(num / 10, cont + 1);
    }
}

// Función para invertir el número

int invertir(int num){

    if (num < 10)
    {
        // Cuando num solo tenga 1 digito retorna num
        return num;
    } else
    {
        /*
            Va retornar lo siguiente:
            1. saca el primer valor y lo multiplica por la cantidad digitos que tenia el numero ingresado para poner de primer lugar
            2. sumarle la recursión del mismo numero pero quitandole el numero que ya pusimos en la primera posición
            3. Repite el proceso hasta que el numero solo tenga 1 digito y simplemente lo suma
        */
        return (num % 10) * pow(10, digitos(num, 0)) + invertir(num / 10);
    }
}