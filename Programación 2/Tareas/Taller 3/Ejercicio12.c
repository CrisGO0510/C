/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 17:17
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:

                           PPPPPPPPPPPPP
                            NNNNNNNNNNN
                             LLLLLLLLL
                              JJJJJJJ
                               HHHHH
                                FFF
                                 D
 */

#include <stdio.h>

void imp(int, int);
void letras(int, char);
char caracter(int);

int main()
{
    imp(13, 1);

    return 0;
}

// Función que imprime el triangulo de A's a través de recursividad
void imp(int num, int espacios)
{
    if (num > 0)
    {
        letras(espacios, ' ');
        letras(num, caracter(espacios));
        printf("\n");
        imp(num - 2, espacios + 1);
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

// Función que retorna el cáracter solicitado por numero

char caracter(int num)
{
    switch (num)
    {
    case 1:
        return 'P';
    case 2:
        return 'N';
    case 3:
        return 'L';
    case 4:
        return 'J';
    case 5:
        return 'H';
    case 6:
        return 'F';
    case 7:
        return 'D';
    default:
        return '*';
    }
}