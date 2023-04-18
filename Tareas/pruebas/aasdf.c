#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PuntoSospechoso (int [80][80][80], int, int, int);
int LineaSospechosa (int [80][80][80], int, int [80][80]);
void LlenarVector (int [80][80], int, int, int);
void ImprimirLinea (int [80][80], int, int);


int main () {
	srand (time (NULL)); //Semilla para generar los números aleatorios
	int resonancia [80][80][80]; //Arreglo tridimensional
	int lineas [80][80];
	int x = 0; //x son las coordenadas en el eje x que serían a su vez las columnas
	int y = 0; //y son las coordenadas en el eje y que serían a su vez las filas
	int z = 0; //z son las coordenadas en el eje z que serían a su vez los planos

	for (z = 0; z < 80; z++){ //Inicializamos z en 0 hasta que llegue  100 e incrementa en 1
		for (y = 0; y < 80; y++) { //Inicializamos z en 0 hasta que llegue  100 e incrementa en 1
			for (x = 0; x < 80; x++) { //Inicializamos z en 0 hasta que llegue  100 e incrementa en 1
				
				int numran = rand () % 20 + 23; //Declaramos el número que al que le adignamos un número random entre 0 y 255
				
				resonancia [x][y][z] = numran; //En las coordenadas (x,y,z) de resonancia guardamos el número anterior
				
			}
		}
	}

	for (y = 0; y < 80; y++){
		for (x = 0; x < 80; x++){
			lineas [x][y] = 0;
		} 
	}
	LineaSospechosa (resonancia, 0, lineas);
}


int PuntoSospechoso (int punto [80][80][80], int x, int y, int z) {
	
	int contador = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	if (x == 0 || x == 79)
	return 0;
	
	if (y == 0 || y == 79)
	return 0;
	
	if (z == 0 || z == 79)
	return 0;
	
	for (k = -1; k <= 1; k++) {
		for (j = -1; j <= 1; j++) {
			for (i = -1; i <= 1; i++) {
				
				if (i == 0 && j == 0 && k == 0) {
				}
				
				else {
					if (punto [x - i][y - j][z - k] >= 20 && punto [x - i][y - j][z - k] <= 40)
					contador++;
				}
			}
		}
	}
	
	if (contador == 26)
	return 1;
	
	else
	return 0;
	
}

int LineaSospechosa (int plano [80][80][80], int z, int lineas [80][80]) {
	
	printf ("Ingrese el plano en el que desea ver las líneas sospechosas: ");
	scanf ("%i", &z);
	
	int x = 0;
	int y = 0;
	int contpuntos = 0;
	int contlineas = 0;
	
	for (y = 0; y < 80; y++) {
		for (x = 0; x < 80; x++) {
			
			if (PuntoSospechoso (plano, x, y, z) == 1)
			contpuntos++;
			
			else{
				if (contpuntos >= 3) {
					contlineas++;
					LlenarVector (lineas, x - contpuntos, y, x);
					contpuntos = 0;
				}
				
				else {
					contpuntos = 0;
				}
			}
		}
	}
	
	ImprimirLinea (lineas, 0, 0);
	return contlineas;
}


void LlenarVector (int lineas [80][80], int xinicial, int y, int x) {
	
	if (xinicial <= x) {
		lineas [xinicial][y] = 1;
		xinicial++;
	}
}

void ImprimirLinea (int lineas [80][80], int x, int y) { //Esta funcion imprimirá el plano con las líneas sospechosas
	
	printf ("  0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789 \n");
	printf (" +----------------------------------------------------------------------------------------------------+ \n  ");
	
	for (y = 0; y < 80; y++) { //Inicializamos y en 0 hasta que llegue  100 e incrementa en 1
		if (y < 10) 
		printf ("\n%i   |", y);
	
		else
		printf ("\n%i  |", y);
			
			for (x = 0; x < 80; x++) { //Inicializamos x en 0 hasta que llegue  100 e incrementa en 1
				
				if (lineas [x][y] == 1){ //Se llama a la función PuntoSospechoso para verificar si lo es y en este caso se imprime un pixel negro 
					printf ("%c", '*');
				}
				else{ //De lo contrario imprime un caracter de espacio
					printf ("%c", ' ');
				}
			
			}
			printf ("|\n");
	}
}