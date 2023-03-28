/*
 * Fecha de publicación: 20 de Marzo del 2023
 * Hora: 12:35
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

void letras(int, char);
void lineas(int, int);

int main()
{
    // Declaramos variable para determinar cuantas "A" se imprimiran
    int num = 1;

    // Declaramos variable para determinar cuantos espacios se imprimiran
    int espacios = 5;

    for (; espacios > 0;)
    {
        lineas(num, espacios);
        // Hacemos el incremento a la variable num y el decremento a la variable espacio
        num++;
        espacios -= 2;
    }

    // Redefinimos las variables con el valor para el siguiente ciclo
    num = 3;
    espacios = 1;
    // Imprimimos la linea de la mitad
    letras(7, 'P');
    printf("\n");

    for (; num > 0;)
    {
        lineas(num, espacios);

        // Hacemos el incremento a la variable espacio y el decremento a la variable num
        num--;
        espacios += 2;
    }

    return 0;
}

// Función que imprime la cantidad(num) de veces el caracter (caracter) enviado como parametro
void letras(int num, char caracter)
{
    for (int i = 0; i < num; i++)
    {
        printf("%c", caracter);
    }
}

// Función para imprimir los espacios y letras de una linea
void lineas(int num, int espacios)
{
    letras(num, 'P');
    letras(espacios, ' ');
    letras(num, 'P');
    printf("\n");
}