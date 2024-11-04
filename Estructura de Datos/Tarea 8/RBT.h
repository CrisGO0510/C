#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

// Estructura del nodo Red-Black
typedef struct RBT
{
    int data;
    int color; // RED = 1, BLACK = 0
    struct RBT *right;
    struct RBT *left;
    struct RBT *parent;
} RBT;

// Función para visualizar el árbol
void printRBT(RBT *tree, int n)
{
    if (tree == NULL)
        return;
    printRBT(tree->right, n + 1);

    for (int i = 0; i < n; i++)
        printf("   ");
    
    printf("%s%d\033[0m\n", (tree->color == RED) ? "\033[31m" : "\033[0m", tree->data);

    printRBT(tree->left, n + 1);
}

// Rotación a la izquierda
void rotateLeft(RBT **root, RBT *x)
{
    RBT *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Rotación a la derecha
void rotateRight(RBT **root, RBT *y)
{
    RBT *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Corrige las violaciones de la propiedad rojo-negro después de la inserción
void fixInsert(RBT **root, RBT *z)
{
    while (z->parent && z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            RBT *y = z->parent->parent->right;

            if (y && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        }
        else
        {
            RBT *y = z->parent->parent->left;

            if (y && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Inserta un nodo en el árbol rojo-negro
void insertRBT(RBT **root, int data)
{
    RBT *z = (RBT *)malloc(sizeof(RBT));
    z->data = data;
    z->color = RED;
    z->left = z->right = z->parent = NULL;

    RBT *y = NULL;
    RBT *x = *root;

    while (x != NULL)
    {
        y = x;
        x = (data < x->data) ? x->left : x->right;
    }

    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(root, z);
    printf("\nEl número ha sido insertado\n\n");
}

// Busca un nodo en el árbol rojo-negro
int searchRBT(RBT *root, int data)
{
    RBT *current = root;
    while (current != NULL)
    {
        if (data == current->data)
        {
            printf("\nEl número %d existe en el árbol\n", data);
            return current->data;
        }
        current = (data < current->data) ? current->left : current->right;
    }
    printf("\nEl número %d NO existe en el árbol\n", data);
    return -1;
}

// Menú para interactuar con el árbol rojo-negro
void menuRBT()
{
    RBT *root = NULL;
    int option, data;

    do
    {
        printf("\n--- Menú Red-Black Tree ---\n");
        printf("1. Insertar\n");
        printf("2. Buscar\n");
        printf("3. Ver el Árbol\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Ingrese el número a insertar: ");
            scanf("%d", &data);
            insertRBT(&root, data);
            break;
        case 2:
            printf("Ingrese el número a buscar: ");
            scanf("%d", &data);
            searchRBT(root, data);
            break;
        case 3:
            printRBT(root, 0);
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (option != 4);
}