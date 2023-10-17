/*
 * Fecha de publicación: 20 de Marzo del 2023
 * Hora: 11:40
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:

                                 PPPPPPPPPPPPP
                                  PPPPPPPPPPP
                                   PPPPPPPPP
                                    PPPPPPP
                                     PPPPP
                                      PPP
                                       P   <--- Debe estar en la columna 7
 */

#include <stdio.h>

void letras(int, char);

int main()
{
    // Declaramos en la variable num la cantidad de letras que se imprimiran el la primera fila
    int num = 13;
    // Declaramos variable donde guardaremos los espacios
    int espacios = 0;

    // Ciclo que imprime el triangulo de letras a través de un bucle for
    for (int i = num; i > 0; i -= 2)
    {
        // Imprimimos la cantidad "espacios" de espacios (' ')
        letras(espacios, ' ');
        // Imprimimos la cantidad de caracteres (i), el caracter retornado por la funcion caracter(espacios)
        letras(i, 'P');
        printf("\n");
        // Hacemos el incremento de la variable "espacios" y a su vez hacemos el decremento de la variable "i"
        espacios++;
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