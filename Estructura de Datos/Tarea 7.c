#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passenger
{
    char idFlight[7];
    char cc[11];
    char name[21];
    char cellphone[11];
    char status;
    struct Passenger *next;
} Passenger;

typedef struct Flight
{
    char idFlight[7];
    char from[13];
    char to[13];
    char registration[7];
    char pilot[21];
    char cellphone[11];
    char status;
    Passenger *passenger;
    struct Flight *next;
} Flight;

Flight *getFlights(const char *);
Passenger *getPassengers(const char *, char[7]);
void newFlight(Flight **);
void newPassenger(Flight *);
void printPassengersByFlight(Flight *, char[7]);
void printScheduledFlight(Flight *);
void printCompletedFlight(Flight *);
void printPassengerInFlightByDocument(Flight *, const char *);
void approveStatusFlight(Flight *);
void approveStatusPassenger(Passenger *, const char *);
void clearScreen();
void menu();
void saveFlights(Flight *);
void savePassengers(Passenger *);

int main()
{
    menu();

    return 0;
}

Flight *getFlights(const char *nameArchive)
{
    FILE *file = fopen(nameArchive, "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    Flight *first = NULL;
    Flight *last = NULL;

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        Flight *newFlight = (Flight *)malloc(sizeof(Flight));
        if (newFlight == NULL)
        {
            printf("Error al reservar memoria.\n");
            fclose(file);
            return NULL;
        }

        // Procesar la línea
        strncpy(newFlight->idFlight, line, 6);
        newFlight->idFlight[6] = '\0';

        strncpy(newFlight->from, line + 6, 12);
        newFlight->from[12] = '\0';

        strncpy(newFlight->to, line + 18, 12);
        newFlight->to[12] = '\0';

        strncpy(newFlight->registration, line + 30, 6);
        newFlight->registration[6] = '\0';

        strncpy(newFlight->pilot, line + 36, 20);
        newFlight->pilot[20] = '\0';

        strncpy(newFlight->cellphone, line + 56, 10);
        newFlight->cellphone[10] = '\0';

        // Guardar el status
        newFlight->status = line[66];

        newFlight->passenger = getPassengers("pasajeros.txt", newFlight->idFlight);
        newFlight->next = NULL;

        // Enlazar el vuelo en la list
        if (first == NULL)
        {
            first = newFlight;
            last = newFlight;
        }
        else
        {
            last->next = newFlight;
            last = newFlight;
        }
    }

    fclose(file);

    return first;
}

Passenger *getPassengers(const char *nameArchive, char idFlight[7])
{
    FILE *file = fopen(nameArchive, "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    Passenger *first = NULL;
    Passenger *last = NULL;

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        Passenger *newPassenger = (Passenger *)malloc(sizeof(Passenger));
        if (newPassenger == NULL)
        {
            printf("Error al reservar memoria.\n");
            fclose(file);
            return NULL;
        }

        // Procesar la línea
        strncpy(newPassenger->idFlight, line, 6);
        newPassenger->idFlight[6] = '\0';

        if (strcmp(newPassenger->idFlight, idFlight) != 0)
        {
            free(newPassenger);
            continue;
        }

        strncpy(newPassenger->cc, line + 6, 10);
        newPassenger->cc[10] = '\0';

        strncpy(newPassenger->name, line + 16, 20);
        newPassenger->name[20] = '\0';

        strncpy(newPassenger->cellphone, line + 36, 10);
        newPassenger->cellphone[10] = '\0';

        // Guardar el status (asumiendo que está en la posición 46)
        newPassenger->status = line[46];

        newPassenger->next = NULL;

        // Enlazar el pasajero en la list
        if (first == NULL)
        {
            first = newPassenger;
            last = newPassenger;
        }
        else
        {
            last->next = newPassenger;
            last = newPassenger;
        }
    }

    fclose(file);
    return first;
}

