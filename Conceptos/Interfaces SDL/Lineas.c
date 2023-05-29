#include <SDL2/SDL.h>
#include <stdio.h>

int main()
{

    // Inicializamos SDL2 con todos los subsistemas y en caso de generar error, obtener el error y parar el programa

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error initializing SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Declaramos una variable para poder manejar eventos (en este caso cerrar la ventana)
    SDL_Event event;

    // Creamos una ventana

    SDL_Window *window = SDL_CreateWindow("Mi ventana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 480, SDL_WINDOW_SHOWN);

    // Verificamos si la ventana logró crearse de manera exitosa, sino imprime el error y retorna 1
    if (window == NULL)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Declaramos el renderizados que usaremos para poder dibujar graficos en la ventana
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Verificamos si el render logró crearse de manera exitosa, sino imprime el error y retorna 1
    if (renderer == NULL)
    {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Acá estamos creando un tipo de dato basado en un struct que se va a llamar SDL_Line
    typedef struct
    {
        SDL_Point start;
        SDL_Point end;
        SDL_Color color;
    } SDL_Line;

    SDL_Line linea = {{100, 100}, {200, 200}, {255, 0, 0, 255}};

    // Le damos un color a la linea
    SDL_SetRenderDrawColor(renderer, linea.color.r, linea.color.g, linea.color.b, linea.color.a);

    // Dibujamos la linea
    SDL_RenderDrawLine(renderer, linea.start.x, linea.start.y, linea.end.x, linea.end.y);

    // Actualizar el render para mostrar la linea
    SDL_RenderPresent(renderer);

    // Esperar a que el usuario cierre la ventana
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    // Es importante siempre liberar recursos y cerrar SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
