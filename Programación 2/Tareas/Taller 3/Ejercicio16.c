/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 16:40
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

void impUp(int, int);
void impDown(int, int);
void letras(int, char);

int main()
{
    impUp(7, 1);
    impDown(5, 2);

    return 0;
}

// Función que imprime la piramide superior
void impUp(int num, int espacios)
{

    if (num > 0)
    {
        impUp(num - 2, espacios + 1);
        letras(espacios + 5, ' ');
        letras(num, 'Z');
        printf("\n");
    }
}

// Función que imprime la piramide inversa inferior
void impDown(int num, int espacios)
{
    if (num > 0)
    {
        letras(espacios + 5, ' ');
        letras(num, 'Z');
        printf("\n");
        impDown(num - 2, espacios + 1);
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