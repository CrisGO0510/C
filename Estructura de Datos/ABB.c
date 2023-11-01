#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *rigth;
} tree;

void insert(tree **, int);
void imprimirPre(tree *);
void imprimirIn(tree *);
void imprimirPost(tree *);
void print_piramid(tree *, int);
int count_nodes(tree *);
void delete_tree(tree **, int);

int main()
{
  tree *root = NULL;

  int option;
  int value;

  while (option != 8)
  {
    system("cls");
    printf("Menu de arbol Binario\n");
    printf("1. Insertar un valor\n");
    printf("2. Imprimir en PreOrden\n");
    printf("3. Imprimir en InOrden\n");
    printf("4. Imprimir en PostOrden\n");
    printf("5. Imprimir en forma piramidal\n");
    printf("6. Cantidad de nodos\n");
    printf("7. Eliminar nodo\n");
    printf("8. Salir\n");

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
      printf("Impresion en PreOrden: ");
      imprimirPre(root);
      printf("\n");
    }
    else if (option == 3)
    {
      printf("Impresion en InOrden: ");
      imprimirIn(root);
      printf("\n");
    }
    else if (option == 4)
    {
      printf("Impresion en PostOrden: ");
      imprimirPost(root);
      printf("\n");
    }
    else if (option == 5)
    {
      printf("Impresion Piramidal (pruebas):\n");
      print_piramid(root, 0);
      printf("\n");
    }
    else if (option == 6)
    {
      printf("Cantidad de nodos: %d\n", count_nodes(root));
    }
    else if(option == 7)
    {
      printf("Ingrese el valor a eliminar: ");
      scanf("%d", &value);
      delete_tree(&root, value);
    }
    else if (option == 8)
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

void imprimirPre(tree *aux)
{
  if (aux != NULL)
  {
    printf("%i-", aux->data);
    imprimirPre(aux->left);
    imprimirPre(aux->rigth);
  }
}

void imprimirIn(tree *aux)
{
  if (aux != NULL)
  {
    imprimirIn(aux->left);
    printf("%i-", aux->data);
    imprimirIn(aux->rigth);
  }
}

void imprimirPost(tree *aux)
{
  if (aux != NULL)
  {
    imprimirPost(aux->left);
    imprimirPost(aux->rigth);
    printf("%i-", aux->data);
  }
}

void print_piramid(tree *root, int level)
{
  if (root == NULL)
    return;

  print_piramid(root->rigth, level + 1);

  for (int i = 0; i < level; i++)
    printf("xxx");

  printf("%d\n", root->data);

  print_piramid(root->left, level + 1);
}

int count_nodes(tree *root)
{
  if (root == NULL)
    return 0;
  else
    return 1 + count_nodes(root->left) + count_nodes(root->rigth);
}

void delete_tree(tree **root, int data)
{
  if (*root == NULL)
    return;

  if ((*root)->data == data)
  {
    if ((*root)->left == NULL && (*root)->rigth == NULL)
    {
      root = NULL;
      return;
    }

    if ((*root)->left != NULL && (*root)->rigth != NULL)
    {
      tree *aux = (*root)->rigth;

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
    else if ((*root)->rigth != NULL)
    {
      *root = (*root)->rigth;
      return;
    }
  }
  else if ((*root)->data > data)
  {
    delete_tree(&(*root)->left, data);
  }
  else if ((*root)->data < data)
  {
    delete_tree(&(*root)->rigth, data);
  }
}