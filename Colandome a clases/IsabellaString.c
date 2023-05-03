#include <stdio.h>
#include <string.h>

int substring(char[], char[]);

int main()
{
    char cad1[] = "Helado de vainilla";
    char cad2[] = "de";

    substring(cad1, cad2) ? printf("VERDADERO") : printf("FALSO");

    return 0;
}

int substring(char cad1[], char cad2[])
{
    for (size_t i = 0, j = 0; i < strlen(cad1); i++)
    {
        if (cad1[i] == cad2[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
        if (j == strlen(cad2))
        {
            return 1;
        }
    }

    return 0;

}