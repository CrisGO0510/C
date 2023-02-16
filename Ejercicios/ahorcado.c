/*
 * Haremos un ahorcado en el cual usaremos vectores de string y un crearemos una
 * función que retorne una palabra random
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *setPalabra();
int randomNum();

int main(){

    char palabra[15] = "";
    strcpy(palabra, setPalabra());

    printf("%s\n", palabra);

    char palabraOculta[15] = "";

    for (int i = 0; i < strlen(palabra); i++)
    {
        palabraOculta[i] = "-";
    }
    
    printf("%s", palabraOculta);
 
    return 0;
}

char *setPalabra(){

    switch (randomNum()){
    case 1:
        return "CELULAR";
    case 2:
        return "CARRO";
    case 3:
        return "ARROZ";
    case 4:
        return "CADENA";
    case 5:
        return "ESTUDIANTE";
    case 6:
        return "MESA";
    case 7:
        return "EXTINTOR";
    case 8:
        return "ENGRAPADORA";
    case 9:
        return "CASCO";
    case 10:
        return "GORRA";
    default:
        *setPalabra();
        break;
    }
}

int randomNum(){

    srand(time(NULL));
    int num = rand() % 10 + 1; 
    
    return num;
}