/*
    El funcionamiento del char vector es similar al del int vector,
    entonces en ese caso trataré de realizar un char Matriz.
*/

#include <stdio.h>

int main()
{

    // Con el siguiente ejemplo podemos ver que se puede acceder de la misma manera que un vector

    char pala[4] = "hola";
    printf("Palabra completa es: %s\n\n", pala);
    printf("Palabra solo una letra es: %c\n\n", pala[0]);

    // Con el siguiente ejemplo podemos ver que se puede acceder de la misma manera que a una matriz, probrando de que este método si funciona

    char word[3][3] = {"abc", "efg", "hij"};
    printf("Word completa es: %s\n\n", word);
    printf("Word solo una letra es: %c\n\n", word[0][0]);

    // !!Salvedad: Sale una advertencia (advertencia != error) no se como corregirlo pq no tengo wifi

    return 0;
}