// Se incluyen las librerías necesarias
#include <stdio.h>
#include <string.h>
// Función principal del programa
int main()
{
    // Se declaran las variables necesarias
    char str[100], remove;
    int i, j;
    // Se solicita al usuario que ingrese una cadena y se lee con fgets
    printf("Ingresa una cadena: ");
    fgets(str, sizeof(str), stdin);

    // Se solicita al usuario que ingrese un caracter a remover y se lee con scanf
    printf("Ingresa el caracter a remover: ");
    scanf("%c", &remove);

    // Se recorre la cadena y se reemplaza el caracter a remover con un caracter nulo
    for (i = 0, j = 0; i < strlen(str); i++)
    {
        if (str[i] != remove)
        {
            str[j++] = str[i];
        }

        printf("\n%i %i\n", i, j);
    }

    // Se agrega un caracter nulo al final de la cadena
    str[j] = '\0';

    // Se imprime la cadena resultante
    printf("Cadena despues de remover el caracter '%c': %s", remove, str);

    // Se finaliza la función principal del programa
    return 0;
}
