// Programa que detecta si el numero supera a 10, si es así los multiplica, sino, sumarlos.

#include<stdio.h>

int main(){
	
	int num,res;
	printf("Ingrese un numero: ");
	scanf("%i",&num);
	
	if(num>=10){
		//multiplican
		res = 1;
		while(num>=1){
			res = res*num;
			num--;
		}
	} else if(num<10){
		//suma
		res = 0;
		while(num>=1){
			res = res+num;
			num--;			
		}
	} else {
		printf("Error, Ingrese numeros");
	}
	
	printf("%i",res);
	
	return 0;
}
