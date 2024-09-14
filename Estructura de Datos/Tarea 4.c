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
void displayMenu();

int main()
{
    node *list = NULL;
    node *list1 = NULL;
    node *list2 = NULL;
    int option, value, pos;
    
    do
    {
        displayMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Ingrese el valor a agregar: ");
            scanf("%d", &value);
            push(&list, value);
            break;
        case 2:
            value = pop(&list);
            if (value != -1)
            {
                printf("Valor eliminado: %d\n", value);
            }
            break;
        case 3:
            impList(list);
            break;
        case 4:
            reverb(&list);
            printf("La lista ha sido invertida.\n");
            break;
        case 5:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &value);
            if (findValue(list, value))
            {
                printf("Valor %d encontrado en la lista.\n", value);
            }
            else
            {
                printf("Valor %d no encontrado.\n", value);
            }
            break;
        case 6:
            if (isSortedAscending(list))
            {
                printf("La lista está ordenada de manera ascendente.\n");
            }
            else
            {
                printf("La lista NO está ordenada de manera ascendente.\n");
            }
            break;
        case 7:
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &value);
            removeValue(&list, value);
            printf("Valor %d eliminado de la lista.\n", value);
            break;
        case 8:
            printf("Ingrese el valor a agregar: ");
            scanf("%d", &value);
            printf("Ingrese la posición en la que desea agregar el valor: ");
            scanf("%d", &pos);
            addValue(&list, value, pos);
            break;
        case 9:
            printf("Ingrese el valor de referencia para dividir la lista: ");
            scanf("%d", &value);
            splitList(&list, value, &list1, &list2);
            printf("Lista 1 (mayores que %d):\n", value);
            impList(list1);
            printf("Lista 2 (menores o iguales a %d):\n", value);
            impList(list2);
            break;
        case 10:
            printf("Comparando dos listas...\n");
            if (compareLists(list, list1))
            {
                printf("Las listas son iguales.\n");
            }
            else
            {
                printf("Las listas NO son iguales.\n");
            }
            break;
        case 11:
            printf("Saliendo del programa...\n");
            freeList(&list);
            freeList(&list1);
            freeList(&list2);
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (option != 11);

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

/**
 * @brief Valida si el elemento se encuentra en la lista
 *
 * @param head Puntero al primer nodo de la lista.
 * @param value elemento que vamos a buscar
 * @return 0 = falso, 1 = verdadero
 */
int findValue(node *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
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
int isSortedAscending(node *head)
{
    int previousValue = head->value;
    head = head->next;

    while (head != NULL)
    {
        if (head->value > previousValue)
        {
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
int compareLists(node *list1, node *list2)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->value != list2->value)
        {
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
    int tempValue = 0;

    while (*head != NULL)
    {
        tempValue = pop(head);
        if (tempValue != value)
        {
            push(&tempList, tempValue);
        }
    }

    reverb(&tempList);

    *head = tempList;
}

/**
 * @brief Inserta un valor en una posición específica de la lista enlazada. Si la posición es inválida o la lista está vacía, el valor se inserta al inicio.
 *
 * La función recorre la lista, moviendo temporalmente los elementos a una lista auxiliar, y agrega el valor en la posición indicada.
 * Luego, la lista original se reconstruye con el nuevo valor insertado en la posición correcta.
 *
 * @param head Puntero a un puntero que apunta al primer nodo de la lista enlazada.
 * @param value Valor que se insertará en la posición indicada.
 * @param pos Posición en la que se insertará el valor. Si la posición es menor o igual a 0, el valor se insertará al inicio de la lista.
 */
void addValue(node **head, int value, int pos)
{
    if (*head == NULL || pos <= 0)
    {
        push(head, value);
        return;
    }

    node *auxList = NULL;
    int count = 1;
    int tempValue = 0;

    while (*head != NULL)
    {
        tempValue = pop(head);
        if (count == pos)
        {
            push(&auxList, tempValue);
        }
        push(&auxList, tempValue);
        count++;
    }

    *head = auxList;
}

/**
 * @brief Divide una lista enlazada en dos listas basadas en un valor de referencia.
 *
 * La función recorre la lista original, separando los elementos en dos nuevas listas:
 * - Los valores mayores que el valor de referencia se insertan en `list1`.
 * - Los valores menores o iguales se insertan en `list2`.
 *
 * Al final, la lista original queda vacía, y sus elementos se distribuyen entre las dos listas nuevas.
 *
 * @param head Puntero a un puntero que apunta al primer nodo de la lista original.
 * @param value Valor de referencia utilizado para dividir la lista.
 * @param list1 Puntero a un puntero donde se insertarán los valores mayores que el valor de referencia.
 * @param list2 Puntero a un puntero donde se insertarán los valores menores o iguales que el valor de referencia.
 */
void splitList(node **head, int value, node **list1, node **list2)
{
    if (*head == NULL)
    {
        return;
    }

    int tempValue = 0;

    while (*head != NULL)
    {
        tempValue = pop(head);
        if (tempValue > value)
        {
            push(list1, tempValue);
        }
        else
        {
            push(list2, tempValue);
        }
    }
}

void displayMenu()
{
    printf("\n--- MENU ---\n");
    printf("1. Agregar valor a la lista (push)\n");
    printf("2. Eliminar valor de la lista (pop)\n");
    printf("3. Imprimir lista (impList)\n");
    printf("4. Invertir lista (reverb)\n");
    printf("5. Buscar valor en la lista (findValue)\n");
    printf("6. Verificar si la lista está ordenada (isSortedAscending)\n");
    printf("7. Eliminar valor específico (removeValue)\n");
    printf("8. Agregar valor en una posición específica (addValue)\n");
    printf("9. Dividir lista en dos (splitList)\n");
    printf("10. Comparar dos listas (compareLists)\n");
    printf("11. Salir\n");
}
