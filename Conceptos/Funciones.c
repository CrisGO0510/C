// Haremos un ejemplo de como utilizar lsa funciones

#include <stdio.h>

int main(){
    fun();
    printf("Después del main");

    return 0;
}

// Creamos la función con el tipado que queremos retornar, en este caso será
// un 0 (int)
int fun(){
    printf("Antes del main");
    
    return 0;
}