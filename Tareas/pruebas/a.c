// Para este ejemplo usé C por qué en el ejemplo del problema se ve que se declaran el tipo de dato y en js no existe el tipado de datos

#include <stdio.h>>

int brecha(int[], int, int, int, int);

int main()
{

   int array[] = {1, 0, 1, 0, 0, 0 ,1};

   int tama = sizeof(array) / sizeof(array[0]);

   brecha(array, 0, 0, 1, tama);

   return 0;
}

int brecha(int x[], int c, int n, int i, int tam)
{

   if (tam < n)
   {
      printf("ACABÓ EL PROGRAMA");
      // Acaba el programa
   }
   else
   {
      if (x[n] == 1 && n != 0)
      {
         // Si el vector es 1 imprime la cantidad de esa brecha y sigue desde 0 con la siguiente
         printf("La brecha %i es de: %i\n", i, c);
         brecha(x, 0, n + 1, i + 1, tam);
      }
      else
      {
         // Contar y volver a empezar con la siguiente posición
         brecha(x, c + 1, n + 1, i, tam);
      }
   }
}