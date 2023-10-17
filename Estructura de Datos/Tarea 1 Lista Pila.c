#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

void insertInfo(node **, int);
void impList(node *);
int extractHeadList(node **);
void freeList(node **);
int countElements(node *);
int voidList(node *);
void deleteElement(node **, int);
void addElement(node **, int, int);

int main()
{
    node *list = NULL;

    insertInfo(&list, 10);
    insertInfo(&list, 40);
    insertInfo(&list, 3);
    insertInfo(&list, 20);
    insertInfo(&list, 50);

    impList(list);
    // printf("Extraemos un nodo de la pila: %i\n", extractHeadList(&list));
    // impList(list);
    // printf("La cantidad de nodos de la pila es: %i\n", countElements(list));

    // while (voidList(list) == 0)
    // {
    //     printf("Extraemos un nodo de la pila: %i\n", extractHeadList(&list));
    // }

    // deleteElement(&list, 13);

    addElement(&list, 3, 100);

    impList(list);

    printf("Presione una tecla para finalizar...\n");
    getchar();
    freeList(&list);
    return 0;
}

void insertInfo(node **head, int info)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->info = info;

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

void impList(node *head)
{
    node *reco = head;

    if (head == NULL)
        printf("La pila esta vacia.\n");
    else
    {
        printf("Impresion de Lista tipo pila...\n");
        while (reco != NULL)
        {
            printf("%i ", reco->info);
            reco = reco->next;
        }
    }
    printf("\n");
}

int extractHeadList(node **head)
{
    if (*head == NULL)
    {
        printf("La pila esta vacia.\n");
        return -1;
    }
    else
    {
        int informacion = (*head)->info;
        node *tempList = *head;

        *head = (*head)->next;

        free(tempList);
        return informacion;
    }
}

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
        head = NULL;
    }
}

int countElements(node *head)
{
    node *reco = (node *)malloc(sizeof(node));
    reco = head;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->next;
    }
    return cant;
}

int voidList(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

/*
// Función para eliminar un elemento de la lista por posición

void deleteElement(node **head, int position)
{
    node *tempList = NULL;

    while (*head != NULL)
    {
        if ((*head)->info != position)
            insertInfo(&tempList, extractHeadList(head));
        else
            extractHeadList(head);
    }

    while (tempList != NULL)
    {
        insertInfo(head, extractHeadList(&tempList));
    }

    freeList(&tempList);
}*/

void deleteElement(node **head, int position)
{
    node *tempList = NULL;

    int i = 0;

    while (*head != NULL)
    {
        i++;
        if (i != position)
            insertInfo(&tempList, extractHeadList(head));
        else
            extractHeadList(head);
    }

    while (tempList != NULL)
    {
        insertInfo(head, extractHeadList(&tempList));
    }

    if (i != 0)
        printf("La posicion ingresada no existe.\n");

    freeList(&tempList);
}

// Función para agregar un elemento a la lista

void addElement(node **head, int position, int data)
{
    node *tempList = NULL;

    int i = 0;

    while (*head != NULL)
    {
        i++;
        if (i == position)
            insertInfo(&tempList, data);
        else
            insertInfo(&tempList, extractHeadList(head));
    }

    while (tempList != NULL)
    {
        insertInfo(head, extractHeadList(&tempList));
    }

    freeList(&tempList);
}