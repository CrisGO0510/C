#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

// prototipos de funciones
void insertValue(node **, node **, int);
void freeList(node **, node **);
void impList(node *);
int extractHeadList(node **, node **);
int voidList(node *);
void reverseQueue(node **, node **);
int searchValue(node *, int);
int isSorted(node *);
int compareLists(node *, node *);
void addValue(node **, node **, int, int);
void splitQueue(node **, node **, node **, int);

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int option, value, position, searchVal;

    do
    {
        printf("\n--- Menú de Operaciones con la Cola ---\n");
        printf("1. Insertar un valor en la cola\n");
        printf("2. Imprimir la cola\n");
        printf("3. Extraer el primer elemento de la cola\n");
        printf("4. Buscar un valor en la cola\n");
        printf("5. Verificar si la cola está ordenada\n");
        printf("6. Invertir la cola\n");
        printf("7. Comparar con otra lista\n");
        printf("8. Añadir un valor en una posición específica\n");
        printf("9. Dividir la cola en dos\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Ingrese un valor para insertar en la cola: ");
            scanf("%d", &value);
            insertValue(&head, &tail, value);
            break;
        case 2:
            impList(head);
            break;
        case 3:
            value = extractHeadList(&head, &tail);
            if (value == -1)
                printf("La cola está vacía.\n");
            else
                printf("Valor extraído: %d\n", value);
            break;
        case 4:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &searchVal);
            if (searchValue(head, searchVal))
                printf("El valor %d está presente en la cola.\n", searchVal);
            else
                printf("El valor %d no se encontró en la cola.\n", searchVal);
            break;
        case 5:
            if (isSorted(head))
                printf("La cola está ordenada.\n");
            else
                printf("La cola no está ordenada.\n");
            break;
        case 6:
            reverseQueue(&head, &tail);
            printf("La cola ha sido invertida.\n");
            break;
        case 7:
        {
            node *head2 = NULL, *tail2 = NULL;
            printf("Inserte elementos para la segunda lista, ingrese -1 para terminar: ");
            while (1)
            {
                scanf("%d", &value);
                if (value == -1)
                    break;
                insertValue(&head2, &tail2, value);
            }
            if (compareLists(head, head2))
                printf("Las colas son iguales.\n");
            else
                printf("Las colas no son iguales.\n");
            freeList(&head2, &tail2);
        }
        break;
        case 8:
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &value);
            printf("Ingrese la posición: ");
            scanf("%d", &position);
            addValue(&head, &tail, value, position);
            printf("Valor añadido en la posición %d.\n", position);
            break;
        case 9:
        {
            node *head2 = NULL, *head3 = NULL;
            printf("Ingrese el valor de referencia para dividir la cola: ");
            scanf("%d", &value);
            splitQueue(&head, &head2, &head3, value);
            printf("Cola dividida en dos:\n");
            printf("Cola 1:\n");
            impList(head2);
            printf("Cola 2:\n");
            impList(head3);
            freeList(&head2, &head3);
        }
        break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (option != 0);

    freeList(&head, &tail);
    return 0;
}

/**
 * @brief Inserta un nuevo valor al final de la cola.
 *
 * @param head Puntero a un puntero al primer nodo de la cola.
 * @param tail Puntero a un puntero al último nodo de la cola.
 * @param x Valor a insertar en la cola.
 */
void insertValue(node **head, node **tail, int x)
{
    node *new = (node *)malloc(sizeof(node *));
    new->value = x;
    new->next = NULL;

    if (voidList(*head))
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
}

/**
 * @brief Imprime los valores de la cola.
 *
 * @param head Puntero al primer nodo de la cola.
 */
void impList(node *head)
{
    if (head == NULL)
    {
        printf("La cola esta vacia.\n");
        return;
    }

    while (head != NULL)
    {
        printf("%i ", head->value);
        head = head->next;
    }

    printf("\n");
}

/**
 * @brief Extrae y devuelve el valor del primer nodo de la cola.
 *
 * @param head Puntero a un puntero al primer nodo de la cola.
 * @param tail Puntero a un puntero al último nodo de la cola.
 * @return int El valor almacenado en el nodo extraído. Retorna -1 si la cola está vacía.
 */
