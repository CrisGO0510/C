/*
 * Fecha de publicación: 20 de Marzo del 2023
 * Hora: 13:40
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:

                              1234567890123
                                       Z
                                      ZZZ
                                     ZZZZZ
                                    ZZZZZZZ
                                     ZZZZZ
                                      ZZZ
                                       Z   <--- Debe estar en la columna 10
 */

#include <stdio.h>

int main()
{
    // Declaramos las variables para imprimir los caracteres "num", espacios "espacios"
    int num, espacios;

    espacios = 4;
    num = 1;

    // Imprime la piramide superior
    while (num < 7)
    {
        letras(espacios, ' ');
        letras(num, 'Z');
        printf("\n");
        espacios--;
        num += 2;
    }

    // Imprime la piramide inferior
    while (num > 0)
    {
        letras(espacios, ' ');
        letras(num, 'Z');
        printf("\n");
        espacios++;
        num -= 2;
    }

    return 0;
}

// Función que imprime la cantidad(num) de veces el caracter (caracter) enviado como parametro
void letras(int num, char caracter)
{
    // Declaramos varible con la que controlaremos las iteraciones y estableceremos cuantos caracteres se imprimirán
    int i = 0;

    // Ciclo para imprimir "num" veces el caracter "caracter"
    while (i < num)
    {
        printf("%c", caracter);
        // Hacemos el incremento de la variable i
        i++;
    }
}