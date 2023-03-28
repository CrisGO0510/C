#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Esta es una cadena de caracteres.";
    char subcadena[20];
    int inicio = 2; // Indica el índice del primer caracter de la sección
    int fin = 5; // Indica el índice del último caracter de la sección
    
    // Copiar la sección de cadena a subcadena
    memcpy(subcadena, &cadena[inicio], fin - inicio + 1);
    
    // Agregar el caracter nulo al final de subcadena
    subcadena[fin - inicio + 1] = '\0';
    
    // Imprimir el contenido de subcadena
    printf("La subcadena es: %s\n", subcadena);
    
    return 0;
}
