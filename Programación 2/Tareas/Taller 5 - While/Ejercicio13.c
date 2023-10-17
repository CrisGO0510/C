/*
 * Fecha de publicación: 18 de Marzo del 2023
 * Hora: 12:21
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Hacer un programa que lea desde el teclado un grupo de 75 números, diferentes a cero (validar este requisito) e imprima:
 * Cantidad de números Mayores a 150
 * Número mayor y número menor encontrado en el grupo
 * Cantidad de Números negativos encontrados
 * Promedio de los Positivos Encontrados.
 */

#include <stdio.h>

int mayores150(int);
int numMayor(int, int);
int numMenor(int, int);
int negativo(int);
int positivo(int);
float promedio(int);

int main()
{

    printf("Este programa te pide 75 números diferentes a cero\n");
    
/*
    Declaramos las variables que usaremos para alojar toda la información ingresada por el usuario:

    num = Variable donde se guardará el numero ingresado por el usuario
    nMayores = Contador para saber cuantos numeros son mayores a 150
    nMayor = Variable donde se guardará el numero mayor
    nMenor = Variable donde se guardará el numero menor
    nNegativos = Contador de numeros negativos
    nPositivos = Contador de números positivos para lograr el promedio de los numeros positivos
    prom = Suma de todos los números positivos para lograr el promedio de los numeros positivos
    i = Variable con la que controlaremos las iteraciones, para que no pase los 75 numeros
*/
    int num = 0;
    int nMayores = 0;
    int nMayor = 0;
    int nMenor = 0;
    int nNegativos = 0;
    int nPositivos = 0;
    float prom = 0;
    int i = 1;

    // Ciclos para pedir los datos y guardarlos en las variables destinadas
    while (i <= 75)
    {
        // Pedimos un numero al usuario
        printf("Por favor ingrese el valor del numero %i: ", i);
        scanf("%i", &num);

        // Asignamos a las variables lo que nos retorne las funciones
        nMayores += mayores150(num);
        nMayor = numMayor(nMayor, num);
        nMenor = numMenor(nMenor, num);
        nNegativos += negativo(num);
        nPositivos += positivo(num);
        prom += promedio(num);
        i++;
    }
    // Imprimimos los valores que nos piden en el ejercicio y obtuvimos a través de las iteraciones
    printf("La cantidad de números mayores a 150 son: %i\n", nMayores);
    printf("El número mayor es: %i\n", nMayor);
    printf("El número menor es: %i\n", nMenor);
    printf("La cantidad de números negativos son: %i\n", nNegativos);
    printf("El promedio de los números positivos es: %.2f\n", prom / nPositivos);

    return 0;
}


// Función que retornará 1 si el número es mayor a 150 y retornará 0 si es menor a 150

int mayores150(int num)
{

    if (num > 150)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función a la cual se debe ingresar 2 numeros y retornará el mayor

int numMayor(int mayor, int num)
{
    // Si mayor llega a ser 0 significa que el programa apenas empezó por lo cual nMayor debe tomar el primer valor ingresado, y este nunca podrá ser 0, por lo tanto podemos agregarlo de esta forma.
    if (mayor != 0)
    {
        if (mayor > num)
        {
            return mayor;
        }
        else
        {
            return num;
        }
    }
    else
    {
        return num;
    }
}

// Función a la cual se debe ingresar 2 numeros y retornará el menor

int numMenor(int menor, int num)
{
    // Si menor llega a ser 0 significa que el programa apenas empezó por lo cual nMenor debe tomar
    // el primer valor ingresado, y este nunca podrá ser 0, por lo tanto podemos agregarlo de esta forma
    if (menor != 0)
    {
        if (menor < num)
        {
            return menor;
        }
        else
        {
            return num;
        }
    }
    else
    {
        return num;
    }
}

// Función que retornará 1 si el número es negativo y retornará 0 si es positivo

int negativo(int num)
{

    if (num < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función que retornará 1 si el número es positivo y retornará 0 si es negativo

int positivo(int num)
{

    if (num > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función que sumará todos losn numeros positivos

float promedio(int num)
{
    // Esta función solo retornará algo si es valor es positivo, y retorna el mismo valor para sumarlo y dividirlo luego
    if (num > 0)
    {
        return num;
    }
    else
    {
        return 0;
    }
}