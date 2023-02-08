// Programa que escribe el literal que le corresponde a cada nota

#include<stdio.h>
#include<ctype.h> // Esta libreria nos permite funciones como el cambio de caracteres

int main(){
	
	char nota;
	
	printf("Ingrese la nota del estudiante: ");
	scanf("%c",&nota);
	
	nota = toupper(nota); // Para volverlo minuscula necesitariamos usar tolower
	
	switch(nota){
		case 'A':
			printf("La nota del estudiante es Excelente"); break;
		case 'B':
			printf("La nota del estudiante es Notable"); break;
		case 'C':
			printf("La nota del estudiante es Aprobado"); break;
		case 'D':
			printf("La nota del estudiante es Reprobado"); break;
		case 'F':
			printf("La nota del estudiante es Reprobado"); break;
		default:
			printf("Error, Ingrese un valor valido"); break;	
	}
	
	return 0;
}
