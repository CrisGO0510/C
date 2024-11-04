#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
} tree;

void insert(tree **, int);
void imprimirPre(tree *);
void imprimirIn(tree *);
void imprimirPost(tree *);
void print_piramid(tree *, int);
int count_nodes(tree *);
void delete_tree(tree **, int);
void delete_node(tree **, int);
int search(tree *, int);
int tree_height(tree *);
int find_parent(tree *, int);
int tree_weight(tree *);
int count_leaves(tree *);

int menuABB()
{
  tree *root = NULL;

  int option = 0;
  int value;

  while (option != 12)
  {
    system("cls");
    printf("Menu de arbol Binario\n");
    printf("1. Insertar un valor\n");
    printf("2. Eliminar un valor\n");
    printf("3. Buscar un valor\n");
    printf("4. Ver el Árbol\n");
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
      insert(&root, value);
    }
    else if (option == 2)
    {
      printf("Ingrese el valor a eliminar: ");
      scanf("%d", &value);
      delete_node(&root, value);
    }
    else if (option == 3)
    {
      printf("Ingrese el valor a buscar: ");
      scanf("%d", &value);
      if (search(root, value))
        printf("Valor encontrado en el arbol.\n");
      else
        printf("Valor no encontrado en el arbol.\n");
    }
    else if (option == 4)
    {
      printf("Impresion del árbol:\n");
      print_piramid(root, 0);
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
      printf("Peso del árbol: %d\n", tree_weight(root));
    }
    else if (option == 9)
    {
      printf("Altura del árbol: %d\n", tree_height(root));
    }
    else if (option == 10)
    {
      printf("Cantidad de hojas: %d\n", count_leaves(root));
    }
    else if (option == 11)
    {
      printf("Ingrese el valor del nodo para encontrar su padre: ");
      scanf("%d", &value);
      int parent = find_parent(root, value);
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

void insert(tree **root, int x)
{
  tree *newTree = (tree *)malloc(sizeof(tree));
  newTree->data = x;
  newTree->left = NULL;
  newTree->right = NULL;
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

void delete_node(tree **root, int data)
{
  if (*root == NULL)
    return;

  if (data < (*root)->data)
    delete_node(&(*root)->left, data);
  else if (data > (*root)->data)
    delete_node(&(*root)->right, data);
  else
  {
    if ((*root)->left == NULL)
    {
      tree *temp = (*root)->right;
      free(*root);
      *root = temp;
    }
    else if ((*root)->right == NULL)
    {
      tree *temp = (*root)->left;
      free(*root);
      *root = temp;
    }
    else
    {
      tree *temp = (*root)->right;
      while (temp && temp->left != NULL)
        temp = temp->left;

      (*root)->data = temp->data;
      delete_node(&(*root)->right, temp->data);
    }
  }
}

int search(tree *root, int data)
{
  if (root == NULL)
    return 0;

  if (root->data == data)
    return 1;
  else if (data < root->data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

void print_piramid(tree *root, int level)
{
  if (root == NULL)
    return;

  print_piramid(root->right, level + 1);

  for (int i = 0; i < level; i++)
    printf("xxx");

  printf("%d\n", root->data);

  print_piramid(root->left, level + 1);
}

void imprimirPre(tree *aux)
{
  if (aux != NULL)
  {
    printf("%i-", aux->data);
    imprimirPre(aux->left);
    imprimirPre(aux->right);
  }
}

void imprimirIn(tree *aux)
{
  if (aux != NULL)
  {
    imprimirIn(aux->left);
    printf("%i-", aux->data);
    imprimirIn(aux->right);
  }
}

void imprimirPost(tree *aux)
{
  if (aux != NULL)
  {
    imprimirPost(aux->left);
    imprimirPost(aux->right);
    printf("%i-", aux->data);
  }
}

int tree_weight(tree *root)
{
  if (root == NULL)
    return 0;
  return 1 + tree_weight(root->left) + tree_weight(root->right);
}

int tree_height(tree *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    if (left_height > right_height)
      return (left_height + 1);
    else
      return (right_height + 1);
  }
}

int count_leaves(tree *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  return count_leaves(root->left) + count_leaves(root->right);
}

void delete_tree(tree **root, int data)
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
      tree *aux = (*root)->right;

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
    delete_tree(&(*root)->left, data);
  }
  else if ((*root)->data < data)
  {
    delete_tree(&(*root)->right, data);
  }
}

int find_parent(tree *root, int data)
{
  if (root == NULL || root->data == data)
    return -1;

  if ((root->left != NULL && root->left->data == data) ||
      (root->right != NULL && root->right->data == data))
    return root->data;

  if (data < root->data)
    return find_parent(root->left, data);
  else
    return find_parent(root->right, data);
}
