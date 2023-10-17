#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *sig;
} node;

// prototipos de funciones
void insertInfo(node **head, node **tail, int x);
void impList(node *head);
void freeList(node **head, node **tail);
void deleteElement(node **head, node **tail, int position);
int extractHeadList(node **head, node **tail);
int voidList(node *head);

int main()
{

    // variables globales que apuntan al primer nodo de la cola, y al ultimo
    node *head = NULL;
    node *tail = NULL;

    int opc, val;
    do
    {
        system("cls");
        printf("\n============================================\n");
        printf("1. Entra nodo a la cola\n");
        printf("2. Sale nodo de la cola\n");
        printf("3. Mostrar Cola\n");
        printf("4. Vaciar Cola\n");
        printf("5. Ver si Cola esta vacia\n");
        printf("6. Eliminar elemento por posición\n");
        printf("7. Terminar\n");
        printf("\nEscoja opcion: \n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Indique valor\n");
            scanf("%d", &val);
            insertInfo(&head, &tail, val);
            break;
        case 2:
            printf("Eliminamos nodo de la Cola (siempre el primero): %i\n", extractHeadList(&head, &tail));
            break;
        case 3:
            impList(head);
            break;
        case 4:
            freeList(&head, &tail);
            break;
        case 5:
            if (voidList(head) == 0)
                printf("La Cola tiene informacion\n");
            else
                printf("La Cola esta vacia\n");
            break;
        case 6:
            printf("Indique valor\n");
            scanf("%d", &val);
            deleteElement(&head, &tail, val);
            break;
        case 7:
            printf("Chao\n");
            break;
        default:
            printf("Error de opcion\n");
            break;
        }
        printf("\nPresione una tecla para continuar\n");
        getchar();
        getchar();
    } while (opc != 7);
    return 0;
}

void insertInfo(node **head, node **tail, int x)
{
    node *nuevo;
    nuevo = malloc(sizeof(node));
    nuevo->info = x;
    nuevo->sig = NULL;
    if (voidList(*head))
    {
        *head = nuevo;
        *tail = nuevo;
    }
    else
    {
        (*tail)->sig = nuevo;
        *tail = nuevo;
    }
}

void impList(node *head)
{
    node *reco = head;
    if (head == NULL)
        printf("La cola esta vacia.\n");
    else
    {
        printf("Listado de todos los elementos de la cola.\n");
        while (reco != NULL)
        {
            printf("%i - ", reco->info);
            reco = reco->sig;
        }
        printf("\n");
    }
}

int extractHeadList(node **head, node **tail)
{
    if (!voidList(*head))
    {
        int informacion = (*head)->info;
        node *bor = *head;
        if (head == tail)
        {
            *head = NULL;
            *tail = NULL;
        }
        else
        {
            *head = (*head)->sig;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void freeList(node **head, node **tail)
{
    node *reco = *head;
    node *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
    *head = NULL;
    *tail = NULL;
}

int voidList(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void deleteElement(node **head, node **tail, int position)
{
    node *tempListHead = NULL;
    node *tempListTail = NULL;

    int i = 0;

    while (*head != NULL)
    {
        i++;
        if (i != position)
            insertInfo(&tempListHead, &tempListTail, extractHeadList(head, tail));
        else
            extractHeadList(head, tail);
    }

    while (tempListHead != NULL)
    {
        insertInfo(head, tail, extractHeadList(&tempListHead, &tempListTail));
    }

    if (i != 0)
        printf("La posicion ingresada no existe.\n");

    freeList(head, tail);
}

// Función para agregar un elemento a la lista

// void addElement(node **head, int position, int data)
// {
//     node *tempList = NULL;

//     int i = 0;

//     while (head != NULL)
//     {
//         i++;
//         if (i != position)
//             insertInfo(&tempList, extractHeadList(head));
//         else
//             extractHeadList(head);
//     }

//     while (tempList != NULL)
//     {
//         insertInfo(head, extractHeadList(&tempList));
//     }

//     if (i != 0)
//         printf("La posicion ingresada no existe.\n");

//     freeList(&tempList);
// }
