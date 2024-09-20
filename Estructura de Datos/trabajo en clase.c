/*
 * Fecha de publicación: 20/09/2024
 * Versión de su código: 1.0
 * Autores: Ing(c) Cristhian Giraldo Orozco
 * Nombre del lenguaje: C 201710
 * Versión del copilador: gcc (GCC) 12.2.1 20230111
 * Lenguaje utilizado C(ISO/IEC) 201710
 * Sistema Operativo: Arch Linux
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int value;
  struct node *next;
} node;

void insert(node **, int);
void printlist(node *);
void createSoldierList(node **);
void killSoldier(node **, int);
void killUntilTwo(node **, int);
int randomNum(int);

int main()
{

  srand(time(NULL));

  int value = randomNum(10);

  node *head = NULL;
  createSoldierList(&head);

  killUntilTwo(&head, value);

  return 0;
}

/**
 * @brief Inserta un nuevo nodo con el valor dado en la lista circular.
 *
 * Esta función crea un nuevo nodo con el valor especificado y lo inserta
 * al final de la lista circular.
 *
 * @param head Un doble puntero a la cabeza de la lista circular.
 * @param value El valor que se va a insertar en el nuevo nodo.
 */
void insert(node **head, int value)
{
  node *new_node = (node *)malloc(sizeof(node *));
  new_node->value = value;
  if (*head == NULL)
  {
    *head = new_node;
    new_node->next = *head;
  }
  else
  {
    node *temp = *head;
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
  }
}

/**
 * @brief Imprime los elementos de una lista circular.
 *
 * Esta función recorre una lista circular comenzando desde el nodo
 * cabeza y imprime los valores de cada nodo en la lista.
 *
 * @param head Un puntero al primer nodo de la lista circular.
 */
void printlist(node *head)
{
  if (head == NULL)
  {
    printf("La lista está vacía.\n");
    return;
  }

  node *temp = head;

  do
  {
    printf("%d -> ", temp->value);
    temp = temp->next;
  } while (temp != head);

  printf("%d\n\n\n", head->value);
}

/**
 * @brief Genera un número aleatorio basado en un valor dado.
 *
 * Esta función toma un valor entero como entrada y genera un número aleatorio
 * basado en ese valor. El propósito exacto y el rango del número aleatorio
 * generado no están especificados en el código proporcionado.
 *
 * @param value Un entero que se utiliza como base para generar el número aleatorio.
 * @return Un número entero aleatorio basado en el valor proporcionado.
 */
int randomNum(int value)
{
  return rand() % value;
}

/**
 * @brief Crea una lista de 40 soldados del 0 al 39.
 *
 * Esta función inicializa una lista circular de soldados, estableciendo el puntero de la cabeza de la lista.
 *
 * @param head Doble puntero al nodo cabeza de la lista de soldados.
 */
void createSoldierList(node **head)
{
  for (int i = 0; i < 40; i++)
  {
    insert(head, i);
  }
}

/**
 * @brief Elimina un soldado de la lista circular.
 *
 * Esta función busca y elimina un nodo de la lista circular que contiene el valor especificado.
 *
 * @param head Un puntero doble al puntero de la cabeza de la lista circular.
 * @param value El valor del nodo que se desea eliminar.
 */
void killSoldier(node **head, int value)
{
  node *temp = *head;
  node *prev = NULL;

  if (value == 0)
  {
    do
    {
      prev = temp;
      temp = temp->next;
    } while (temp != *head);
  }

  while (value > 0)
  {
    prev = temp;
    temp = temp->next;
    value--;
  }

  prev->next = temp->next;

  free(temp);

  *head = prev->next;
}

/**
 * @brief Elimina nodos de la lista circular hasta que se encuentren dos nodos restantes.
 *
 * Esta función itera a través de la lista circular comenzando desde el nodo cabeza y elimina cada nodo
 * hasta que queden solo dos nodos en la lista. La función modifica la lista circular en su lugar.
 *
 * @param head Un doble puntero al nodo cabeza de la lista circular.
 * @param value El valor que se usa para eliminar nodos en la lista circular.
 */
void killUntilTwo(node **head, int value)
{
  node *temp = *head;

  while (temp->next->next != temp)
  {
    killSoldier(&temp, value);
    printlist(temp);
  }
}