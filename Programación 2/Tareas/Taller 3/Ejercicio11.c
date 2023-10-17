/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 16:39
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:
 
                                                                               A  1
                                                                              AA  2
                                                                             AAA  3
                                                                            AAAA  4
                                                                           AAAAA  5
                                                                          AAAAAA  6
                                                                         AAAAAAA  7
                                                                        AAAAAAAA  8
                                                                       AAAAAAAAA  9
                                                                      AAAAAAAAAA  10
                                                                     AAAAAAAAAAA  11
                                                                    AAAAAAAAAAAA  12
                                                                   AAAAAAAAAAAAA  13
                                                                  AAAAAAAAAAAAAA  14
                                                                 AAAAAAAAAAAAAAA  15
                                                                AAAAAAAAAAAAAAAA  16
                                                               AAAAAAAAAAAAAAAAA  17
                                                              AAAAAAAAAAAAAAAAAA  18
                                                             AAAAAAAAAAAAAAAAAAA  19
                                                            AAAAAAAAAAAAAAAAAAAA  20
                                                           AAAAAAAAAAAAAAAAAAAAA  21
                                                          AAAAAAAAAAAAAAAAAAAAAA  22
                                                         AAAAAAAAAAAAAAAAAAAAAAA  23
                                                        AAAAAAAAAAAAAAAAAAAAAAAA  24
                                                       AAAAAAAAAAAAAAAAAAAAAAAAA  25
 */

#include <stdio.h>

void imp(int);

int main()
{
    imp(25);

    return 0;
}

// Función que imprime el triangulo de A's a través de recursividad
void imp(int num)
{
    if (num > 0)
    {
        imp(num - 1);
        letras(80 - num, ' ');
        letras(num, 'A');
        printf("\n");
    }
}

// Función que imprime la cantidad(num) de veces el caracter (caracter) enviado como parametro
void letras(int num, char caracter)
{
    // Condicional para determinar cuantas veces(num) se imprimirá el cáracter
    if (num > 0)
    {
        printf("%c", caracter);
        letras(num - 1, caracter);
    }
}