#include <stdio.h>

int main()
{

    char tablero[9] = "         ";
    char turno = 'X';

    palabra(tablero, turno, 9);

    return 0;
}

void impTabla(char tabla[9])
{
    system("clear");
    printf("%c|%c|%c\n", tabla[0], tabla[1], tabla[2]);
    printf("-----\n");
    printf("%c|%c|%c\n", tabla[3], tabla[4], tabla[5]);
    printf("-----\n");
    printf("%c|%c|%c\n", tabla[6], tabla[7], tabla[8]);

    /* Resultado=
        0|1|2
        -----
        3|4|5
        -----
        6|7|8   */
}

int win(char tabla[9])
{
    // * Crearemos una condicional la cual evaluará cada una de las formas de ganar (8), analizando las posiciones y verificando si hay 3 seguidas iguales

    if (tabla[0] == tabla[3] && tabla[0] == tabla[6] && tabla[0] != ' ')
    {
        // * Hacemos la victoria de la primera columna
        return 1;
    }
    else if (tabla[1] == tabla[4] && tabla[1] == tabla[7] && tabla[1] != ' ')
    {
        // * Hacemos la victoria de la segunda columna
        return 1;
    }
    else if (tabla[2] == tabla[5] && tabla[2] == tabla[8] && tabla[2] != ' ')
    {
        // * Hacemos la victoria de la tercer columna
        return 1;
    }
    else if (tabla[0] == tabla[1] && tabla[0] == tabla[2] && tabla[0] != ' ')
    {
        // * Hacemos la victoria de la primera fila
        return 1;
    }
    else if (tabla[3] == tabla[4] && tabla[3] == tabla[5] && tabla[3] != ' ')
    {
        // * Hacemos la victoria de la segundo fila
        return 1;
    }
    else if (tabla[6] == tabla[7] && tabla[6] == tabla[8] && tabla[6] != ' ')
    {
        // * Hacemos la victoria de la tercer fila
        return 1;
    }
    else if (tabla[0] == tabla[4] && tabla[0] == tabla[8] && tabla[0] != ' ')
    {
        // * Hacemos la victoria de la primera diagonal ( \ )
        return 1;
    }
    else if (tabla[2] == tabla[4] && tabla[2] == tabla[6] && tabla[2] != ' ')
    {
        // * Hacemos la victoria de la segunda diagonal ( / )
        return 1;
    }
    return 0;
}

void palabra(char tabla[9], char turno, int intentos)
{
    impTabla(tabla);
    printf("\nEl jugador %c es el siguiente\n", turno);
    printf("\nIntentos: %i\n", intentos);
    // Le pedimos la usuario el espacio donde desea ingresar la letra actual
    int espacio = -1;
    printf("Por favor ingrese el espacio donde desea ingresar el cáracter: ");
    scanf("%i", &espacio);

    if (espacio > 8 || tabla[espacio] != ' ')
    {
        printf("Esta ocupado el espacio o se excedió el limite\n");
        palabra(tabla, turno, intentos);
    }
    else
    {

        tabla[espacio] = turno;

        if (win(tabla) == 1 || intentos <= 1)
        {
            // Se acabó el juego
            impTabla(tabla);
            printf("\nSe acabó el juego\n");
        }
        else
        {

            if (turno == 'X')
            {
                palabra(tabla, 'O', intentos - 1);
            }
            else
            {
                palabra(tabla, 'X', intentos - 1);
            }
        }
    }
}