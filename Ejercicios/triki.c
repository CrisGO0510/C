/*
 * Fecha de publicación:
 * Hora:
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C - 2017
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Descripción: Programa de un triki o 3 en raya
 */

#include <stdio.h>
#include <stdlib.h>

// Definimos 2 macros para determinar cual va a ser el simbolo de cada jugador, lo hacemos de este modo para en caso de querer poner otro simbolo sea mas sencillo cambiarlo

#define jugador1 'X'
#define jugador2 'O'

// Prototipos

void impTabla(char[3][3]);
int win(char[3][3]);
void turno(char *, char[3][3]);

int main()
{

    // * Declaramos la matriz que simulará el tablero

    char tablero[3][3] = {"   ", "   ", "   "};

    // * Declaramos la variable que determinará cual es el jugador que sigue X o O
    char jugador = jugador1;

    // * Variable para poder parar el programa en caso de empate
    int i = 0;

    // * Creamos un while que no pare hasta que hayan pasado 9 acciones o alguno haya ganado

    while (i >= 9 || win(tablero) == 0)
    {
        // Imprimimos el tablero
        impTabla(tablero);

        // Pedimos la coordenada que rellenará el jugador actual
        turno(&jugador, tablero);

        i++;
    }

    impTabla(tablero);
    printf("FIN DEL JUEGO");

    return 0;
}

/*
 ? Haremos una función la cuál, limpiará la pantalla, imprimirá los nuevos datos del vector y organizará todo en una tabla de triki.
 */

void impTabla(char tabla[3][3])
{
    system("clear");
    printf("%c|%c|%c\n", tabla[0][0], tabla[0][1], tabla[0][2]);
    printf("-----\n");
    printf("%c|%c|%c\n", tabla[1][0], tabla[1][1], tabla[1][2]);
    printf("-----\n");
    printf("%c|%c|%c\n", tabla[2][0], tabla[2][1], tabla[2][2]);

    /* Resultado=
        0|1|2
        -----
        3|4|5
        -----
        6|7|8   */
}

// ? Haremos una función la cual determinará si un jugador ganó, esto lo hará determinando todas las posibles victorias, si alguna es cierta retorna 1, si no ha ganado retorna 0

int win(char tabla[3][3])
{
    // * Crearemos una condicional la cual evaluará cada una de las formas de ganar (8), analizando las posiciones y verificando si hay 3 seguidas iguales

    if (tabla[0][0] == tabla[1][0] && tabla[0][0] == tabla[2][0] && tabla[0][0] != ' ')
    {
        // * Hacemos la victoria de la primera columna
        return 1;
    }
    else if (tabla[0][1] == tabla[1][1] && tabla[0][1] == tabla[2][1] && tabla[0][1] != ' ')
    {
        // * Hacemos la victoria de la segunda columna
        return 1;
    }
    else if (tabla[0][2] == tabla[1][2] && tabla[0][2] == tabla[2][2] && tabla[0][2] != ' ')
    {
        // * Hacemos la victoria de la tercer columna
        return 1;
    }
    else if (tabla[0][0] == tabla[0][1] && tabla[0][0] == tabla[0][2] && tabla[0][0] != ' ')
    {
        // * Hacemos la victoria de la primera fila
        return 1;
    }
    else if (tabla[1][0] == tabla[1][1] && tabla[1][0] == tabla[1][2] && tabla[1][0] != ' ')
    {
        // * Hacemos la victoria de la segundo fila
        return 1;
    }
    else if (tabla[2][0] == tabla[2][1] && tabla[2][0] == tabla[2][2] && tabla[2][0] != ' ')
    {
        // * Hacemos la victoria de la tercer fila
        return 1;
    }
    else if (tabla[0][0] == tabla[1][1] && tabla[0][0] == tabla[2][2] && tabla[0][0] != ' ')
    {
        // * Hacemos la victoria de la primera diagonal ( \ )
        return 1;
    }
    else if (tabla[0][2] == tabla[1][1] && tabla[0][2] == tabla[2][0] && tabla[0][2] != ' ')
    {
        // * Hacemos la victoria de la segunda diagonal ( / )
        return 1;
    }
    return 0;
}

// ? Haremos una función para ingresar el valor el espacio vacío

/*
    * Varibles que usaremos

    player = variable para saber que jugador sigue puede ser 1 o 2
    x = fila en donde se pondrá el cáracter
    y = columna en donde se pondrá el cáracter

    tabla[y][x] es la coordenada del vector con respecto a la tabla el numero es [0,2]
*/
void turno(char *player, char tabla[3][3])
{

    // Declaramos la s variables que usaremos como coordenadas
    int x = 0;
    int y = 0;
    // Variable que usaremos en un bucle en caso de que el usuario cometa errores
    int i = 0;

    // Pedimos las coordenadas al usuario

    do
    {
        // * Creamos un do while para que ejecute una vez el programa y en caso de que el usuario haya ingresado un programa fuera del rango vuelva a pedir los datos

        printf("\nPor favor ingrese en que coordenada X donde quiere poner la letra %c: ", *player);
        scanf("%i", &x);

        printf("Por favor ingrese en que coordenada Y donde quiere poner la letra %c: ", *player);
        scanf("%i", &y);

        if (x < 3 && x >= 0 && y < 3 && y >= 0)
        {
            // No hubo desbordamiento y finalizamos el bucle
            i = 1;
        }
        else
        {
            printf("\n\033[31mCOORDENADAS FUERA DEL RANGO ESTABLECIDO\nPOR FAVOR INGRESAR UN NÚMERO DEL 0 AL 3\033[0m\n");
        }

    } while (i == 0);

    if (tabla[y][x] == ' ')
    {
        // Ingresamos el simbolo del jugador actual en las coordenadas ingresadas por el usuario
        tabla[y][x] = *player;

        // Cambiamos de jugador

        if (*player == jugador1)
        {
            // Asignamos otro jugador
            *player = jugador2;
        }
        else
        {
            // Asignamos otro jugador
            *player = jugador1;
        }
    }
    else
    {
        // En caso de que se haya ingresado una coordenada ocupada se ejecutará de nuevo la
        printf("El espacio está ocupado");
        turno(player, tabla);
    }
}