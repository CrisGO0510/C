#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Estructura del nodo AVL
typedef struct AVL
{
  int data;
  int FE;
  struct AVL *right;
  struct AVL *left;
  struct AVL *parent;
} AVL;

// Función para visualizar el árbol
void printAVL(AVL *tree, int n)
{
  if (tree == NULL)
    return;
  printAVL(tree->right, n + 1);

  for (int i = 0; i < n; i++)
    printf("   ");

  printf("%d\n", tree->data);

  printAVL(tree->left, n + 1);
}

// Rotación doble derecha
void RDD(AVL **r, AVL *nodoAVL)
{
  AVL *parent = nodoAVL->parent;
  AVL *A = nodoAVL;
  AVL *B = A->left;
  AVL *C = B->right;
  AVL *CI = C->left;
  AVL *CD = C->right;

  if (parent != NULL)
  {
    if (parent->right == A)
      parent->right = C;
    else
      parent->left = C;
  }
  else
  {
    *r = C;
  }

  // ROTAR
  B->right = CI;
  A->left = CD;
  C->left = B;
  C->right = A;
  C->parent = parent;
  A->parent = B->parent = C;
  if (CI)
    CI->parent = B;
  if (CD)
    CD->parent = A;

  // Actualizar factores de equilibrio
  switch (C->FE)
  {
  case -1:
    B->FE = 0;
    A->FE = 1;
    break;
  case 0:
    B->FE = 0;
    A->FE = 0;
    break;
  case 1:
    B->FE = -1;
    A->FE = 0;
    break;
  }
  C->FE = 0;
}

// Rotación doble izquierda
void RDI(AVL **r, AVL *nodoAVL)
{
  AVL *parent = nodoAVL->parent;
  AVL *A = nodoAVL;
  AVL *B = A->right;
  AVL *C = B->left;
  AVL *CI = C->left;
  AVL *CD = C->right;

  if (parent)
  {
    if (parent->right == A)
      parent->right = C;
    else
      parent->left = C;
  }
  else
  {
    *r = C;
  }

  // ROTAR
  A->right = CI;
  B->left = CD;
  C->left = A;
  C->right = B;
  C->parent = parent;
  A->parent = B->parent = C;
  if (CI)
    CI->parent = A;
  if (CD)
    CD->parent = B;

  // Actualizar factores de equilibrio
  switch (C->FE)
  {
  case -1:
    A->FE = 0;
    B->FE = 1;
    break;
  case 0:
    A->FE = 0;
    B->FE = 0;
    break;
  case 1:
    A->FE = -1;
    B->FE = 0;
    break;
  }
  C->FE = 0;
}

// Rotación simple derecha
void RSD(AVL **r, AVL *nodoAVL)
{
  AVL *parent = nodoAVL->parent;
  AVL *A = nodoAVL;
  AVL *B = A->left;
  AVL *C = B->right;

  if (parent)
  {
    if (parent->right == A)
      parent->right = B;
    else
      parent->left = B;
  }
  else
  {
    *r = B;
  }

  // ROTAR
  A->left = C;
  B->right = A;
  A->parent = B;
  if (C)
    C->parent = A;
  B->parent = parent;

  // Actualizar factores de equilibrio
  A->FE = 0;
  B->FE = 0;
}

// Rotación simple izquierda
void RSI(AVL **r, AVL *nodoAVL)
{
  AVL *parent = nodoAVL->parent;
  AVL *A = nodoAVL;
  AVL *B = A->right;
  AVL *C = B->left;

  if (parent)
  {
    if (parent->right == A)
      parent->right = B;
    else
      parent->left = B;
  }
  else
  {
    *r = B;
  }

  // ROTAR
  A->right = C;
  B->left = A;
  A->parent = B;
  if (C)
    C->parent = A;
  B->parent = parent;

  // Actualizar factores de equilibrio
  A->FE = 0;
  B->FE = 0;
}

// Determina si el nodo es hoja
int isSheet(AVL *nodoAVL)
{
  return !nodoAVL->right && !nodoAVL->left;
}

// Calcula la altura del árbol
int height(AVL *tree)
{
  if (tree == NULL)
    return 0;
  int altIzq = height(tree->left);
  int altDer = height(tree->right);
  return (altIzq > altDer ? altIzq : altDer) + 1;
}

