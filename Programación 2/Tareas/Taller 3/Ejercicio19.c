/*
 * Fecha de publicación: 7 de Marzo del 2023
 * Hora: 13:09
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

void imp(int, int);
void letras(int, char);

int main()
{
    imp(6, 0);
    imp(5, 1);

    return 0;
}

// Función que imprime el triangulo de A's a través de recursividad
/*
    num = cantidad de letras que van a ver por fila
    reverse = Variable que determinará a que dirección apunta el triangulo
*/
void imp(int num, int reverse)
{
    if (num > 0)
    {
        if (reverse == 0)
        {
            // Se ejecuta la piramide asiendo el llamado recursivo antes de imprimir
            imp(num - 1, reverse);
        }

        letras(34 - num, ' ');
        letras(num, 'A');
        printf("\n");

        if (reverse == 1)
        {
            // Se ejecuta la piramide inversa asiendo el llamado recursivo después de imprimir
            imp(num - 1, reverse);
        }
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