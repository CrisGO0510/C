/*
 * Fecha de publicación: 21 de Marzo del 2023
 * Hora: 15:15
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:

                                 A
                                AA
                               AAA
                              AAAA
                             AAAAA
                            AAAAAA <--- Debe ser columna 40 y fila 6
                             AAAAA
                              AAAA
                               AAA
                                AA
                                 A
 */

#include <stdio.h>

int main()
{
    // Declaramos las variables para imprimir los caracteres "num", espacios "espacios"
    int num, espacios;

    espacios = 5;
    num = 1;

    // Imprime el triangulo superior
    while (num < 6)
    {
        letras(34 + espacios, ' ');
        letras(num, 'A');
        printf("\n");
        espacios--;
        num++;
    }

    // Imprime el triangulo inferior
    while (num > 0)
    {
        letras(34 + espacios, ' ');
        letras(num, 'A');
        printf("\n");
        espacios++;
        num--;
    }

    return 0;
}

// Función que imprime la cantidad(num) de veces el caracter (caracter) enviado como parametro
void letras(int num, char caracter)
{
    // Declaramos la variable con la cual controlaremos las iteraciones
    int i = 0;

    while (i < num)
    {
        printf("%c", caracter);

        // Hacemos el incremento a la variable i
        i++;
    }
}