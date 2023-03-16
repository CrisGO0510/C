#include <stdio.h>

int main(){

    char hola[8] = "";
    printf("%s\n", hola);

    hola[0] = 'a';

    printf("%s\n", hola);

    return 0;
}