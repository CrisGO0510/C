#include <stdio.h>
#include <string.h>

int substring(char[], char[]);

int main()
{
    char frase1[] = "Hola mundo";
    char frase2[] = "mundo";

    substring(frase1, frase2) ? printf("VERDADERO") : printf("FALSO");

    return 0;
}

int substring(char frase1[], char frase2[])
{
    for (size_t i = 0, j = 0; i < strlen(frase1); i++)
    {
        if (frase1[i] == frase2[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }

        if (j == strlen(frase2))
        {
            return 1;
        }
    }

    return 0;
}