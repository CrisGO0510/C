#include <SDL2/SDL.h>
#include <stdio.h>

void algo(SDL_Rect *);

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("SDL_ttf Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect textRect = {0, 0, 640, 100}; // Posición centrada del texto

    SDL_Event event;
    int quit = 0;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect destRect;
    destRect.x = 100;
    destRect.y = 100;
    destRect.w = 1;
    destRect.h = 1;

    printf("%i %i %i %i\n", destRect.x, destRect.y, destRect.w, destRect.h);

    algo(&destRect);

    printf("%i %i %i %i\n", destRect.x, destRect.y, destRect.w, destRect.h);

    SDL_RenderPresent(renderer);

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

void algo(SDL_Rect *destRect)
{

    destRect->h = 1000;

    printf("%i %i %i %i\n", destRect->x, destRect->y, destRect->w, destRect->h);
}