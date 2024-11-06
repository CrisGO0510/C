#include <stdio.h>
#include <stdlib.h>

typedef struct ABB
{
  int data;
  struct ABB *left;
  struct ABB *right;
} ABB;

void insertABB(ABB **, int);
void imprimirPre(ABB *);
void imprimirIn(ABB *);
void imprimirPost(ABB *);
void printPiramid(ABB *, int);
int countNodes(ABB *);
void deleteTree(ABB **, int);
void deleteNode(ABB **, int);
int searchABB(ABB *, int);
int treeHeight(ABB *);
int findParent(ABB *, int);
int treeWeight(ABB *);
int countLeaves(ABB *);
void printGivenLevel(ABB *, int);
int findMax(ABB *);

int menuABB()
{
  ABB *root = NULL;

  int option = 0;
  int value;

  while (option != 12)
  {
    system("cls");
    printf("Menu de arbol Binario\n");
    printf("1. Insertar un valor\n");
    printf("2. Eliminar un valor\n");
    printf("3. Buscar un valor\n");
    printf("4. Ver el Arbol\n");
    printf("5. Recorrer el árbol en En-orden\n");
    printf("6. Recorrer el árbol en Pre-orden\n");
    printf("7. Recorrer el árbol en Post-orden\n");
    printf("8. Calcular el Peso del árbol\n");
    printf("9. Altura del árbol\n");
    printf("10. Contar Cuantas hojas Tiene el árbol\n");
    printf("11. Padre de un Nodo\n");
    printf("12. Salir\n");

    printf("Seleccione una opcion: ");
    scanf("%d", &option);

    if (option == 1)
    {
      printf("Ingrese el valor a insertar: ");
      scanf("%d", &value);
      insertABB(&root, value);
    }
    else if (option == 2)
    {
      printf("Ingrese el valor a eliminar: ");
      scanf("%d", &value);
      deleteNode(&root, value);
    }
    else if (option == 3)
    {
      printf("Ingrese el valor a buscar: ");
      scanf("%d", &value);
      if (searchABB(root, value))
        printf("Valor encontrado en el arbol.\n");
      else
        printf("Valor no encontrado en el arbol.\n");
    }
    else if (option == 4)
    {
      printf("Impresion del árbol:\n");
      printPiramid(root, 0);
      printf("\n");
    }
    else if (option == 5)
    {
      printf("Recorrido en En-orden: ");
      imprimirIn(root);
      printf("\n");
    }
    else if (option == 6)
    {
      printf("Recorrido en Pre-orden: ");
      imprimirPre(root);
      printf("\n");
    }
    else if (option == 7)
    {
      printf("Recorrido en Post-orden: ");
      imprimirPost(root);
      printf("\n");
    }
    else if (option == 8)
    {
      printf("Peso del árbol: %d\n", treeWeight(root));
    }
    else if (option == 9)
    {
      printf("Altura del árbol: %d\n", treeHeight(root));
    }
    else if (option == 10)
    {
      printf("Cantidad de hojas: %d\n", countLeaves(root));
    }
    else if (option == 11)
    {
      printf("Ingrese el valor del nodo para encontrar su padre: ");
      scanf("%d", &value);
      int parent = findParent(root, value);
      if (parent == -1)
        printf("El nodo no tiene padre o no existe en el árbol.\n");
      else
        printf("El padre del nodo %d es %d.\n", value, parent);
    }
    else if (option == 12)
    {
      printf("Saliendo del programa.\n");
    }
    else
    {
      printf("Opcion no valida. Intentelo de nuevo.\n");
    }

    printf("\nPresione enter para continuar...");
    getchar();
    getchar();
  }

  return 0;
}

// Función para visualizar el árbol
void printPiramid(ABB *tree, int n)
{
  if (tree == NULL)
    return;
  printPiramid(tree->right, n + 1);

  for (int i = 0; i < n; i++)
    printf("   ");

  printf("%d\n", tree->data);

  printPiramid(tree->left, n + 1);
}

