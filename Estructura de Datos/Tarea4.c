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

int main()
{
    node *list = NULL;
    node *list2 = NULL;

    push(&list, 3);
    push(&list, 10);
    push(&list, 20);
    push(&list, 40);
    push(&list, 50);

    // push(&list2, 3);
    // push(&list2, 10);
    // push(&list2, 20);
    // push(&list2, 40);
    // push(&list2, 50);

    impList(list);
    // impList(list2);

    // if (compareLists(list, list2)){
    //     printf("Las listas son iguales\n");
    // } else {
    //     printf("Las listas NO son iguales\n");
    // }

    // reverb(&list);

    // removeValue(&list, 20);

    addValue(&list, 100, 2);

    impList(list);

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
 * @brief Valida si la lista esta ordenada
 * 
 * @param head Puntero al primer nodo de la lista.
 * @return 0 = falso, 1 = verdadero
 */
int isSortedAscending(node *head){
    int previousValue = head->value;
    head = head->next;

    while (head != NULL)
    {
        if (head->value > previousValue){
            return 0;
        }

        head = head->next;
    }

    return 1; 
}

/**
 * @brief Compara que 2 listas sean iguales
 * 
 * @param list1 Puntero al primer nodo de la lista 1.
 * @param list2 Puntero al primer nodo de la lista 2.
 * @return 0 = falso, 1 = verdadero
 */
int compareLists(node *list1, node *list2){
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->value != list2->value){
            return 0;
        }

        list1 = list1->next;
        list2 = list2->next;

    }
    return 1;
}

/**
 * @brief Saca de la pila el objeto X (si existe) y deja la pila con los objetos restantes en el mismo orden.
 * 
 * @param head Puntero a un puntero al primer nodo de la lista.
 * @param value Valor a eliminar de la pila.
 */
void removeValue(node **head, int value)
{
    if (*head == NULL)
    {
        return;
    }

    node *tempList = NULL;
    int poppedValue = 0;

    while (*head != NULL)
    {
        poppedValue = pop(head);
        if (poppedValue != value)
        {
            push(&tempList, poppedValue);
        }
    }

    reverb(&tempList);

    *head = tempList;
}

void addValue(node **head, int value, int pos) {
    if (*head == NULL || pos <= 0) {
        push(head, value);
        return;
    }

    node *auxList = NULL;
    int count = 1;
    int poppedValue = 0;

    while (*head != NULL) {
        poppedValue = pop(head);
        if (count == pos) {
            push(&auxList, value);
        }
        push(&auxList, poppedValue);
        count++;
    }

    *head = auxList;
}

void splitList(node **head, int value, node **list1, node **list2) {
    if (*head == NULL) {
        return;
    }

    int poppedValue = 0;

    while (*head != NULL) {
        poppedValue = pop(head);
        if (poppedValue > value) {
            push(list1, poppedValue);
        } else {
            push(list2, poppedValue);
        }
    }
}