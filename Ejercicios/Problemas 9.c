#include<stdio.h>

int main(){
	int opcion,num,mod;
	
	printf("/tBienvenido, Elija una de las opciones");
	printf("\n1. El cubo del numero");
	printf("\n2. El numero es par o impar");
	printf("\n3. Salir");
	printf("\nDigite su opcion: ");
	scanf("%i",&opcion);
	
	switch(opcion){
		case 1:
			printf("A que numero desea hayar su cubo: ");
			scanf("%i",&num);
			printf("El cubo de %i es: %i",num,num*num*num);
			break;
		case 2:
			printf("Que numero desea saber si es par o impar: ");
			scanf("%i",&num);
			
			mod = num%2;
			
			if(mod == 0){
				printf("%i es par",num);
			} else {
				printf("%i es impar",num);
			}
			break;
		case 3:
			printf("Gracias por usar el programa");
			break;
		default:
			printf("Esa opcion no existe en el menu");
			break;
	}
	return 0;
}
