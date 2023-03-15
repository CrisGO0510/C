/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 13:35
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: 15.Hacer un programa de computador, de tal manera que presente lo siguiente en la pantalla:

                                        A     A
                                        AA   AA
                                        AAA AAA
                                        AAAAAAA
                                        AAA AAA
                                        AA   AA
                                        A     A
 */

#include <stdio.h>

void imp(int, int);
void letras(int, char);
void lineas(int, int);

int main()
{
    imp(1, 5);

    return 0;
}

// Función que imprime el patrón de A's a través de recursividad
void imp(int num, int espacios)
{
    if (espacios > 0)
    {
        // Forma inicial del patrón
        lineas(num,espacios);
        printf("\n");
        imp(num + 1, espacios - 2);
        printf("\n");
        lineas(num, espacios);
    }
    else if (espacios == -1)
    {
        // imprimimos la parte de la mitad del patrón
        letras(7, 'P');
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

// Función para imprimir los espacios y letras de una linea
void lineas(int num, int espacios)
{
    letras(num, 'P');
    letras(espacios, ' ');
    letras(num, 'P');
}