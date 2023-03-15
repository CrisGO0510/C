/*
 * Fecha de publicación: 3 de Marzo del 2023
 * Hora: 20:00
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

void pedirDatos(int, int, int, int, int, float);
int mayores150(int);
int numMayor(int, int);
int numMenor(int, int);
int negativo(int);
float promedio(int);

int main()
{

    printf("Este programa te pide 75 números diferentes a cero\n");

    pedirDatos(0, 0, 0, 0, 0, 0);

    return 0;
}

/*
    cont = Contador para parar la recursividad despues de 75 numeros
    nMayores = Contador para saber cuantos numeros son mayores a 150
    nMayor = Variable donde se guardará el numero mayor
    nMenor = Variable donde se guardará el numero menor
    nNegativos = Contador de numeros negativos
    prom = promedio de los numeros positivos
*/

void pedirDatos(int cont, int nMayores, int nMayor, int nMenor, int nNegativos, float prom)
{

    // Variable que guardará un numero del usuario
    int num = 0;

    if (cont >= 75)
    {
        // Si cont es mayor a 75 que pare la recursividad e imprima los datos

        printf("Los números mayores a 150 son: %i\n", nMayores);
        printf("El numero mayor es: %i\n", nMayor);
        printf("El numero menor es: %i\n", nMenor);
        printf("La cantidad de números negativos son: %i\n", nNegativos);
        printf("El promedio de numeros positivos son: %.1f\n", prom / 75);
    }
    // Si es diferente de 0 ejecutamos las funciones, sino pedimos de nuevo el dato
    else
    {
        // Pedimos los datos
        printf("Por favor ingrese el %i número: ", cont + 1);
        scanf("%i", &num);

        if (num != 0)
        {
            // Ejecutamos las funciones y generamos recursividad
            pedirDatos(cont + 1, nMayores + mayores150(num), numMayor(nMayor, num), numMenor(nMenor, num), nNegativos + negativo(num), prom + promedio(num));
        }
        else
        {
            // Volvemos a pedir el numero
            printf("Error, por favor ingrese un dato diferente a 0\n");
            pedirDatos(cont, nMayores, nMayor, nMenor, nNegativos, prom);
        }
    }
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
    if (mayor > num)
    {
        return mayor;
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

// Función que retornará el promedio de 2 numeros positivos, uno será el promedio que ya llevamos y el otro será el que queramos agregar al promedio

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