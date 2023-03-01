/*
 * Fecha de publicación: 25 de febrero del 2023
 * Hora: 16:11
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida un número del 1 al 7 e imprima el día de la semana correspondiente.
 */

#include <stdio.h>

int main()
{

    // Declaramos la varible donde se guardará el numero del usuario
    int num = 0;

    // Pedimos el numero al usuario
    printf("Este programa, lee un número entre [1 y 7] e imprime el día que le corresponde en la semana. Referencia: 1=Lunes. 7=Domingo\nEntre un número: ");
    scanf("%i", &num);

    // Condicionales para determinar que dia de la semana es

    if (num == 1)
    {
        // Si num es 1 el dia de la semana equivalente seria el lunes
        printf("El dia es Lunes");
    } // FIN DEL IF DIA LUNES
    else
    {
        if (num == 2)
        {
            // Si num es 2 el dia de la semana equivalente seria el Martes
            printf("El dia es Martes");
        } // FIN DEL IF DIA MARTES
        else
        {
            if (num == 3)
            {
                // Si num es 3 el dia de la semana equivalente seria el Miercoles
                printf("El dia es Miercoles");
            } // FIN DEL IF DIA MIERCOLES
            else
            {
                if (num == 4)
                {
                    // Si num es 4 el dia de la semana equivalente seria Jueves
                    printf("El dia es Jueves");
                } // FIN DE IF DIA JUEVES
                else
                {
                    if (num == 5)
                    {
                        // Si num es 5 entonces el dia de la semana seria Viernes
                        printf("El dia es Viernes");
                    } // FIN DEL IF DIA VIERNES
                    else
                    {
                        if (num == 6)
                        {
                            // Si num es 6 entonces el dia de la semana seria Sábado
                            printf("El dia es Sábado");
                        } // FIN DEL IF DIA SÁBADO
                        else
                        {
                            if (num == 7)
                            {
                                // Si num es 7 entonces el dia de la semana seria Domingo
                                printf("El dia es Domingo");
                            } // FIN DE DIA DOMINGO
                        }
                    }
                }
            }
        }
    }

    return 0;
}