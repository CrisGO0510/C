#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    // Inicializa SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return -1;
    }

    // Crea la ventana
    window = SDL_CreateWindow("Ventana Básica", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Obtiene la superficie de la ventana
    screenSurface = SDL_GetWindowSurface(window);

    // Rellena la superficie de color blanco
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));

    // Actualiza la superficie de la ventana
    SDL_UpdateWindowSurface(window);

    // Espera a que el usuario cierre la ventana
    SDL_Event event;
    while (1) { // Se utiliza el valor entero 1 en lugar de true
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    // Destruye la ventana y finaliza SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
