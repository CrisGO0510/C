#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int puntoSus(int[80][80][80], int, int, int);

// ? Función que imprime la resonancia (Vector) en la hoja(Z)
void imp(int vector[80][80][80], int z)
{
  
   for (int x = 0; x < 80; x++)
   {
      // Imprimimos el valor de la fila(X)
      printf("%i |", x % 10);

      /* Sentencia for que me imprimirá uno a uno cada punto de la resonancia.
      Se consideran sospechosos aquellos puntos para los que TODOS los puntos adyacentes
      tengan un valor entre 20 y 40 (esto incluye los puntos pertenecientes al mismo plano,
      al plano inferior y al plano superior). */
      for (int y = 0; y < 80; y++)
      {
         // TODO: Condicional para determinar si imprime "█" ó " ".
         if (puntoSus(vector, x, y, z))
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
      printf("| %i\n", x);
   } //! FIN DEL FOR PARA IMPRIMIR LA LINEA X

}

int main()
{
    srand(time(NULL));          // Semilla para generar los números aleatorios
   // Declaramos vector tridimencional (X, Y, Z), el cuál contendrá la resonancia, y sus valores seran [0,255]
   // Declaramos vector tridimencional (X, Y, Z), el cuál contendrá la resonancia, y sus valores seran [0,255]
   int resonancia[80][80][80];

   // Declaramos vector tridimencional (X, Y, Z), el cuál contendrá las lineas sospechosas de la resonancia y se rellenará de 0 y 1, siendo 0 espacios " " y 1 las lineas a imprimir "█"
   int vectorLineas[80][80][80];

   // Sentencia for para rellenar el vector de numeros seudoaleatorios entre el 0 y el 255
   // For para rellenar por cada iteración una "hoja" (Z).
   for (int z = 0; z < 80; z++)
   {
      // Sentencia for para rellenar por cada iteración una fila (X).
      for (int x = 0; x < 80; x++)
      {
         // Sentencia for para rellenar un punto por cada iteración (Y).
         for (int y = 0; y < 80; y++)
         {
            // Llamamos la función "randomNum" para conseguir rellenar el valor de ese punto (X, Y, Z), y la siguiente iteración pasamos al siguiente punto a la derecha.
            resonancia[x][y][z] = randomNum();

            // Rellenamos el vector de lineas de 0's junto al otro vector para ahorrar recursos
            vectorLineas[x][y][z] = 0;
         }
      }
   }

    imp(resonancia, 1);
}

int randomNum()
{
    // Declaramos una variable que generará un número entre el 0 y el 255, para retornarlo luego
    int numeroSeudo = rand() % 25 + 20;

    return numeroSeudo;
}

int puntoSus(int vector[80][80][80], int x, int y, int z)
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