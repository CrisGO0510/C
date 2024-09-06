#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void push(node **, int);
int pop(node **);
void impList(node *);
void reverb(node **);
int countElements(node *);
void freeList(node **);
int findValue(node *, int);

int main()
{
    node *list = NULL;

    push(&list, 10);
    push(&list, 40);
    push(&list, 3);
    push(&list, 20);
    push(&list, 50);

    impList(list);

    int value = 4;
    if (findValue(list, value)){
        printf("El elemento %i se encuentra en la lista\n", value);
    } else {
        printf("El elemento %i NO se encuentra en la lista\n", value);

    }

    // reverb(&list);

    // impList(list);

    printf("Presione una tecla para finalizar...\n");
    getchar();
    freeList(&list);
    return 0;
}

/**
 * @brief Agrega un nuevo nodo al inicio de la lista.
 * 
 * @param head Puntero a un puntero al primer nodo de la lista.
 * @param value Valor a almacenar en el nuevo nodo.
 */
void push(node **head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;

    if (head == NULL)
    {
        head = &newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

/**
 * @brief Elimina el nodo al inicio de la lista y devuelve su valor.
 * 
 * @param head Puntero a un puntero al primer nodo de la lista.
 * @return Valor del nodo eliminado o -1 si la lista está vacía.
 */
int pop(node **head)
{
    if (*head == NULL)
    {
        printf("La pila esta vacia.\n");
        return -1;
    }
    else
    {
        int value = (*head)->value;
        node *tempList = *head;

        *head = (*head)->next;

        free(tempList);
        return value;
    }
}

/**
 * @brief Invierte el orden de los nodos en la lista.
 * 
 * @param head Puntero a un puntero al primer nodo de la lista.
 */
void reverb(node **head)
{
    if (*head == NULL)
    {
        return;
    }

    node *tempList = NULL;

    int value = 0;
    while (*head != NULL)
    {
        value = pop(head);
        push(&tempList, value);
    }

    *head = tempList; 
}

/**
 * @brief Imprime los valores de todos los nodos en la lista.
 * 
 * @param head Puntero al primer nodo de la lista.
 */
void impList(node *head)
{
    if (head == NULL){
        printf("La pila esta vacia.\n");
        return;
    }
    
    printf("Impresion de Lista tipo pila...\n");
    while (head != NULL)
    {
        printf("%i ", head->value);
        head = head->next;
    }

    printf("\n");
}

/**
 * @brief Libera la memoria de todos los nodos en la lista.
 * 
 * @param head Puntero a un puntero al primer nodo de la lista.
 */
void freeList(node **head)
{
    node *currencyList = *head;
    node *tempList;
    if (head == NULL)
        printf("La pila esta vacia.\n");
    else
    {
        while (currencyList != NULL)
        {
            tempList = currencyList;
            currencyList = currencyList->next;
            free(tempList);
        }
        *head = NULL;
    }
}

/**
 * @brief Valida si el elemento se encuentra en la lista
 * 
 * @param head Puntero al primer nodo de la lista.
 * @param value elemento que vamos a buscar
 * @return 0 = falso, 1 = verdadero
 */
int findValue(node *head, int value){
    while (head != NULL)
    {
        if (head->value == value){
            return 1;
        }

        head = head->next;
    }

    return 0;
}


/**
 * @brief Cuenta el número de nodos en la lista.
 * 
 * @param head Puntero al primer nodo de la lista.
 * @return Número de nodos en la lista.
 */
int countElements(node *head)
{
    node *tempList = head;
    int cant = 0;
    while (tempList != NULL)
    {
        cant++;
        tempList = tempList->next;
    }
    return cant;
}