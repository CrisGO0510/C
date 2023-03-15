/*
 * Fecha de publicación: 4 de Marzo del 2023
 * Hora: 15:56
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Se pide hacer un programa de computadora, de tal forma que imprima lo mostrado en el diseño de pantalla:
 * Efecto de movimeinto:
            12345678
            
         -> A      A  <-
             A    A
              A  A
               AA
 */

#include <stdio.h>
#include <unistd.h>

void imp(int, int);

int main()
{
    imp(0, 6);

    return 0;
}

// Haremos la función que hace el efecto de "Moverse" a las filas que imprima la función esp
void imp(int incio, int intermedio)
{
    if (intermedio >= 0)
    {
        system("clear");
        esp(incio, 0);
        esp(intermedio, 1);
        sleep(1);
        imp(incio + 1, intermedio - 2);
    }
}

// Función que como parametro recibe: num que es la cantidad de espacios que se colocarán, y fin que definirá si la "A" tendrá salto de linea o no.

void esp(int num, int fin)
{
    // Condicional para determinar cuantas veces(num) se imprimirá el espacio
    if (num > 0)
    {
        printf(" ");
        esp(num - 1, fin);
    }
    else
    {
        // Si "fin" es verdadero significa que se debe imprimir "A" y un salto de linea, pero si es falso solo se imprime "A"
        if (fin)
        {
            printf("A\n");
        }
        else
        {
            printf("A");
        }
    }
}