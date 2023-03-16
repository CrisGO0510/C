/*
 * Fecha de publicación: 16 de Marzo del 2023
 * Hora: 16:21
 * Versión de su código: 1.0
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Presentado a: PHD Ricardo Moreno Laverde
 * Universidad : Universidad Tecnologica de Pereira
 * Programa: Ingenieria en sistemas y computación
 * Descripción: Programa que hace el juego del ahorcado
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Hacemos el prototipo de las funciones que usaremos

char *setPalabra();
int randomNum();
void ingresaLetra(char[], char[], int *, char[]);
void impAhorcado(int, char[], char[]);

int main()
{
    /*
        * Definimos una variable char array para alojar la palabra que el usuario adivinará,
        * Le asignamos 15 espacios para añadirle un limite de espacio y no ocurra errores el
        * Limite puede ser cualquiera, en este caso como no hay palabras de +15 letras elejimos 15
        TODO: En caso de querer palabras mas grandes aumentar el limite de todas (2) las variables char.
    */

    //* Variable que contendrá el número de intentos que le quedan al usuario
    int intentos = 8;

    //* Variable que contendrá las letras que ha utilizado
    char letrasUsadas[8] = "";

    char palabra[15] = "";
    // * Copiamos en la variable una "palabra" generada en la función setPalabra()
    strcpy(palabra, setPalabra());

    /*
     * Definimos una variable char array, la que contendrá la cantidad de espacios que tiene la variable
     * "Palabra" en forma de guiones, y esta la imprimieros en pantalla. Además, cuando el usuario
     * Adivine una letra, todos los espacios que tuviesen esa letra serán remplazados por la misma
     */
    char palabraOculta[15] = "";

    //* Creamos un bucle for para asignarle un guion x espacio en la variable "palabra", a "palabraOculta"

    for (int i = 0; i < strlen(palabra); i++)
    {
        // * Función añade una cadena al final de otra.
        strcat(palabraOculta, "-");
    }
    /*---------------------------------FIN DE GENERAR PALABRA-------------------------------------*/

    /*
     * Enviamos las 2 variables (palabra y palabraOculta) y la variable intentos
     * Enviamos la variable "palabraOculta" con el parámetro de dirección para
     * editar directamente su valor y no de manera "local" en la función.
     */

    ingresaLetra(palabra, &palabraOculta, &intentos, letrasUsadas);

    return 0;
}

// ? Función para que el usuario ingrese una letra y se verifique si esta o no

void ingresaLetra(char palabra[], char palabraOculta[], int *inte, char letrasU[8])
{
    impAhorcado(*inte, palabraOculta, letrasU);

    //* Variable que contendrá la letra ingresada por el usuario
    char letra = "";

    //* Le pedimos al usuario que ingrese un caracter
    printf("\nIngrese una letra: ");
    scanf("%c", &letra);
    /*
     * getchar() es una función para consumir el "enter" que se envia automaticamente
     * cuando se usa scanf con chars (intenté usar fflush(stdin) y no funcionó).
     */
    getchar();

    if (strchr(palabra, toupper(letra)) != NULL)
    {
        /*
         * Creamos un bucle que recorrerá cada uno de los espacios de "palabra" y
         * cuando identifique que la letra del espacio es igual al cáracter ingresado
         * por el usuario, remplazará en el espació correspondiente de "palabraOculta"
         * el guión por la letra ingresada.
         */

        for (int i = 0; i < strlen(palabra); i++)
        {
            /*
                * Condicional para verificar si el espacio designado a "palabra" es igual
                * a la letra ingresada por el usuario, si es el caso remplazar, si no es
                * el caso seguir el bucle.
                ? El toupper es para convertir la letra ingresada por el usuario en mayús
            */
            if (toupper(letra) == palabra[i])
            {
                //* Remplazamos el valor del guión por la letra ingresa por el usuario
                palabraOculta[i] = toupper(letra);
            } // Fin del if
        }     // Fin del bucle for

        //* Condicional para verificar si ya adivinó la palabra, comparando las variables "palabra" y "palabraOculta"

        if (strcmp(palabra, palabraOculta) == 0)
        {
            /* Fin del programa */
            impAhorcado(*inte, palabraOculta, letrasU);
            printf("\nGANASTE!!!\n");

        } //! En caso de no haber ganado aún
        else
        {
            //* Volvemos a llamar a la función ingresaLetra
            ingresaLetra(palabra, palabraOculta, inte, letrasU);
        } // Fin del if
    }     //! En caso de no acertar la letras+
    else
    {
        //* Asignamos la letra al string de letras usadas "letrasU"
        letrasU[(8 - *inte)] = toupper(letra);

        //* Condicional para saber si se acabaron los intentos
        if (*inte > 2)
        {
            //* Restamos 1 intento y volvemos a ejecutar la función
            *inte -= 1;
            ingresaLetra(palabra, palabraOculta, inte, letrasU);
        } //! En caso de no tener mas intentos
        else
        {
            //* En caso de que se acaben los intentos acabar el programa
            impAhorcado(1, palabraOculta, letrasU);
            printf("\nTe has quedado sin intentos\n");

        } // Fin del if

    } // Fin del if
}

