/*
 * Fecha de publicación: 2023/03/26
 * Hora: 8:03
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Lenguaje utilizado C(ISO/IEC) 201710
 * Versión del lenguaje utilizado
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Sistema Operativo: Arch Linux
 * Presentado a: PhD Ricardo Moreno Laverde
 * Universidad Tecnológica de Pereira
 * Descripción: Haremos un programa que generará un QR con ciertas condiciones, y luego comprobar si tiene las cáracteristicas de los QR asignados por la empresa.
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char randomNum();
void murosExteriores(char[900]);
int validacion1(char[900]);
int validacion2(char[900]);
int validacion3(char[900]);
void imp(char[900]);
void imp1(char[900]);

int main()
{
    // Declaramos las variables de valor de verdad de las 3 validaciones
    int verdad1 = 0;
    int verdad2 = 0;
    int verdad3 = 0;

    // Cambiamos la semilla a una generada por el tiempo actual del dispositivo
    srand(time(NULL));

    // Declaramos la variable que contendrá el qr
    char qr[900] = "";

    for (size_t i = 0; i < 900; i++)
    {
        // Asignamos el valor random (0 o 1) a la posición del qr[i]
        qr[i] = randomNum();
    }

    // Añadimos los muros o periferia
    murosExteriores(qr);

    // Imprimimos los qr
    imp(qr);
    imp1(qr);

    // Imprimimos los requisitos para que sea original
    printf("Requisitos:\n");
    printf("a) Los píxeles de la periferia están siempre en blanco\n");
    printf("b) El código tiene reservados un cuadrado de 7x7 píxeles encajado en la parte más externa superior derecha(sin incluir la periferia), que debe estar formado por al menos 25 píxeles negros, con cualquier disposición\n");
    printf("c) En la séptima fila(subíndice 6 de la figura), las columnas en la figura 2, 4, y 25 del arreglo son píxeles de color negro. El número de errores se calculará teniendo en cuenta solo el último requisito (c), asignando un punto por cada píxel de los citados que no sea negro\n\n");

    // Ejecutamos las validaciones, se imprimirán si son ciertas o falsas y además se guardará un 0 o 1 en la variable verdad#
    verdad1 = validacion1(qr);
    verdad2 = validacion2(qr);
    verdad3 = validacion3(qr);

    // Imprimimos un mensaje si el QR es original o no
    if (verdad1 && verdad2 && verdad3)
    {
        // Si los 3 valores son 1 o verdadero, el QR es original
        printf("\033[32m\nEl QR es original");
    }
    else
    {
        // Si no se cumple es por qué al menos 1 es 0, por lo tanto es falsificado
        printf("\033[31m\nEl QR es falsificado");
    }
}

// ? Función que retorna un numero seudoaleatorio
char randomNum()
{
    /*
     * Empezamos por definir una semilla para poder generar un número, esta semilla cambiará en base
     * Al tiempo del dispositivo, dando así la ilusión de ser aleatorio, luego de ello declaramos una
     * Variable "num" con el valor que retorne la función rand, esta función que retorna un número
     * En base a la semilla pero es un numero muy grande, para ello le sacamos el modulo de 2, así
     * haciendo que el numero solo pueda estar entre 0 y 1.
     */
    char caracter = rand() % 2 == 1 ? '0' : '1';

    return caracter;
}

// ? Función para crear la periferia
void murosExteriores(char qr[900])
{
    // creando los muros superiores
    for (int i = 0; i < 30; i++)
    {
        qr[i] = '0';
    }
    // creando los muros inferiores
    for (int i = 870; i < 900; i++)
    {
        qr[i] = '0';
    }
    // creando los muros laterales izquierdos
    for (int i = 1; i < 29; i++)
    {
        qr[i * 30] = '0';
    }
    // creando los muros laterales derechos
    for (int i = 2; i < 30; i++)
    {
        qr[(i * 30) - 1] = '0';
    }
}

