void imp(int, int);
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

    do
    {
        lineas(num, espacios);
        // Hacemos el incremento a la variable num y el decremento a la variable espacio
        num++;
        espacios -= 2;
    } while (espacios > 0);

    // Redefinimos las variables con el valor para el siguiente ciclo
    num = 3;
    espacios = 1;
    // Imprimimos la linea de la mitad
    letras(7, 'P');
    printf("\n");

    do
    {
        lineas(num, espacios);

        // Hacemos el incremento a la variable espacio y el decremento a la variable num
        num--;
        espacios += 2;
    } while (num > 0);

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

// Función para imprimir los espacios y letras de una linea
void lineas(int num, int espacios)
{
    letras(num, 'P');
    letras(espacios, ' ');
    letras(num, 'P');
    printf("\n");
}