/*
 * Fecha de publicación: YYYY/MM/DD
 * Hora: 00:00
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Lenguaje utilizado C(ISO/IEC) 201710
 * Versión del lenguaje utilizado
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Sistema Operativo: Arch Linux
 * Presentado a: PhD Ricardo Moreno Laverde
 * Universidad Tecnológica de Pereira
 * Descripción: Nos piden hacer un arreglo tridimencional de una resonacia magnetica, donde lo llenaremos de manera aleatoria con numeros entre el 0 y 255. Además debemos hacer:

 1. Función que determinado un punto (x, y, z) detecte si es sospechoso (valor entre el 20 y 40, esto incluye los puntos pertenecientes al mismo plano, al plano inferior y al plano superior).

 2. Función que para un determinado plano de la imagen, busque líneas sospechosas. Se considera una línea sospechosa toda línea HORIZONTAL (paralelas al eje X) en la que haya al menos tres(3) puntos sospechosos consecutivos, para esto se pide que imprima el plano

 3.
 Escribir un programa que emplee las funciones anteriormente descritas para identificar en una imagen si hay
alguna línea sospechosa y genere el siguiente informe(Ejemplo):

Plano en Z(Fotografia) | Líneas sospechosas x plano(foto) | Puntos sospechosos por plano(foto)
1                      | 0                                | 7
2                      | 3                                | 25
3                      | 0                                | 16
........               | ....                             | .....
97                     | 0                                | 4
98                     | 1                                | 5

* Los valores de todos los elementos de la matriz se supondrán ya cargados en memoria (no es necesario leerlos). En caso de que existan líneas sospechosas en la imagen, el programa mostrará en qué plano hay más líneas sospechosas (servirá para saber en qué lugar es mejor hacer una biopsia).

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ? Prototipos de las funciones:
int randomNum();
void imp(int[100][100][100], int);
int puntoSus(int[100][100][100], int, int, int);
int lineasSus(int[100][100][100], int, int[100][100][100]);
void rellenarLinea(int vector[100][100][100], int, int, int, int);

int main()
{
    srand(1);

    // Declaramos vector tridimencional (X, Y, Z), el cuál contendrá la resonancia, y sus valores seran [0,255]
    int resonancia[100][100][100];

    // Declaramos vector tridimencional (X, Y, Z), el cuál contendrá las lineas sospechosas de la resonancia y se rellenará de 0 y 1, siendo 0 espacios " " y 1 las lineas a imprimir "█"
    int vectorLineas[100][100][100];

    // Sentencia for para rellenar el vector de numeros seudoaleatorios entre el 0 y el 255
    // For para rellenar por cada iteración una "hoja" (Z).
    for (int z = 0; z < 100; z++)
    {
        // Sentencia for para rellenar por cada iteración una fila (X).
        for (int x = 0; x < 100; x++)
        {
            // Sentencia for para rellenar un punto por cada iteración (Y).
            for (int y = 0; y < 100; y++)
            {
                // Llamamos la función "randomNum" para conseguir rellenar el valor de ese punto (X, Y, Z), y la siguiente iteración pasamos al siguiente punto a la derecha.
                resonancia[x][y][z] = randomNum();

                // Rellenamos el vector de lineas de 0's junto al otro vector para ahorrar recursos
                vectorLineas[x][y][z] = 0;
            }
        }
    }

    printf("LINEAS = %i\n", lineasSus(resonancia, 1, vectorLineas));
    imp(vectorLineas, 1);

    return 0;
}

// ? Función que rellenará una fila de un vector desde Y valor hasta llegada con el valor 1
void rellenarLinea(int vector[100][100][100], int x, int y, int z, int llegada)
{
    // Hacemos un ciclo que rellenará las posiciones del vector
    while (y < llegada)
    {
        // Asignamos el valor
        vector[x][y++][z] = 1;
    }
}

// ? Función que retorna un numero seudoaleatorio
int randomNum()
{
    // Declaramos una variable que generará un número entre el 0 y el 255, para retornarlo luego
    int numeroSeudo = rand() % 25 + 20;

    return numeroSeudo;
}

// ? Función que imprime la resonancia (Vector) en la hoja(Z)
void imp(int vector[100][100][100], int z)
{
    // Imprimimos el valor de Z para guiarnos
    printf("Z: %i\n\n    ", z);

    // Sentencia for para imprimir las decenas del valor de la columna
    for (int i = 0; i < 90; i++)
    {
        // Cada 10 valores se le sumará 1 a la impresión
        if (i % 10 == 0)
        {
            // Imprimimos el valor de las decenas
            printf("         %i", i / 10 + 1);
        }
    } //! FIN DEL FOR PARA IMPRIMIR LAS DECENAS

    printf("\n   ");

    // Imprimimos el valor de las columnas
    for (int i = 0; i < 10; i++)
    {

        printf("0123456789");
    }

    // Imprimimos la linea separadora entre los numeros y la resonancia
    printf("\n  +----------------------------------------------------------------------------------------------------+\n");

    // Declaramos segunda sentencia for, para imprimir una fila(X) por cada iteración
    for (int x = 0; x < 100; x++)
    {
        // Imprimimos el valor de la fila(X)
        printf("%i |", x % 10);

        /* Sentencia for que me imprimirá uno a uno cada punto de la resonancia.
        Se consideran sospechosos aquellos puntos para los que TODOS los puntos adyacentes
        tengan un valor entre 20 y 40 (esto incluye los puntos pertenecientes al mismo plano,
        al plano inferior y al plano superior). */
        for (int y = 0; y < 100; y++)
        {
            // TODO: Condicional para determinar si imprime "█" ó " ".
            if (vector[x][y][z] == 1)
            {
                // Imprimimos que el punto es sospechoso "█"
                printf("█");
            }
            else
            {
                // Imprimimos que el punto NO es sospechoso " "
                printf(" ");
            }

        } //! FIN DEL FOR PARA IMRPIMIR PUNTOS EN Y
          // Imprimimos el valor de la fila(X)
        printf("| %i\n", x % 10);
    } //! FIN DEL FOR PARA IMPRIMIR LA LINEA X

    // Imprimimos la linea separadora entre los numeros y la resonancia
    printf("  +----------------------------------------------------------------------------------------------------+\n   ");

    // Imprimimos el valor de las columnas
    for (int i = 0; i < 10; i++)
    {
        printf("0123456789");
    }

    printf("\n   ");

    // Sentencia for para imprimir las decenas del valor de la columna
    for (int i = 0; i < 90; i++)
    {
        // Cada 10 valores se le sumará 1 a la impresión
        if (i % 10 == 0)
        {
            // Imprimimos el valor de las decenas
            printf("         %i", i / 10 + 1);
        }
    } //! FIN DEL FOR PARA IMPRIMIR LAS DECENAS

    printf("\n");
}

