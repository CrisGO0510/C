#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

// prototipos de funciones
void insertValue(node **, node **, int);
int extractHeadList(node **, node **);
void freeList(node **, node **);
void impList(node *);
int voidList(node *);
int insertInPos(node **, int, int);

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertValue(&head, &tail, 1);
    insertValue(&head, &tail, 2);
    insertValue(&head, &tail, 3);
    insertValue(&head, &tail, 4);

    impList(head);

    insertInPos(&head, 5, 0);

    impList(head);

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

// punto 3
int insertInPos(node **list, int value, int pos)
{
    node *head = *list;

    node *aux = (node *)malloc(sizeof(node *));
    node *before = NULL;
    aux->value = value;

    while (head != NULL && pos > 0)
    {
        before = head;
        head = head->next;
        pos--;
    }

    if (head == NULL) return -1;

    if (before == NULL)
    {
        aux->next = head;
        *list = aux;
    }
    else
    {
        aux->next = head;
        before->next = aux;
    }

    return 1;
}