// Función para adicionar un vuelo
void newFlight(Flight **listFlights)
{
    Flight *newFlight = (Flight *)malloc(sizeof(Flight));

    // Solicitar datos al usuario
    printf("Ingrese el ID del vuelo: ");
    scanf("%s", newFlight->idFlight);
    fflush(stdin);

    printf("Ingrese el origen del vuelo: ");
    scanf("%s", newFlight->from);
    fflush(stdin);

    printf("Ingrese el destino del vuelo: ");
    scanf("%s", newFlight->to);
    fflush(stdin);

    printf("Ingrese la matrícula del avión: ");
    scanf("%s", newFlight->registration);
    fflush(stdin);

    printf("Ingrese el nombre del piloto: ");
    fgets(newFlight->pilot, sizeof(newFlight->pilot), stdin);
    newFlight->pilot[strcspn(newFlight->pilot, "\n")] = '\0'; // Remove newline character

    printf("Ingrese el número de celular del piloto: ");
    scanf("%s", newFlight->cellphone);
    fflush(stdin);

    newFlight->status = '0';     // 0 = Programado, 1 = Realizado
    newFlight->passenger = NULL; // Lista de pasajeros inicial vacía
    newFlight->next = NULL;

    // Añadir el nuevo vuelo a la lista de vuelos
    if (*listFlights == NULL)
    {
        *listFlights = newFlight;
    }
    else
    {
        Flight *current = *listFlights;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newFlight;
    }

    printf("Vuelo agregado correctamente.\n");
}

// Función para agregar un nuevo pasajero a un vuelo
void newPassenger(Flight *listFlights)
{
    char idFlight[7];
    printf("Ingrese el ID del vuelo al que se va a añadir el pasajero: ");
    scanf("%s", idFlight);
    fflush(stdin);

    // Buscar el vuelo correspondiente
    Flight *currentFlight = listFlights;
    while (currentFlight != NULL && strcmp(currentFlight->idFlight, idFlight) != 0)
    {
        currentFlight = currentFlight->next;
    }

    if (currentFlight == NULL)
    {
        printf("Vuelo no encontrado.\n");
        return;
    }

    // Crear nuevo pasajero
    Passenger *newPassenger = (Passenger *)malloc(sizeof(Passenger));
    printf("Ingrese el número de cédula del pasajero: ");
    scanf("%s", newPassenger->cc);
    fflush(stdin);

    printf("Ingrese el nombre del pasajero: ");
    fgets(newPassenger->name, sizeof(newPassenger->name), stdin);
    newPassenger->name[strcspn(newPassenger->name, "\n")] = '\0'; // Remove newline character
    fflush(stdin);


    printf("Ingrese el número de celular del pasajero: ");
    scanf("%s", newPassenger->cellphone);
    fflush(stdin);

    newPassenger->status = '1'; // No está a bordo por defecto
    strncpy(newPassenger->idFlight, currentFlight->idFlight, sizeof(newPassenger->idFlight) - 1);
    newPassenger->idFlight[sizeof(newPassenger->idFlight) - 1] = '\0'; // Ensure null-termination
    newPassenger->next = NULL;

    // Añadir el pasajero a la lista de pasajeros del vuelo
    if (currentFlight->passenger == NULL)
    {
        currentFlight->passenger = newPassenger;
    }
    else
    {
        Passenger *currentPassenger = currentFlight->passenger;
        while (currentPassenger->next != NULL)
        {
            currentPassenger = currentPassenger->next;
        }
        currentPassenger->next = newPassenger;
    }

    printf("Pasajero agregado correctamente al vuelo %s.\n", newPassenger->idFlight);
}

