#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

// Prototipos a usar

void generarPlano(int, int, SDL_Renderer *, int);
void eliminarCaracter(char[15], char);
void generarFuncion(char[15], int, int, int, SDL_Renderer *);

/* Acá estamos creando un tipo de dato basado en un struct que se va a contener 2 puntos, de inicio y de llegada
 *@param start {{x1,y1}, {x2,y2}}
 *@param end {{x1,y1}, {x2,y2}}
 */
typedef struct
{
    SDL_Point start;
    SDL_Point end;
} SDL_Line;

int main()
{

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

    // Declaramos 2 variables que contendrán el valor de la ventana
    int window_width, window_height;

    // Variable para saber cuantas divisiónes a de tener (DEBE SER PAR)
    int divisiones = 16;

    // Función que nos asigna el valor del tamaño de la ventana
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Llamamos a la función para generar el plano
    generarPlano(window_height, window_width, plano, divisiones);
    // SDL_RenderPresent(plano);

    // TODO: Función que dividirá el monomio
    char funcion[15] = "3X";
    generarFuncion(funcion, divisiones, window_width, window_height, plano);

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

// ? Función que genera el plano con sus renderizaciones
void generarPlano(int h, int w, SDL_Renderer *render, int divisiones)
{
    // Declaramos un vector de lineas que dividirán el plano
    SDL_Line divisoresVerticales[divisiones];
    SDL_Line divisoresHorizontales[divisiones];
    float x = 0;
    float y = 0;

    // Lineas divisoras
    for (int i = 0; i < divisiones; i++)
    {
        divisoresVerticales[i] = (SDL_Line){{x, 0}, {x, h}};
        divisoresHorizontales[i] = (SDL_Line){{0, y}, {w, y}};
        x += (float)w / divisiones;
        y += (float)h / divisiones;
    }

    // Color blanco al fondo del plano
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

    // Limpiamos la ventana
    SDL_RenderClear(render);

    // Cambiamos el color a un tono grisaseo
    SDL_SetRenderDrawColor(render, 205, 205, 205, 255);

    // Dibujamos las lineas divisoras a través de un bucle for
    for (int i = 0; i < divisiones; i++)
    {
        SDL_RenderDrawLine(render, divisoresVerticales[i].start.x, divisoresVerticales[i].start.y, divisoresVerticales[i].end.x, divisoresVerticales[i].end.y);

        SDL_RenderDrawLine(render, divisoresHorizontales[i].start.x, divisoresHorizontales[i].start.y, divisoresHorizontales[i].end.x, divisoresHorizontales[i].end.y);
    }

    // Le damos un color a las lineas
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

    // Declaramos la linea X del plano cartesiano
    SDL_Line lineaX = {{0, h / 2}, {w, h / 2}};

    // Declaramos la linea Y del plano cartesiano
    SDL_Line lineaY = {{w / 2, 0}, {w / 2, h}};

    // Dibujamos las lineas
    SDL_RenderDrawLine(render, lineaY.start.x, lineaY.start.y, lineaY.end.x, lineaY.end.y);

    SDL_RenderDrawLine(render, lineaX.start.x, lineaX.start.y, lineaX.end.x, lineaX.end.y);

    // // Actualizar el render para mostrar las lineas
    // SDL_RenderPresent(render);
}

// ? Función que secciona y renderiza la función
void generarFuncion(char funcion[15], int divisiones, int w, int h, SDL_Renderer *render)
{

    /*---------------------Seccionamos el función---------------------*/

    // Declaramos la variable que guardará el coeficiente
    char coef[15] = "";

    // Declaramos variable que alojará la posición en donde esta la X
    int puesto = strchr(funcion, 'X') - funcion;

    // Verificamos si el funcionomio tiene una variable (X)
    if (strchr(funcion, 'X') != NULL)
    {
        // Quitamos los parentesis que haya después de la X
        eliminarCaracter(funcion, '(');
        eliminarCaracter(funcion, ')');

        if (funcion[0] == 'X' || ((funcion[0] == '+') && (funcion[1] == 'X')))
        {
            // En caso de que el valor de funcion[0] == 'X', significa que el coeficiente es 1
            coef[0] = '1';

            // Agregar el caracter nulo al final de coef
            coef[1] = '\0';
        }
        else
        {
            // Copiamos el string "funcion" en la variable "coef", hasta que llegue a la X
            memcpy(coef, funcion, puesto);

            // Agregar el caracter nulo al final de coef
            coef[puesto] = '\0';
        }

        // Quitamos el + de coeficiente ya que el '+' al principio de un numero no se pone
        eliminarCaracter(coef, '+');

        // Condición para ingresarle 1 al exponente, debido a que se intuye que si no hay nada, hay un "1"
        if (funcion[puesto + 1] == '\0')
        {
            // Le asignamos el valor a 1 al valor después de la X (puesto + 1)
            funcion[puesto + 1] = '1';

            // Le asignamos el null para determinar que se acabó el string
            funcion[puesto + 2] = '\0';
        }

        // Imprimimos el coeficiente y el exponente
        printf("coef : %s, exponente: %s\n", coef, &funcion[puesto + 1]);
    }
    else
    {
        // Quitamos el + de coeficiente ya que el '+' al principio de un numero no se pone
        eliminarCaracter(funcion, '+');

        // Si llega a ser falsa la condición, determinamos que el exponente es 0 y lo imprimimos
        printf("coef = %s\n", funcion);
    }

    /*-----------------------Dibujamos la función-----------------------*/

    SDL_SetRenderDrawColor(render, 0, 0, 255, 255); // Color negro

    SDL_Point puntos[divisiones]; // Array de puntos para guardar la curva
    int x = w / 2;
    int y = h / 2;

    // Generamos los del eje y-
    for (int i = 0; i <= divisiones / 2; i++)
    {
        printf("%i %i %i\n", w - x, y, i);

        puntos[i] = (SDL_Point){w - x, y - (+ 40)};
        x += w / divisiones;
        y += 4 * (h / divisiones);
    } 

    SDL_RenderDrawLines(render, puntos, divisiones / 2 + 1);

    x = w / 2;
    y = h / 2;

    // Generamos los del eje y+
    for (int i = 0; i <= divisiones / 2; i++)
    {
        printf("%i %i %i\n", x, y, i);

        puntos[i] = (SDL_Point){x, h - y - (+ 40)};
        x += w / divisiones;
        y += 4 * (h / divisiones);
    }

    SDL_RenderDrawLines(render, puntos, divisiones / 2 + 1);

    SDL_RenderPresent(render);
}