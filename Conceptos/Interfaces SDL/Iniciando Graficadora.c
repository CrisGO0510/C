#include <SDL2/SDL.h>
#include <stdio.h>

// Prototipos a usar

void generarPlano(int, int, SDL_Renderer *, int);
void generarFuncion(char[], SDL_Renderer *, int);

/* Acá estamos creando un tipo de dato basado en un struct que se va a llamar SDL_Line
 *@param start {{x1,y1}, {x2,y2}, {R,G,B,A}}
 *@param end {{x1,y1}, {x2,y2}, {R,G,B,A}}
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
    int divisiones = 8;

    // Función que nos asigna el valor del tamaño de la ventana
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Llamamos a la función para generar el plano
    generarPlano(window_height, window_width, plano, divisiones);

    //! Esperar a que el usuario cierre la ventana
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    SDL_DestroyRenderer(plano);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

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
        printf("%f\n", x);
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

    // Actualizar el render para mostrar las lineas
    SDL_RenderPresent(render);
}

void generarFuncion(char funcion[], SDL_Renderer *render, int divisiones) {}