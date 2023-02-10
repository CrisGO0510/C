// Hablaremos del concepto de las Arrays / Vectores

#include <stdio.h>
#include <stdlib.h>

/*
 * Las arrays son un concepto el cual se parece a un grupo de espacios
 * ■ ■ ■ ■ ■
 * 0 1 2 3 4
 * En este orden empezando por la posición 0
 */

main()
{
    /*
     * Para declarar un array creamos un entero con corchetes
     * que determinarán su rango.
     * Además sus valores de definen en llaves y separados por comas.
     */

    int array[] = {2, 4, 5, 7, 9, 1, 4, 8, 3};

    // * Creamos un bucle para imprimir todos los valores del array 
    for (int i = 0; i < 9; i++)
    {
        /*
            * Imprimimos la posición "i" del array, y con el bucle,
            * para tomar así los todos los valores del arrays.
        */
        printf("%i, ", array[i]);
    }


    return 0;
}