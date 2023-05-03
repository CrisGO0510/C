#include <SDL2/SDL.h>
#include <math.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Curva Senoidal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Color blanco
    SDL_RenderClear(renderer);                            // Limpiamos la ventana

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Color negro

        SDL_Point puntos[640]; // Array de puntos para guardar la curva

    // Generamos los puntos de la curva senoidal
    for (int x = 0; x < 640; x++)
    {
        int y = 240 + 100 * sin(0.1 * x);
        puntos[x] = (SDL_Point){x, y};
    }

    // Dibujamos la curva
    SDL_RenderDrawLines(renderer, puntos, 640);

    SDL_RenderPresent(renderer);

    // Esperar a que el usuario cierre la ventana
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}