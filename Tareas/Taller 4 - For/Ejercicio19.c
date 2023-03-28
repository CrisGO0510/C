/*
 * Fecha de publicación: 19 de Marzo del 2023
 * Hora: 13:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que imprima un efecto de "Movimiento" en el cuál 2 letras se acercan
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declaración de la función "esp"
void esp(int num);

int main()
{
    // Inicialización de las variables "inicio" e "intermedio"
    int inicio = 0;
    int intermedio = 80;

    // Ciclo que se ejecutará mientras "intermedio" sea mayor o igual a cero
    for (; intermedio >= 0;)
    {
        // Llamada a la función "system" para borrar la pantalla
        system("clear");

        // Llamada a la función "esp" para imprimir los espacios de la izquierda
        esp(inicio);

        // Llamada a la función "esp" para imprimir los espacios intermedios
        esp(intermedio);

        // Pausa la ejecución durante 50 milisegundos
        usleep(50000);

        // Incrementa la variable "inicio" y decrementa "intermedio" en 2 unidades
        inicio++;
        intermedio -= 2;
    }

    return 0;
}

// Definición de la función "esp"
void esp(int num)
{
    // Si "num" es mayor que cero, imprime la cantidad de espacios indicada por "num"
    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            printf(" ");
        }
    }

    // Imprime la letra "A" después de los espacios
    printf("A");

    // Limpia el buffer después de la impresión para evitar errores
    fflush(stdout);
}