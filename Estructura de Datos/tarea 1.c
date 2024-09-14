#include <stdio.h>
#include <string.h>

// Prototipos de funciones
void sumVector(int *vec, int size);
void searchValue(int *vec, int size, int num);
void reverseString(char *str);
void reverseVector(int *vec, int size);
void lastOccurrence(int *vec, int size, int val);
int compareVectors(int *vec1, int *vec2, int size);
void removeElement(int *vec, int *size, int val);
void printVectorRecursively(int *vec, int size);
void sortVectorRecursively(int *vec, int size);
void swap(int *a, int *b);
void menu();

int main() {
    menu();
    return 0;
}

// Función que calcula la suma de todos los elementos de un vector
void sumVector(int *vec, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    printf("La suma de los elementos del vector es: %d\n", sum);
}

// Función que indica si un valor num se encuentra en un vector
void searchValue(int *vec, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (vec[i] == num) {
            printf("El valor %d se encuentra en el vector.\n", num);
            return;
        }
    }
    printf("El valor %d no se encuentra en el vector.\n", num);
}

// Función que invierte una cadena
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Cadena invertida: %s\n", str);
}

// Función que invierte los elementos de un vector
void reverseVector(int *vec, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(&vec[i], &vec[size - i - 1]);
    }
    printf("Vector invertido: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Función que encuentra la última aparición de un valor en un vector
void lastOccurrence(int *vec, int size, int val) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (vec[i] == val) {
            pos = i;
        }
    }
    if (pos != -1) {
        printf("El valor %d aparece por última vez en la posición %d\n", val, pos);
    } else {
        printf("El valor %d no se encuentra en el vector.\n", val);
    }
}

// Función que compara dos vectores
int compareVectors(int *vec1, int *vec2, int size) {
    for (int i = 0; i < size; i++) {
        if (vec1[i] != vec2[i]) {
            return 0;
        }
    }
    return 1;
}

// Función que elimina todas las apariciones de un elemento de un vector
void removeElement(int *vec, int *size, int val) {
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (vec[i] != val) {
            vec[j++] = vec[i];
        }
    }
    *size = j;
    printf("Vector modificado: ");
    for (int i = 0; i < *size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Función recursiva que imprime los elementos de un vector
void printVectorRecursively(int *vec, int size) {
    if (size == 0) {
        return;
    }
    printf("%d ", *vec);
    printVectorRecursively(vec + 1, size - 1);
}

// Función que intercambia dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función recursiva que ordena un vector
void sortVectorRecursively(int *vec, int size) {
    if (size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            swap(&vec[i], &vec[i + 1]);
        }
    }
    sortVectorRecursively(vec, size - 1);
}

// Menú que permite seleccionar qué función ejecutar
void menu() {
    int option, num, size, val;
    int vec[100], vec1[100], vec2[100];
    char str[100];

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Sumar todos los elementos de un vector\n");
        printf("2. Buscar un valor en un vector\n");
        printf("3. Invertir una cadena\n");
        printf("4. Invertir los elementos de un vector\n");
        printf("5. Encontrar la última aparición de un valor en un vector\n");
        printf("6. Comparar dos vectores\n");
        printf("7. Eliminar todas las apariciones de un elemento de un vector\n");
        printf("8. Imprimir los elementos de un vector recursivamente\n");
        printf("9. Ordenar un vector recursivamente\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                sumVector(vec, size);
                break;
            case 2:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &num);
                searchValue(vec, size, num);
                break;
            case 3:
                printf("Ingrese la cadena: ");
                scanf("%s", str);
                reverseString(str);
                break;
            case 4:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                reverseVector(vec, size);
                break;
            case 5:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &val);
                lastOccurrence(vec, size, val);
                break;
            case 6:
                printf("Ingrese el tamaño de los vectores: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del primer vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec1[i]);
                }
                printf("Ingrese los elementos del segundo vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec2[i]);
                }
                if (compareVectors(vec1, vec2, size)) {
                    printf("Los vectores son iguales.\n");
                } else {
                    printf("Los vectores no son iguales.\n");
                }
                break;
            case 7:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &val);
                removeElement(vec, &size, val);
                break;
            case 8:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                printf("Vector: ");
                printVectorRecursively(vec, size);
                printf("\n");
                break;
            case 9:
                printf("Ingrese el tamaño del vector: ");
                scanf("%d", &size);
                printf("Ingrese los elementos del vector: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &vec[i]);
                }
                sortVectorRecursively(vec, size);
                printf("Vector ordenado: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", vec[i]);
                }
                printf("\n");
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente nuevamente.\n");
                break;
        }
    } while (option != 0);
}