// Equilibrar el árbol
void balance(AVL **r, AVL *nodoAVL)
{
  int exit = FALSE;

  while (nodoAVL && exit != TRUE)
  {
    nodoAVL->FE = height(nodoAVL->right) - height(nodoAVL->left);

    if (nodoAVL->FE == -2)
    {
      if (nodoAVL->left->FE == 1)
        RDD(r, nodoAVL);
      else
        RSD(r, nodoAVL);
      exit = TRUE;
    }
    else if (nodoAVL->FE == 2)
    {
      if (nodoAVL->right->FE == -1)
        RDI(r, nodoAVL);
      else
        RSI(r, nodoAVL);
      exit = TRUE;
    }
    nodoAVL = nodoAVL->parent;
  }
}

// Inserta un nodo en el árbol AVL
void insertAVL(AVL **r, int data)
{
  AVL **nodoAVL = r;
  AVL *parent = NULL;
  AVL *currency = *nodoAVL;

  while (currency != NULL && data != currency->data)
  {
    parent = currency;
    currency = (data < currency->data) ? currency->left : currency->right;
  }
  if (currency != NULL)
    return;

  AVL *newAvl = (AVL *)malloc(sizeof(struct AVL));
  newAvl->data = data;
  newAvl->left = newAvl->right = NULL;
  newAvl->FE = 0;
  newAvl->parent = parent;

  if (parent == NULL)
    *nodoAVL = newAvl;
  else if (data < parent->data)
  {
    parent->left = newAvl;
  }
  else
  {
    parent->right = newAvl;
  }

  balance(nodoAVL, parent);
  printf("\nEl numero ha sido insertado\n\n");
}

// Busca un nodo en el árbol y retorna el dato
int searchAVL(AVL *nodoAVL, int data)
{
  AVL *currency = nodoAVL;
  while (currency != NULL)
  {
    if (data == currency->data)
    {
      printf("\nEl numero %d existe en el arbol\n", data);
      return currency->data;
    }
    currency = (data < currency->data) ? currency->left : currency->right;
  }
  printf("\nEl numero %d NO existe en el arbol\n", data);
  return -1;
}

// Elimina un nodo del árbol AVL
void deleteAVL(AVL **r, int data)
{
  AVL *nodoAVL = *r;
  AVL *parent = NULL;
  AVL *currency = nodoAVL;

  // Buscar el nodo a eliminar
  while (currency != NULL && data != currency->data)
  {
    parent = currency;
    currency = (data < currency->data) ? currency->left : currency->right;
  }

  if (currency == NULL)
  {
    printf("\nEl numero %d NO existe en el tree\n", data);
    return;
  }

  // Nodo con dos hijos
  if (currency->left != NULL && currency->right != NULL)
  {
    AVL *successor = currency->right;
    while (successor->left != NULL)
    {
      successor = successor->left;
    }
    currency->data = successor->data;
    currency = successor;
  }

  // Nodo con uno o ningún hijo
  AVL *child = (currency->left != NULL) ? currency->left : currency->right;

  if (child != NULL)
  {
    child->parent = currency->parent;
  }

  if (currency->parent == NULL)
  {
    *r = child;
  }
  else if (currency == currency->parent->left)
  {
    currency->parent->left = child;
  }
  else
  {
    currency->parent->right = child;
  }

  free(currency);

  // Balancear el árbol
  balance(r, parent);
  printf("\nEl numero ha sido eliminado\n\n");
}

// Menú para interactuar con el árbol AVL
void menuAVL()
{
  AVL *root = NULL;
  int option, data;

  do
  {
    printf("\n--- Menú AVL ---\n");
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    printf("3. Buscar\n");
    printf("4. Ver el Árbol\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Ingrese el número a insertar: ");
      scanf("%d", &data);
      insertAVL(&root, data);
      break;
    case 2:
      printf("Ingrese el número a insertar: ");
      scanf("%d", &data);
      deleteAVL(&root, data);
      break;
    case 3:
      printf("Ingrese el número a buscar: ");
      scanf("%d", &data);
      searchAVL(root, data);
      break;
    case 4:
      printAVL(root, 0);
      break;
    case 5:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (option != 5);
}