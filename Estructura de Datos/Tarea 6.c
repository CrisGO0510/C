#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void impList(node *);
void insert2Head(node **, int);
void insert2Tail(node **, int);
int popHead(node **);
void freeList(node **);
void findValue(node *, int);
void deleteValue(node **, int);
void deleteDuplicate(node **, int);

int countValue(node *, int);
void reverseList(node **);
double getAverage(node *);
int findMax(node *);
int isSorted(node *);
void menu(node **);

int main()
{

    node *head = NULL;
    insert2Tail(&head, 4);
    insert2Head(&head, 1);
    insert2Head(&head, 2);
    insert2Head(&head, 3);

    insert2Tail(&head, 5);
    insert2Tail(&head, 5);
    insert2Tail(&head, 4);

    impList(head);

    deleteDuplicate(&head, 4);

    impList(head);

    // menu(&head);

    return 0;
}

/**
 * @brief Imprime los valores de todos los nodos en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 */
void impList(node *head)
{
    if (head == NULL)
    {
        printf("La lista esta vacia.\n");
        return;
    }

    printf("Impresion de la lista...\n");
    while (head != NULL)
    {
        printf("%i ", head->value);
        head = head->next;
    }

    printf("\n");
}

/**
 * @brief Inserta un nuevo nodo al inicio de la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value Valor a insertar.
 */
void insert2Head(node **head, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

/**
 * @brief Inserta un nuevo nodo al final de la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value Valor a insertar.
 */
void insert2Tail(node **head, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    node *before = *head;
    while (before->next != NULL)
    {
        before = before->next;
    }

    before->next = new_node;
}

/**
 * @brief Elimina el primer nodo de la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @return int Valor del nodo eliminado.
 */
int popHead(node **head)
{
    if (*head == NULL)
    {
        return -1;
    }

    int value = (*head)->value;
    node *aux = *head;
    *head = (*head)->next;
    free(aux);

    return value;
}

/**
 * @brief Libera la memoria de todos los nodos en la lista.
 *
 * @param head Puntero a un puntero al primer nodo de la lista.
 */
void freeList(node **head)
{
    node *currentNode = *head;
    node *tempNode;

    while (currentNode != NULL)
    {
        tempNode = currentNode;
        currentNode = currentNode->next;
        free(tempNode);
    }

    *head = NULL;
}

/**
 * @brief Busca un valor en la lista e imprime su posición.
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value Valor a buscar.
 */
void findValue(node *head, int value)
{
    if (head == NULL)
    {
        printf("La lista esta vacia.\n");
        return;
    }

    int pos = 0;

    while (head != NULL)
    {
        if (head->value == value)
        {
            printf("El valor %i se encuentra en la lista en la posición %i.\n", value, pos);
            return;
        }

        head = head->next;
        pos++;
    }

    printf("El valor %i no se encuentra en la lista.\n", value);
}

/**
 * @brief Elimina un valor de la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value Valor a eliminar.
 */
void deleteValue(node **head, int value)
{
    if (*head == NULL)
        return;

    node *currentNode = *head;
    node *before;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            if (currentNode == *head)
            {
                *head = currentNode->next;
                free(currentNode);
                return;
            }

            before->next = currentNode->next;
            free(currentNode);
            return;
        }

        before = currentNode;
        currentNode = currentNode->next;
    }
}

void deleteDuplicate(node **head, int value)
{
    if (*head == NULL)
        return;

    node *currentNode = *head;
    node *before;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            if (currentNode == *head)
            {
                *head = currentNode->next;
                free(currentNode);
                currentNode = *head;
                continue;
            }

            before->next = currentNode->next;
            free(currentNode);
            currentNode = before->next;
            continue;
        }

        before = currentNode;
        currentNode = currentNode->next;
    }
}

/**
 * @brief Cuenta cuantas veces se repite un valor en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value Valor a contar.
 * @return int Cantidad de veces que se repite el valor.
 */
int countValue(node *head, int value)
{
    int count = 0;
    while (head != NULL)
    {
        if (head->value == value)
        {
            count++;
        }
        head = head->next;
    }
    return count;
}

/**
 * @brief Invierte el orden de los nodos en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 */
void reverseList(node **head)
{
    node *aux = NULL;

    while (*head != NULL)
    {
        insert2Head(&aux, popHead(head));
    }

    *head = aux;
}

/**
 * @brief Calcula el promedio de los valores en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @return double Promedio de los valores en la lista.
 */
double getAverage(node *head)
{
    if (head == NULL)
        return 0;

    float sum = 0;
    float count = 0;
    while (head != NULL)
    {
        sum += head->value;
        count++;
        head = head->next;
    }

    return sum / count;
}

/**
 * @brief Encuentra el valor maximo en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 * @return int Valor maximo en la lista.
 */
int findMax(node *head)
{
    if (head == NULL)
        return -1;

    int max = head->value;
    while (head != NULL)
    {
        if (head->value > max)
        {
            max = head->value;
        }
        head = head->next;
    }

    return max;
}

/**
 * @brief Verifica si la lista esta ordenada de forma ascendente.
 *
 * @param head Puntero al primer nodo de la lista.
 * @return int 1 si la lista esta ordenada, 0 en caso contrario.
 */
int isSorted(node *head)
{
    if (head == NULL)
        return 1;

    while (head->next != NULL)
    {
        if (head->value > head->next->value)
            return 0;

        head = head->next;
    }

    return 1;
}

void menu(node **list)
{
    int option;
    do
    {
        system("clear");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. EXtraer en el inicio\n");
        printf("4. Buscar valor\n");
        printf("5. Contar valor\n");
        printf("6. Invertir lista\n");
        printf("7. Promedio de valores\n");
        printf("8. Valor maximo\n");
        printf("9. Verificar si esta ordenada\n");
        printf("10. Imprimir lista\n");
        printf("11. Salir\n");
        printf("Opcion: ");
        scanf("%i", &option);

        switch (option)
        {
        case 1:
            int value;
            printf("Ingrese el valor a insertar: ");
            scanf("%i", &value);
            insert2Head(list, value);
            break;
        case 2:
            printf("Ingrese el valor a insertar: ");
            scanf("%i", &value);
            insert2Tail(list, value);
            break;
        case 3:
            printf("Se elimino el valor %i\n", popHead(list));
            break;
        case 4:
            printf("Ingrese el valor a buscar: ");
            scanf("%i", &value);
            findValue(*list, value);
            break;
        case 5:
            printf("Ingrese el valor a contar: ");
            scanf("%i", &value);
            printf("El valor %i se repite %i veces.\n", value, countValue(*list, value));
            break;
        case 6:
            reverseList(list);
            break;
        case 7:
            printf("El promedio de los valores en la lista es: %.2f\n", getAverage(*list));
            break;
        case 8:
            printf("El valor maximo en la lista es: %i\n", findMax(*list));
            break;
        case 9:
            printf("La lista %s.\n", isSorted(*list) ? "esta ordenada" : "no esta ordenada");
            break;
        case 10:
            impList(*list);
            break;
        case 11:
            freeList(list);
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }

        printf("Presione una tecla para continuar...\n");
        getchar();
        getchar();
    } while (option != 11);
}