// ? Imprimimos el primer formato del qr
void imp(char qr[900])
{
    // Declaramos una variable con la que controlaremos los espacios entre el numero y el qr
    char espacios[6] = "     ";

    printf("  %s012345678901234567890123456789\n %s+------------------------------+\n0%s|", espacios, espacios, espacios);

    for (int i = 0; i < 900; i++)
    {
        // Si "i" llega a 100 significa que los numeros laterales ya tienen 2 cifras, por lo tanto quitamos 1 espacio al "espacios", para que se alinee
        if (i >= 300 && strlen(espacios) == 5)
        {
            // Afirmamos que espacios tenga 5 espacios para que no se reste inecesariamente
            espacios[4] = '\0';
        }

        // Si "i" Es multiplo de 30 hacemos un salto de linea
        if (i % 30 == 0 && i != 0)
        {
            printf("|%i\n%i%s|", (i / 30) - 1, i / 30, espacios);
        }

        // Imprimimos " " o "█", si qr[i] es igual a 0 o a 1 respectivamente
        if (qr[i] == '0')
        {
            printf(" ");
        }
        else
        {
            printf("█");
        }
    }

    printf("|29\n  %s+------------------------------+\n%s   012345678901234567890123456789\n\n", espacios, espacios);
}

// ? Imprimimos el segundo formato del qr
void imp1(char qr[900])
{
    // Declaramos una variable con la que controlaremos los espacios entre el numero y el qr
    char espacios[6] = "     ";

    printf(" %s|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|\n", espacios);
    printf(" %s+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n0%s", espacios, espacios);

    for (int i = 0; i < 900; i++)
    {
        // Si "i" llega a 100 significa que los numeros laterales ya tienen 2 cifras, por lo tanto quitamos 1 espacio al "espacios", para que se alinee
        if (i >= 300 && strlen(espacios) == 5)
        {
            // Afirmamos que espacios tenga 5 espacios para que no se reste inecesariamente
            espacios[4] = '\0';
        }

        // Si "i" Es multiplo de 30 hacemos un salto de linea
        if (i % 30 == 0 && i != 0)
        {
            printf("|%i", (i / 30) - 1);
            printf("\n %s+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", "     ");
            printf("\n%i%s", i / 30, espacios);
        }

        // Imprimimos " " o "█", si qr[i] es igual a 0 o a 1 respectivamente
        if (qr[i] == '0')
        {
            printf("| ");
        }
        else
        {
            printf("|█");
        }
    }

    printf("|%i\n%s+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", 29, "      ");
    printf("\n%s|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|\n\n", "      ");
}

// ? Función de la validación 1, el cuál se basa en que la periferia del qr debe ser blanca
int validacion1(char qr[900])
{
    // Declaramos variable con la que recorreremos el qr hasta el 239, ya que, ahí es la periferia y la siguiente fila sale del rango de 7x7, planteado anteriormente
    int i = 900;

    // Declaramos la variable contadora de pixeles negros(1) entre el rango del 7x7 superior derecho
    int cont = 0;

    // Bucle para recorrer la sección del 7x7 del qr, y contará los pixeles negros en ciertos rangos
    // Hasta 51 debido a que de ahí hacia atras sale del rango del 7x7
    while (i >= 0)
    {
        // Condición para determinar el rango de la periferia
        if ((i >= 0 && i < 30) || (i >= 870 && i < 900) || (i % 30 == 0) || ((i + 1) % 30 == 0))
        {
            // Condicional para determinar si en el rango hay pixeles blancos
            if (qr[i] == '1')
            {
                // Aumentamos al contador 1
                cont++;
            }
        }

        // Hacemos el decremento a la variable "i"
        i--;
    }

    // Condicional que verificará si la condición de que en la periferia solo hay pixeles blanco es cierta
    if (cont > 0)
    {
        // Si cont es mayor a 0 significa que encontró al menos 1 pixel negro
        printf("Condición a: No se cumple.\n");
        return 0;
    }
    else
    {
        // Si cont no es mayor a 0, es decir, 0, significa que la periferia solo tiene pixeles blancos
        printf("Condición a: Se cumple.\n");
        return 1;
    }
}

