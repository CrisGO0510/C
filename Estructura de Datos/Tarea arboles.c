#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int info;
  struct tree *left;
  struct tree *right;
} tree;

void insert_left(tree *, int);
void insert_right(tree *, int);
void impTree(tree *);
void print_inorder(tree *);
void printPiramid(tree *, int);
void newNode(tree **, int, int);

int main()
{
  tree *raiz = NULL;
  int option, data;

  while (option != 4)
  {
    system("cls");
    printf("Bienvenido a los arboles binarios\n");
    printf("1. Insertar nodo\n");
    printf("2. Imprimir arbol en inorder\n");
    printf("3. Imprimir arbol piramide (testeo)\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &option);

    if (option == 1)
    {
      printf("Ingresa el dato a insertar: ");
      scanf("%d", &data);
      newNode(&raiz, data, 0);
    }

    if (option == 2)
    {
      if (raiz == NULL)
        printf("El arbol esta vacio, no se puede imprimir nada\n");
      else
        print_inorder(raiz);
    }

    if (option == 3)
    {
      if (raiz == NULL)
        printf("El arbol esta vacio, no se puede imprimir nada\n");
      else
        printPiramid(raiz, 0);
    }

    printf("\nPresiona enter para continuar...");
    getchar();
    getchar();
  }

  printf("Adios, suerte c:\n");

  return 1;
}

void insert_left(tree *root, int data)
{
  tree *newTree;
  if (root == NULL)
    printf("Error: arbol vacío");
  else if (root->left != NULL)
    printf("Error: Subarbol izquierdo ya existe");
  else
  {
    newTree = malloc(sizeof(tree));
    newTree->info = data;
    newTree->left = NULL;
    newTree->right = NULL;
    root->left = newTree;
  }
}

void insert_right(tree *root, int data)
{
  tree *newTree;
  if (root == NULL)
    printf("Error: arbol vacío");
  else if (root->right != NULL)
    printf("Error: Subarbol derecho ya existe");
  else
  {
    newTree = malloc(sizeof(tree));
    newTree->info = data;
    newTree->left = NULL;
    newTree->right = NULL;
    root->right = newTree;
  }
}

void print_inorder(tree *root)
{
  if (root == NULL)
    return;

  print_inorder(root->left);
  printf("%d ", root->info);
  print_inorder(root->right);
}

void printPiramid(tree *root, int level)
{
  if (root == NULL)
    return;

  printPiramid(root->right, level + 1);

  for (int i = 0; i < level; i++)
    printf("xxx");

  printf("%d\n", root->info);

  printPiramid(root->left, level + 1);
}

void newNode(tree **root, int data, int level)
{
  if (*root == NULL)
  {
    *root = (tree *)malloc(sizeof(tree));
    (*root)->info = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return;
  }

  printf("Estamos en el nivel: %d\n", level);
  printf("Deseas ir a la izquierda o derecha? (0 / 1)\n");
  int option;
  scanf("%d", &option);

  if (option == 0)
  {
    if ((*root)->left == NULL)
    {
      insert_left(*root, data);
      printf("Insercion exitosa en el nodo izquierdo del nivel %i\n", level);
      return;
    }

    if ((*root)->left != NULL)
    {
      newNode(&(*root)->left, data, level + 1);
      return;
    }
  }

  if (option == 1)
  {
    if ((*root)->right == NULL)
    {
      insert_right(*root, data);
      printf("Insercion exitosa en el nodo derecho del nivel %i\n", level);
      return;
    }

    if ((*root)->right != NULL)
    {
      newNode(&(*root)->right, data, level + 1);
      return;
    }
  }
}