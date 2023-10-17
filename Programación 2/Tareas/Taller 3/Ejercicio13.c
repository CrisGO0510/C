/*
 * Fecha de publicación: 5 de Marzo del 2023
 * Hora: 17:35
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
                                       P   <--- Debe estar en la columna 40
 */

#include <stdio.h>

void imp(int, int);
void letras(int, char);

int main()
{
    imp(13, 1);

    return 0;
}

// Función que imprime el triangulo de P's a través de recursividad
/*
    num = cantidad de "P" a imprimir por linea
    espacios = cantidad de espacios a imprimir antes de cada p
*/
void imp(int num, int espacios)
{
    if (num > 0)
    {
        letras(espacios + 32, ' ');
        letras(num, 'P');
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