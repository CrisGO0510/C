#include <SDL2/SDL.h>
#include <stdio.h>

int main()
{

    // Inicializamos SDL2 con todos los subsistemas y en caso de generar error, obtener el error y parar el programa

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Declaramos una variable para poder manejar eventos (en este caso cerrar la ventana)
    SDL_Event event;

    /* Creamos una ventana, el tipado es SDL_Window*, y para crearlo usamos la función SSDL_CreateWindow() con los siguientes prototipos:

    title: el titulo que le queremos dar a la ventana
    x: Las Coordenadas en X donde queremos que se genere la ventana
    y: Las Coordenadas en y donde queremos que se genere la ventana
    w: El ancho de la ventana
    h: La altura de la ventana
    flags: Valores Uint32 que especifican las opciones de la ventana, como si debe ser redimensionable, debe estar en pantalla completa, si tiene un borde, etc.
    */

    SDL_Window *window = SDL_CreateWindow("Mi ventana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    // Verificamos si la ventana logró crearse de manera exitosa, sino imprime el error y retorna 1
    if (window == NULL)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Declaramos el renderizados que usaremos para poder dibujar graficos en la ventana (los parametros suelen ser siempre los mismos)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Verificamos si el render logró crearse de manera exitosa, sino imprime el error y retorna 1
    if (renderer == NULL)
    {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Declaramos un rectangulo en las coordenadas 100x100 del tamaño de 50x50
    SDL_Rect rect = {100, 100, 50, 50};

    // Declaramos un punto en las coordenadas 200x200
    SDL_Point punto = {200, 200};

    // Usamos SDL_SetRenderDrawColor para establecer el color utilizado para renderizar los elementos gráficos.
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Dibujar el rectángulo en el render
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Dibujamos el punto en el render
    SDL_RenderDrawPoint(renderer, punto.x, punto.y);

    // Actualizar el render para mostrar el rectangulo
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
