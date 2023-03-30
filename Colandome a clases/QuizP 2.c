/*
    Quiz programación II

    Programa que haga los siguientes pasos:

    - Eliminar el mayor de 4 numeros
    - Eliminar el menor de 3 numeros
    - Mostrar cual es mayor y cual menor

    Presentado a: Ing Luis Eduardo Muñoz
    Autor: Ing(c) Cristhian Giraldo Orozco

    Salvedad: Si se ingresan numeros iguales no se garantiza el resultado
*/

#include <stdio.h>

int algoritmo(int, int, int, int);

int main()
{

    algoritmo(3, 14, 6, 7);
    printf("\n");
    algoritmo(2, 3, 4, 5);
    printf("\n");
    algoritmo(11, 12, 7, 5);

    return 0;
}

int algoritmo(int num1, int num2, int num3, int num4)
{

    if (num1 > num2 && num1 > num3 && num1 > num4)
    {
        // Eliminamos num1 porque es el mayor

        if (num2 < num3 && num2 < num4)
        {
            // Eliminamos num2 porque es el menor
            if (num3 > num4)
            {
                // Imprimimos que num3 es mayor que num4
                printf("Mayor es: %i\nMenor es: %i", num3, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num4 es mayor que num3
                printf("Mayor es: %i\nMenor es: %i", num4, num3);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 2
        else if (num3 < num2 && num3 < num4)
        {
            // Eliminamos num3 porque es el menor
            if (num2 > num4)
            {
                // Imprimimos que num2 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num2, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num4 es mayor a num2
                printf("Mayor es: %i\nMenor es: %i", num4, num2);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 3
        else if (num4 < num2 && num4 < num3)
        {
            // Eliminamos num 4 porque es el menor
            if (num2 > num3)
            {
                // Imprimimos que num2 es mayor a num3
                printf("Mayor es: %i\nMenor es: %i", num2, num3);
                return 0;
            }
            else
            {
                // Imprimimos que num4 es mayor a num2
                printf("Mayor es: %i\nMenor es: %i", num4, num2);
                return 0;
            }

        } // FIN DEL IF MENOR NUM4

    } // FIN DEL IF MAYOR NUM 1
    else if (num2 > num1 && num2 > num3 && num2 > num4)
    {
        // Eliminamos num2 porque es el mayor

        if (num1 < num3 && num1 < num4)
        {
            // Eliminamos num1 porque es el menor

            if (num3 > num4)
            {
                // Imprimimos que num3 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num3, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num3 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num4, num3);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 1
        else if (num3 < num1 && num3 < num4)
        {
            // ELiminamos num3 porque es el menor

            if (num1 > num4)
            {

                // Imprimimos que num1 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num1, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num4 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num4, num1);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 3
        else if (num4 < num1 && num4 < num3)
        {
            // ELiminamos num4 porque es el menor

            if (num1 > num3)
            {
                // Imprimimos que num1 es mayor a num3
                printf("Mayor es: %i\nMenor es: %i", num1, num3);
                return 0;
            }
            else
            {
                // Imprimimos que num3 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num3, num1);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 4

    } // FIN DEL IF MAYOR NUM 2
    else if (num3 > num1 && num3 > num2 && num3 > num4)
    {
        // Eliminamos num3 porque es el mayor

        if (num1 < num2 && num1 < num4)
        {
            // Eliminamos num1 porque es el menor

            if (num2 > num4)
            {
                // Imprimimos que num2 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num2, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num2 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num4, num2);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 1
        else if (num2 < num1 && num2 < num4)
        {
            // ELiminamos num2 porque es el menor

            if (num1 > num4)
            {

                // Imprimimos que num1 es mayor a num4
                printf("Mayor es: %i\nMenor es: %i", num1, num4);
                return 0;
            }
            else
            {
                // Imprimimos que num4 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num4, num1);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 2
        else if (num4 < num1 && num4 < num2)
        {
            // ELiminamos num4 porque es el menor

            if (num1 > num2)
            {
                // Imprimimos que num1 es mayor a num2
                printf("Mayor es: %i\nMenor es: %i", num1, num2);
                return 0;
            }
            else
            {
                // Imprimimos que num2 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num2, num1);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 4

    } // FIN DEL IF NUM 3
    else if (num4 > num1 && num4 > num2 && num4 > num3)
    {
        // Eliminamos num4 porque es el mayor

        if (num1 < num2 && num1 < num3)
        {
            // Eliminamos num1 porque es el menor

            if (num2 > num3)
            {
                // Imprimimos que num2 es mayor a num3
                printf("Mayor es: %i\nMenor es: %i", num2, num3);
                return 0;
            }
            else
            {
                // Imprimimos que num2 es mayor a num3
                printf("Mayor es: %i\nMenor es: %i", num3, num2);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 1
        else if (num2 < num1 && num2 < num3)
        {
            // ELiminamos num2 porque es el menor

            if (num1 > num3)
            {

                // Imprimimos que num1 es mayor a num3
                printf("Mayor es: %i\nMenor es: %i", num1, num3);
                return 0;
            }
            else
            {
                // Imprimimos que num3 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num3, num1);
                return 0;
            }

        } // FIN DEL IF MENOR NUM 2
        else if (num3 < num1 && num3 < num2)
        {
            // ELiminamos num3 porque es el menor

            if (num1 > num2)
            {
                // Imprimimos que num1 es mayor a num2
                printf("Mayor es: %i\nMenor es: %i", num1, num2);
                return 0;
            }
            else
            {
                // Imprimimos que num2 es mayor a num1
                printf("Mayor es: %i\nMenor es: %i", num2, num1);
                return 0;
            }
        }

    } // FIN DEL IF NUM 4
    else
    {
        printf("Error al ingresar los numeros");
    }
}