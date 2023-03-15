/*
 * Fecha de publicación: 26 de febrero del 2023
 * Hora: 12:27
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que leyendo por teclado la antigüedad en años, que calcule el sueldo mensual que le corresponde al
 * trabajador de una empresa.
 */

#include <stdio.h>

int main()
{

    // Declaramos la variable donde se guardará los años de antigüedad del usuario
    int num = 0;

    // Pedimos los años de antigüedad al usuario
    printf("Entre el número de años de antigüedad del trabajador: ");
    scanf("%i", &num);

    // Condicional para saber cuanto aumento otorgarle al usuario

    if (num > 10)
    {
        // Se le aplica un aumento del 10%
        printf("el sueldo mensual es de %.2f euros", 40000 * 1.1 / 12);
    } // FIN DEL IF DEL AUMENTO DEL 10%
    else
    {
        if (num > 5)
        {
            // Se le aplica un aumento del 7%
            printf("el sueldo mensual es de %.2f euros", 40000 * 1.07 / 12);
        } // FIN DEL IF DEL AUMENTO DEL 7%
        else
        {
            if (num > 3)
            {
                // Se le aplica un aumento del 5%
                printf("el sueldo mensual es de %.2f euros", 40000 * 1.05 / 12);
            } // FIN DEL IF DEL AUMENTO DEL 5%
            else
            {
                // Se le aplica un aumento del 3%
                printf("el sueldo mensual es de %.2f euros", 40000 * 1.03 / 12);
            } // FIN DEL ELSE PARA AUMENTO DEL 3%
        }
    }

    return 0;
}