void insertABB(ABB **root, int x)
{
  ABB *newTree = (ABB *)malloc(sizeof(ABB));
  newTree->data = x;
  newTree->left = NULL;
  newTree->right = NULL;
  if (*root == NULL)
    *root = newTree;
  else
  {
    ABB *currency, *aux;
    currency = NULL;
    aux = *root;
    while (aux != NULL)
    {
      currency = aux;
      if (x < aux->data)
        aux = aux->left;
      else if (x > aux->data)
        aux = aux->right;
      else
      {
        // Si el número es igual, no inserta
        free(newTree);
        return;
      }
    }
    if (x < currency->data)
      currency->left = newTree;
    else
      currency->right = newTree;
  }
}

void deleteNode(ABB **root, int data)
{
  if (*root == NULL)
    return;

  if (data < (*root)->data)
    deleteNode(&(*root)->left, data);
  else if (data > (*root)->data)
    deleteNode(&(*root)->right, data);
  else
  {
    if ((*root)->left == NULL)
    {
      ABB *temp = (*root)->right;
      free(*root);
      *root = temp;
    }
    else if ((*root)->right == NULL)
    {
      ABB *temp = (*root)->left;
      free(*root);
      *root = temp;
    }
    else
    {
      ABB *temp = (*root)->right;
      while (temp && temp->left != NULL)
        temp = temp->left;

      (*root)->data = temp->data;
      deleteNode(&(*root)->right, temp->data);
    }
  }
}

int searchABB(ABB *root, int data)
{
  int steps = 0;
  while (root != NULL)
  {
    if (root->data == data)
      return steps;
    else if (data < root->data)
      root = root->left;
    else
      root = root->right;

    steps++;
  }
  return -1;
}

void imprimirPre(ABB *aux)
{
  if (aux != NULL)
  {
    printf("%i-", aux->data);
    imprimirPre(aux->left);
    imprimirPre(aux->right);
  }
}

void imprimirIn(ABB *aux)
{
  if (aux != NULL)
  {
    imprimirIn(aux->left);
    printf("%i-", aux->data);
    imprimirIn(aux->right);
  }
}

void imprimirPost(ABB *aux)
{
  if (aux != NULL)
  {
    imprimirPost(aux->left);
    imprimirPost(aux->right);
    printf("%i-", aux->data);
  }
}

int treeWeight(ABB *root)
{
  if (root == NULL)
    return 0;
  return 1 + treeWeight(root->left) + treeWeight(root->right);
}

int treeHeight(ABB *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int left_height = treeHeight(root->left);
    int right_height = treeHeight(root->right);

    if (left_height > right_height)
      return (left_height + 1);
    else
      return (right_height + 1);
  }
}

int countLeaves(ABB *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  return countLeaves(root->left) + countLeaves(root->right);
}

void deleteTree(ABB **root, int data)
{
  if (*root == NULL)
    return;

  if ((*root)->data == data)
  {
    if ((*root)->left == NULL && (*root)->right == NULL)
    {
      root = NULL;
      return;
    }

    if ((*root)->left != NULL && (*root)->right != NULL)
    {
      ABB *aux = (*root)->right;

      while (aux->left != NULL)
      {
        aux = aux->left;
      }

      *root = aux;

      return;
    }

    if ((*root)->left != NULL)
    {
      *root = (*root)->left;
      return;
    }
    else if ((*root)->right != NULL)
    {
      *root = (*root)->right;
      return;
    }
  }
  else if ((*root)->data > data)
  {
    deleteTree(&(*root)->left, data);
  }
  else if ((*root)->data < data)
  {
    deleteTree(&(*root)->right, data);
  }
}

int findParent(ABB *root, int data)
{
  if (root == NULL || root->data == data)
    return -1;

  if ((root->left != NULL && root->left->data == data) ||
      (root->right != NULL && root->right->data == data))
    return root->data;

  if (data < root->data)
    return findParent(root->left, data);
  else
    return findParent(root->right, data);
}

void print_level_order(ABB *root)
{
  if (root == NULL)
    return;

  int h = treeHeight(root);
  for (int i = 0; i < h; i++)
  {
    printf("Nivel %d: ", i);
    printGivenLevel(root, i);
    printf("\n");
  }
}

void printGivenLevel(ABB *root, int level)
{
  if (root == NULL)
    return;
  if (level == 0)
    printf("%d ", root->data);
  else if (level > 0)
  {
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
  }
}

int findMax(ABB *root)
{
  if (root == NULL)
    return -1;

  while (root->right != NULL)
    root = root->right;

  return root->data;
}