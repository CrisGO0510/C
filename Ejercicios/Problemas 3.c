/*Calcular el nuevo salario de un obrero si obtuvo un incremento de sueldo del 25%
con respecto a su salario anterior*/

#include<stdio.h>

int main(){
	
	float salario;
	
	printf("Ingrese su salario: ");
	scanf("%f",&salario);
	
	printf("Su incremento de 25%% en el salario es: %.1f",salario*1.250);
	
	return 0;
}