// Función para imprimir los pasajeros de un vuelo
void printPassengersByFlight(Flight *flightList, char idFlight[7])
{
    while (flightList != NULL)
    {
        if (strcmp(flightList->idFlight, idFlight) == 0)
            break;

        flightList = flightList->next;
    }

    if (flightList == NULL)
    {
        printf("No hay vuelos con esta id.\n");
        return;
    }

    if (flightList->passenger == NULL)
    {
        printf("No hay pasajeros en este vuelo.\n");
        return;
    }

    Passenger *currentPassenger = flightList->passenger;
    while (currentPassenger != NULL)
    {
        printf("CC: %s | Nombre: %s | cellphone: %s | Estado: %s\n",
               currentPassenger->cc,
               currentPassenger->name,
               currentPassenger->cellphone,
               currentPassenger->status == '1' ? "Reserva" : "A bordo");
        currentPassenger = currentPassenger->next;
    }
}

// Función para imprimir vuelos programados
void printScheduledFlight(Flight *flightList)
{
    while (flightList != NULL)
    {
        if (flightList->status == '0') // 0: Programado
        {
            printf("Nro Vuelo: %s | Origen: %s | Destino: %s | Matricula: %s | Piloto: %s | cellphone: %s | Estado: %s\n",
                   flightList->idFlight, flightList->from, flightList->to, flightList->registration, flightList->pilot, flightList->cellphone, flightList->status == '0' ? "Programado" : "Realizado");
        }
        flightList = flightList->next;
    }
}

// Función para imprimir vuelos realizados
void printCompletedFlight(Flight *flightList)
{
    while (flightList != NULL)
    {
        if (flightList->status == '1') // 1: Realizado
        {
            printf("Nro Vuelo: %s | Origen: %s | Destino: %s | Matricula: %s | Piloto: %s | cellphone: %s | Estado: %s\n",
                   flightList->idFlight, flightList->from, flightList->to, flightList->registration, flightList->pilot, flightList->cellphone, flightList->status == '0' ? "Programado" : "Realizado");
        }
        flightList = flightList->next;
    }
}

// Función para imprimir vuelos por cédula
void printPassengerInFlightByDocument(Flight *vuelos, const char *cc)
{
    while (vuelos != NULL)
    {
        Passenger *currentPassenger = vuelos->passenger;
        while (currentPassenger != NULL)
        {
            if (strcmp(currentPassenger->cc, cc) == 0)
            {
                printf("Nro Vuelo: %s, Origen: %s, Destino: %s\n",
                       vuelos->idFlight,
                       vuelos->from,
                       vuelos->to);
            }
            currentPassenger = currentPassenger->next;
        }
        vuelos = vuelos->next;
    }
}

// Función para modificar el status de un vuelo a realizado
void approveStatusFlight(Flight *vuelo)
{
    if (vuelo != NULL)
    {
        vuelo->status = '1';
    }
}

// Función para registrar un pasajero a bordo
void approveStatusPassenger(Passenger *passenger, const char *cc)
{
    Passenger *currentPassenger = passenger;
    while (currentPassenger != NULL)
    {
        if (strcmp(currentPassenger->cc, cc) == 0)
        {
            currentPassenger->status = '2';
            printf("Passenger %s ha sido registrado a bordo.\n", currentPassenger->name);
            return;
        }
        currentPassenger = currentPassenger->next;
    }
    printf("Passenger no encontrado.\n");
}

// Función para limpiar pantalla
void clearScreen()
{
    // system("cls||clear");
}

