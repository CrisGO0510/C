#include <SDL2/SDL.h>

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL no pudo inicializarse. Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Mi ventana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("No se pudo crear la ventana de SDL. Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("No se pudo crear el renderizador de SDL. Error: %s\n", SDL_GetError());
        return 1;
    }

    // Obtener las dimensiones de la ventana
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Calcular las coordenadas del centro de la ventana
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    // Dibujar un rectángulo rojo en el centro de la ventana
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect rect = {centerX - 160 / 2, centerY - 160 / 2, 160, 160};
    SDL_RenderFillRect(renderer, &rect);

    // Actualizar la ventana con el dibujo
    SDL_RenderPresent(renderer);

    // Esperar a que el usuario cierre la ventana
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    // Liberar recursos y cerrar SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
