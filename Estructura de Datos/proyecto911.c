#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes
#define PROGRAMADO 0
#define REALIZADO 1

// Estructura de pasajero
typedef struct Pasajero {
    char cedula[20];
    struct Pasajero* siguiente;
} Pasajero;

// Estructura de vuelo
typedef struct Vuelo {
    char numeroVuelo[10];
    int estado;  // 0 para programado, 1 para realizado
    Pasajero* listaPasajeros;
    struct Vuelo* siguiente;
} Vuelo;

// Lista de vuelos (lista principal)
Vuelo* listaVuelos = NULL;

// Función para crear un nuevo vuelo
void adicionarVuelo(char* numeroVuelo) {
    Vuelo* nuevoVuelo = (Vuelo*)malloc(sizeof(Vuelo));
    strcpy(nuevoVuelo->numeroVuelo, numeroVuelo);
    nuevoVuelo->estado = PROGRAMADO;
    nuevoVuelo->listaPasajeros = NULL;
    nuevoVuelo->siguiente = listaVuelos;
    listaVuelos = nuevoVuelo;
}

// Función para adicionar un pasajero a un vuelo
void adicionarPasajero(char* numeroVuelo, char* cedula) {
    Vuelo* vuelo = listaVuelos;
    while (vuelo != NULL) {
        if (strcmp(vuelo->numeroVuelo, numeroVuelo) == 0) {
            Pasajero* nuevoPasajero = (Pasajero*)malloc(sizeof(Pasajero));
            strcpy(nuevoPasajero->cedula, cedula);
            nuevoPasajero->siguiente = vuelo->listaPasajeros;
            vuelo->listaPasajeros = nuevoPasajero;
            return;
        }
        vuelo = vuelo->siguiente;
    }
    printf("Vuelo no encontrado.\n");
}

// Función para listar los pasajeros de un vuelo
void listarPasajeros(char* numeroVuelo) {
    Vuelo* vuelo = listaVuelos;
    while (vuelo != NULL) {
        if (strcmp(vuelo->numeroVuelo, numeroVuelo) == 0) {
            printf("Pasajeros del vuelo %s:\n", vuelo->numeroVuelo);
            Pasajero* pasajero = vuelo->listaPasajeros;
            while (pasajero != NULL) {
                printf("- %s\n", pasajero->cedula);
                pasajero = pasajero->siguiente;
            }
            return;
        }
        vuelo = vuelo->siguiente;
    }
    printf("Vuelo no encontrado.\n");
}

// Función para listar vuelos programados o realizados
void listarVuelos(int estado) {
    Vuelo* vuelo = listaVuelos;
    while (vuelo != NULL) {
        if (vuelo->estado == estado) {
            printf("Vuelo %s - %s\n", vuelo->numeroVuelo, estado == PROGRAMADO ? "Programado" : "Realizado");
        }
        vuelo = vuelo->siguiente;
    }
}

// Función para obtener los vuelos realizados o programados por un pasajero
void listarVuelosPorPasajero(char* cedula) {
    Vuelo* vuelo = listaVuelos;
    printf("Vuelos del pasajero con cédula %s:\n", cedula);
    while (vuelo != NULL) {
        Pasajero* pasajero = vuelo->listaPasajeros;
        while (pasajero != NULL) {
            if (strcmp(pasajero->cedula, cedula) == 0) {
                printf("- Vuelo %s (%s)\n", vuelo->numeroVuelo, vuelo->estado == PROGRAMADO ? "Programado" : "Realizado");
            }
            pasajero = pasajero->siguiente;
        }
        vuelo = vuelo->siguiente;
    }
}

// Función para registrar que un vuelo ha sido realizado
void registrarVueloRealizado(char* numeroVuelo) {
    Vuelo* vuelo = listaVuelos;
    while (vuelo != NULL) {
        if (strcmp(vuelo->numeroVuelo, numeroVuelo) == 0) {
            vuelo->estado = REALIZADO;
            printf("El vuelo %s ha sido marcado como realizado.\n", numeroVuelo);
            return;
        }
        vuelo = vuelo->siguiente;
    }
    printf("Vuelo no encontrado.\n");
}

// Función para registrar que un pasajero ha abordado el vuelo
void registrarPasajeroAbordo(char* numeroVuelo, char* cedula) {
    Vuelo* vuelo = listaVuelos;
    while (vuelo != NULL) {
        if (strcmp(vuelo->numeroVuelo, numeroVuelo) == 0) {
            Pasajero* pasajero = vuelo->listaPasajeros;
            while (pasajero != NULL) {
                if (strcmp(pasajero->cedula, cedula) == 0) {
                    printf("Pasajero con cédula %s ha abordado el vuelo %s.\n", cedula, numeroVuelo);
                    return;
                }
                pasajero = pasajero->siguiente;
            }
            printf("Pasajero no encontrado en el vuelo.\n");
            return;
        }
        vuelo = vuelo->siguiente;
    }
    printf("Vuelo no encontrado.\n");
}

int main() {
    // Ejemplos de uso
    adicionarVuelo("AA123");
    adicionarVuelo("BB456");
    
    adicionarPasajero("AA123", "123456789");
    adicionarPasajero("AA123", "987654321");
    adicionarPasajero("BB456", "123456789");
    
    listarPasajeros("AA123");

    listarVuelos(PROGRAMADO);

    listarVuelosPorPasajero("123456789");

    registrarVueloRealizado("AA123");

    listarVuelos(REALIZADO);

    registrarPasajeroAbordo("AA123", "123456789");

    return 0;
}