void menu()
{
    Flight *listFlights = getFlights("Vuelos.txt");
    int option;

    do
    {
        printf("\n------ Menú ------\n");
        printf("1. Mostrar vuelos programados\n");
        printf("2. Mostrar vuelos realizados\n");
        printf("3. Mostrar pasajeros por vuelo\n");
        printf("4. Mostrar vuelos por cédula de pasajero\n");
        printf("5. Registrar vuelo como realizado\n");
        printf("6. Registrar pasajero a bordo\n");
        printf("7. Agregar nuevo vuelo\n");
        printf("8. Agregar nuevo pasajero\n");
        printf("0. Salir\n");
        printf("--------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            clearScreen();
            printScheduledFlight(listFlights);
            break;
        case 2:
            clearScreen();
            printCompletedFlight(listFlights);
            break;
        case 3:
        {
            clearScreen();
            char idFlight[7];
            printf("Ingrese el ID del vuelo: ");
            scanf("%s", idFlight);
            fflush(stdin);

            printPassengersByFlight(listFlights, idFlight);
            break;
        }
        case 4:
        {
            clearScreen();
            char cc[11];
            printf("Ingrese el número de cédula: ");
            scanf("%s", cc);
            fflush(stdin);

            printPassengerInFlightByDocument(listFlights, cc);
            break;
        }
        case 5:
        {
            clearScreen();
            char idFlight[7];
            printf("Ingrese el ID del vuelo a registrar como realizado: ");
            scanf("%s", idFlight);
            fflush(stdin);

            Flight *currentFlight = listFlights;
            while (currentFlight != NULL)
            {
                if (strcmp(currentFlight->idFlight, idFlight) == 0)
                {
                    approveStatusFlight(currentFlight);
                    printf("Vuelo %s registrado como realizado.\n", idFlight);
                    break;
                }
                currentFlight = currentFlight->next;
            }
            if (currentFlight == NULL)
                printf("Vuelo no encontrado.\n");
            break;
        }
        case 6:
        {
            clearScreen();
            char cc[11];
            printf("Ingrese el número de cédula del pasajero: ");
            scanf("%s", cc);
            fflush(stdin);

            Flight *currentFlight = listFlights;
            int found = 0;
            while (currentFlight != NULL)
            {
                Passenger *currentPassenger = currentFlight->passenger;
                while (currentPassenger != NULL)
                {
                    if (strcmp(currentPassenger->cc, cc) == 0)
                    {
                        approveStatusPassenger(currentPassenger, cc);
                        found = 1;
                        break;
                    }
                    currentPassenger = currentPassenger->next;
                }
                if (found)
                    break;
                currentFlight = currentFlight->next;
            }
            if (!found)
                printf("Pasajero no encontrado.\n");
            break;
        }
        case 7:
            clearScreen();
            newFlight(&listFlights);
            break;
        case 8:
            clearScreen();
            newPassenger(listFlights);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida, intente nuevamente.\n");
        }

        fflush(stdin);

        printf("Presione Enter para continuar...");
        getchar();
    } while (option != 0);

    FILE *file = fopen("PASAJEROS.txt", "w"); // Limpiamos el archivo primero
    if (file != NULL)
        fclose(file);
        
    saveFlights(listFlights);
}

void saveFlights(Flight *head)
{
    FILE *file = fopen("Vuelos.txt", "w");
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", "Vuelos.txt");
        return;
    }

    Flight *currentFlight = head;
    while (currentFlight != NULL)
    {
        fprintf(file, "%-6s%-12s%-12s%-6s%-20s%-10s%c\n",
                currentFlight->idFlight,
                currentFlight->from,
                currentFlight->to,
                currentFlight->registration,
                currentFlight->pilot,
                currentFlight->cellphone,
                currentFlight->status);

        savePassengers(currentFlight->passenger); // Guardar los pasajeros del vuelo

        currentFlight = currentFlight->next; // Avanzar al siguiente vuelo
    }

    fclose(file);
    printf("Información de vuelos guardada en %s\n", "Vuelos.txt");
}

void savePassengers(Passenger *head)
{
    // Abre el archivo en modo de "adjuntar" para no sobrescribir el contenido anterior
    FILE *file = fopen("PASAJEROS.txt", "a");
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", "PASAJEROS.txt");
        return;
    }

    Passenger *currentPassenger = head;
    while (currentPassenger != NULL)
    {
        fprintf(file, "%-6s%-10s%-20s%-10s%c\n",
                currentPassenger->idFlight,
                currentPassenger->cc,
                currentPassenger->name,
                currentPassenger->cellphone,
                currentPassenger->status
                );

        currentPassenger = currentPassenger->next; // Avanzar al siguiente pasajero
    }

    fclose(file);
    printf("Información de pasajeros guardada en %s\n", "PASAJEROS.txt");
}