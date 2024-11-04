#include <stdio.h>

#include "abb.h"
#include "avl.h"
#include "rbt.h"

int main() {
  int choice;
  do {
    printf("Menú Principal\n");
    printf("1. ABB\n");
    printf("2. Arboles AVL\n");
    printf("3. Arboles Rojo - Negros\n");
    printf("4. Salir\n");
    printf("Qué tipo de árbol Desea Implementar (1-4)? ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        menuABB();
        break;
      case 2:
        menuAVL();
        break;
      case 3:
        menuRBT();
        break;
      case 4:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (choice != 4);

  return 0;
}