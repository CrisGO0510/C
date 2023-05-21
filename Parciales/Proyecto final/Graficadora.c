/*
 * Fecha de publicación: xxxx/xx/xx
 * Hora: xx:xx
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
 * Salvedades: No se garantiza el resultado si se ingresan valores diferentes a "X" mayúscula o funciones que no sean polinomicas
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

/* Acá estamos creando un tipo de dato basado en un struct que se va a contener 2 puntos, de inicio y de llegada
 *@param start {{x1,y1}, {x2,y2}}
 *@param end {{x1,y1}, {x2,y2}}
 */
typedef struct
{
    SDL_Point start;
    SDL_Point end;
} SDL_Line;

// Prototipos a usar
int dividir(char[50], char[15], int);
int valorY(char[15], int);

int main()
{

    /* ----------------------------------------Variables que usaremos---------------------------------------- */

    // Declaramos 2 variables que contendrán el valor de la ventana
    int window_width, window_height;

    // Declaramos 2 variables para saber el intervalo de donde el usuario quiere empezar y terminar el intervalo de la función
    int inicio = 0, fin = 0;

    // Variable que contendrá la función ingresada por el usuario
    char funcion[50] = "2X+1";

    // Declaramos variable que será usada para guardar un monomio de manera temporal
    char mon[15] = "+2";

    /* ------------------------------------------INICIALIZAMOS SDL2------------------------------------------ */

    // Inicializamos SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error initializing SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Declaramos una variable para poder manejar eventos (en este caso cerrar la ventana)
    SDL_Event event;

    // Creamos una ventana
    SDL_Window *window = SDL_CreateWindow("Plano Cartesiano", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

    // Declaramos el renderizados que usaremos para poder dibujar graficos en la ventana
    SDL_Renderer *plano = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Verificamos si el render logró crearse de manera exitosa, sino imprime el error y retorna 1
    if (plano == NULL)
    {
        printf("Error creating \"plano\": %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Función que nos asigna el valor del tamaño de la ventana
    SDL_GetWindowSize(window, &window_width, &window_height);

    // TODO: Función que dividirá el monomio

    printf("hola: %i\n", dividir(funcion, mon, 1));
    // printf("hola: %i\n", valorY(mon, 0));

    //! Esperar a que el usuario cierre la ventana
    int i = 1;
    while (i)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            i = 0;
        }
    }

    SDL_DestroyRenderer(plano);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//? Función que divide el polinomio (poli), y lo pega en "mon" como si se tratase de un monomio

int dividir(char poli[50], char mon[15], int x)
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

    if (poli[0] != '\0')
    {
        return (valorY(mon, x) + dividir(poli, mon, x));
    }
    else
    {
        return valorY(mon, x);
    }
}

//? Función que retorna el valor de la función
int valorY(char mon[15], int x)
{
    // Declaramos la variable que guardará el coeficiente
    char coef[15] = "";

    // Declaramos variable que alojará la posición en donde esta la X
    int puesto = strchr(mon, 'X') - mon;

    // Verificamos si el monomio tiene una variable (X)
    if (strchr(mon, 'X') != NULL)
    {

        // Hacemos una condicional para verificar si el coeficiente es un 1 implicito
        if (mon[0] == 'X' || ((mon[0] == '+') && (mon[1] == 'X')))
        {
            // En caso de que el valor de mon[0] == 'X', significa que el coeficiente es 1
            coef[0] = '1';

            // Agregar el caracter nulo al final de coef
            coef[1] = '\0';
        }
        // Hacemos una condicional para verificar si el coeficiente es un -1 implicito
        else if ((mon[0] == '-') && (mon[1] == 'X'))
        {
            // En caso de que el valor de mon[0] == '-X', significa que el coeficiente es -1
            coef[0] = '-';
            coef[1] = '1';

            // Agregar el caracter nulo al final de coef
            coef[2] = '\0';
        }
        else
        {
            // Copiamos el string "mon" en la variable "coef", hasta que llegue a la X
            memcpy(coef, mon, puesto);

            // Agregar el caracter nulo al final de coef
            coef[puesto] = '\0';
        }

        // Condición para ingresarle 1 al exponente, debido a que se intuye que si no hay nada, hay un "1"
        if (mon[puesto + 1] == '\0')
        {
            // Le asignamos el valor a 1 al valor después de la X (puesto + 1)
            mon[puesto + 1] = '1';

            // Le asignamos el null para determinar que se acabó el string
            mon[puesto + 2] = '\0';
        }
    }
    //! En caso de que la función no tenga una X retornamos el valor de mon
    else
    {
        // Si llega a ser falsa la condición, determinamos que el exponente es 0 y lo imprimimos
        return atoi(mon);
    }

    // printf("valor actual: %i\n", atoi(coef) * SDL_pow(x, atoi(&mon[puesto + 1])));

    // Retornamos la multiplicación del coeficiente por x elevado a lo que este a la derecha de la x
    return atoi(coef) * SDL_pow(x, atoi(&mon[puesto + 1]));
}