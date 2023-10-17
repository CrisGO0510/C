#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define NUM_NUMBERS 10

int main() {
    // Inicializar SDL y SDL_ttf
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // Crear ventana y renderizador
    SDL_Window* window = SDL_CreateWindow("Números en Columnas", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Cargar una fuente
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/TTF/times_new_roman/times.ttf", 24);
    if (!font) {
        printf("Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Crear vector de superficies para los números
    SDL_Surface* numberSurfaces[NUM_NUMBERS] = {NULL};

    // Renderizar los números en columnas
    SDL_Color textColor = {255, 255, 255};
    int columnWidth = 80;
    int rowHeight = 40;
    int x = (320 - columnWidth) / 2;
    int y = 20;

    for (int i = 1; i <= NUM_NUMBERS; i++) {
        // Crear una superficie para el número
        char numberText[3];
        sprintf(numberText, "%d", i);
        numberSurfaces[i - 1] = TTF_RenderText_Solid(font, numberText, textColor);
        if (!numberSurfaces[i - 1]) {
            printf("Error al crear la superficie del número %d: %s\n", i, TTF_GetError());
            break;
        }

        // Calcular la posición del número
        SDL_Rect destRect = {x, y, columnWidth, rowHeight};

        // Crear una textura a partir de la superficie
        SDL_Texture* numberTexture = SDL_CreateTextureFromSurface(renderer, numberSurfaces[i - 1]);
        if (!numberTexture) {
            printf("Error al crear la textura del número %d: %s\n", i, SDL_GetError());
            SDL_FreeSurface(numberSurfaces[i - 1]);
            break;
        }

        // Renderizar el número en la posición calculada
        SDL_RenderCopy(renderer, numberTexture, NULL, &destRect);

        // Actualizar la posición para el próximo número
        y += rowHeight;

        // Liberar recursos
        SDL_DestroyTexture(numberTexture);
    }

    // Presentar el renderizador
    SDL_RenderPresent(renderer);

    // Esperar hasta que se cierre la ventana
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // Liberar recursos
    for (int i = 0; i < NUM_NUMBERS; i++) {
        SDL_FreeSurface(numberSurfaces[i]);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