// ? Función para imprimir el ahorcado

void impAhorcado(int intentos, char palabraOculta[], char letrasU[])
{
    //* Limpiamos la pantalla para una pero UX
    system("clear");

    //* Según los intentos restantes se imprime la forma del ahorcado
    switch (intentos)
    {

    case 8:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|              ");
        printf("%s\n", palabraOculta);
        printf("|              \n");
        printf("|              ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;
    case 7:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|              \n");
        printf("|              ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;
    case 6:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|     |        \n");
        printf("|              ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;
    case 5:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|     |\\       \n");
        printf("|              ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;
    case 4:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|    /|\\       \n");
        printf("|              ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;

    case 3:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|    /|\\       \n");
        printf("|     |        ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|              \n");
        printf("-----       \n");
        break;

    case 2:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|    /|\\       \n");
        printf("|     |        ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|    /         \n");
        printf("-----       \n");
        break;

    case 1:
        printf("JUEGO AHORCADO\n");
        printf("+----+        \n");
        printf("|     O        ");
        printf("%s\n", palabraOculta);
        printf("|    /|\\       \n");
        printf("|     |        ");
        printf("Letras Usadas: %s\n", letrasU);
        printf("|    / \\       \n");
        printf("-----       \n");
        break;

    default:
        printf("ERROR CON LOS INTENTOS");
        break;
    }
}

// ? Función que retorna un string dependiendo el numero ingresado
char *setPalabra()
{

    /*
     * Creamos un switch como 10 casos posibles los cuales retornarán un string
     * Usamos como valor lo que retorne la función "randomNum()" para hacerlo seudoaleatorio
     */
    switch (randomNum())
    {
    case 1:
        return "CELULAR";
    case 2:
        return "CARRO";
    case 3:
        return "ARROZ";
    case 4:
        return "CADENA";
    case 5:
        return "ESTUDIANTE";
    case 6:
        return "MESA";
    case 7:
        return "EXTINTOR";
    case 8:
        return "ENGRAPADORA";
    case 9:
        return "CASCO";
    case 10:
        return "GORRA";
    /*
     * En caso de un numero diferente (no deberia pasar debido a que el random esta limitado)
     * Se vuelve a ejecutar la función sin retornar nada, mas que nada lo hicimos por buena
     * Practica de programación.
     */
    default:
        setPalabra();
        break;
    }

    return 0;
}

// ? Función que retorna un numero seudoaleatorio

int randomNum()
{
    /*
     * Empezamos por definir una semilla para poder generar un número, esta semilla cambiará en base
     * Al tiempo del dispositivo, dando así la ilusión de ser aleatorio, luego de ello declaramos una
     * Variable "num" con el valor que retorne la función rand, esta función que retorna un número
     * En base a la semilla pero es un numero muy grande, para ello le sacamos el modulo de 10, así
     * haciendo que el numero solo pueda estar entre 0 y 9, pero como no deseamos que empiece en 0
     * Le sumamos 1 para que ahora sea un numero entre 1 y 10.
     */
    srand(time(NULL));
    int num = rand() % 10 + 1;

    return num;
}