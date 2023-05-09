#include <stdio.h>

int main()
{

    int dim = 0;

    printf("Ingrese la dimensión: ");
    scanf("%i", &dim);

    int vector[dim];

    for (int i = 0; i < dim; i++)
    {
        printf("Ingrese el valor que desea asignar a la posición %i: ", i);
        scanf("%i", &vector[i]);
        fflush(stdout);
    }

    for (int i = 0; i < dim; i++)
    {
        printf("%i\n", vector[i]);

    }

    return 0;
}