/*
    * Haremos un sistema el cuál determinará el tamaño del vector
*/

#include <stdio.h>

int main(){

    // * Declaramos el array con los valores que deseamos
    int arr[] = {1, 2, 3, 4, 8};


    /*
        * Primero que todo explicaremos que hace cada función:
        * El sizeof lo que hace es determinar el tamaño en bytes
        * Entonces el proceso que haremos es tomar el tamaño total
        * de la array ("size(arr)") y lo dividiremos por su valor
        * individual ("sizeof(arr[0])")
    */
    printf("%d", sizeof(arr) / sizeof(arr[0]));

}