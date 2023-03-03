#include <stdio.h>

int main() {
    // Se imprime texto en rojo
    printf("\033[31mTexto en rojo\n");
    // Se imprime texto en verde
    printf("\033[32mTexto en verde\n");
    // Se restaura el color por defecto
    printf("\033[0mTexto en color por defecto\n");
    return 0;
}
