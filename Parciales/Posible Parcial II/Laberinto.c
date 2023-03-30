//* No tengo ni idea de como hacer el laberinto pero se intentará

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char randomNum();
void murosExteriores(char[900], int);
void imp(char[900]);
int validacionesPrincipales(char[900], int);
int encontrarNum(int[675], int);

int main()
{
    // Cambiamos la semilla a una generada por el tiempo actual del dispositivo
    srand(time(NULL));

    // Declaramos el tablero del laberinto
    char tablero[900] = "";

    // Declaramos el vector para poder recorrer el laberinto
    int buscador[675] = {};

    // Declaramos variable que generará la salida
    int salida = (rand() % 28 + 1) * 30;

    for (size_t i = 0; i < 900; i++)
    {
        // Asignamos el valor random (0 o 1) a la posición del tablero[i]
        tablero[i] = randomNum();
    }

    // Añadimos los muros o periferia
    murosExteriores(tablero, salida);

    // imprimimos el tablero
    imp(tablero);

    // // Definimos si es posible resolverlo
    // validacionesPrincipales(tablero, salida);

    // buscarSalida(tablero, buscador, salida);
}

// ? Función que retorna un '1' con un 25% y un '0' con un 75%
char randomNum()
{
    char caracter;

    // Genera un numero aleatorio entre el 0 y el 3, si el numero es 0 retorna 0, y si es 1, 2 o 3, retorna 1. Con eso obtengo un 75% de que salga '0' y un 25% de que salga '1'
    if (rand() % 4 == 0)
    {
        caracter = '1';
    }
    else
    {
        caracter = '0';
    }

    return caracter;
}

// ? Función para crear la periferia
void murosExteriores(char tablero[900], int salida)
{
    // creando los muros superiores
    for (int i = 0; i < 30; i++)
    {
        tablero[i] = '1';
    }
    // creando los muros inferiores
    for (int i = 870; i < 900; i++)
    {
        tablero[i] = '1';
    }
    // creando los muros laterales izquierdos
    for (int i = 1; i < 29; i++)
    {
        tablero[i * 30] = '1';
    }
    // creando los muros laterales derechos
    for (int i = 2; i < 30; i++)
    {
        tablero[(i * 30) - 1] = '1';
    }

    // Genero la entrada
    tablero[0] = '0', tablero[1] = '0', tablero[30] = '0';

    // Generamos la salida de forma aleatoria
    tablero[salida - 1] = '0';
}

// ? Imprimimos el primer formato del tablero
void imp(char tablero[900])
{
    // Declaramos una variable con la que controlaremos los espacios entre el numero y el tablero
    char espacios[6] = "     ";

    printf("  %s012345678901234567890123456789\n %s+------------------------------+\n0%s|", espacios, espacios, espacios);

    for (int i = 0; i < 900; i++)
    {
        // Si "i" llega a 100 significa que los numeros laterales ya tienen 2 cifras, por lo tanto quitamos 1 espacio al "espacios", para que se alinee
        if (i >= 300 && strlen(espacios) == 5)
        {
            // Afirmamos que espacios tenga 5 espacios para que no se reste inecesariamente
            espacios[4] = '\0';
        }

        // Si "i" Es multiplo de 30 hacemos un salto de linea
        if (i % 30 == 0 && i != 0)
        {
            printf("|%i\n%i%s|", (i / 30) - 1, i / 30, espacios);
        }

        // Imprimimos " " o "█", si tablero[i] es igual a 0 o a 1 respectivamente
        if (tablero[i] == '0')
        {
            printf(" ");
        }
        else
        {
            printf("█");
        }
    }

    printf("|29\n  %s+------------------------------+\n%s   012345678901234567890123456789\n\n", espacios, espacios);
}

// ? Función para determinar si el laberinto se puede resolver (Solo excepciones principales)
int validacionesPrincipales(char tablero[900], int salida)
{
    if (tablero[31] == '1' || tablero[salida - 2] == '1')
    {
        // Si estas condiciones se cumplen, significa que la entrada o salida esta obtruida y no se puede pasar
        printf("No tiene solución\n");
        return 0;
    }
    return 1;
}

// ? Función para buscar la salida con un vector que recorra cada uno de los cuadros
void buscarSalida(char tablero[900], int buscador[675], int salida)
{
    // Declaramos la variable para controlar los movimientos del vector (buscador)
    int i = 0;

    // Declaramos la variable donde guardaremos la posición del vector (buscador)
    int k = 0;

    while (buscador[k] == tablero[salida - 1] || k < 10)
    {

        printf("numero: %i\n", i);

        // Se verificará a que dirección irá el cursor, la prioridad es la siguiente →, ↓, ↑, ←.
        if (tablero[i + 1] == '0' && buscador[k-1] != i)
        {
            // Si a la derecha hay una posición libre se irá a ese lugar
            buscador[++k] = ++i;
        }
        else if (tablero[i + 30] == '0' && buscador[k-1] != i)
        {
            // Asignamos la posición de abajo al buscador
            i += 30;

            // Si a la derecha no hay una posición disponible verificará si puede subir
            buscador[++k] = i;
        }
        else if (tablero[i - 30] == '0' && buscador[k-1] != i)
        {
            // Asignamos la posición de arriba al buscador
            i -= 30;

            // Si arriba no hay una posición disponible verificará si puede bajar
            buscador[++k] = i;
        }
        else if (tablero[i - 1] == '0' && buscador[k-1] != i)
        {
            // Si no se puede bajar verificará si puede ir a la izquierda
            buscador[++k] = --i;
        }
    }

    printf("Acabó");
}

// ? Función para validar si un elemento existe en un vector
int encontrarNum(int vec[675], int num)
{
    // Bucle para comparar cada posición de memoria con la variable "num"
    for (int i = 0; i < 675; i++)
    {
        // Condicional para saber si los numeros "vec[i]" y "num" son iguales
        if (vec[i] == num)
        {
            // Si se encuentra el valor retorna 0
            return 0;
        }
    }
    // Si en el for vec[i] no encuentra ningún valor igual a "num" retorna 1
    return 1;
}