// ? Función de la validación 2, el cuál se basa en que en una zona de 7x7 en la parte superior derecha (sin contar la periferia) debe contener al menos 25 pixeles negros
int validacion2(char qr[900])
{
    // Declaramos variable con la que recorreremos el qr hasta el 239, ya que, ahí es la periferia y la siguiente fila sale del rango de 7x7, planteado anteriormente
    int i = 239;

    // Declaramos la variable contadora de pixeles negros(1) entre el rango del 7x7 superior derecho
    int cont = 0;

    // Bucle para recorrer la sección del 7x7 del qr, y contará los pixeles negros en ciertos rangos
    // Hasta 51 debido a que de ahí hacia atras sale del rango del 7x7
    while (i > 51)
    {
        // Condición para determinar el rango del 7x7, cada uno de los rangos es el valor de la fila
        if ((i >= 52 && i <= 58) || (i >= 82 && i <= 88) || (i >= 112 && i <= 118) || (i >= 142 && i <= 148) || (i >= 172 && i <= 178) || (i >= 202 && i <= 208) || (i >= 232 && i <= 238))
        {
            // Condicional para determinar si en el rango hay pixeles negros
            if (qr[i] == '1')
            {
                // Aumentamos al contador 1
                cont++;
            }
        }

        // Hacemos el decremento a la variable "i"
        i--;
    }

    // Condicional que verificará si la condición de al menos 25 pixeles negros en el 7x7 superior derecho
    if (cont >= 25)
    {
        // Si cont es mayor a 0 significa que encontró al menos 25 pixeles negro
        printf("Condición b: Se cumple. Número de pixeles negros = %i\n", cont);
        return 1;
    }
    else
    {
        // Si cont no es al menos a 25, significa que la condición no cumple
        printf("Condición b: No se cumple. Número de pixeles negros = %i\n", cont);
        return 0;
    }
}

// ? Función de la validación 3, la cual se basa en que en la séptima fila(subíndice 6 de la figura), las columnas en la figura 2, 4, y 25 del arreglo son píxeles de color negro
int validacion3(char qr[900])
{
    // Declaramos variable con la que recorreremos el qr hasta el 210, ya que, ahí es la octava fila de la figura
    int i = 210;

    // Declaramos la variable contadora de pixeles negros(1) entre el rango del 7x7 superior derecho
    int cont = 0;

    // Bucle para recorrer la sección del 7x7 del qr, y contará los pixeles negros en ciertos rangos
    // Hasta 51 debido a que de ahí hacia atras sale del rango del 7x7
    while (i >= 180)
    {
        // Condición para determinar si la "i" se encuentra en las 3 posiciones definidas
        if (i == 182 || i == 184 || i == 205)
        {
            // Condicional para determinar si en el rango hay pixeles blancos
            if (qr[i] == '0')
            {
                // Aumentamos al contador 1 para saber cuantos errores hay
                cont++;
            }
        }

        // Hacemos el decremento a la variable "i"
        i--;
    }

    // Condicional que verificará si la condición de que en la posición 182, 184 y 205 solo hay pixeles negros es cierta
    if (cont > 0)
    {
        // Si cont es mayor a 0 significa que encontró al menos 1 pixel blanco
        printf("Condición c: NO se cumple.\n");
        // Imprimimos la cantidad de errores (cont) que fueron encontrados
        printf("Errores %i.\n", cont);
        return 0;
    }
    else
    {
        // Si cont no es mayor a 0, es decir, 0, significa que en la posición 182, 184 y 205 solo hay pixeles negros
        printf("Condición c: Se cumple.\n");
        return 1;
    }
}