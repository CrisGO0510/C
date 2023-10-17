/*
 * Fecha de publicación: 21 de Marzo del 2023
 * Hora: 15:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa de computador, de tal manera que presente lo siguiente en la pantalla:
 
                                            Z   <--- Debe estar en la columna 10
                                           Z Z
                                          Z   Z
                                         Z     Z
                                        Z       Z
                                       Z         Z
                                      Z           Z
                                     Z             Z
                                    Z               Z
                                   Z                 Z

                                   1234567890123456789
 */

#include <stdio.h>

// Declaración de la función "esp"
void esp(int, int);

int main()
{
    // Inicialización de las variables "inicio" e "intermedio"
    int inicio = 8;
    int intermedio = 1;

    // Imprimimos la letra inicial
    esp(9, 1);

    // Ciclo que se ejecutará mientras "intermedio" sea mayor o igual a cero
    for (; inicio >= 0;)
    {
        // Llamada a la función "esp" para imprimir los espacios de la izquierda
        esp(inicio, 0);

        // Llamada a la función "esp" para imprimir los espacios intermedios
        esp(intermedio, 1);

        // Incrementa la variable "inicio" y decrementa "intermedio" en 2 unidades
        inicio--;
        intermedio += 2;
    }


    return 0;
}

// Definición de la función "esp"
void esp(int num, int final)
{
    // Si "num" es mayor que cero, imprime la cantidad de espacios indicada por "num"
    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            printf(" ");
        }
    }

    // Evaluamos la variable "final" para saber si se requiere salto de linea o no,
    if (final)
    {
        // Se necesita salto de linea
        printf("Z\n");
    }
    else
    {
        // No se requiere un salto de linea
        printf("Z");
    }
}