int extractHeadList(node **head, node **tail)
{
    if (!voidList(*head))
    {
        int value = (*head)->value;
        node *bor = *head;
        if (head == tail)
        {
            *head = NULL;
            *tail = NULL;
        }
        else
        {
            *head = (*head)->next;
        }
        free(bor);
        return value;
    }
    else
        return -1;
}

/**
 * @brief Verifica si la cola está vacía.
 *
 * @param head Puntero al primer nodo de la cola.
 * @return int 1 si la cola está vacía, 0 en caso contrario.
 */
int voidList(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

/**
 * @brief Invierte el orden de los elementos en la cola.
 *
 * @param head Puntero a un puntero al primer nodo de la cola.
 * @param tail Puntero a un puntero al último nodo de la cola.
 */
void reverseQueue(node **head, node **tail)
{
    if (voidList(*head))
        return;

    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    *tail = *head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * @brief Busca un valor en la cola.
 *
 * @param head Puntero al primer nodo de la cola.
 * @param x Valor a buscar.
 * @return int 1 si el valor está presente en la cola, 0 en caso contrario.
 */
int searchValue(node *head, int x)
{
    while (head != NULL)
    {
        if (head->value == x)
            return 1;

        head = head->next;
    }
    return 0;
}

/**
 * @brief Verifica si la cola está ordenada de forma ascendente.
 *
 * @param head Puntero al primer nodo de la cola.
 * @return int 1 si la cola está ordenada, 0 en caso contrario.
 */
int isSorted(node *head)
{
    if (head == NULL || head->next == NULL)
        return 1;

    while (head->next != NULL)
    {
        if (head->value > head->next->value)
            return 0;
        head = head->next;
    }
    return 1;
}

/**
 * @brief Compara dos colas para verificar si son iguales.
 *
 * @param head1 Puntero al primer nodo de la primera cola.
 * @param head2 Puntero al primer nodo de la segunda cola.
 * @return int 1 si las dos colas son iguales, 0 en caso contrario.
 */
int compareLists(node *head1, node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->value != head2->value)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == NULL && head2 == NULL);
}

/**
 * @brief Inserta un valor en una posición específica dentro de la cola.
 *
 * @param head Puntero a un puntero al primer nodo de la cola.
 * @param tail Puntero a un puntero al último nodo de la cola.
 * @param x Valor a insertar.
 * @param pos Posición en la que se insertará el valor.
 */
void addValue(node **head, node **tail, int x, int pos)
{
    node *tempHead = NULL;
    node *tempTail = NULL;
    int currentPos = 0;

    while (!voidList(*head) && currentPos < pos)
    {
        insertValue(&tempHead, &tempTail, extractHeadList(head, tail));
        currentPos++;
    }

    insertValue(&tempHead, &tempTail, x);

    while (!voidList(*head))
    {
        insertValue(&tempHead, &tempTail, extractHeadList(head, tail));
    }

    *head = tempHead;
    *tail = tempTail;
}

/**
 * @brief Divide la cola en dos nuevas colas basadas en un valor de referencia.
 *
 * @param head1 Puntero a un puntero al primer nodo de la cola original.
 * @param head2 Puntero a un puntero al primer nodo de la nueva cola con valores mayores.
 * @param head3 Puntero a un puntero al primer nodo de la nueva cola con valores menores o iguales.
 * @param value Valor de referencia para la división.
 */
void splitQueue(node **head1, node **head2, node **head3, int value)
{
    while (!voidList(*head1))
    {
        int tempValue = extractHeadList(head1, head1);
        if (tempValue > value)
        {
            insertValue(head2, head2, tempValue);
        }
        else
        {
            insertValue(head3, head3, tempValue);
        }
    }
}

/**
 * @brief Libera la memoria de la cola, eliminando todos los nodos.
 *
 * @param head Puntero a un puntero al primer nodo de la cola.
 * @param tail Puntero a un puntero al último nodo de la cola.
 */
void freeList(node **head, node **tail)
{
    node *current = *head;
    node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
    *tail = NULL;
}