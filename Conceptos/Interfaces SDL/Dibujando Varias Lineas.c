#include <SDL2/SDL.h>

int main()
{
    // Inicializamos los procesos necesarios
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Triángulo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    /*
        Definimos un arreglo de 4 puntos (Una estructura de tipo {X,Y})
        definimos 4 puntos debido a que SDL_RenderDrawLines() no asume que tiene 
        una forma cerrada; es solo dibujar líneas entre los puntos que ha
        proporcionado. Entonces para dibujar el triangulo necesitaria 4 puntos
        repitiendo el primero
    */
    SDL_Point points[4] = {{100, 100}, {200, 300}, {300, 100}, {100, 100}};

    // Hacemos el fondo blanco
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Cambiamos el color a azul
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    /* Llamamos la función RenderDrawLines la cuál como párametro recibe:
     * El renderer a usar
     * Un puntero a un arreglo donde tenemos un vector de puntos
     * La cantidad de puntos en el arreglo
     */
    SDL_RenderDrawLines(renderer, points, 4);

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