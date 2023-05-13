/*
 * Fecha de publicación: 2023/03/25
 * Hora: 14:28
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
 * Descripción: Haremos un programa que leerá una función polinómica ingresada por el usuario e imprimirá cada coeficiente con su potencia.
 * Salvedades: No se garantiza el resultado si se ingresan valores diferentes a "X" mayús o números enteros
 */

#include <stdio.h>
#include <string.h>

void dividir(char[50], char[15]);
void imp(char[15]);
void eliminarCaracter(char[15], char);

int main()
{
    // Declaramos la variable que contendrá la función polinómica ingresada por el usuario
    // ! Valor de prueba para no invertarme 348X5-6X-78X2+6-2X(-3)
    char poli[50] = "";
    // Declaramos variable que será usada para guardar un monomio de manera temporal
    char mon[15] = "";

    // Le pedimos la función al usuario
    printf("Por favor ingrese su función polinómica:\nf(x)= ");
    scanf("%s", poli);

    printf("\nCoeficiente | Potencia\n");

    // Hacemos condicional para determinar si seguimos con los polinomios o ya se acabaron
    // Si la posición 0 de poli es null, significa que ya no hay mas valores, por lo tanto finaliza el programa
    while (poli[0] != '\0')
    {
        // Si aún no se han acabado los polinomios volvemos a empezar la función
        dividir(poli, mon);
    }

    return 0;
}

//? Función que divide el polinomio (poli), y lo pega en "mon" como si se tratase de un monomio

void dividir(char poli[50], char mon[15])
{
    // Declaramos variable para recorrer cada uno de los caracteres en el string "poli" para dividirlo al monomio "mon"
    // Lo declaramos 1 para que ignore el simbolo del inicio y solo mire los siguientes simbolos (+ / -)
    int i = 1;

    // Declaramos variable para recorrer el string "poli" para quitarle el monomio que ya guardamos en "mon"
    int j = 0;

    // Declaramos variable que guardará el fin del monomio
    int fin = 0;

    // Bucle para recorrer el string y poder copiar en otra variable el primer monomio encontrado
    while (fin == 0)
    {
        // Sí se encuentra un carácter '+' o '-' o ' ' (Espacio en caso de ser el primer valor porque se omite el '+') significa que el polinomio terminó en dicha posición (i)
        if (poli[i] == '+' || poli[i] == '-' || poli[i] == '\0')
        {

            // Si antes del signo + / - hay un parentesis, significa que es del mismo monomio
            if (poli[i - 1] == '(')
            {
                // En este caso, haremos un incremento a la variable i y seguiremos con el bucle
                i++;
            }
            else
            {
                // Definimos el valor de fin con la posición actual del string, para así determinar el fin del monomio
                fin = i;
            }
        }
        else
        {
            // Haremos un incremento a la variable i
            i++;
        }
    }

    // Copiamos el monomio en la variable "mon"
    memcpy(mon, poli, fin);
    // Agregamos el null al final del string para finalizarlo
    mon[fin] = '\0';

    // Hacemos un bucle para quitar el monomio del la variable "poli"
    while (poli[i] != '\0')
    {
        // Remplazamos el valor de la posición de "j", por el valor de la posición de "i"
        poli[j] = poli[i];

        // Hacemos el incremento de las variables "j" y "i"
        j++;
        i++;
    }

    // Añadimos el null, para determinar que ahí finaliza el string
    poli[j] = '\0';

    // Llamamos a la función para imprimir
    imp(mon);
}

//? Función que imprime el coeficiente y el la potencia
void imp(char mon[15])
{
    // Declaramos variable con espacios para poder centrar la tabla a la hora de imprimir
    char espacios[14] = "";

    // Declaramos la variable que guardará el coeficiente
    char coef[15] = "";

    // Declaramos variable que alojará la posición en donde esta la X
    int puesto = strchr(mon, 'X') - mon;

    // Verificamos si el monomio tiene una variable (X)
    if (strchr(mon, 'X') != NULL)
    {
        // Quitamos los parentesis que haya después de la X
        eliminarCaracter(mon, '(');
        eliminarCaracter(mon, ')');

        if (mon[0] == 'X' || ((mon[0] == '+') && (mon[1] == 'X')))
        {
            // En caso de que el valor de mon[0] == 'X', significa que el coeficiente es 1
            coef[0] = '1';

            // Agregar el caracter nulo al final de coef
            coef[1] = '\0';
        }
        else
        {
            // Copiamos el string "mon" en la variable "coef", hasta que llegue a la X
            memcpy(coef, mon, puesto);

            // Agregar el caracter nulo al final de coef
            coef[puesto] = '\0';
        }

        // Quitamos el + de coeficiente ya que el '+' al principio de un numero no se pone
        eliminarCaracter(coef, '+');

        // Le asignaremos 14 - la cantidad de caracteres en coef, como espacios a la variable espacios
        for (size_t i = 0; i < 14 - strlen(coef); i++)
        {
            // Asignamos un espacio al la posición actual de "i"
            espacios[i] = ' ';
        }

        // Condición para ingresarle 1 al exponente, debido a que se intuye que si no hay nada, hay un "1"
        if (mon[puesto + 1] == '\0')
        {
            // Le asignamos el valor a 1 al valor después de la X (puesto + 1)
            mon[puesto + 1] = '1';

            // Le asignamos el null para determinar que se acabó el string
            mon[puesto + 2] = '\0';
        }

        // Imprimimos el coeficiente y el exponente
        printf("%s%s%s\n", coef, espacios, &mon[puesto + 1]);
    }
    else
    {
        // Quitamos el + de coeficiente ya que el '+' al principio de un numero no se pone
        eliminarCaracter(mon, '+');

        // Le asignaremos 14 - la cantidad de caracteres en mon, como espacios a la variable espacios
        for (size_t i = 0; i < 14 - strlen(mon); i++)
        {
            // Asignamos un espacio al la posición actual de "i"
            espacios[i] = ' ';
        }

        // Si llega a ser falsa la condición, determinamos que el exponente es 0 y lo imprimimos
        printf("%s%s0\n", mon, espacios);
    }
}

// ? Función para eliminar los caracteres "caracter" del string "str" recibido como párametro
void eliminarCaracter(char str[15], char caracter)
{

    // Declaramos variables para controlar las iteraciones del ciclo para eliminar los párentesis
    size_t i = 0;
    size_t j = 0;

    // Se recorre la cadena y se reemplaza el caracter a remover con un caracter nulo
    for (i = 0, j = 0; i < strlen(str); i++)
    {
        // Determinamos si la posición str[i] es diferente al caracter enviado
        if (str[i] != caracter)
        {
            // Si la condición es verdadera, entonces se guardará en la posición de j y luego hacemos un incremento a la variable j
            str[j++] = str[i];
        }

        /* En caso de que la condición sea falsa no guarda el carácter y hace el incremento de la variable i, para seguir con la siguiente posición y que la variable j, estando en la posición anterior remplace ese espacio*/
    }

    // Se agrega un caracter nulo al final de la cadena
    str[j] = '\0';
}