#include <SDL2/SDL.h>
#include <stdio.h>

// Prototipos a usar

void generarPlano(int, int, SDL_Renderer *);

/* Acá estamos creando un tipo de dato basado en un struct que se va a llamar SDL_Line
 *@param start {{x1,y1}, {x2,y2}, {R,G,B,A}}
 *@param end {{x1,y1}, {x2,y2}, {R,G,B,A}}
 */
typedef struct
{
	SDL_Point start;
	SDL_Point end;
} SDL_Line;

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
	SDL_Window *window = SDL_CreateWindow("Mi Ventana Redimensionable",
										  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640,
										  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

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

	// Llamamos a la función para generar el plano
	generarPlano(window_height, window_width, plano);

	//! Esperar a que el usuario cierre la ventana
	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			// Si el usuario cerró la ventana
			if (event.type == SDL_QUIT)
			{
				break;
			}
			// Si la ventana fue redimensionada
			else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			{

				SDL_Delay(500);

				int new_width, new_height;
				SDL_GetWindowSize(window, &new_width, &new_height);

				// Actualizamos las variables del tamaño de la ventana
				window_height > window_width ? SDL_SetWindowSize(window, new_height, new_height) : SDL_SetWindowSize(window, new_width, new_width);

				// Volvemos a generar el plano con las nuevas dimensiones de la ventana
				generarPlano(new_height, new_width, plano);
			}
		}
	}

	SDL_DestroyRenderer(plano);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void generarPlano(int h, int w, SDL_Renderer *render)
{
	// Variable para saber cuantas divisiónes a de tener (DEBE SER PAR)
	int divisiones = 8;
	SDL_Line divisoresVerticales[divisiones];
	SDL_Line divisoresHorizontales[divisiones];
	float x = 0;
	float y = 0;

	// Lineas divisoras
	for (int i = 0; i < divisiones; i++)
	{
		divisoresVerticales[i] = (SDL_Line){{x, 0}, {x, h}};
		divisoresHorizontales[i] = (SDL_Line){{0, y}, {w, y}};
		x += (float)w / divisiones;
		y += (float)h / divisiones;
		printf("%f\n", x);
	}

	// Color blanco al fondo del plano
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

	// Limpiamos la ventana
	SDL_RenderClear(render);

	// Cambiamos el color a un tono grisaseo
	SDL_SetRenderDrawColor(render, 205, 205, 205, 255);

	// Dibujamos las lineas divisoras a través de un bucle for
	for (int i = 0; i < divisiones; i++)
	{
		SDL_RenderDrawLine(render, divisoresVerticales[i].start.x, divisoresVerticales[i].start.y, divisoresVerticales[i].end.x, divisoresVerticales[i].end.y);

		SDL_RenderDrawLine(render, divisoresHorizontales[i].start.x, divisoresHorizontales[i].start.y, divisoresHorizontales[i].end.x, divisoresHorizontales[i].end.y);
	}

	// Le damos un color a las lineas
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

	// Declaramos la linea X del plano cartesiano
	SDL_Line lineaX = {{0, h / 2}, {w, h / 2}};

	// Declaramos la linea Y del plano cartesiano
	SDL_Line lineaY = {{w / 2, 0}, {w / 2, h}};

	// Dibujamos las lineas
	SDL_RenderDrawLine(render, lineaY.start.x, lineaY.start.y, lineaY.end.x, lineaY.end.y);

	SDL_RenderDrawLine(render, lineaX.start.x, lineaX.start.y, lineaX.end.x, lineaX.end.y);

	// Actualizar el render para mostrar las lineas
	SDL_RenderPresent(render);
}