// En este programa haremos un Factorial con funciones y recursividad

#include <stdio.h>

// Declaramos la función principal, llamada "Main"
int main(){

    /* Declaramos una variable con el resultado de la recursividad de
    la función "fac"*/
    int num = fac(5);
    // Imprimimos el valor de "num" para mostrar así el valor de la factorial
    printf("%i", num);
}

/* Creamos una función fac para realizar las operaciones necesarias de la 
factorial, de manera recursiva */

// X será el parametro a utilizar para generar y multiplicar los numeros
int fac(int x)
{
    // Creamos una condicional que nos dirá si el numero es mayor a cero
    if (x > 0){
        /* Si la condicional es cierta multiplicamos el valor que tenga X por 
        el que tenga la función "fac(x - 1)", haciendo así una recursividad*/
        return x * fac(x - 1);
    } else if (x < 0){
        /* Esta sección es por si el usuario ingresa un numero negativo 
        mandar un error para evitar problemas*/
        printf("No se pueden ingresar numeros negativos: ");
        return x;
    } else {
        /* Esta parte es para cuando el numero llegue a 0 retorne 1 siendo así el punto de para de la recursividad. Ej X * X-1 ... * 3 * 2 * "1", Este uno es el mismo que el que retorna abajo*/
        return 1;
    }
}