// ? Función que determina si un punto es sospechoso
int puntoSus(int vector[100][100][100], int x, int y, int z)
{
    /*
        Determinaremos si un punto es sospechoso sí alrededor de él hay los puntos están entre 20 y 40, tanto en la capa superior, actual e inferior.
        Es decir ni la hoja 0, ni la 99 se incluyen en este.
    */

    // Declaramos un variable que contará cuantos puntos adyacentes hay (deben haber 26)
    int cont = 0;

    // Primero hacemos las discriminantes

    // Ni en la primera, ni en la ultima capa puede haber un punto sospechoso
    if (z == 0 || z == 99)
    {
        return 0;
    }

    // Ni el la primera, ni en la ultima fila pueden haber puntos sospechosos
    if (x == 0 || x == 99)
    {
        return 0;
    }

    // Ni el la primera, ni en la ultima columna pueden haber puntos sospechosos
    if (y == 0 || y == 99)
    {
        return 0;
    }

    // Ahora verificaremos si la coordenada esta rodeada de puntos entre 20 y 40

    for (int k = -1; k <= 1; k++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int i = -1; i <= 1; i++)
            {
                // vector[x - i][y - j][z - k] = 40;

                // Condicional para saltarse el punto central
                if (k == 0 && j == 0 && i == 0)
                {
                    // Es el punto centra, por lo tanto lo ignora, y pasa a la siguiente iteración
                }
                else
                {
                    if (vector[x - i][y - j][z - k] >= 20 && vector[x - i][y - j][z - k] <= 40)
                    {
                        cont++;
                    }
                }

            } //! FIN DEL FOR PARA ANALIZAR LOS PUNTOS EN X

        } //! FIN DEL FOR PARA CAMBIAR EL VALOR DE Y

    } //! FIN DEL FOR PARA CAMBIAR EL VALOR DE Z

    // Condición que retorna 1 si es un punto sospechoso y 0 si no lo es
    if (cont == 26)
    {
        // Es sospechoso
        return 1;
    }
    else
    {
        // No es sospechoso
        return 0;
    }
}

// ? Función que buscará las lineas sospechosas en un plano Z
int lineasSus(int vector[100][100][100], int z, int vectorAuxiliar[100][100][100])
{
    // Declaramos una variable contador para saber cuantos puntos sospechosos hay en una linea
    int cont = 0;

    // Declaramos una variable contador para saber cuantas lineas en total hubieron en este plano
    int lineas = 0;

    // Hacemos un ciclo for que recorrerá las 99 filas de un plano(Z) del vector, para analizar donde y cuantas lineas sospechosas hay
    for (int x = 0; x < 100; x++)
    {
        // Hacemos un ciclo que recorrerá cada una de las posiciones de una fila, para analizar cuantas lineas sospechosas hay
        for (int y = 0; y < 100; y++)
        {
            // Verificamos si en la posición actual hay un punto sospechoso
            if (puntoSus(vector, x, y, z))
            {
                // Si se encuentra un punto sospechoso se incrementará en 1 el valor del contador(cont)
                cont++;
            } // ! FIN IF DE CUANDO ENCUENTRA PUNTO SOSPECHOSO
            else
            {
                // Si no es un punto sospechoso entramos a la siguiente condicional:

                // Si cont es mayor o igual a 3 significa que habia una linea y justo acabó, por lo guardamos los valores en el vectorAuxiliar, en caso contrario significa que no hay linea y solo hacemos el contador 0
                if (cont >= 3)
                {
                    // Rellenamos la linea con la función rellenar vec, restandole cont a y, para saber donde empezó y terminando en y que seria el fin de la linea
                    rellenarLinea(vectorAuxiliar, x, y - cont, z, y);

                    // Como encontramos una linea aumentamos en 1 la variable "lineas"
                    lineas++;
                } // ! FIN CONDICIONAL DE VERIFICACIÓN DE LINEA

                // Hacemos el contador 0 para seguir con la siguiente linea
                cont = 0;
            } // ! FIN DE ELSE CUANDO NO ENCUENTRA PUNTO SOSPECHOSO
        } // ! FIN FOR, DANDO PASO A LA SIGUIENTE POSICIÓN
    } // ! FIN FOR, DANDO PASO A LA SIGUIENTE FILA

    // Retornamos la cantidad de lineas en este plano
    return lineas;
}