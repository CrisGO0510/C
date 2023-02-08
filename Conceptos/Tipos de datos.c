// Tipos de datos

#include<stdio.h>

int main(){
	char a = 'e'; // tamaño = 1 byte Rango: 0..255 	se debe poner: %c, a
	short b = -15; // tamaño = 2 bytes Rango: -128...127
	int c = 1024; // tamaño = 2 bytes Rango: -32768...32767
	unsigned int d = 128; // tamaño = 2 bytes Rango: 0..65535
	long e = 123456; // tamaño = 4 bytes Rango: -2147483648...-2147483647 	se debe poner: %li, e
	float f = 15.765; // tamaño = 4 bytes	 se debe poner: %f, f
	double m = 1223.1234;  // tamaño = 8 bytes 		se debe poner %lf, m
		
	printf("El elemento es: %i", b);
	
	return 0;
}
