#include <stdio.h>
#include <string.h>

int main()
{
   char cadena[] = "Hola, mundo!";
   char *puntero;

   puntero = strchr(cadena, 'm');

   /*
    * La resta de un puntero y un array (o cadena) en C es una forma de determinar
    * la distancia en bytes entre dos posiciones de memoria.
    */

   if (puntero != NULL)
   {
      printf("Se encontró el carácter 'm' en la posición %ld de la cadena '%s'.\n", puntero - cadena, cadena);
   }
   else
   {
      printf("No se encontró el carácter 'm' en la cadena '%s'.\n", cadena);
   }

   return 0;
}
