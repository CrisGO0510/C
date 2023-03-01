/*
 * Fecha de publicación: 25 de febrero del 2023
 * Hora: 16:27
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHP Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que pida un número del 1 al 12 e imprima el nombre del mes correspondiente.
 */

#include <stdio.h>

int main()
{

    // Declaramos la variable donde se va a guardar el numero ingresado por el usuario
    int num = 0;

    // Le pedimos un numero al usuario
    printf("Este programa, lee un número entre [1 y 12] e imprime el mes que le corresponde en el año. Referencia: 1=Enero. 12=Diciembre\nEntre un número: ");
    scanf("%i", &num);

    if (num == 1)
    {
        // Si num es 1 el mes es Enero
        printf("El mes es Enero");
    } // FIN DEL IF MES Enero
    else
    {
        if (num == 2)
        {
            // Si num es 2 el mes es Febrero
            printf("El mes es Febrero");
        } // FIN DEL IF MES FEBRERO
        else
        {
            if (num == 3)
            {
                // Si num es 3 el mes es Marzo
                printf("El mes es Marzo");
            } // FIN DEL IF MES MARZO
            else
            {
                if (num == 4)
                {
                    // Si num es 4 el mes es Abril
                    printf("El mes es Abril");
                } // FIN DEL IF MES Abril
                else
                {
                    if (num == 5)
                    {
                        // Si num es 1 el mes es Mayo
                        printf("El mes es Mayo");
                    } // FIN DEL IF MES MAYO
                    else
                    {
                        if (num == 6)
                        {
                            // Si num es 6 el mes es Junio
                            printf("El mes es Junio");
                        } // FIN DEL IF MES JUNIO
                        else
                        {
                            if (num == 7)
                            {
                                // Si num es 7 el mes es Julio
                                printf("El mes es Julio");
                            } // FIN DEL IF MES JULIO
                            else
                            {
                                if (num == 8)
                                {
                                    // Si num es 8 el mes es Agosto
                                    printf("El mes es Agosto");
                                } // FIN DEL IF MES AGOSTO
                                else
                                {
                                    if (num == 9)
                                    {
                                        // Si num es 9 el mes es Septiembre
                                        printf("El mes es Septiembre");
                                    } // FIN DEL IF MES SEPTIEMBRE
                                    else
                                    {
                                        if (num == 10)
                                        {
                                            // Si num es 10 el mes es Octubre
                                            printf("El mes es Octubre");
                                        } // FIN DEL IF MES OCTUBRE
                                        else
                                        {
                                            if (num == 11)
                                            {
                                                // Si num es 11 el mes es Noviembre
                                                printf("El mes es Noviembre");
                                            } // FIN DEL IF MES NOVIEMBRE
                                            else
                                            {
                                                if (num == 12)
                                                {
                                                    // Si num es 12 el mes es DICIEMBRE
                                                    printf("El mes es Diciembre");
                                                } // FIN DEL IF MES DICIEMBRE
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}