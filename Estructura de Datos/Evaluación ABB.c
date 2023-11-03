/*
 * Fecha de publicación: 2023-09-01
 * Hora: 14:16
 * Autor: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Descripción del programa: Programa que implementa un menú para interactuar con un ABB
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *rigth;
} tree;

typedef struct list
{
  int info;
  struct list *sig;
} list;

void insert(tree **, int);
void printIn(tree *);
void printPiramid(tree *, int);
int count_nodes(tree *);
void delete_tree(tree **, int);
int min_value(tree *);
int count_leaf(tree *);
int count_level(tree *);
void printBreadth(tree *);
void insertList(list **, list **, int);
int extractHeadList(list **, list **);
tree *findNode(tree *, int);
int max_value(tree *);
void printDescendent(tree *);
tree *copyTree(tree *root);

int main()
{
  tree *root = NULL;

  int option;
  int value;

  // Pruebas
  insert(&root, 8);
  insert(&root, 3);
  insert(&root, 10);
  insert(&root, 1);
  insert(&root, 6);
  insert(&root, 4);
  insert(&root, 7);
  insert(&root, 14);
  insert(&root, 13);

  while (option != 10)
  {
    system("cls");
    printf("Menu de arbol Binario\n");
    printf("0. Imprimir en forma piramidal (pruebas)\n");
    printf("1. Insertar un valor\n");
    printf("2. Imprimir en InOrden\n");
    printf("3. Cantidad de nodos\n");
    printf("4. Valor minimo contenido en el arbol\n");
    printf("5. Eliminar nodo\n");
    printf("6. Numero de nodos hoja\n");
    printf("7. Niveles del ABB\n");
    printf("8. Imprimir por amplitud\n");
    printf("9. Imprimir arbol descendetemente\n");
    printf("10. Salir\n");

    printf("Seleccione una opcion: ");
    scanf("%d", &option);

    if (option == 1)
    {
      printf("Ingrese el valor a insertar: ");
      scanf("%d", &value);
      insert(&root, value);
    }
    else if (option == 2)
    {
      printf("Impresion en InOrden: ");
      printIn(root);
      printf("\n");
    }
    else if (option == 0)
    {
      printf("Impresion Piramidal (pruebas):\n");
      printPiramid(root, 0);
    }
    else if (option == 3)
      printf("Cantidad de nodos: %d\n", count_nodes(root));
    else if (option == 4)
      printf("Valor minimo: %d\n", min_value(root));
    else if (option == 5)
    {
      printf("Ingrese el valor a eliminar: ");
      scanf("%d", &value);
      delete_tree(&root, value);
    }
    else if (option == 6)
    {
      if (root == NULL)
        printf("El arbol esta vacio.\n");
      else
        printf("Cantidad de nodos hoja: %d\n", count_leaf(root));
    }
    else if (option == 7)
      printf("Niveles del ABB: %d\n", count_level(root));
    else if (option == 8)
      printBreadth(root);
    else if (option == 9)
      printDescendent(root);
    else if (option == 10)
      printf("Saliendo del programa.\n");
    else
      printf("Opcion no valida. Intentelo de nuevo.\n");

    printf("\nPresione enter para continuar...");
    getchar();
    getchar();
  }

  return 0;
}

//? Función para imprimir en forma piramidal (pruebas)
void printPiramid(tree *root, int level)
{
  if (root == NULL)
    return;

  printPiramid(root->rigth, level + 1);

  for (int i = 0; i < level; i++)
    printf("xxx");

  printf("%d\n", root->data);

  printPiramid(root->left, level + 1);
}

//? Función para insertar un valor en el arbol
void insert(tree **root, int x)
{
  tree *newTree = (tree *)malloc(sizeof(tree));
  newTree->data = x;
  newTree->left = NULL;
  newTree->rigth = NULL;
  if (*root == NULL)
    *root = newTree;
  else
  {
    tree *currency, *aux;
    currency = NULL;
    aux = *root;
    while (aux != NULL)
    {
      currency = aux;
      if (x < aux->data)
        aux = aux->left;
      else
        aux = aux->rigth;
    }
    if (x < currency->data)
      currency->left = newTree;
    else
      currency->rigth = newTree;
  }
}

// ? Función para imprimir en InOrden
void printIn(tree *aux)
{
  if (aux != NULL)
  {
    printIn(aux->left);
    printf("%i-", aux->data);
    printIn(aux->rigth);
  }
}

//? Función para contar nodos
int count_nodes(tree *root)
{
  if (root == NULL)
    return 0;
  else
    return 1 + count_nodes(root->left) + count_nodes(root->rigth);
}

//? Función para encontrar el valor mínimo
int min_value(tree *root)
{
  if (root == NULL)
    return 0;

  if (root->left == NULL)
    return root->data;

  return min_value(root->left);
}

//? Función para encontrar el valor máximo
int max_value(tree *root)
{
  if (root == NULL)
    return 0;

  if (root->left == NULL)
    return root->data;

  return max_value(root->left);
}

//? Función para eliminar un nodo
void delete_tree(tree **root, int data)
{
  if (*root == NULL)
    return;

  if (data < (*root)->data)
    delete_tree(&((*root)->left), data);
  else if (data > (*root)->data)
    delete_tree(&((*root)->rigth), data);
  else
  {
    if ((*root)->left == NULL)
    {
      tree *temp = (*root)->rigth;
      free(*root);
      *root = temp;
    }
    else if ((*root)->rigth == NULL)
    {
      tree *temp = (*root)->left;
      free(*root);
      *root = temp;
    }
    else
    {
      tree *temp = (*root)->rigth;
      while (temp->left != NULL)
      {
        temp = temp->left;
      }
      (*root)->data = temp->data;
      delete_tree(&((*root)->rigth), temp->data);
    }
  }
}

//? Función para contar nodos hoja
int count_leaf(tree *root)
{
  if (root == NULL)
    return 0;
  else if (root->left == NULL && root->rigth == NULL)
    return 1;
  else
    return count_leaf(root->left) + count_leaf(root->rigth);
}

//? Función para contar los niveles de un arbol
int count_level(tree *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int left = count_level(root->left);

    int rigth = count_level(root->rigth);

    if (left > rigth)
      return left + 1;
    else
      return rigth + 1;
  }
}

//? Función para imprimir por amplitud
void printBreadth(tree *root)
{
  if (root == NULL)
    return;

  tree *aux = NULL;

  list *head = NULL;
  list *tail = NULL;

  insertList(&head, &tail, root->data);

  while (head != NULL)
  {
    int value = extractHeadList(&head, &tail);
    printf("%d ", value);
    aux = findNode(root, value);
    if (aux->left != NULL)
      insertList(&head, &tail, aux->left->data);
    if (aux->rigth != NULL)
      insertList(&head, &tail, aux->rigth->data);
  }
}

//? Función para imprimir el arbol descendetemente
void printDescendent(tree *root)
{
  if (root == NULL)
    return;

  tree *aux = copyTree(root);
  int value = 0;

  while (aux != NULL)
  {
    value = min_value(aux);
    printf("%d ", value);
    delete_tree(&aux, value);
  }
}

//? Función para copiar un arbol
tree *copyTree(tree *root)
{
  if (root == NULL)
  {
    return NULL;
  }

  tree *copyRoot = (tree *)malloc(sizeof(tree));
  copyRoot->data = root->data;
  copyRoot->left = copyTree(root->left);
  copyRoot->rigth = copyTree(root->rigth);

  return copyRoot;
}

//? Función para encontrar un nodo con un valor específico
tree *findNode(tree *root, int data)
{
  if (root == NULL)
    return NULL;

  if (root->data == data)
    return root;

  if (data < root->data)
    return findNode(root->left, data);

  return findNode(root->rigth, data);
}

//? Función para insertar en una lista tipo cola
void insertList(list **head, list **tail, int x)
{
  list *newList = (list *)malloc(sizeof(list));
  newList->info = x;
  newList->sig = NULL;
  if (*head == NULL)
  {
    *head = newList;
    *tail = newList;
  }
  else
  {
    (*tail)->sig = newList;
    *tail = newList;
  }
}

//? Función para extraer el primer elemento de una lista tipo cola
int extractHeadList(list **head, list **tail)
{
  if ((*head) != NULL)
  {
    int informacion = (*head)->info;
    list *aux = *head;
    if (head == tail)
    {
      *head = NULL;
      *tail = NULL;
    }
    else
    {
      *head = (*head)->sig;
    }
    free(aux);
    return informacion;
  }
  else
    return -1;
}
