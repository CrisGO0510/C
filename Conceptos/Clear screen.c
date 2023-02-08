// Sistema para borrar texto en pantallas, con librerias

#include<stdio.h>
#include<stdlib.h>

int main ( ) {
    char tecla ;

    printf(" Programa de Borrado de pantalla !!!!");
    printf("\n---------------------------------------");
    printf("\n --------------------------------------");
    printf("\nDigite el numero 1: ");
    scanf("%c",&tecla);
    
    if(tecla=='1') {
		system("clear");
    	printf("Ha funcionado , el limpiador de pantalla");
    }
    else {   
        printf ( " \nNo ha funcionado el limpiador de pantalla");
	}
    return 0 ;
}
