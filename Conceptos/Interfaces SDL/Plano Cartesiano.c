#include <SDL2/SDL.h>
#include <stdio.h>

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
    SDL_Window *window = SDL_CreateWindow("Plano Cartesiano", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

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

    // Función que nos asigna el valor del tamaño de la ventana
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Acá estamos creando un tipo de dato basado en un struct que se va a llamar SDL_Line
    typedef struct
    {
        SDL_Point start;
        SDL_Point end;
        SDL_Color color;
    } SDL_Line;

    // Declaramos la linea X del plano cartesiano
    SDL_Line lineaX = {{0, window_height / 2}, {window_width, window_height / 2}, {0, 0, 0, 255}};

    // Declaramos la linea Y del plano cartesiano
    SDL_Line lineaY = {{window_width / 2, 0}, {window_width / 2, window_height}, {0, 0, 0, 255}};

    // Color blanco al fondo del plano
    SDL_SetRenderDrawColor(plano, 255, 255, 255, 255);

    // Limpiamos la ventana
    SDL_RenderClear(plano); 

    // Le damos un color a las lineas
    SDL_SetRenderDrawColor(plano, lineaY.color.r, lineaY.color.g, lineaY.color.b, lineaY.color.a);

    SDL_SetRenderDrawColor(plano, lineaX.color.r, lineaX.color.g, lineaX.color.b, lineaX.color.a);

    // Dibujamos las lineas
    SDL_RenderDrawLine(plano, lineaY.start.x, lineaY.start.y, lineaY.end.x, lineaY.end.y);

    SDL_RenderDrawLine(plano, lineaX.start.x, lineaX.start.y, lineaX.end.x, lineaX.end.y);

    // Actualizar el render para mostrar las lineas
    SDL_RenderPresent(plano);

    // Esperar a que el usuario cierre la ventana
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    // Es importante siempre liberar recursos y cerrar SDL
    SDL_DestroyRenderer(plano);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}