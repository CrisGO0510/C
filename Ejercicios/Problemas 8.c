// Solicitar un numero del 1 al 12 y mostrar el mes que corresponde

#include<stdio.h>

int main(){
	
	int a;
	
	printf("Ingrese un numero del 1 al 12: ");
	scanf("%i",&a);
	
	switch(a){
		case 1: printf("Su mes es enero"); break;
		case 2: printf("Su mes es febrero"); break;
		case 3: printf("Su mes es marzo"); break;
		case 4: printf("Su mes es abril"); break;
		case 5: printf("Su mes es mayo"); break;
		case 6: printf("Su mes es junio"); break;
		case 7: printf("Su mes es julio"); break;
		case 8: printf("Su mes es agosto"); break;
		case 9: printf("Su mes es septiembre"); break;
		case 10: printf("Su mes es octubre"); break;
		case 11: printf("Su mes es noviembre"); break;
		case 12: printf("Su mes es dicienbre"); break;
		default: printf("Por favor ingrese un numero del 1 al 12");
	}
	
	return 0;
}
