#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

void algo(TTF_Font *, char[], SDL_Rect);

int main()
{
    // Inicializar SDL y SDL_ttf
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // Crear ventana y renderizador
    SDL_Window *window = SDL_CreateWindow("Renderizar Texto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Cargar una fuente
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/TTF/times_new_roman/times.ttf", 34);
    if (!font)
    {
        printf("Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    //.--------------------------------

    // Renderizar texto sin estirarlo y centrarlo
    SDL_Color textColor = {255, 255, 255};
    char text[] = "Texto de ejemplo";
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect destRect;
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = textSurface->w;
    destRect.h = textSurface->h;

    printf("%i %i\n", textSurface->w, textSurface->h);

    SDL_RenderCopy(renderer, textTexture, NULL, &destRect);

    // algo(font,text, destRect);

    //.--------------------------------

    SDL_RenderPresent(renderer);

    // Esperar hasta que se cierre la ventana
    SDL_Event event;
    while (SDL_WaitEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            break;
        }
    }

    // Liberar recursos
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

void algo(TTF_Font *font, char text[], SDL_Rect destRect)
{
    int textWidth, textHeight;
    TTF_SizeText(font, text, &textWidth, &textHeight);

    if (destRect.w < textWidth)
    {
        destRect.w = textWidth;
    }

    if (destRect.h < textHeight)
    {
        destRect.h = textHeight;
    }

    if (destRect.w > textWidth)
    {
        destRect.x += (destRect.w - textWidth) / 2;
    }

    if (destRect.h > textHeight)
    {
        destRect.y += (destRect.h - textHeight) / 2;
    }
}