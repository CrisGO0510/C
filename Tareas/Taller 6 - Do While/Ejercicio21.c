/*
 * Fecha de publicación: 20 de Marzo del 2023
 * Hora: 11:17
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

void letras(int, char);
char caracter(int);

int main()
{
    // Declaramos en la variable num la cantidad de letras que se imprimiran el la primera fila
    int num = 13;
    // Declaramos variable donde guardaremos los espacios
    int espacios = 0;
    // Declaramos varible con la que controlaremos las iteraciones y estableceremos cuantos caracteres se imprimirán
    int i = num;

    // Ciclo que imprime el triangulo de letras a través de un bucle
    do
    {
        // Imprimimos la cantidad "espacios" de espacios (' ')
        letras(espacios, ' ');
        // Imprimimos la cantidad de caracteres (i), el caracter retornado por la funcion caracter(espacios)
        letras(i, caracter(espacios + 1));
        printf("\n");
        // Hacemos el incremento de la variable "espacios" y a su vez hacemos el decremento de la variable "i"
        espacios++;
        i -= 2;
    } while (i > 0);

    return 0;
}

// Función que imprime la cantidad(num) de veces el caracter (caracter) enviado como parametro
void letras(int num, char caracter)
{
    // Declaramos varible con la que controlaremos las iteraciones y estableceremos cuantos caracteres se imprimirán
    int i = 0;

    // Ciclo para imprimir "num" veces el caracter "caracter"
    do
    {
        // Hacemos la condicional, debido a que al ser un do, va a entrar así el valor sea 0, es decir, 
        // como minimo imprime una vez, y en la primera fila (P), no nos interesa imprimir espacios

        if (num != 0)
        {
            printf("%c", caracter);
            // Hacemos el incremento de la variable i
            i++;
        }
    } while (i < num);
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
