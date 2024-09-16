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
int findValue(node *, int);
int isSortedAscending(node *);
void removeValue(node **, int);
void addValue(node **, int, int);
void splitList(node **, int, node **, node **);
int compareLists(node *, node *);
void freeList(node **);
void deleteDoodsValue(node **);
int isPalindrome(node *);
int sum(node *);

int main()
{

    node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 4);

    impList(head);

    // deleteDoodsValue(&head);
    // printf("La lista %s.\n", isPalindrome(head) ? "es palindroma" : "no es palindroma");
    printf("La suma de los valores de la lista es: %i\n", sum(head));

    // impList(head);

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
 * @brief Imprime los valores de todos los nodos en la lista.
 *
 * @param head Puntero al primer nodo de la lista.
 */
void impList(node *head)
{
    if (head == NULL)
    {
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

// Punto 1
void deleteDoodsValue(node **stack)
{
    if (*stack == NULL)
        return;
    int value = 0;

    node *aux = NULL;

    while (*stack != NULL)
    {
        value = pop(stack);
        if (value % 2 == 0)
        {
            push(&aux, value);
        }
    }

    impList(aux);

    *stack = aux;
}

// Punto 2
int isPalindrome(node *stack)
{
    node *aux = NULL;
    node *temp = stack;

    int value = 0;

    while (temp != NULL)
    {
        value = pop(&temp);
        push(&aux, value);
    }

    while (stack != NULL)
    {
        if (stack->value != aux->value)
            return 0;
        stack = stack->next;
        aux = aux->next;
    }

    return 1;
}

// Punto 4
int sum(node *stack)
{
    int value= 0;    // printf("La lista %s.\n", isPalindrome(head) ? "es palindroma" : "no es palindroma");

    while (stack != NULL)
    {
        value = value + pop(&stack);
    }

    return value;
}